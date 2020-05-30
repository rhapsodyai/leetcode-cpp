#include <string>
#include <iostream>

using namespace std;

/*
709. To Lower Case
Easy

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"
*/

/*
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for To Lower Case.
*/
string toLowerCase(string str) {
    for(auto& e : str)
        e = tolower(e);
    
    return str;
}

int main(int argc, char** argv) {
	string s = "Hello";
	cout << toLowerCase(s) << endl;
}