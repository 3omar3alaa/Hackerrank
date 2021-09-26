class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> table (amount + 1, 0);
        table[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                if(j >= coins[i])
                    table[j] += table[j - coins[i]];                
            }
        }
        return table[amount];
    }
};