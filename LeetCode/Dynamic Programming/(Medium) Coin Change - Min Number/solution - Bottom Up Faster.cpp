class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Faster Bottom Up Approach
        vector<int> table (amount + 1, amount + 1);
        table[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                // if the amount is greater than the coin
                if(i >= coins[j]){
                    table[i] = min(table[i], table[i - coins[j]] + 1);
                }
            }
        }        
        return table[amount] > amount ? -1 : table[amount];
    }
};