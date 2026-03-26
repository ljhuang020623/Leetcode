#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        vector<int> need(26, 0);
        for (auto& x : s1){
            need[x - 'a']++;
        }
        
        vector<int> window(26, 0);
        for (int i = 0; i < n; i++){
            window[s2[i] - 'a']++;
        }
        if (window == need) return true;

        for (int right = n; right < m; right++){
            window[s2[right] - 'a']++;
            window[s2[right - n] - 'a']--;
            if (window == need) return true;
        }
        return false;

    }
};