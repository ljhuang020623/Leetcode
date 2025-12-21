#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> mpp;
        for (char i : s){
            mpp[i]++;
        } 
        for (char i : t){
            auto it = mpp.find(i);
            if (it == mpp.end()){
                return false;
            }
            if (--it->second == 0){
                mpp.erase(i);
            }
        }
        return true;
        

    }
};