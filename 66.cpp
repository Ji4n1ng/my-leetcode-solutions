#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    vector<int> numbers;
    bool plus = true;
    for (int i = 0; i < n; i++) {
        int d = digits[n - i - 1];
        if (plus) {
            if (d == 9) {
                d = 0;
                plus = true;
            } else {
                d++;
                plus = false;
            }
        }
        numbers.insert(numbers.begin(), d);
    }
    if (plus) {
        numbers.insert(numbers.begin(), 1);
    }
    return numbers;
}

// 这个答案才是对加法的精简描述
// 0 <= digit <= 9
void add(vector<int> &digits, int digit) {
    int c = digit; // carry, 进位
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        *it += c;
        c = *it / 10;
        *it %= 10;
    }
    if (c > 0) digits.insert(digits.begin(), 1);
}

vector<int> plusOne2(vector<int> &digits) {
    add(digits, 1);
    return digits;
}




int main() {
    vector<int> n1 { 1, 2, 3 }; // return 124
    plusOne(n1);
    for (int i = 0; i < n1.size(); i++) {
        cout << n1[i];
    }
    cout << endl;

    
    vector<int> n2 { 1, 0, 9 }; // return 110
    plusOne(n2);
    for (int i = 0; i < n2.size(); i++) {
        cout << n2[i];
    }
    cout << endl;

    
    vector<int> n3 { 9, 9, 9 }; // return 1000
    plusOne(n3);
    for (int i = 0; i < n3.size(); i++) {
        cout << n3[i];
    }
    cout << endl;

}