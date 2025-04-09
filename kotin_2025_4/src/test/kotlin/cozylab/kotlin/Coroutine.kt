package cozylab.kotlin

import kotlinx.coroutines.*
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

class CoroutineTest {
    val sut = mutableListOf<String>()

    @BeforeTest
    fun before() {
        sut.clear()
    }

    @Test
    fun test_runBlocking() {
        runBlocking {
            sut.add("1")
        }
        sut.add("2")
        assertEquals(listOf("1", "2"), sut)
    }

    @Test
    fun test_launch() {
        runBlocking {
            launch { sut.add("1") }
            sut.add("2")
        }
        sut.add("3")
        assertEquals(listOf("2", "1", "3"), sut)
    }

    @Test
    fun test_explicit_coroutine_job() {
        runBlocking {
            val job = launch {
                sut.add("1")
            }
            sut.add("3")
            job.join()
            sut.add("2")
        }
        assertEquals(listOf("3", "1", "2"), sut)
    }

    /**
     * 1. launch returns a future
     * 2. scope returns an object that waits on completion of its own
     * 3. run attached to a future is NOT A CONTINUATION
     * 4. run attached to a scope is waits on the scope to return, therefore, IS A CONTINUATION
     * */
    @Test
    fun test_scope_launch_suspend_block() {
        runBlocking {
            suspend {
                coroutineScope {
                    launch {
                        sut.add("run job1")
                        coroutineScope {
                            launch {
                                sut.add("run job1.1")
                            }.run {
                                // run block is NOT a continuation
                                // this equals
                                // var future = launch{...}
                                // sut.add("job1 launch done")
                                //
                                // Not equals a continuation like
                                // var future = launch{...}
                                // future.supply(()->{
                                //  sut.add("this is a continuation")
                                // })
                                sut.add("job1.1 launch done")
                            }
                            launch {
                                sut.add("run job1.2")
                            }.run {
                                sut.add("job1.2 launch done")
                            }
                        }
                        // this waits until above scope to finish
                        sut.add("job1 is done")
                    }.run {
                        sut.add("job1 launch done")
                    }
                }.run { sut.add("job1 score is done") }
                //within a scope / suspend block code is sequential
                // this is after the above scope finished
                sut.add("end of suspend")
            }.invoke()
            sut.add("after suspend")
        }

        /**
         * suspend creates a scope
         *
         * */
        assertEquals(
            listOf(
                "job1 launch done",
                "run job1",
                "job1.1 launch done",
                "job1.2 launch done",
                "run job1.1",
                "run job1.2",
                "job1 is done",
                "job1 score is done",
                "end of suspend",
                "after suspend"
            ), sut
        )
    }
}