class Solution {
public:
    bool divisorGame(int N) {
        int select = N-1;
        if(select%2 == 0)
            return false;
        else
            return true;
    }
};