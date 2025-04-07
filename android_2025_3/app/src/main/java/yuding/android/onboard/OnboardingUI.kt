package yuding.android.onboard

import android.widget.Button
import androidx.compose.foundation.ExperimentalFoundationApi
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.pager.rememberPagerState
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.runtime.Composable
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.derivedStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.ViewModel
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

    Scaffold(
        modifier = Modifier,
        topBar = {
            Text(text = stringResource(R.string.onboard_page_1_title))
        }, bottomBar = {
            Row {
                Box {
                    Button(onClick = { /*TODO*/ }) {
                        Text(text = buttonPairState.value.first)
                    }
                }
                Box{
                    Row{
                        repeat(times = pages.size){
                            Spacer(modifier = Modifier.size(2.5.dp))
                            Box(modifier = Modifier.background(MaterialTheme.colorScheme.secondaryContainer))
                            Spacer(modifier = Modifier.size(2.5.dp))
                        }
                    }
                }

                Box{
                    Button(onClick = {}){
                        Text(text = buttonPairState.value.second)
                    }
                }
            }
        },
        content = {
            OnBoardPage(it)
        }
    )
}

@Composable
private fun OnBoardPage(padding: PaddingValues) {
    Column(
        modifier = Modifier.padding(padding),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Spacer(modifier = Modifier.size(50.dp))
//        Image(
//            painter = painterResource(R.drawable.ic_launcher_background),
//            contentDescription = "content description 1"
//        )
        Spacer(modifier = Modifier.size(50.dp))
        Text(
            text = stringResource(R.string.onboard_page_1_description),
            modifier = Modifier
                .fillMaxSize()
                .padding(25.dp, 0.dp),
            fontSize = 16.sp,
            textAlign = TextAlign.Center,
            style = MaterialTheme.typography.bodySmall,
            color = MaterialTheme.colorScheme.onSurface
        )
    }
}