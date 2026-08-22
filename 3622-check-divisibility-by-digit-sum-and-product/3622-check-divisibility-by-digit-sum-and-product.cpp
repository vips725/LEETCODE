class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int> digits;
        int temp = n;

        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        int result = 0;
        int prodres = 1;

        for (int y : digits) {
            result += y;
            prodres *= y;
        }

        int divisor = result + prodres;
        return (n % divisor == 0);
    }
};
