package yuding.android.onboard

import android.util.Log
import androidx.compose.foundation.ExperimentalFoundationApi
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.pager.HorizontalPager
import androidx.compose.foundation.pager.rememberPagerState
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.derivedStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.launch
import yuding.android.R


@OptIn(ExperimentalFoundationApi::class)
@Composable
fun Onboard(onBoardingViewModel: OnBoardingViewModel) {
    val pages = onBoardingViewModel.onboardPages
    val pageState = rememberPagerState { pages.size }
    val buttonPairState = remember {
        derivedStateOf {
            when (pageState.currentPage) {
                0 -> Pair("", "Next")
                1 -> Pair("Previous", "Next")
                2 -> Pair("Previous", "Finish")
                else -> {
                    throw RuntimeException("wrong button pair state ${pageState.currentPage}")
                }
            }
        }
    }


    val currentPage = pages[pageState.currentPage]

    Scaffold(topBar = {
        Row(
            horizontalArrangement = Arrangement.Center, modifier = Modifier
                .background(
                    randomColor()
                )
                .fillMaxWidth()
        ) {
            Text(text = pageState.currentPage.toString())
        }
    }, bottomBar = {
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .background(randomColor()),
            horizontalArrangement = Arrangement.SpaceBetween,
            verticalAlignment = Alignment.CenterVertically
        ) {
            Box(
                contentAlignment = Alignment.CenterStart,
                modifier = Modifier
                    .weight(1f)
                    .background(randomColor())
            ) {
                val scope = rememberCoroutineScope()
                if (pageState.currentPage > 0) {
                    Button(onClick = {
                        scope.launch {
                            pageState.animateScrollToPage(pageState.currentPage - 1)
                        }
                    }) {
                        Text(text = buttonPairState.value.first)
                    }
                }
            }
            Box(contentAlignment = Alignment.Center, modifier = Modifier.weight(1f)) {
                Row {
                    repeat(times = pages.size) {
                        Spacer(modifier = Modifier.size(3.dp))
                        Box(
                            modifier = Modifier
                                .width(
                                    when (it == pageState.currentPage) {
                                        true -> {
                                            20.dp
                                        }

                                        false -> {
                                            10.dp
                                        }
                                    }
                                )
                                .height(10.dp)
                                .clip(RoundedCornerShape(20.dp))
                                .background(
                                    when (it == pageState.currentPage) {
                                        true -> {
                                            MaterialTheme.colorScheme.primary
                                        }

                                        false -> {
                                            MaterialTheme.colorScheme.secondary
                                        }
                                    }
                                )
                        )
                        Spacer(
                            modifier = Modifier.size(3.dp)
                        )
                    }
                }
            }
            Box(
                contentAlignment = Alignment.CenterEnd,
                modifier = Modifier
                    .weight(1f)
                    .background(randomColor())
            ) {
                val scope = rememberCoroutineScope()
                LaunchedEffect(pageState.currentPage) {
                    Log.d(TAG, "current Page : ${pageState.currentPage}")
                }
                Button(onClick = {
                    scope.launch {
                        if (pageState.currentPage >= pages.size) {
                            TODO("onboard complete")
                        } else {
                            Log.d(TAG, "animate to page :${pageState.currentPage + 1}")
                            pageState.animateScrollToPage(pageState.currentPage + 1)
                        }
                    }
                }) {
                    Text(text = buttonPairState.value.second)
                }
            }
        }
    }, content = {
        Column(
            modifier = Modifier
                .padding(it)
                .background(randomColor()),
            horizontalAlignment = Alignment.Start,
            verticalArrangement = Arrangement.Center
        ) {
            HorizontalPager(state = pageState) {
                Spacer(modifier = Modifier.size(50.dp))

                val currentImageId = currentPage.image
                val currentDescription = currentPage.description
                Log.d(TAG, "current image id:$currentImageId, description:$currentDescription")
                Image(painter = painterResource(id = R.drawable.ic_launcher_background), contentDescription = currentDescription)
//            AsyncImage(
//                model = ImageRequest.Builder(LocalContext.current).data(currentDescription).build(),
//                contentDescription = currentDescription
//            )
//            Spacer(modifier = Modifier.size(50.dp))
                Text(
                    text = pages[pageState.currentPage].description,
                    modifier = Modifier.fillMaxSize()
//                    .padding(25.dp, 0.dp),
//                fontSize = 16.sp,
//                textAlign = TextAlign.Center,
//                style = MaterialTheme.typography.bodySmall,
//                color = MaterialTheme.colorScheme.onSurface
                )

            }
        }
    })
}


fun randomColor(): Color {
    val random = java.util.Random()
    Log.d("OnboardingUI", "randomColor()")
    val r = random.nextInt(255)
    val g = random.nextInt(255)
    val b = random.nextInt(255)
    val color = Color(r, g, b)
    Log.d(TAG, "randomColor() color:$r $g $b")
    return color
}

val TAG = "OnboardingUI"