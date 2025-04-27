package yuding.android.onboard

import android.content.Context
import androidx.compose.ui.res.stringResource
import androidx.lifecycle.ViewModel
import yuding.android.R

class OnBoardingViewModel(context: Context) : ViewModel() {
    val onboardPages = listOf(
        OnboardPageMode(
            id = 1,
            title = context.getString(R.string.onboard_page_1_title),
            description = context.getString(R.string.onboard_page_1_description),
            image = R.drawable.onboard_1
        ), OnboardPageMode(
            id = 2,
            title = context.getString(R.string.onboard_page_2_title),
            description = context.getString(R.string.onboard_page_2_description),
            image = R.drawable.onboard_2
        ), OnboardPageMode(
            id = 3,
            title = context.getString(R.string.onboard_page_3_title),
            description = context.getString(R.string.onboard_page_3_description),
            image = R.drawable.onboard_1
        )
    )
}

data class OnboardPageMode(
    val id: Int, val title: String, val description: String, val image: Int
) {

}

