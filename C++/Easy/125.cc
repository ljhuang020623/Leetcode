#include <string>
#include <cctype>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        t.reserve(s.size());
        for (char c : s){
            if (isalnum(c)){
                t.push_back(tolower(c));
            }
        }
        int l{0}, r{(int)t.size() - 1};
        while (l < r){
            if (t[l] == t[r]){
                l++;
                r--;
                continue;
            }
            else {
                return false;
            }
        }
        return true;

    }
};