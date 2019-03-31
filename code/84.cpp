#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 我的方法比较慢，是 n2 的复杂度。
// 每个柱子开始往右找，分别和右边的柱子求最大面积，然后再添加右边的柱子，循环下去。
int largestRectangleArea(vector<int>& heights) {
	if (heights.size() == 0) return 0;
	int max_area = 0;
	for (int i = 0; i < heights.size(); i++) {
		int r = i;
		int right_min = heights[i];
		// 向右找
		while (r < heights.size()) {
			if (heights[r] < right_min) {
				right_min = heights[r];
			}
			int right_area = right_min * (r - i + 1);
			if (right_area > max_area)
				max_area = right_area;
			r++;
		}
	}
	return max_area;
}

void judge(vector<int>& input, int output) {
	int r = largestRectangleArea(input);
	if (r == output) {
		cout << "T  "  << "  \"" << r << "\"" << endl;
	} else {
		cout << "X  "  << "  \"" << r << "\" (" << output << ")" << endl;
	}
}

int main() {
	vector<int> v1 {2,1,5,6,2,3};
	judge(v1, 10);

	vector<int> v2 {2};
	judge(v2, 2);

	vector<int> v3 {0,9};
	judge(v3, 9);

	vector<int> v4 {0,1,0,2,1,0,1,3,2,1,2,1};
	judge(v4, 6);

	vector<int> v5 {3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3};
	judge(v5, 24);
}
