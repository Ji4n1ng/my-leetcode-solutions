#include <vector>
#include <iostream>

using namespace std;

// 这道题并没有读懂什么意思。看看答案
template<typename BidiIt>
bool _next_permutation(BidiIt first, BidiIt last) {
    // Get a reversed range to simplify reversed traversal.
    const auto rfirst = reverse_iterator<BidiIt>(last);
    const auto rlast = reverse_iterator<BidiIt>(first);
    // Begin from the second last element to the first element.
    auto pivot = next(rfirst);
    // Find `pivot`, which is the first element that is no less than its
    // successor.  `Prev` is used since `pivort` is a `reversed_iterator`.
    while (pivot != rlast && *pivot >= *prev(pivot))
        ++pivot;
    // No such elemenet found, current sequence is already the largest
    // permutation, then rearrange to the first permutation and return false.
    if (pivot == rlast) {
        reverse(rfirst, rlast);
        return false;
    }
    // Scan from right to left, find the first element that is greater than
    // `pivot`.
    auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
    swap(*change, *pivot);
    reverse(rfirst, pivot);
    return true;
}

void nextPermutation(vector<int> &nums) {
    _next_permutation(nums.begin(), nums.end());
}

int main() {

    vector<int> vector1{ 1,2,3 };
    nextPermutation(vector1); // return 1,3,2
    for (auto n: vector1) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> vector2{ 3,2,1 };
    nextPermutation(vector2); // return 1,2,3
    for (auto n: vector2) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> vector3{ 6,8,7,4,3,2 };
    nextPermutation(vector3); // return 7,2,3,4,6,8
    for (auto n: vector3) {
        cout << n << " ";
    }
    cout << endl;
}