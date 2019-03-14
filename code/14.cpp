#include <string>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";

    string first = strs[0];
    string result;

    for (int i = 0; i < first.length(); i++) {
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != first[i]) {
                goto breakLoop;
            }
        }
        result.push_back(first[i]);
    }
    breakLoop:

    return result;
}


int main() {
    vector<string> s1{"flower", "flow", "flight"};
    cout << longestCommonPrefix(s1) << endl; // "fl"

    vector<string> s2{"dog", "racecar", "car"};
    cout << longestCommonPrefix(s2) << endl; // ""

    vector<string> s3{"aca","cba"};
    cout << longestCommonPrefix(s3) << endl; // ""
}
