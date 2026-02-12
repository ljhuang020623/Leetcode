#include <vector>

using namespace std;



class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()){
            return false;
        }
        int i = 0;
        for (int j = 0; j < (int)t.size(); j++){
            if (s[i] == t[j]){
                i++;
            }
        }
        return i == (int)s.size();

    }
};