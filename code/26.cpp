#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) return 0;

    int index = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[index] != nums[i])
            nums[++index] = nums[i];
    }

    return index + 1;
}

template<typename InIt, typename OutIt>
OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
    while (first != last) {
        *output++ = *first;
        first = upper_bound(first, last, *first);
    }
    return output;
}

int removeDuplicates2(vector<int>& nums) {
    return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

int removeDuplicates3(vector<int>& nums) {
    return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
}


int main() {
    vector<int> vector1{ 0,0,1,1,1,2,2,3,3,4 }; // return 5
    cout << removeDuplicates(vector1) << endl;
}