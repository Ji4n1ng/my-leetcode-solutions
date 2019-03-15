#include <string>

using namespace std;


// 这道题很垃圾，怪不得一堆差评。
// 不难，就是条件啰嗦。
// 垃圾 CLion 不小心把我的代码弄没了，一堆测试用例没了。这样吧。

bool isNumber(string s) {
    size_t found = s.find('e');
    bool hasE = false;
    if (found != string::npos)
        hasE = true;
    string s1 = s; // before E
    string s2 = ""; // after E
    if (hasE) {
        s1 = s.substr(0, found);
        s2 = s.substr(found + 1);
    }
    // remove valid blank
    int i1 = 0;
    for (; i1 < s1.length(); i1++) {
        if (s1[i1] != ' ')
            break;
    }
    s1 = s1.substr(i1);
    if (hasE) {
        int i2 = s2.length() - 1;
        for (; i2 > 0; i2--) {
            if (s2[i2] != ' ')
                break;
        }
        s2 = s2.substr(0, i2 + 1);
    } else {
        int i11 = s1.length() - 1;
        for (; i11 > 0; i11--) {
            if (s1[i11] != ' ')
                break;
        }
        s1 = s1.substr(0, i11 + 1);
    }


    if (s1 == "")
        return false;
    if (hasE && s2 == "")
        return false;

    bool valid = true;

    bool s1BeforeNum = true;
    bool s1HasSign = false;
    bool s1HasDot = false;

    for (auto c: s1) {
        if (isdigit(c)) {
            s1BeforeNum = false;
        } else if (c == '-' || c == '+') {
            if (!s1BeforeNum || s1HasSign || s1HasDot)
                return false;
            s1HasSign = true;
        } else if (c == '.') {
            if (s1HasDot)
                return false;
            s1HasDot = true;
        } else {
            return false;
        }
    }

    if (s1BeforeNum)
        if (s1HasDot || s1HasSign )
            return false;

    if (hasE) {
        bool s2BeforeNum = true;
        bool s2HasSign = false;
        for (auto c: s2) {
            if (isdigit(c)) {
                s2BeforeNum = false;
            } else if (c == '-' || c == '+') {
                if (!s2BeforeNum || s2HasSign)
                    return false;
                s2HasSign = true;
            } else {
                return false;
            }
        }

        if (s2BeforeNum)
            if (s2HasSign)
                return false;
    }

    return valid;


}