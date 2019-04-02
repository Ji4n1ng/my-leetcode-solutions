#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 很简单的一道题。栈的经典用法，学过数据结构的应该都会。简略计算器的实现。
// 93.42%
int evalRPN(vector<string>& tokens) {
	stack<int> numbers;
	for (auto token: tokens) {
		if (token == "+" || token == "*" || token == "/" || token == "-") {
			int n1 = numbers.top();
			numbers.pop();
			int n2 = numbers.top();
			numbers.pop();
			int result;
			if (token == "+") {
				result = n2 + n1;
			} else if (token == "-") {
				result = n2 - n1;
			} else if (token == "*") {
				result = n2 * n1;
			} else {
				result = n2 / n1;
			}
			numbers.push(result);
		} else {
			int n = stoi(token);
			numbers.push(n);
		}
	}
	return numbers.top();
}

void judge(vector<string>& input, int output) {
	int r = evalRPN(input);
	if (r == output) {
		cout << "T  "  << "  \"" << r << "\"" << endl;
	} else {
		cout << "X  "  << "  \"" << r << "\" (" << output << ")" << endl;
	}
}

int main() {
	vector<string> v1{"2", "1", "+", "3", "*"};
	judge(v1, 9);

	vector<string> v2{"4", "13", "5", "/", "+"};
	judge(v2, 6);

	vector<string> v3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	judge(v3, 22);

}

