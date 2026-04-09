#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        // max length for a x b is len(a) + len(b)
        int m = num1.size(), n = num2.size();
        vector<int> ans(n + m, 0);
        for (int i = n - 1; i >= 0; i--){
            for (int j = m - 1; j >= 0; j--){
               int d1 = num1[j] - '0';
               int d2 = num2[i] - '0';
               int product =  d1 * d2;

               int sum = product + ans[i + j + 1];
               ans[i + j + 1] = sum % 10;
               ans[i + j] += sum / 10; 
            }
        }

        string res;
        bool leadingzero = true;
        for (auto& digit : ans){
            if (leadingzero && digit == 0) continue;
            leadingzero = false;
            res.push_back(digit + '0'); 
        }
        return res;



    }
};