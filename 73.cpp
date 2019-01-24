#include <iostream>
#include <vector>
#include <set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int> row, col;
    
    for (int i = 0; i < matrix.size(); i++) { 
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    } 

    for (auto i: row) {
        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = 0;
        }
    }

    for (auto j: col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][j] = 0;
        }
    }
}


int main() {
    vector<vector<int>> m1 {
        { 1, 1, 1 },
        { 1, 0, 1 },
        { 1, 1, 1 }
    };
    // return 
    // 1 0 1
    // 0 0 0
    // 1 0 1
    setZeroes(m1);
    for (int i = 0; i < m1.size(); i++) { 
        for (int j = 0; j < m1[i].size(); j++) 
            cout << m1[i][j] << " "; 
        cout << endl; 
    } 
    cout << endl; 

    
    vector<vector<int>> m2 {
        { 0, 1, 2, 0 },
        { 3, 4, 5, 2 },
        { 1, 3, 1, 5 }
    };
    // return 
    // 0 0 0 0
    // 0 4 5 0
    // 0 3 1 0 
    setZeroes(m2);
    for (int i = 0; i < m2.size(); i++) { 
        for (int j = 0; j < m2[i].size(); j++) 
            cout << m2[i][j] << " "; 
        cout << endl; 
    } 
    cout << endl; 
}