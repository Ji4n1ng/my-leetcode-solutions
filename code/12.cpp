#include <string>
#include <iostream>
#include <vector>

using namespace std;

// digitToRoman 是根据 n 在第几位求出罗马数字。位数为 d。
// 比如：1 在个位是 I，十位是 X。以此类推。
// 题目的数字范围为 (1, 3999)
string digitToRoman(int n, int d) {
    vector<string> roman{"I", "V", "X", "L", "C", "D", "M"};
    string r1 = roman[ 2*(d - 1) ];
    string r5, r10;
    if (d < 4) {
        r5 = roman[ 2*(d - 1) + 1 ];
        r10 = roman[ 2*d ];
    }
    string result;
    if (n == 4) {
        result = r1 + r5;
    } else if (n == 9) {
        result = r1 + r10;
    } else if (n == 5) {
        result = r5;
    } else if (n > 5) {
        result = r5;
        n = n - 5;
        for (int i = 0; i < n; i++) {
            result += r1;
        }
    } else if (n < 4) {
        for (int i = 0; i < n; i++) {
            result += r1;
        }
    }
    return result;
}


string intToRoman(int num) {
    string result = "";
    int d = 1;
    unsigned int n = num;
    while (n != 0) {
        int i = n % 10;
        result = digitToRoman(i, d) + result;
        n /= 10;
        d++;
    }

    return result;
}

void judge(int num, string result) {
    string r = intToRoman(num);
    if (r == result) {
        cout << "√  " << num << "\t\"" << r << "\"" << endl;
    } else {
        cout << "X  " << num << "\t\"" << r << "\" (" << result << ")" << endl;
    }
}

int main() {
    judge(3, "III");
    judge(4, "IV");
    judge(9, "IX");
    judge(58, "LVIII");
    judge(1994, "MCMXCIV");
    judge(669, "DCLXIX");
    judge(20, "XX");
    judge(750, "DCCL");
}