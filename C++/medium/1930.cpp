#include <string>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        int n = s.size();
        int count = 0;
        for (char c = 'a'; c <= 'z'; c++){
            int left = -1, right = -1;
            
            // find the first and the last occurence of c
            for(int i = 0; i < n; i++){
                if (s[i] == c){
                    if (left == -1){
                        left = i;
                    }
                    right = i;
                }
            }
            // left == -1 means didnt find c in s, left == right means there is only one occurence instead of 2
            if (left == -1 || left == right){
                continue;
            }

            bool seen[26] = {false};
            for(int i = left + 1; i < right; i++){
                char mid = s[i];
                // this is encoding mid to numbers, by - 'a', ex: 'a' - 'a' = 0, 'b' - 'a' = 1 
                int idx = mid - 'a';
                if (!seen[idx]){
                    count += 1;
                    seen[idx] = true;
                }
            }
        }
        return count;
    }
};