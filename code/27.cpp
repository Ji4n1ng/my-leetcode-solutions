#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for (auto n: nums) {
        if (n == val)
            continue;
        nums[index++] = n;
    }
    nums.erase(nums.begin() + index, nums.end());
    return nums.size();
}


int main() {

    vector<int> vector1{ 3,2,2,3 };
    int result1 = removeElement(vector1, 3); // return 2
    cout << result1 << endl << endl;

    vector<int> vector2{ 0,1,2,2,3,0,4,2 };
    int result2 = removeElement(vector2, 2); // return 5
    cout << result2 << endl << endl;

    vector<int> vector3{ 3,3,3,3 };
    int result3 = removeElement(vector3, 3); // return 0
    cout << result3 << endl << endl;

}