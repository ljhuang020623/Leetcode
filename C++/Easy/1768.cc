#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0;
        while (i < word1.length() || i < word2.length()) {
            if (i < word1.length()) {
                res += word1[i];
            } 
            if (i < word2.length()) {
                res += word2[i];
            }
            i++;
        }
        
        return res;
    }
};

// Initial answer without any gpt help.
// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         // word1 = "ab", word2 = "qprs"
//         int w1 = 0, w2 = 0, idx = 0;
//         string result = "";
//         while (w1 < (int)word1.size() && w2 < (int)word2.size()){
//             if (idx % 2 == 0){
//                 result.push_back(word1[w1]);
//                 w1++;
//             }else {
//                 result.push_back(word2[w2]);
//                 w2++;
//             }
//             idx += 1;
//         }
//         if (w1 >= (int)word1.size()){
//             result.append(word2.substr(w2));
//         }
//         if (w2 >= (int)word2.size()){
//             result.append(word1.substr(w1));
//         }
//         return result;
//     }
// };