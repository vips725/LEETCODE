class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int sumLeft = 0, sumRight = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num.charAt(i) == '?') qLeft++;
                else sumLeft += num.charAt(i) - '0';
            } else {
                if (num.charAt(i) == '?') qRight++;
                else sumRight += num.charAt(i) - '0';
            }
        }

        int diff = sumLeft - sumRight;

        // If total '?' is odd, Alice wins
        if ((qLeft + qRight) % 2 == 1) return true;

        // If even, Bob wins only if exact balance possible
        return 2 * diff != (qRight - qLeft) * 9;
    }
}
