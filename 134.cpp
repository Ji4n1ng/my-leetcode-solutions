#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    for (int i = 0; i < gas.size(); i++) {
        if (cost[i] > gas[i])
            continue;
        else {
            int s = i, tank = 0, count = 0;
            while (tank >= 0) {
                tank = tank + gas[s] - cost[s];
                s += 1;
                s %= gas.size();
                count++;
                if (count > gas.size())
                    return i;
            }
        }
    }
    return -1;
}

// 答案还是厉害，total用来判断整个数组是否有解，然后从前往后找就行了。
// 这样就不用跟我一样，每一个都全走一遍试试。
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int total = 0;
    int j = -1;
    for (int i = 0, sum = 0; i < gas.size(); ++i) {
        sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (sum < 0) {
            j = i;
            sum = 0;
        }
    }
    return total >= 0 ? j + 1 : -1;
}


int main() {
    vector<int> g1 = { 1, 2, 3, 4, 5 };
    vector<int> c1 = { 3, 4, 5, 1, 2 }; // return 3
    cout << canCompleteCircuit(g1, c1) << endl;

    
    vector<int> g2 = { 2, 3, 4 };
    vector<int> c2 = { 3, 4, 3 }; // return -1
    cout << canCompleteCircuit(g2, c2) << endl;

    
    vector<int> g3 = { 4,5,2,6,5,3 };
    vector<int> c3 = { 3,2,7,3,2,9 }; // return -1
    cout << canCompleteCircuit(g3, c3) << endl;
}