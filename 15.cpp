#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

// 先排序，为了提高效率，去重，最多允许三次重复（其实两次就够了，除了0，0，0）
// 遍历去重的同时，把数加入到 map 里，顺便保存它的 Index，
// 因为是 unordered_map，所以后面的重复元素会把 Index 覆盖并增大
// 这样在查到第三个数存不存在的时候，可以通过 Index 判断他是不是和前两个重了
// 为了防止重复结果，把三个数从小到大排序，然后拼接为 string 当做 key，放进 map 里
vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> map;
    unordered_map<string, vector<int>> result;
    vector<vector<int>> resultSet;

    sort(nums.begin(), nums.end());

    int index = 0;
    for (int n : nums) {
        if (index < 3 || n > nums[index - 3]) {
            nums[index] = n;
            map[nums[index]] = index;
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = i+1; j < index; j++) {
            int three = - nums[i] - nums[j];
            if (map.find(three) != map.end()) {
                if (map[three] == j || map[three] == i) {
                    // three is the same with one or two.
                    continue;
                } else {
                    vector<int> r;
                    r.push_back(nums[i]);
                    r.push_back(nums[j]);
                    r.push_back(nums[map[three]]);
                    sort(r.begin(), r.end());

                    string key = "";
                    for (auto i: r) key += to_string(i);
                    if (result.find(key) == result.end()) {
                        result[key] = r;
                    }
                }
            }
        }
    }

    for ( auto it = result.begin(); it != result.end(); ++it )
        resultSet.push_back(it->second);

    return resultSet;
}

// 先排序，然后左右夹逼，注意跳过重复的数，时间复杂度 O(n^2)􏰌􏰴􏰩􏰓􏰔􏰕 空间复杂度 O(1)
// 这个方法可以推广到 k-sum 先排序，然后做 k-2 次循环，在最内层循环左右夹逼
// 时间复杂度是 O(max{nlogn, n^k-1})
// i 在nums左边，k在右边，j开始从左往右递增
// 如果sum小于0，j右移，跳过重复元素
// 如果sum大于0，k左移，跳过重复元素
// 如果sum等于0，加入结果
vector<vector<int>> threeSum2(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) return result;
    sort(nums.begin(), nums.end());
    const int target = 0;

    auto last = nums.end();
    for (auto i = nums.begin(); i < last-2; ++i) {
        auto j = i+1;
        if (i > nums.begin() && *i == *(i-1)) continue;
        auto k = last-1;
        while (j < k) {
            if (*i + *j + *k < target) {
                ++j;
                while(*j == *(j - 1) && j < k) ++j;
            } else if (*i + *j + *k > target) {
                --k;
                while(*k == *(k + 1) && j < k) --k;
            } else {
                result.push_back({ *i, *j, *k });
                ++j;
                --k;
                while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
            }
        }
    }
    return result;
}

int main() {
    vector<int> vector1{ -1, 0, 1, 2, -1, -4 };
//    [
//      [-1, 0, 1],
//      [-1, -1, 2]
//    ]

    vector<vector<int>> result1 = threeSum(vector1);

    for (auto i: result1) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    vector<int> vector2{ 1,2,-2,-1 }; //[-2, -1, 1, 2] return []

    vector<vector<int>> result2 = threeSum(vector2);

    for (auto i: result2) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    //[-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0]
    //Output   [[-2,1,1],[-4,0,4],[-5,1,4],[-4,1,3],[-2,-2,4]]
    //Expected [[-5,1,4],[-4,0,4],[-4,1,3],[-2,-2,4],[-2,1,1],[0,0,0]]


    vector<int> vector3{ -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 }; //[-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0] return []

    vector<vector<int>> result3 = threeSum(vector3);

    for (auto i: result3) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    //[-1,-4,-5,2,-2,-1,-6,-10,-10,-9,2,3,2,2,-1,4,-9,-1,-4,6,3,-2,-8,-4,5,-3,-9]

    vector<int> vector4{ -1,-4,-5,2,-2,-1,-6,-10,-10,-9,2,3,2,2,-1,4,-9,-1,-4,6,3,-2,-8,-4,5,-3,-9 };
    // return [[-10,4,6],[-9,3,6],[-9,4,5],[-8,2,6],[-8,3,5],[-6,2,4],[-6,3,3],[-5,-1,6],[-5,2,3],[-4,-2,6],[-4,-1,5],[-4,2,2],[-3,-2,5],[-3,-1,4],[-2,-2,4],[-2,-1,3],[-1,-1,2]]

    vector<vector<int>> result4 = threeSum(vector4);

    for (auto i: result4) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

}