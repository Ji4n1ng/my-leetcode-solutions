#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 我写的不够简洁，可以看看答案，很多这种题了。记住简介的写法啊。
string addBinary(string a, string b) {
	int aLen = a.length();
	int bLen = b.length();
	bool aMoreThanB = aLen >= bLen;
	int count = aMoreThanB ? bLen : aLen;
	string result;
	bool carry = false;
	for (int i = 1; i <= count; i++) {
		int i1 = a[aLen - i] - '0';
		int i2 = b[bLen - i] - '0';
		int tmp = i1 + i2;
		if (carry) {
			carry = false;
			tmp++;
		}
		if (tmp > 1) {
			carry = true;
			tmp -= 2;
		}
		result = to_string(tmp) + result;
	}
	count = aMoreThanB ? aLen - bLen : bLen - aLen;
	string remain = aMoreThanB ? a.substr(0, count) : b.substr(0, count);
	for (int i = 1; i <= count; i++) {
		int tmp = remain[count - i] - '0';
		if (carry) {
			carry = false;
			tmp++;
		}
		if (tmp > 1) {
			carry = true;
			tmp -= 2;
		}
		result = to_string(tmp) + result;
	}
	if (carry)
		result = "1" + result;
	return result;
}

string addBinary2(string a, string b) {
	string result;
	const size_t n = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (size_t i = 0; i < n; i++) {
		const int ai = i < a.size() ? a[i] - '0' : 0;
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int val = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.insert(result.begin(), val + '0');
	}
	if (carry == 1) {
		result.insert(result.begin(), '1');
	}
	return result;
}

int main() {
	string a1 = "11";
	string b1 = "1";
	cout << addBinary(a1, b1) << endl; // return 100

	string a2 = "1010";
	string b2 = "1011";
	cout << addBinary(a2, b2) << endl; // return 10101

}