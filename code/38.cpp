#include <string>
#include <iostream>

using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";
    string last = "1";
    string tmp_result;
    for (int loop = 1; loop < n; loop++) {
        tmp_result = "";
        int i = 0;
        for (; i < last.length(); i++) {
            char c = last[i];
            int count = 1;
            while (i+1 < last.length() && last[i+1] == c) {
                i++;
                count++;
            }
            tmp_result += to_string(count);
            tmp_result.push_back(c);
        }
        last = tmp_result;
    }
    return last;
}

void judge(int num, string result) {
    string r = countAndSay(num);
    if (r == result) {
        cout << "√  " << num << "\t\"" << r << "\"" << endl;
    } else {
        cout << "X  " << num << "\t\"" << r << "\" (" << result << ")" << endl;
    }
}

int main() {
    judge(1, "1");
    judge(2, "11");
    judge(3, "21");
    judge(4, "1211");
    judge(5, "111221");
    judge(6, "312211");
    judge(7, "13112221");
    judge(8, "1113213211");
}