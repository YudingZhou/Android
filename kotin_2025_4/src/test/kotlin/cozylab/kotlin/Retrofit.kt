package cozylab.kotlin

import com.google.gson.Gson
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import okhttp3.ResponseBody
import org.junit.jupiter.api.Test
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.scalars.ScalarsConverterFactory
import retrofit2.http.GET

class RetrofitTest {
    @Test
    fun test() {
        fun Array<Object>.toString(): String {
            return asSequence().map { it.toString() }.reduce { a, b -> "${a}, ${b}" }
        }
        runBlocking {
            var sut: Array<Object>? = null
            launch {
                Api.apiEndpoint.list().enqueue(object : Callback<ResponseBody> {
                    override fun onResponse(p0: Call<ResponseBody>, p1: Response<ResponseBody>) {
                        if (p1.isSuccessful) {
                            val fromJson =
                                Gson().fromJson<Array<Object>>(p1.body()?.string(), Array<Object>::class.java)
                            sut = fromJson
                        } else {
                            println(p1.body()?.string())
                        }
                    }

                    override fun onFailure(p0: Call<ResponseBody>, p1: Throwable) {
                        TODO("Not yet implemented")
                    }
                })
                delay(5000)
                println(sut.toString())
                println(sut?.size)
                sut?.forEach { println(it) }
            }
//            assertTrue { sut?.length ?: 0 > 0 }
        }
    }

    @Test
    fun test_blocking() {
        val sut = Api.apiEndpoint.list()
        println(sut)
    }


    data class Object(
        var id: String? = null,
        var name: String? = null,
        var data: Map<Any, Any>? = null
    )

    // define retrofit end point
    interface Endpoints {
        @GET("objects")
        fun list(): Call<ResponseBody>
    }

    // define a singleton to hold the end points
    object Api {
        val apiEndpoint by lazy {
            val retrofit = Retrofit.Builder()
                .baseUrl("https://api.restful-api.dev/").addConverterFactory(ScalarsConverterFactory.create()).build()
            retrofit.create(Endpoints::class.java)
        }
    }
}