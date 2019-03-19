#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

// 特殊情况只有 4 和 9，所以用 last 保存一下上一次的值
// 如果上次的值小于这一次的值说明，是 4 和 9，减去两倍上次的值就行。
int romanToInt(string s) {
    //{"I", "V", "X", "L", "C", "D", "M"}
    unordered_map<char, int> roman;
    roman['I'] = 1; roman['V'] = 5;
    roman['X'] = 10; roman['L'] = 50;
    roman['C'] = 100; roman['D'] = 500;
    roman['M'] = 1000;

    int result = 0;
    int last = 10000;
    for (auto c: s) {
        int cInt = roman[c];
        if (last < cInt) {
            result -= 2 * last;
        }
        result += cInt;
        last = cInt;
    }
    return result;
}

void judge(string s, int result) {
    int r = romanToInt(s);
    if (r == result) {
        cout << "√  " << s << "\t\"" << r << "\"" << endl;
    } else {
        cout << "X  " << s << "\t\"" << r << "\" (" << result << ")" << endl;
    }
}


int main() {
    judge("III", 3);
    judge("IV", 4);
    judge("IX", 9);
    judge("LVIII", 58);
    judge("MCMXCIV", 1994);
    judge("DCLXIX", 669);
    judge("XX", 20);
    judge("DCCL", 750);
}