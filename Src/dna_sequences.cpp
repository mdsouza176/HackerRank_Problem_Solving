#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
using namespace std;

// Takes a string of a set of DNA sequence, checks if there are substrings
// of size 10 and exactly equal to each other, and if there is one, adds
// one copy of that substring (even if there might be more that 2 of the 
// same DNA substring) to the vector and returns it.
// there are more 10 char sets in the same order). 
// precond: string of valid size and input
// postcond: returns a vector with either no copies, or copies of substr
// from the input
vector<string>* DNA(string input) {
	vector<string>* seq = new vector<string>();
	int length = input.length();
	if (length < 10) {
		return seq;
	}
	map<string, int> seqValues;
	for (int i = 0; i < length - 10; i++) {
		string s = input.substr(i, 10);
		seqValues[s] += 1;
		if (seqValues[s] == 2) {
			seq->push_back(s);
			
		}
	}
	return seq;
}

// Helper method that prints and deletes the vector.
// precond: Valid input, within size limits
// posCond: Prints out contents of vector and deletes the vector.
void printAndDeleteVector(vector<string> *vec) {
	cout << "Output: ";
	for (int i = 0; i < vec->size(); i++) {
		string s = vec->at(i);
		cout << s << " ";
	}
	cout << endl;
	delete vec;
	vec = nullptr;
}
// Test method which creates strings of input, calls the DNA 
// method, and shows output of the vector created by the method.
void testDNA() {
	string input1 = "AAAAAAAAAABBAAAAAAAAAAB";
	string input2 = "AAAAAAAAAAAAAAAABBBBBAAAAAAAAAAAAAAABBBBB";
	string input3 = "AA";
	vector<string>* copies;

	copies = DNA(input1);
	printAndDeleteVector(copies); // test for a single instance of a copy.
	copies = DNA(input2); // test for larger input and multiple copies
	printAndDeleteVector(copies);
	copies = DNA(input3); // test for input which is less than 10 characters in length.
	printAndDeleteVector(copies);

}
// Main method with calls the testDna method.
int main() {
	testDNA(); // method to be tested.
	cin.get(); //stops command prompt from exiting.
	return 0;
}