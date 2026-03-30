#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


// Time Complexity: O(N * 3 ^ N) where N is the length of digits (if char in digits is 2, 3, 4, 5, 6, 8)
//                  O(N * 4 ^ N) if char in digits is 7 or 9
class Solution {
public:
    vector<string> mp = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
    };
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string path = "";
        dfs(0, digits, path);
        return ans;
    }

    void dfs(int idx, string& digits, string& path){
        // means the idx = digits.size() - 1 has pushed onto path
        if (idx == digits.size()){ 
            ans.push_back(path);
            return;
        }

        for(auto& ch : mp[digits[idx] - '0']){
            path.push_back(ch);
            dfs(idx + 1, digits, path);
            path.pop_back();
        }
    }
};