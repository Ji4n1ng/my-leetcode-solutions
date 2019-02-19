#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// 我利用了额外的空间，不符合要求。
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> map;
    for (auto i: nums) {
        if (map.find(i) == map.end()) {
            map[i] = 1;
        } else {
            map[i]++;
        }
    }
    for (auto i: map) {
        if (i.second == 1) {
            return i.first;
        }
    }
    return -1;
}

// 答案 1
// 创建一个长度为 sizeof(int) 的数组 count[sizeof(int)],
// count[i] 表示在在 i 位出现的 1 的次数。
// 如果 count[i] 是 3 的整数倍，则忽略；否则就把该位取出来组成答案。
int singleNumber2(vector<int>& nums) {
    const int W = sizeof(int) * 8; // 一个整数的 bit 数，即整数字长
    int count[W]; // count[i] 表示在在 i 位出现的 1 的次数
    fill_n(&count[0], W, 0);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < W; j++) {
            count[j] += (nums[i] >> j) & 1;
            count[j] %= 3;
        }
    }
    int result = 0;
    for (int i = 0; i < W; i++) {
        result += (count[i] << i);
    }
    return result;
}

// 答案2 用二进制模拟三进制运算
// 用 one 记录到当前处理的元素为止，二进制 1 出现"1次"（mod 3 之后的 1）的有哪些二进制位。
// 用 two 记录到当前计算的变量为止，二进制 1 出现"2次"（mod 3 之后的 2）的有哪些二进制位。
// 当 one 和 two 中的某一位同时为 1 时表示该二进制位 1 出现了 3 次。此时需要清零。
// 最后 one 记录的是最终结果。
int singleNumber3(vector<int>& nums) {
    int one = 0, two = 0, three = 0;
    for (auto i : nums) {
        two |= (one & i);
        one ^= i;
        three = ~(one & two);
        one &= three;
        two &= three;
    }
    return one;
}