#include <string>
using namespace std;


//Given a string ex. PAYPALISHIRING, convert to zigzag form pattern in the given number of rows and return the
//complete result by reading each line and giving total string.
//ex. P   A   H   N                        
//    A P L S I I G     ------->  Converted line by line to "PAHNAPLSIIGYIR"
//    Y   I   R
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		string *lists = new string[numRows];
		string res = "";
		int position = 0;
		bool turn = false;
		for (int i = 0; i < s.length(); i++) {
			lists[position] += s[i];
			if (position >= numRows - 1) {
				turn = true;
			}
			else if (position == 0) {
				turn = false;
			}
			if (turn) {
				position--;
			}
			else {
				position++;
			}
		}
		for (int i = 0; i < numRows; i++) {
			res += lists[i];
		}
		delete[] lists;
		return res;
	}
};