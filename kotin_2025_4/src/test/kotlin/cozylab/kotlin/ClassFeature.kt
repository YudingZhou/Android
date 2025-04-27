package cozylab.kotlin

import java.lang.StringBuilder
import kotlin.test.Test
import kotlin.test.assertEquals

class ClassFeatureTest {

    @Test
    fun test_singleton() {
        assertEquals(Data("default name", 18), DataSingleton.instance)
    }

    @Test
    fun test_factory() {
        assertEquals(Data("1", 1), DataFactory.produceData("1", 1))
    }

    @Test
    fun test_data_class() {
        val sut = Data("1", 1)
        sut.toString()
        assertEquals(2, sut.copy(age = 2).age)
        assertEquals(Data("2", 3), sut.copy("2", 3))
    }

    @Test
    fun test_extension() {
        fun Data.ext1(): String {
            return "my name is $name"
        }
        assertEquals("my name is default name", DataSingleton.instance.ext1())
    }
}

data class Data(var name: String = "default name", val age: Int = 18)

object DataSingleton {
    val instance = Data()
}

object DataFactory {
    fun produceData(name: String, age: Int) = Data(name, age)
}