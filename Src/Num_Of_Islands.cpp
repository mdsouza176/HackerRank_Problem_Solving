/*
  Melroy Dsouza
  Last edited: November 18, 2018
  NumOfIslands problem solution + testing.
*/

#include <iostream>
#include <vector>
using namespace std;

//helper function to explore all one's to the top, left, right, and down
//of the current position. Cover the entire island found with -1
//so that the numOfIs function won't go over it again and confuse the islands.
void explore(int i, int j, vector<vector<int>> &grid, int r, int c) {
	grid.at(i).at(j) = -1;
	if (i > 0 && grid.at(i - 1).at(j) == 1) {
		explore(i - 1, j, grid, r, c);
	}
	if (j > 0 && grid.at(i).at(j-1) == 1) {
		explore(i, j - 1, grid, r, c);
	}
	if (i + 1 < r && grid.at(i + 1).at(j) == 1) {
		explore(i + 1, j, grid, r, c);
	}
	if (j + 1 < c && grid.at(i).at(j + 1) == 1) {
		explore(i, j + 1, grid, r, c);
	}
}
//precond: Valid input of integer vector and values are either 0's or 1's.
//postcond: return number of islands in the vector.
int numOfIs(vector<vector<int>> grid) {
	int islands = 0;
	int rows = grid.size();
	if (rows == 0) { //empty vector case handling.
		return islands;
	}
	int cols = grid.at(0).size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid.at(i).at(j) != -1 && grid.at(i).at(j) != 0) {
				islands++;
				explore(i, j, grid, rows, cols);
			}
		}
	}
	return islands;
}
void testNumOfIs() {
	vector<vector<int>> vec{ {1,1,0,0 },
	{ 1, 0, 0, 1 }, {1,0,1,0} };
	cout << numOfIs(vec) << endl; //should print 3.
	vector<vector<int>> vec2{};
	cout << numOfIs(vec2) << endl; //should print 0.
}

int main() {
	testNumOfIs(); 


	cin.get();
	return 0;
}