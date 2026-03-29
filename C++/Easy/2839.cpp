#include <string>

using namespace std;



class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        if (s1 == s2) return true;
        // swap idx 0 and 2 
        string string_1 = s1;
        swap(string_1[0], string_1[2]);
        if (string_1 == s2) return true;
        
        // swap idx 1 and 3
        string string_2 = s1;
        swap(string_2[1], string_2[3]);
        if (string_2 == s2) return true;

        // swap both 
        string string_3 = s1;
        swap(string_3[0], string_3[2]);
        swap(string_3[1], string_3[3]);
        if (string_3 == s2) return true;
        
        return false;
    }
};