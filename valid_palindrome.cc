#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isPalindrome(string s) {
    if(s.length() == 0)
        return true;
    
    /* convert to lower case */
    locale loc;
    for(string::size_type i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i], loc);
    }

    
    /* remove non-alphanumeric */
    for(string::iterator i = s.begin(); i != s.end(); i++) {
        if(!isalnum(s.at(i-s.begin()))) {
            s.erase(i);
            i--;
        }
    }

    /* palindrome check */
    for(int i = 0; i < s.length(); i++) {
        if(s[i]  != s[s.length()-1-i])
            return false;
    }
    
    return true;
}

int main(int argc, char** argv) {
    cout << isPalindrome("Racecar") << endl;
}


