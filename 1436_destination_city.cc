#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

template<typename K, typename V>
void print_map(unordered_map<K,V> const &m) {
    for (auto const& pair: m) {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

/*
Success
Details
Runtime: 24 ms, faster than 86.21% of C++ online submissions for Destination City.
Memory Usage: 11.7 MB, less than 100.00% of C++ online submissions for Destination City.
*/
string destCity(vector<vector<string>>& paths) {
    unordered_map<string,int> m = {};
    
    for(auto e : paths) {
        if(m[e[0]])
            m[e[0]]++;
        else
            m[e[0]]+=1;
        
        if(m[e[1]])
            m[e[1]]++;
        else
            m[e[1]]+=1;
    }
    
    //print_map(m);
    
    for(auto e : paths)
        if(m[e[1]] == 1)
            return e[1];

    return "";
}

int main(int argc, char** argv) {

    /* input prep */
    vector<vector<string>> input = {};
    vector<string> v1 = {"London", "New York"};
    vector<string> v2 = {"New York", "Lima"};
    vector<string> v3 = {"Lima", "Sao Paulo"};
    input.push_back(v1);
    input.push_back(v2);
    input.push_back(v3);


    cout << destCity(input) << endl;
    return 0;
}