#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (int)s.length();
        unordered_set<string> st;
        if (n < (pow(2, k) + k - 1)) return false;
        for (int i = 0; i < n - k + 1; i++){
            string bincode = s.substr(i, k);
            if (st.count(bincode) == 0){
                st.insert(bincode);
            }
        }
        return (int)st.size() == pow(2, k);
    }
};