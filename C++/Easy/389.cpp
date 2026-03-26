#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;
        for (auto& c : t){
            freq[c]++;
        }

        for (auto& c : s){
            freq[c]--;
        }
        for (auto& [key, value] : freq){
            if (value == 1){
                return key;
            }
        }
        return '\0';
    
    }
};