class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int ans = 0;
        int lcount = 0, rcount = 0;
        for (int i = 0; i < n; i++){
            if (moves[i] == 'L') lcount += 1;
            else if (moves[i] == 'R') rcount += 1;
            else continue;
        }
        if (lcount >= rcount) {
            return n - rcount * 2;
        }else {
            return n - lcount * 2;
        }
    }
};