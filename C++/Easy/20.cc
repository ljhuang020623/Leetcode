#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<int> stack;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : s){
            if (pairs.find(c) != pairs.end()){
                if (stack.empty() || stack.back() != pairs[c]) return false;
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }
        return stack.empty();               
    }
};