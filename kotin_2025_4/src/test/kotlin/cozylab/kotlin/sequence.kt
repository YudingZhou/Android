package cozylab.kotlin

import kotlin.test.Test
import kotlin.test.assertEquals

class SequenceTest {
    @Test
    fun test() {
        val sequence = "".asSequence()
        var size = 5
        val element = "e"
        val sut = generateSequence {
            size--.let {
                if (size > 0) {
                    element
                } else {
                    null
                }
            }
        }

        assertEquals(5, sut.reduce({ a, b -> a + b }).length)
    }
}