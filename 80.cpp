#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int index = 0;
    int count = 0;
    int duplicateCount = 2;
    for (int i = 1; i < nums.size(); i++) {
        if (count == duplicateCount - 1) {
            if (nums[index - 1] != nums[i]) {
                count = 0;
                nums[++index] = nums[i];
            }
        } else {
            if (nums[index] == nums[i]) {
                count++;
                nums[++index] = nums[i];
            } else {
                nums[++index] = nums[i];
            }
        }
    }

    return index + 1;
}

int removeDuplicates2(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}

int removeDuplicates3(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int index = 2;
    for (int i = 2; i < nums.size(); i++){
        if (nums[i] != nums[index - 2])
            nums[index++] = nums[i];
    }
    return index;
}

int removeDuplicates4(vector<int>& nums) {
    const int n = nums.size();
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
            continue;
        nums[index++] = nums[i];
    }
    return index;
}

int main() {
    vector<int> vector1{ 0,0,1,1,1,1,2,3,3 }; // return 7
    cout << removeDuplicates(vector1) << endl;
}
