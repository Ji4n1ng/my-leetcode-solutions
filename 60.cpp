#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 我的思路是，从左到右的每一位，可以用 k / (n-1)! 来表示
// 其中，商在 nums 的位置，代表 nums 剩余的第几大的数，
// 需要注意，如果余数为 0，商 - 1
// 添加到结果后，将该数删除
// k 相应的减少 商*被除数
string getPermutation(int n, int k) {
    if (n == 1) return "1";
    string result = "";
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);

    for (int i = 1; i < n - 1; i++) {
        int fac = factorial(n - i);
        int quotient = k / fac;
        if (k % fac == 0)
            quotient -= 1;

        result += to_string(nums[quotient]);

        nums.erase(nums.begin() + quotient);
        k -= quotient * fac;
    }

    if (k % 2 == 0)
        result += to_string(nums[1]) + to_string(nums[0]);
    else
        result += to_string(nums[0]) + to_string(nums[1]);

    return result;
}

int main() {
    cout << getPermutation(5, 1) << endl;
    cout << getPermutation(5, 7) << endl;
    cout << getPermutation(5, 17) << endl;
    cout << getPermutation(5, 18) << endl;
    cout << getPermutation(5, 120) << endl;

    cout << endl;

    cout << getPermutation(2, 2) << endl;

}