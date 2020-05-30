#include <string>
#include <iostream>

using namespace std;

/*
1108. Defanging an IP Address
Easy

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

Constraints:

    The given address is a valid IPv4 address.
*/

/*
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defanging an IP Address.
Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Defanging an IP Address.
*/
string defangIPaddr(string address) {
    string result = "";
    for(char e : address) {
        if(e == '.')
            result += "[.]";
        else
            result += e;
    }
    
    return result;
}

int main(int argc, char** argv) {
	cout << defangIPaddr("1.1.1.1") << endl;
}