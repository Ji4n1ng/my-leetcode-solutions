
#include <string>
#include <iostream>

using namespace std;

// 两种遍历方法，记笔记！
//    for (unsigned int i = 0; i < s.length(); i++) {
//        char c = s[i];
//    }

bool isPalindrome(string s) {
    string s1;
    for (auto c: s) {
        if (isalpha(c) || isdigit(c)) {
            s1.push_back(tolower(c));
        }
    }

    int len = s1.length();
    int count = len / 2;
    string right;

    for (int i = 1; i <= count; i++) {
        char c = s1[len - i];
        right.push_back(c);
    }

    return s1.substr(0, count) == right;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama"; // return true
    cout << isPalindrome(s1) << endl;

    string s2 = "race a car"; // return false
    cout << isPalindrome(s2) << endl;

    string s3 = "0P"; // return false
    cout << isPalindrome(s3) << endl;
}