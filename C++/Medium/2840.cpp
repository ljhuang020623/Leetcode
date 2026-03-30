#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1 == s2) return true;
        
        unordered_map<char, int> freq_even;
        unordered_map<char, int> freq_odd;
        int n = s1.length();
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) freq_even[s1[i]]++;
            else{ freq_odd[s1[i]]++; }
        }

        for (int j = 0; j < n; j++){
            if (j % 2 == 0) {
                if (freq_even[s2[j]] > 0){
                    freq_even[s2[j]]--;
                }else{
                    return false;
                }
            }else {
                if (freq_odd[s2[j]] > 0){
                    freq_odd[s2[j]]--;
                }else{
                    return false;
                }
            } 
                
        }
        
        return true;

    }
};