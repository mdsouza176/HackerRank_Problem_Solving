#include <string>
#include <algorithm>
#include <vector>
using namespace std;



/*
Given a vector words, group them based on which words are anagrams of each other.
So return a 2-d array, each row having words that are anagrams of each other.


*/
class Solution {
public:

	bool compare(string s1, string s2) {
		if (s1.length() != s2.length()) {
			return false;
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) {
				return false;
			}
		}
		return true;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int row = 0;
		vector<vector<string>> ch;
		for (int j = 0; j < strs.size(); j++) {
			int count = 0;
			for (int i = 0; i < ch.size(); i++) {
				if (compare(ch[i][0], strs[j])) {
					ch[i].push_back(strs[j]);
					break;
				}
				else {
					count++;
				}
			}
			if (count == ch.size()) {
				vector<string> ch2;
				ch2.push_back(strs[j]);
				ch.push_back(ch2);
			}
		}
		return ch;
	}
};