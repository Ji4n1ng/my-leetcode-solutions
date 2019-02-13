#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 初始时，数组都为1。从左往右走，如果碰上 右>左，再回头看看有没有需要增加的。
// 效率比较低
// 760 ms 5.81
int candy(vector<int>& ratings) {
    vector<int> candy;
    for (auto i: ratings) {
        candy.insert(candy.end(), 1);
    }
    for (int i = 0; i < ratings.size() - 1; i++) {
        if (ratings[i] > ratings[i + 1]) {
            if (candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
                int j = i - 1;
                while (j != -1 && ratings[j] > ratings[j + 1] && candy[j] <= candy[j + 1]) {
                    candy[j] = candy[j + 1] + 1;
                    j--;
                }
            }
        } else if (ratings[i] < ratings[i + 1]) {
            if (candy[i] >= candy[i + 1])
                candy[i + 1] = candy[i] + 1;
        }

    }

    int sum = 0;
    for (auto i: candy) 
        sum += i;
        
    return sum;
}

int candy2(vector<int> &ratings) {
    const int n = ratings.size();
    vector<int> increment(n);
    //左右各扫描一次
    for (int i = 1, inc = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            increment[i] = max(inc++, increment[i]);
        else
            inc = 1;
    }
    for (int i = n - 2, inc = 1; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1])
            increment[i] = max(inc++, increment[i]);
        else
            inc = 1;
    }
    //初始值为n，因为每个小朋友至少一颗糖。
    return accumulate(&increment[0], &increment[0]+n, n);
}

int main() {
    vector<int> c1 = { 1, 0, 2 }; // return 5
    cout << candy(c1) << endl;

    vector<int> c2 = { 1, 2, 2 }; // return 4
    cout << candy(c2) << endl;

    vector<int> c3 = { 1, 0, 2, 1, 0, 2, 1, 1, 0 }; // return 15
    cout << candy(c3) << endl;

    vector<int> c4 = { 1, 2, 3, 4, 5 }; // return 15
    cout << candy(c4) << endl;

    vector<int> c5 = { 5, 4, 3, 2, 1 }; // return 15
    cout << candy(c5) << endl;
    
    vector<int> c6 = { 5, 3, 7, 3 }; // return 6
    cout << candy(c6) << endl;
}