#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        int i = (int)a.length() - 1, j = (int)b.length() - 1;
        int carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry){
            int sum = carry;
            if (i >= 0){
                // this line is to convert the char in a into int
                sum += a[i] - '0';      
                i--;
            }
            if (j >= 0){
                sum += b[j] - '0';
                j--;
            }
            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};