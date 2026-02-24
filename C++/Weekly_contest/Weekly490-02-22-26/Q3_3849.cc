#include <string>

using namespace std;


class Solution {
public:
    string maximumXor(string s, string t) {
        string maxNum = flipBits(s);
        int paddings = countSetBits(t) - countSetBits(maxNum);
        if (paddings > 0){
            for (int i = maxNum.size() - 1; i >= 0; i--){
                if (maxNum[i] != '1'){
                    maxNum[i] = '1';
                    paddings -= 1;
                }
                if (paddings == 0) break;
            }
        }
        if (paddings < 0) {
            for (int i = maxNum.size() - 1; i >= 0; i--){
                if (maxNum[i] == '1'){
                    maxNum[i] = '0';
                    paddings += 1;
                }
                if (paddings == 0) break;
            }
        }
        string result;
    
        for (int i = 0; i < s.length(); i++){
            result.push_back((s[i] ^ maxNum[i]) + '0');
        }
        return result;
    }

private:
    string flipBits(string s){
        for (auto& c : s){
            if (c == '1'){
                c = '0';
            }else{
                c = '1';
            }
        }
        return s;
    }
    int countSetBits(string s){
        int cnt = 0;
        for (auto& c : s){
            if (c == '1') cnt++;
        }
        return cnt;
    }
};