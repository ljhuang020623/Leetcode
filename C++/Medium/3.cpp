#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left{0}, max_len{0};
        for (int right = 0; right != s.length(); ++right){
            char ch = s[right];
            
            while (seen.find(ch) != seen.end()){
                seen.erase(s[left]);
                left += 1;
            }
            seen.insert(s[right]);
            int window_len = right - left +1;
            if(window_len > max_len){
                max_len = window_len;
            }
        }
        return max_len;
    }
};