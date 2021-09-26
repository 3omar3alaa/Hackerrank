class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
        make a table that it's rows are the coins and the columns are the different amount from 0-n
        */
        if(amount == 0) return 0;
        
        sort(coins.begin(), coins.end());
        vector<vector<int>> table (coins.size(), vector<int>(amount + 1));
        
        // make first column equal to 0
        for(int i = 0; i < coins.size(); i++)
            table[i][0] = 0;

        for(int row = 0; row < coins.size(); row++){
            for(int col = 1; col <= amount; col++){
                if(coins[row] > col){
                    table[row][col] = row > 0 ? table[row - 1][col] : 0;
                }
                else if(coins[row] == col){
                    table[row][col] = 1;
                }
                else{
                    if(row > 0)
                    {
                        if(!table[row][col - coins[row]]) table[row][col] = table[row - 1][col];
                        else if (!table[row - 1][col]) table[row][col] = 1 + table[row][col - coins[row]];
                        else table[row][col] = min(table[row - 1][col], 1 + table[row][col - coins[row]]); 
                    }
                    else{
                        if(!table[row][col - coins[row]]) table[row][col] = 0;
                        else table[row][col] = 1 + table[row][col - coins[row]];
                    }
                }
            }
        }        
        return table[coins.size() - 1][amount] == 0 ? -1 : table[coins.size() - 1][amount];
    }
};