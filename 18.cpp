#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    unordered_multimap<int, vector<int>> twoSum;
    unordered_map<string, int> resultSet;
    vector<vector<int>> result;
    int index = 0;
    // remove repeat element and max repeat count is 4
    for (int n : nums) {
        if (index < 4 || n > nums[index - 4]) {
            nums[index] = n;
            index++;
        }
    }

    // save the sum of any two element,
    // save the sum and element's index to a map
    for (int i = 0; i <= index; i++) {
        for (int j = i + 1; j <= index; j++) {
            vector<int> tmp; // i, n[i], j, n[j]
            tmp.push_back(i);
            tmp.push_back(nums[i]);
            tmp.push_back(j);
            tmp.push_back(nums[j]);
            twoSum.insert({nums[i] + nums[j], tmp});
        }
    }

    for (int i = 0; i <= index; i++) {
        for (int j = i + 1; j <= index; j++) {
            int three = target - nums[i] - nums[j];
            auto range = twoSum.equal_range(three);

            for (auto it = range.first; it != range.second; ++it) {
                auto tmp = it->second;
                if (tmp[0] == i || tmp[0] == j || tmp[2] == i || tmp[2] == j) {
                    continue;
                }
                vector<int> r;

//                cout << "---- " << endl;
//                cout << "i: " << i << " nums[i]: " << nums[i] << endl;
//                cout << "j: " << j << " nums[j]: " << nums[j] << endl;
//                cout << "tmp[0]: " << tmp[0] << " tmp[1]: " << tmp[1] << endl;
//                cout << "tmp[2]: " << tmp[2] << " tmp[3]: " << tmp[3] << endl;
//                cout << "----" << endl;
                r.push_back(nums[i]);
                r.push_back(nums[j]);
                r.push_back(tmp[1]);
                r.push_back(tmp[3]);
                sort(r.begin(), r.end());

                string key = "";
                for (auto i: r) key += to_string(i);
                if (resultSet.find(key) == resultSet.end()) {
                    resultSet[key] = 1;
                    result.push_back(r);
                }
            }
        }
    }

    return result;
}

int main() {
//    vector<int> vector1{ 1, 0, -1, 0, -2, 2 };
////    [
////      [-1,  0, 0, 1],
////      [-2, -1, 1, 2],
////      [-2,  0, 0, 2]
////    ]
//
//    vector<vector<int>> result1 = fourSum(vector1, 0);
//
//    for (auto i: result1) {
//        cout << "[ ";
//        for (auto j: i) {
//            cout << j << " ";
//        }
//        cout << "]" << endl;
//    }
//    cout << endl;
//


    vector<int> vector2{ -4,-3,-2,-1,0,0,1,2,3,4};

    vector<vector<int>> result2 = fourSum(vector2, 0);

    for (auto i: result2) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}