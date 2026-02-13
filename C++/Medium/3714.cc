#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



// There are 3 cases, where the longest balanced substring is consisting of only 1 kind of char, 2 and all 3; 
// "aaaabababcabc" there are "aaaa", "abab", "abcabc" 3 cases





// Example : s = "abaca"
// A[i] = # of 'a' in s[0...i], A = [1, 1, 2, 2, 3]
// B[i] = # of 'b' in s[0...i], B = [0, 1, 1, 1, 1]
// C[i] = # of 'c' in s[0...i], C = [0, 0, 0, 1, 1]
// If substring = s[2...4] = "aca" = s[l...r]
// we simply subtract A_sub = A[r] - A[l - 1] to get the number of 'a' in substring
//
// Ultimate goal is that A_sub = B_sub = C_sub
// B_sub - A_sub = (B[r] - B[l - 1]) - (A[r] - A[l - 1]) 
//               = (B[r] - A[r]) - (B[l - 1] - A[l - 1]) 
//               = 0 
// C_sub - A_sub = (C[r] - C[l - 1]) - (A[r] - A[l - 1]) 
//               = (C[r] - A[r]) - (C[l - 1] - A[l - 1])
//               = 0




class Solution {
public:
    int longestBalanced(string s) {
        return max({
            case1(s),
            case2(s, 'a', 'b', 'c'),
            case2(s, 'a', 'c', 'b'),
            case2(s, 'b', 'c', 'a'),
            case3(s)
        });
    }
private:
    // The substring is 'aaa' or 'bbbb'
    int case1(const string& s){
        int max_len = 0;
        int n = (int)s.size();
        for (int i = 0; i < n;){
            int j = i;
            while(j < n && s[i] == s[j]){
                j++;
            }
            max_len = max(max_len, j - i);
            i = j;
        }
        return max_len;
    }

    int case2(const string& s, char p, char q, char forbid){
        unordered_map<int, int> mp;
        mp.reserve(2 * s.size());
        int max_len = 0;
        int n = (int)s.size();
        // diff: 
        // 1. a, b
        // 2. a, c
        // 3. b, c
        int diff = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == forbid){
                diff = 0;
                mp.clear();
                mp[0] = i;
                continue;
            }

            if (s[i] == q) diff++;
            else diff--;
            auto it = mp.find(diff);
            
            if (it != mp.end()){
                // the key is diff, val is index
                max_len = max(max_len, i - it->second);
            }else {
                mp[diff] = i;
            }
        }
        return max_len;

    }
    int case3(const string& s){
        unordered_map<long long, int> mp;
        int A = 0, B = 0, C = 0;
        int max_len = 0;
        mp[0] = -1;
        for (int i = 0; i < (int)s.size(); i++){
            if (s[i] == 'a') A++;
            else if (s[i] == 'b') B++;
            else C++;

            int X = (B - A);
            int Y = (C - A);

            long long key = ((long long)X << 32) ^ (unsigned int)Y;
            // now u have a key encoded in ur mp that represent the X and Y
            if (mp.find(key) != mp.end()){
                max_len = max(max_len, i - mp[key]);
            }else{
                mp[key] = i;
            }
        }
        return max_len;
    }
};