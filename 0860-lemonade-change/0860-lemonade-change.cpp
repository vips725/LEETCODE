class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0; 
        int five = 0; 
        int n = bills.size();
        for(int i = 0; i < n; i++) {
            int money = bills[i];
            if(money == 5) {
                five++;
            } else if(money == 10) {
                if(five == 0) {
                    return false;
                }
                ten++;
                five--;     
            } else if(money == 20) {
                if(ten > 0) {
                    ten--;
                    if(five == 0) {
                        return false;
                    }
                    five--;
                } else {
                    if(five < 3) {
                        return false; 
                    }
                    five -= 3;
                }
            }
        }
        return true;
    }
};
