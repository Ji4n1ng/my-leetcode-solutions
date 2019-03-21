#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;

    for (auto s: strs) {
        string k = s;
        sort(k.begin(), k.end());
        if (map.find(k) != map.end()) {
            auto array = map[k];
            array.push_back(s);
            map[k] = array;
        } else {
            vector<string> vec;
            vec.push_back(s);
            map[k] = vec;
        }
    }

    vector<vector<string>> result;
    for (auto m = map.begin(); m != map.end(); m++) {
        result.push_back(m->second);
    }
    return result;
}


int main() {
    vector<string> s1{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto r1 = groupAnagrams(s1);
    cout << "[" << endl;
    for (auto i: r1) {
        cout << "\t[";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << "]";


}