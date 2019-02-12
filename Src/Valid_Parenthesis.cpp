#include <string>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s == "") { return true; }
		map<char, char> valids;
		valids[')'] = '(';
		valids['}'] = '{';
		valids[']'] = '[';
		stack<char> opens;
		for (int i = 0; i < s.length(); i++) {
			if (valids.count(s[i]) && !opens.empty()) {
				if (valids[s[i]] == opens.top()) {
					opens.pop();
				}
				else {
					return false;
				}
			}
			else if (opens.empty() && valids.count(s[i])) {
				return false;
			}
			else {
				opens.push(s[i]);
			}
		}
		if (opens.empty()) { return true; }
		return false;
	}
};