#include <vector>
#include <iostream>

using namespace std;

// 改自15题的推荐答案，先排序，然后左右夹逼，注意跳过重复的数
// 在每一次移动指针的时候，判断 abs 是否是最小的。
// 如果sum小于target，j右移，跳过重复元素
// 如果sum大于target，k左移，跳过重复元素
// 如果sum等于target，return
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int sum = 0;
    bool initDone = false;

    auto last = nums.end();
    for (auto i = nums.begin(); i < last-2; ++i) {
        auto j = i + 1;
        if (i > nums.begin() && *i == *(i-1)) continue;
        auto k = last - 1;
        if (!initDone) {
            sum = *i + *j + *k;
            initDone = true;
        }
        while (j < k) {
            int tmpSum = *i + *j + *k;
            if (abs(target - sum) > abs(target - tmpSum))
                sum = tmpSum;
            if (tmpSum < target) {
                ++j;
                while(*j == *(j - 1) && j < k) ++j;
            } else if (tmpSum > target) {
                --k;
                while(*k == *(k + 1) && j < k) --k;
            } else {
                return target;
            }
        }
    }
    return sum;
}

// 下面是推荐答案。注意：关于初始值 min_gap = INT_MAX，为此我多写了 bool initDone
// 这个 prev 第一次见，大体思路是一样的，不过推荐答案更简洁，但没有跳过重复元素。
int threeSumClosest2(vector<int>& nums, int target) {
    int result = 0;
    int min_gap = INT_MAX;

    sort(nums.begin(), nums.end());

    for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
        auto b = next(a);
        auto c = prev(nums.end());
        while (b < c) {
            const int sum = *a + *b + *c;
            const int gap = abs(sum - target);
            if (gap < min_gap) {
                result = sum;
                min_gap = gap;
            }
            if (sum < target)
                ++b;
            else
                --c;
        }
    }
    return result;
}

int main() {
    vector<int> vector1 { -1, 2, 1, -4 };

//    target 1 result -1,2,1 sum is 2. return 2
    int sum1 = threeSumClosest(vector1, 1);
    cout << sum1 << endl;

    vector<int> vector2 { -4, -2, -1, 0, 1, 2, 3, 4, 4, 4 };

//    target 20 result 4,4,4 sum is 12. return 12
    int sum2 = threeSumClosest(vector2, 20);
    cout << sum2 << endl;

//    target 1 result -1,0,2 sum is 1. return 1
    int sum3 = threeSumClosest(vector2, 1);
    cout << sum3 << endl;

    vector<int> vector3 { 1, 1, 1, 0 };

//    target -100 result 0, 1, 1 sum is 2. return 2
    int sum4 = threeSumClosest(vector3, -100);
    cout << sum4 << endl;
}
