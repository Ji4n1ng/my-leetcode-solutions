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

vector<vector<int>> fourSum2(vector<int> &nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4)
        return result;
    sort(nums.begin(), nums.end());

    unordered_map<int, vector<pair<int, int>>> cache;
    for (size_t a = 0; a < nums.size(); ++a) {
        for (size_t b = a + 1; b < nums.size(); ++b) {
            cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
        }
    }

    for (int c = 0; c < nums.size(); ++c) {
        for (size_t d = c + 1; d < nums.size(); ++d) {
            const int key = target - nums[c] - nums[d];
            if (cache.find(key) == cache.end())
                continue;

            const auto &vec = cache[key];
            for (size_t k = 0; k < vec.size(); ++k) {
                if (c <= vec[k].second)
                    continue; // have duplication

                result.push_back({nums[vec[k].first],
                                  nums[vec[k].second], nums[c], nums[d]});
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
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