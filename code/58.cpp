#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 这种题很垃圾，一堆差评。规则说不清楚，全靠测试用例恶心你。
int lengthOfLastWord(string s) {
	int len = s.length();
	int result = 0;
	bool hasWord = false;
	for (int i = len - 1; i >= 0; i--) {
		if (isalpha(s[i])) {
			hasWord = true;
			result++;
		} else if (s[i] == ' ' && hasWord) {
			break;
		}
	}
	return result;
}


void judge(string input, int output) {
	int r = lengthOfLastWord(input);
	if (r == output) {
		cout << "T  " << input << "  \"" << r << "\"" << endl;
	} else {
		cout << "X  " << input << "  \"" << r << "\" (" << output << ")" << endl;
	}
}

int main() {
	judge("Hello World", 5);
	judge("a", 1);
	judge("a ", 1);

}
