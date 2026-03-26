#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> freq;
        vector<string> ans;
        for (int i = 0; i < n - 9; i++){
            string sequence = s.substr(i, 10);
            if (!freq.count(sequence)){
                freq[sequence] = 1;
            }else {
                freq[sequence]++;
                if (freq[sequence] == 2){
                    ans.push_back(sequence);
                }
            }
        }
        return ans;
    }
};