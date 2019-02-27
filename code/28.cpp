
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// 我的是暴力匹配，答案是 KMP，建议多看几遍
int strStr(string haystack, string needle) {
	if (needle == "") return 0;
	int len = needle.length();
	for (unsigned int i = 0; i < haystack.length(); i++) {
		char c = haystack[i];
		if (c == needle[0]) {
			if (haystack.substr(i, len) == needle)
				return i;
		}
	}
	return -1;
}

// 暴力算法 O(m*n)，更高效的有 KMP，Boyer-Mooer 算法和 Rabin-Karp 算法

/*
 * @brief 计算部分匹配表，即 next 数组
 *
 * @param[in] pattern 模式串
 * @param[out] next next 数组
 * @return 无
 */
static void compute_prefix(const char *pattern, int next[]) {
	int i;
	int j = -1;
	const int m = strlen(pattern);
	next[0] = j;
	for (i = 1; i < m; i++) {
		while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
		if (pattern[i] == pattern[j + 1]) j++;
		next[i] = j;
	}
}

/*
 * @brief KMP 算法
 *
 * @param[in] text 文本
 * @param[in] pattern 模式串
 * @return 成功则返回第一次匹配的位置，失败则返回-1
 */
static int kmp(const char *text, const char *pattern) {
	int i;
	int j = -1;
	const int n = strlen(text);
	const int m = strlen(pattern);
	if (n == 0 && m == 0) return 0; /* "","" */
	if (m == 0) return 0; /* "a","" */
	int *next = (int*)malloc(sizeof(int) * m);
	compute_prefix(pattern, next);
	for (i = 0; i < n; i++) {
		while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
		if (text[i] == pattern[j + 1]) j++;
		if (j == m - 1) {
			free(next);
			return i-j;
		}
	}
	free(next);
	return -1;
}

int strStr(const string& haystack, const string& needle) {
	return kmp(haystack.c_str(), needle.c_str());
}
int main() {
	string s1 = "hello"; // return 2
	string n1 = "ll";
	cout << strStr(s1, n1) << endl;


	string s2 = "aaaaa"; // return -1
	string n2 = "bba";
	cout << strStr(s2, n2) << endl;

	string s3 = ""; // return 0
	string n3 = "";
	cout << strStr(s3, n3) << endl;
}