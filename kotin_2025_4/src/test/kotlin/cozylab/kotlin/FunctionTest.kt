package cozylab.kotlin

import org.junit.jupiter.api.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue


/**
 * https://kotlinlang.org/docs/kotlin-tour-functions.html#function-types
 * */

class FunctionTest {

    @Test
    fun test_funType_syntax_definition_1_type_defined() {
        // Test case for a basic function type
        // val <name>: <(ParaType1, ParaType2)> -> <ReturnType> = { <arg1>, <arg2> -> <return logic>}
        // Example: val add: (Int, Int) -> Int = { a, b -> a + b }

        // lambda type define
        // 1. val <val> : (ParaType) -> ReturnType = {it -> <logic>}
        // 2. val <val> = {para: ParaType -> <logic>}
        val add_type_defined: (Int, Int) -> Int = { x, y ->
            x + y
        }

        val ret = listOf(1, 2, 3).reduce(add_type_defined)
        assertEquals(6, ret)
    }

    @Test
    fun test_funType_syntax_definition_2_no_type_defined() {
        val add_no_type_defined = { x: Int, y: Int -> x + y }
        val ret = listOf(1, 2, 3).reduce(add_no_type_defined)
        assertEquals(6, ret)
    }

    @Test
    fun test_noParameter() {
        // Test case for a lambda with no parameters
        // Example: val greet: () -> String = { "Hello" }

        // built-in run
        // val run = { func: ()->Any?  -> func() }

        val lamb = { "123" }
        assertEquals("123", run { lamb }.invoke())
        assertEquals("123", run { "123" })
    }

    @Test
    fun test_hasParameters() {
        // Test case for a lambda with a single parameter
        // Example: val square: (Int) -> Int = { it * it }

        val lamb: (String, String) -> String = { a: String, b: String -> a + b }
        // inline lambda explicitly refer to args
        assertEquals("123", listOf("1", "2", "3").reduce { a, b -> run { lamb }.invoke(a, b) })
        //supply a function type val
        assertEquals("123", listOf("1", "2", "3").reduce(lamb))
        // inline lambda
        assertEquals("123", listOf("1", "2", "3").reduce { a: String, b: String -> a + b })
    }


    @Test
    fun test_HigherOrderFunction() {
        // Test case for a higher-order function
        // Example: fun operate(a: Int, b: Int, operation: (Int, Int) -> Int): Int

        val accumulation = { numbers: List<Int>, accum: (a: Int, b: Int) -> Int ->
            numbers.reduce(accum)
        }
        assertEquals(10, accumulation(listOf(1, 2, 3, 4)) { a: Int, b: Int -> a + b })
        assertEquals(10, accumulation(listOf(1, 2, 3, 4), { a, b -> a + b }))

        val accumulation_stringify: (number: List<Int>, accum: (String, String) -> String, to_string: (Int) -> String) -> String? =
            { number, accumulator, to_string ->
                number.stream().map(to_string).reduce(accumulator).get()
            }

        assertEquals("12345", accumulation_stringify(listOf(1, 2, 3, 4, 5), { a, b -> a + b }, { it.toString() }))
    }

    @Test
    fun test_lambda_selector() {
        val select = { it: String ->
            when (it) {
                "add" -> { a: Int, b: Int -> a + b }
                "multiply" -> { a: Int, b: Int -> a * b }
                else -> {
                    throw RuntimeException("fast-fail")
                }
            }
        }

        assertEquals(6, run { select }.invoke("add").invoke(3, 3))
        assertEquals(9, run { select }.invoke("multiply").invoke(3, 3))
        var sut: Exception? = null
        try {
            assertEquals(6, run { select }.invoke("throws").invoke(3, 3))
        } catch (e: Exception) {
            sut = e
        }
        assertTrue { sut is RuntimeException }
    }

    @Test
    fun test_InlineFunction() {
        // Test case for an inline function
        // Example: inline fun performOperation(crossinline operation: () -> Unit)
    }

    @Test
    fun test_LambdaWithReceiver() {
        // Test case for a lambda with receiver
        // Example:

        val extended: StringBuilder.() -> Unit = { append("3") }

        val sut = StringBuilder("12")
        sut.extended()
        assertEquals("123", sut.toString())
    }

    @Test
    fun test_AnonymousFunction() {
        // Test case for an anonymous function, compare it with function type variable
        // this is a function
        val subtract = fun(a: Int, b: Int): Int { return a - b }
        assertEquals(-1, run { subtract }.invoke(1, 2))

        // this is a variable of function type
        val add_type_defined: (Int, Int) -> Int = { x, y ->
            x + y
        }
    }

    @Test
    fun test_TailRecursiveFunction() {
        // Test case for a tail-recursive function
        // Example: tailrec fun factorial(n: Int, acc: Int = 1): Int
    }
}