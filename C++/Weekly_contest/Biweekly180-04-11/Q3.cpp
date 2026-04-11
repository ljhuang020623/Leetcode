#include <vector>

using namespace std;

class Solution {
public:
    const int LIMIT = 200000;
    int minOperations(vector<int>& nums) {
        long long  ans = 0;
        int n = nums.size();
        vector<bool> table(LIMIT, true);
        table[0] = false;
        table[1] = false;
        for (int i = 2; i * i < LIMIT; i++){
            if (table[i]){
                for (int j = i * i; j < LIMIT; j += i){
                    table[j] = false;
                }
            }
        }


        for (int i = 0; i < n; i++){
            int x = nums[i];
            if (i % 2 == 0){
                while (!table[x]){
                    ans += 1;
                    x += 1;
                }
            }else {
                while (table[x]){
                    ans += 1;
                    x += 1;
                }
            }
        }
        return (int)ans;

    }

};