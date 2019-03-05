#include <string>
#include <iostream>

using namespace std;

// 注：这个题默认单个字母也算回文。所以最短是一个字母。
// 我的思路是，从 i = 0 开始，两个指针 left 和 right，分别指向了回文子串的头和尾。
// 先处理 l-1 或者 r+1 和 i 相同的，再处理 l-1 和 r+1 相同的
// 算一算长度即可
string longestPalindrome(string s) {
    string result = "", tmp = "";
    int len = s.length();
    for (int i = 0; i < len - 1; i++) {
        int l = i, r = i;
        while (l > 0 && s[l - 1] == s[i])
            l--;
        while (r < len - 1 && s[i] == s[r + 1])
            r++;
        while (l > 0 && r < len - 1 && s[l - 1] == s[r + 1]) {
            l--;
            r++;
        }
        if (r - l > 0) {
            tmp = s.substr(l, r - l + 1);
            if (tmp.length() > result.length())
                result = tmp;
        }
    }
    if (result == "")
        result = s[0];
    return result;
}

int main() {
	string a1 = "babad";
	cout << longestPalindrome(a1) << endl; // return bab or aba

	string a2 = "cbbd";
	cout << longestPalindrome(a2) << endl; // return bb

	string a3 = "hiabcccbaabcccbaih";
	cout << longestPalindrome(a3) << endl; // return hiabcccbaabcccbaih

	string a4 = "ghabccccba";
	cout << longestPalindrome(a4) << endl; // return abccccba

	string a5 = "ccccccccccccc";
	cout << longestPalindrome(a5) << endl; // return ccccccccccccc

	string a6 = "a";
	cout << longestPalindrome(a6) << endl; // return a

	string a7 = "ab";
	cout << longestPalindrome(a7) << endl; // return a

	string a8 = "aa";
	cout << longestPalindrome(a8) << endl; // return aa
    
	string a9 = "aba";
	cout << longestPalindrome(a9) << endl; // return aba

	string a10 = "bba";
	cout << longestPalindrome(a10) << endl; // return bb
}