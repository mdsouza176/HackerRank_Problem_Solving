#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:

	//This problem is when you have a list of heights with the width being the abs of the index difference between 2 heights.
	//find greatest area that can be made from 2 heights are different indexes (width is abs difference between 2 heights positions
	//in the vector.
	int maxArea(vector<int>& height) {
		int max = 0;
		int s = 0;
		int k = height.size() - 1;
		while (s < k) {
			int area = (k - s) * min(height[k], height[s]);
			if (area > max) {
				max = area;
			}
			if (height[s] < height[k]) {
				s++;
			}
			else {
				k--;
			}
		}
		return max;
	}
};