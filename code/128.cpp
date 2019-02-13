#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 因为题目要求 O(n) 所以排序肯定不行了。
// 好好记住
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> used;

    for (auto i : nums) used[i] = false;

    int longest = 0;

    for (auto i : nums) {
        if (used[i]) continue;

        int length = 1;

        used[i] = true;

        for (int j = i + 1; used.find(j) != used.end(); ++j) {
            used[j] = true;
            ++length;
        }

        for (int j = i - 1; used.find(j) != used.end(); --j) {
            used[j] = true;
            ++length;
        }

        longest = max(longest, length);
    }
    return longest;
}

int mergeCluster(unordered_map<int, int> &map, int left, int right) {
    int upper = right + map[right] - 1;
    int lower = left - map[left] + 1;
    int length = upper - lower + 1;
    map[upper] = length;
    map[lower] = length;
    return length;
}

// 连续序列可以用两端和长度来表示。
// 遍历 nums，如果不存在就添加到 unordered_map 中，
// 查找 unordered_map 有没有紧邻的两个元素，有的话，
// key 所对应的 value +1，将整个过程中遇到的 max 值记录下来，就是最长序列
// 也是很聪明的办法
int longestConsecutive2(vector<int> &nums) {
    unordered_map<int, int> map;
    int size = nums.size();
    int l = 1;
    for (int i = 0; i < size; i++) {
        if (map.find(nums[i]) != map.end()) continue;
        map[nums[i]] = 1;
        if (map.find(nums[i] - 1) != map.end()) {
            l = max(l, mergeCluster(map, nums[i] - 1, nums[i]));
        }
        if (map.find(nums[i] + 1) != map.end()) {
            l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
        } }
    return size == 0 ? 0 : l;
}

int main() {
    vector<int> vector1{ 100, 4, 200, 1, 3, 2 }; // return 4
    cout << longestConsecutive(vector1) << endl;

    cout << longestConsecutive2(vector1) << endl;
}