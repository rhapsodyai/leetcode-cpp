#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
1309. Decrypt String from Alphabet to Integer Mapping
Easy

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

    Characters ('a' to 'i') are represented by ('1' to '9') respectively.
    Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 

Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:

Input: s = "1326#"
Output: "acz"

Example 3:

Input: s = "25#"
Output: "y"

Example 4:

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

Constraints:

    1 <= s.length <= 1000
    s[i] only contains digits letters ('0'-'9') and '#' letter.
    s will be valid string such that mapping is always possible.
*/


/*
Success
Details
Runtime: 4 ms, faster than 42.78% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
*/
string freqAlphabets(string s) {
    unordered_map<string, char> m =
        {{"1", 'a'},{"2", 'b'},{"3", 'c'},
        {"4", 'd'},{"5", 'e'},{"6", 'f'},
        {"7", 'g'},{"8", 'h'},{"9", 'i'},
        {"10#", 'j'},{"11#", 'k'},{"12#", 'l'},
        {"13#", 'm'},{"14#", 'n'},{"15#", 'o'},
        {"16#", 'p'},{"17#", 'q'},{"18#", 'r'},
        {"19#", 's'},{"20#", 't'},{"21#", 'u'},
        {"22#", 'v'},{"23#", 'w'},{"24#", 'x'},
        {"25#", 'y'},{"26#", 'z'}};
    
    string str = {};


    for(int i = 0; i < s.size(); i++) {
        if(i+2 < s.size()) {
            if(s[i+2] == '#') {
                string t = {};
                t += s[i];
                t += s[i+1];
                t += '#';
                 
                str += m[t];
                i+=2;
            } else {
                string t = {};
                t.push_back(s[i]);

                str += m[t];
            }
        } else {
            string t = {};
            t.push_back(s[i]);

            str += m[t];
        }
    }
    return str;
}

int main(int argc, char** argv) {
	cout << freqAlphabets("10#11#12") << endl;
}