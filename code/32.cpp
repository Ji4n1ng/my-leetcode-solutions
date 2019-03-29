#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 我的思路很麻烦。遇到(，直接压栈。
// 遇到)，从栈顶元素开始判断。
//   如果是(，直接出栈，压进2去。
//   如果是)，就压栈
//   如果是数字，就把所有挨着的数字合并起来，然后判断数字底下的是什么，如果是(，再加2。否则的话，把数字结果压栈，再压)
// 最后栈里，有三种元素，数字、( 和 )。把相邻的数字合并，被 ( 或者 ) 分割的数字，代表无法合并。
// 找到最大的数字，就是结果。很麻烦。效率得分只有 14.02
int longestValidParentheses(string s) {
    stack<string> brackets;
    for (auto c: s) {
        if (c == '(') {
            brackets.push("(");
        } else {
            if (brackets.size() == 0)
                brackets.push(")");
            if (brackets.top() == "(") {
                brackets.pop();
                brackets.push("2");
            } else if (brackets.top() == ")") {
                brackets.push(")");
            } else {
                int tmp = 0;
                while (brackets.size() > 0 && brackets.top() != "(" && brackets.top() != ")") {
                    int t = stoi(brackets.top());
                    tmp += t;
                    brackets.pop();
                }
                if (brackets.size() > 0 && brackets.top() == "(") {
                    tmp += 2;
                    brackets.pop();
                    brackets.push(to_string(tmp));
                } else {
                    brackets.push(to_string(tmp));
                    brackets.push(")");
                }
            }
        }
    }

    vector<int> results;

    while (brackets.size() > 0) {
        int tmp = 0;
        while (brackets.size() > 0 && brackets.top() != "(" && brackets.top() != ")") {
            int t = stoi(brackets.top());
            tmp += t;
            brackets.pop();
        }
        results.push_back(tmp);
        if (brackets.size() > 0)
            brackets.pop();
    }

    int result = 0;
    for (auto r: results)
        if (r > result)
            result = r;

    return result;
}

int longestValidParentheses2(string s) {
}

void judge(string input, int output) {
    int r = longestValidParentheses2(input);
    if (r == output) {
        cout << "√  " << input << "\t\"" << r << "\"" << endl;
    } else {
        cout << "X  " << input << "\t\"" << r << "\" (" << output << ")" << endl;
    }
}

int main() {
//    judge("", "");
//    judge("(()", 2);
//    judge(")()())", 4);
//    judge(")))", 0);
//    judge("(((((", 0);
//    judge("()(()", 2);
//    judge("()((())", 4);
//    judge("((()))", 6);
//    judge("()(())", 6);
//    judge("(()())", 6);
//    judge(")()())()()(", 4);
//    judge("(()))())(", 4);
//    judge("((())())())(", 10);
    judge(")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())", 132);
    // '0': 48, '1': 49, '2': 50
}