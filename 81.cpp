#include <vector>
#include <iostream>

using namespace std;

//好好记住
bool search(vector<int>& nums, int target) {
    int first = 0, last = nums.size();
    while (first != last) {
        const int mid = first  + (last - first) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[first] < nums[mid]) {
            if (nums[first] <= target && target < nums[mid])
                last = mid;
            else
                first = mid + 1;
        } else if (nums[first] > nums[mid]) {
            if (nums[mid] < target && target <= nums[last-1])
                first = mid + 1;
            else
                last = mid;
        } else
            //skip duplicate one
            first++;
    }
    return false;
}

int main() {
    vector<int> vector1{ 2,5,6,0,0,1,2 };
    int target1 = 0; // return true
    cout << search(vector1, target1) << endl;

    vector<int> vector2{ 2,5,6,0,0,1,2 };
    int target2 = 3; // return false
    cout << search(vector2, target2) << endl;
}