#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


// 12ms, 38.32%
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> map;
    for (auto i: nums) {
        if (map.find(i) == map.end()) {
            map[i] = 1;
        } else {
            map[i]++;
        }
    }
    for (auto i: map) {
        if (i.second == 1) {
            return i.first;
        }
    }
    return -1;
}


//16ms, 14.02%
int singleNumber2(vector<int>& nums) {
    set<int> n;
    for (auto i: nums) {
        if (n.find(i) == n.end()) {
            n.insert(i);
        } else {
            n.erase(i);
        }
    }
    for (auto i: n) {
        return i;
    }
    return -1;
}

// 这是答案，用异或来做，之前没接触过这个。
// 我的做法利用了额外的空间，不符合要求。
int singleNumber(vector<int>& nums) {
    int x = 0;
    for (auto i : nums) {
        x ^= i;
    }
    return x;
}

int main() {
    vector<int> v1 { 2, 2, 1 }; // return 1
    cout << singleNumber2(v1) << endl;

    vector<int> v2 { 4,1,2,1,2 }; // return 4
    cout << singleNumber2(v2) << endl;
}