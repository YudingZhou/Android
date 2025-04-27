package cozylab.kotlin

import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.fail

class NullSafeSafetyTest {
    var sut: String? = null

    @BeforeTest
    fun before() {
        sut = null
    }

    @Test
    fun test_not_null_assertion() {
        sut = "1"
        assertEquals(1, sut!!.length)
    }

    @Test
    fun test_nullable() {
        assert(sut?.length == null)
        assert(sut?.getOrNull(1) == null)
    }

    @Test
    fun test_elvis() {
        assertEquals("123", sut ?: "123")
    }

    @Test
    fun test_non_null_but_actually_null() {
        try {
            sut!!.length
            fail()
        } catch (e: Exception) {
            assert(e is NullPointerException)
        }
    }
}