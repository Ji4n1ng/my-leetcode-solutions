#include <vector>
#include <iostream>

using namespace std;

// 二分搜索
int binarySearch(vector<int>& arr, int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left)/2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid-1, x);

        return binarySearch(arr, mid+1, right, x);
    }

    return -1;
}

// Rsearch 是一个递归搜索的方法，分而治之，主要是为了拆子串
// 判断子串是不是连续的，如果是，那么直接可以调用二分搜索
// 如果不是，继续拆子串。
// 发现现在写代码，真的养成了封装和调API的思维习惯。。。
int Rsearch(vector<int>& nums, int target, int left, int right) {
    if (left == right) return -1;
    int middle = (left + right + 1) /  2;
    if (nums[left] < nums[right]) {
        return binarySearch(nums, left, right, target);
    } else {
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        if (right - left == 1)
            return -1;

        int result1 = Rsearch(nums, target, left, middle);
        if (result1 != -1)
            return result1;
        int result2 = Rsearch(nums, target, middle, right);
        if (result2 != -1)
            return result2;
        return -1;
    }
}

int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    if (nums.size() == 1) {
        if (nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }
    return Rsearch(nums, target, 0, nums.size()-1);
}

// 看一下人家的简短答案。。
// 总体有四种情况
// 1.  1 2 3 4 5 6 9 10 11  first < mid
// 2.  9 10 11, 1 2 3 4 5 6  first > mid
// 3.  1 2 3, 7 8 9 10 11 12  first < mid
// 4.  7 8 9 10 11 12, 1 2 3  first < mid
// 不管旋转位置在哪，旋转后的递增数组，只要 first 小于等于 mid，
// （等于的情况是，剩下两个元素，mid = first）
// [first, mid] 递增，判断 target 是否在此区间
// 如果不在，说明 target 在另一半，first = mid + 1 即可
// 如果 first > mid，说明是第二种情况，[mid, last] 之间是递增的
// 一样的判断 target 是否在此区间
int search2(const vector<int>& nums, int target) {
    int first = 0, last = nums.size();
    while (first != last) {
        const int mid = first  + (last - first) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[first] <= nums[mid]) {
            if (nums[first] <= target && target < nums[mid])
                last = mid;
            else
                first = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[last-1])
                first = mid + 1;
            else
                last = mid;
        }
    }
    return -1;
}

int main() {
    vector<int> vector1{ 4,5,6,7,0,1,2 };
    int target = 0; // return 4
    cout << search(vector1, target) << endl;
    cout << search2(vector1, target) << endl;
}