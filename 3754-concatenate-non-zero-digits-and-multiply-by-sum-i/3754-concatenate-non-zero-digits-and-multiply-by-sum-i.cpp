class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);          // convert int to string
        vector<long long> digits;         // store non-zero digits
        long long sum = 0;
        long long x = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';       
                digits.push_back(d);
                sum += d;
            }
        }

        for (long long d : digits) {
            x = x * 10 + d;
        }

        return x * sum;
    }
};
