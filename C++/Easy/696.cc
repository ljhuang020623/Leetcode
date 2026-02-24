#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        vector<int> numList;
        int count = 1;
        for (int i = 1; i < (int)s.length(); i++){
            if (s[i] == s[i - 1]){
                count++;
            }else{
                numList.push_back(count);
                count = 1;
            }
        }
        numList.push_back(count);
        for (int i = 1; i < (int)numList.size(); i++){
            result += min(numList[i], numList[i - 1]);
        }
        return result;
    }
};