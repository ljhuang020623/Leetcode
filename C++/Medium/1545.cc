#include <string>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = build(n);
        return s[k - 1];
    }

private:
    string build(int n){
        if (n == 1) return "0";
        // S = Sprev + "1" + reverse(invert(Sprev))
        string prev = build(n - 1);
        string right = prev;
        // invert
        for(auto& c : right){
            if (c == '1'){
                c = '0';
            }else{
                c = '1';
            }
        }
        // reverse
        reverse(right.begin(), right.end());
        return prev + "1" + right;

    }
};