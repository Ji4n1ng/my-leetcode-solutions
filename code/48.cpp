#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

string toS(int i, int j) {
    return to_string(i) + ',' + to_string(j);
}

void rotate(vector<vector<int>>& matrix) {
    int row = 0, col = 0;
    int n = matrix.size();
    set<string> set;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (set.find(toS(i, j)) == set.end()) { // 没有修改过
                row = i, col = j;
                int last = matrix[row][col];
                while(set.find(toS(col, n - row - 1)) == set.end()) {
                    int t = row;
                    row = col;
                    col = n - t - 1;
                    int tmp = matrix[row][col];
                    matrix[row][col] = last;
                    last = tmp;
                    set.insert(toS(row, col));
                } 
            }
        }
    }
}
 

int main() {
    vector<vector<int>> m1 {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    rotate(m1);
    for (int i = 0; i < m1.size(); i++) { 
        for (int j = 0; j < m1[i].size(); j++) 
            cout << m1[i][j] << " "; 
        cout << endl; 
    } 
    cout << endl; 

    
    vector<vector<int>> m2 {
        { 5, 1, 9, 11 },
        { 2, 4, 8, 10 },
        { 13, 3, 6, 7 },
        { 15, 14, 12, 16 }
    };
    rotate(m2);
    for (int i = 0; i < m2.size(); i++) { 
        for (int j = 0; j < m2[i].size(); j++) 
            cout << m2[i][j] << " "; 
        cout << endl; 
    } 
    cout << endl; 

    
}