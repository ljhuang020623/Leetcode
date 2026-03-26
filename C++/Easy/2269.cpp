#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int start = 0;
        int n = 0;
        int ans = 0;

        int x = num;
        while (x > 0) {
            x /= 10;
            n++;
        }

        string str = to_string(num);

        while (start + k <= n) {
            int temp = stoi(str.substr(start, k));
            if (temp != 0 && num % temp == 0) {
                ans++;
            }
            start++;
        }

        return ans;
    }
};