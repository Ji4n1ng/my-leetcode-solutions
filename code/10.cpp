#include <string>
#include <iostream>
#include <vector>

using namespace std;

// bool isMatch2(string s, string p) {
//     bool m = false;
//     vector<string> patterns;
//     for (int i = 0; i < p.length(); i++) {
//         string s;
//         s.push_back(p[i]);
//         if (i < p.length() - 1 && p[i+1] == '*')
//             s.push_back(p[i++ + 1]);
//         patterns.push_back(s);
//     }
//     vector<string> match;
//     int j = 0;
//     for (int i = 0; i < patterns.size(); i++) {
//         char c = patterns[i][0];
//         bool isDot = c == '.';
//         bool isAsterisk = patterns[i].length() > 1;
        
//         if (isDot && isAsterisk) {
//             match.push_back("any");
//         } else if (!isDot && isAsterisk) {
        
//         } else if (isDot && !isAsterisk) {
//             match.push_back("");
//         } else {

//         }
//     }
    
//     return m;
// }

// bool isMatch(string s, string p) {
//     bool m = false;
//     int i = 0, j = 0;
//     for (; i < s.length(); i++) {
//         char c1 = s[i], c2;
//         for(; j < p.length(); j++) {
//             c2 = p[j];
//             bool isDot = c2 == '.';
//             bool isAsterisk = false;
//             if (j < p.length() - 1 && p[j+1] == '*') {
//                 j++;
//                 isAsterisk = true;
//             }
//             if (isAsterisk) {
//                 if (c1 == c2) {

//                 }
//             }
//         }
//     }
    
//     return m;
// }

bool isMatch2(const char *s, const char *p) {
    if (*p == '\0') return *s == '\0';

    // next char is not '*', then must match current character
    if (*(p + 1) != '*') {
        if (*p == *s || (*p == '.' && *s != '\0'))
            return isMatch2(s + 1, p + 1);
        else
            return false;
    } else { // next char is '*'
        while (*p == *s || (*p == '.' && *s != '\0')) {
            if (isMatch2(s, p + 2))
                return true;
            s++;
        }
        return isMatch2(s, p + 2);
    }
}

bool isMatch(const string& s, const string& p) {
    return isMatch2(s.c_str(), p.c_str());
}

int main() {
	string s1 = "aa";
	string p1 = "a";
	cout << isMatch(s1, p1) << endl; // false
    
	string s2 = "aa";
	string p2 = "a*";
	cout << isMatch(s2, p2) << endl; // true
    
	string s3 = "ab";
	string p3 = ".*";
	cout << isMatch(s3, p3) << endl; // true
    
	string s4 = "aab";
	string p4 = "c*a*b";
	cout << isMatch(s4, p4) << endl; // true
    
	string s5 = "mississippi";
	string p5 = "mis*is*p*.";
	cout << isMatch(s5, p5) << endl; // false

}
