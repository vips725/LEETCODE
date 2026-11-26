class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;

        while (true) {
            if (n < alice) return false;
            n -= alice;

            if (n < bob) return true;
            n -= bob;

            alice -= 2;
            bob -= 2;
        }
    }
};