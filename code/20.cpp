#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> brackets;
    for (auto c: s) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else {
            if (brackets.size() == 0)
                return false;
            if (c == ')' && brackets.top() == '(')
                brackets.pop();
            else if (c == ']' && brackets.top() == '[')
                brackets.pop();
            else if (c == '}' && brackets.top() == '{')
                brackets.pop();
            else
                return false;
        }
    }
    if (brackets.size() != 0)
        return false;
    return true;
}

void judge(string input, bool output) {
    bool r = isValid(input);
    if (r == output) {
        cout << "√  " << input << "\t\"" << r << "\"" << endl;
    } else {
        cout << "X  " << input << "\t\"" << r << "\" (" << output << ")" << endl;
    }
}

int main() {
//    judge("", "");
    judge("()", true);
    judge("()[]{}", true);
    judge("(]", false);
    judge("([)]", false);
    judge("{[]}", true);
    judge("]", false);
    judge("[", false);
}