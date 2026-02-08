#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int a_right = count(s.begin(), s.end(), 'a');
        int b_left = 0;
        int ans = a_right;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'a'){
                a_right -= 1;
            }else if (s[i] == 'b'){
                b_left += 1;
            }
            ans = min(ans, a_right + b_left);
        }
        return ans;
    }
};