#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int max_balance = 0;
        for (int i = 0; i < (int)s.size(); i++){
            int freq[26] = {0};
            for (int j = i; j < (int)s.size(); j++){
                freq[s[j] - 'a']++;

                int min_freq = INT_MAX;
                int max_freq = 0;

                // scan throught the array for max and min frequency
                for (int k = 0; k < 26; k++){
                    if (freq[k] > 0){
                        min_freq = min(min_freq, freq[k]);
                        max_freq = max(max_freq, freq[k]);
                    }
                }
                if (min_freq == max_freq){
                    max_balance = max(max_balance, j - i + 1);
                }
            }
        } 
        return max_balance;
    }
};