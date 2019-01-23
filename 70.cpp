#include <iostream>
#include <unordered_map>

using namespace std;

int climbStairs(int n) {
    unordered_map<int, int> map;
    map[1] = 1;
    map[2] = 2;
    
    int i = 3;

    while (i <= n) {
        map[i] = map[i - 1] + map[i - 2];
        i++;
    }

    return map[n];
}

int main() {
    cout << climbStairs(1) << endl; // return 1
    cout << climbStairs(2) << endl; // return 2
    cout << climbStairs(3) << endl; // return 3
    cout << climbStairs(4) << endl; // return 5
    cout << climbStairs(5) << endl; // return 8
    cout << climbStairs(6) << endl; // return 13
}