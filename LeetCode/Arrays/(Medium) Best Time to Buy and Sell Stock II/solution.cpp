class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
		0 ms solution
		int n = prices.size();
        int sum = 0;
        
        for(int i=0;i<n-1;i++)
        {
            if(prices[i] < prices[i+1])
                sum += prices[i+1] - prices[i];
            
        }
        return sum;
		*/
		
		/*
		4 ms solution
		int buyprice=prices[0];
        int res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]>prices[i]){
                res+=prices[i-1]-buyprice;
                buyprice=prices[i];
            }else if(buyprice>prices[i]){
                buyprice=prices[i];
            }
            if(i==prices.size()-1 && buyprice<prices[i]){
                res+=prices[i]-buyprice;
            }
        }
        return res;
		
		*/
		
		// My solution 8 ms
		if(prices.size() == 1) return 0;
        bool up = false;
        int buy_idx = -1;
        int profit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(i == prices.size() - 1){
                if(up && buy_idx != -1){                    
                    profit += (prices[i] - prices[buy_idx]);
                    up = false;
                    buy_idx = -1;
                }
            }
            else{
                if(prices[i + 1] < prices[i] && up){
                    if(buy_idx != -1){
                        profit += (prices[i] - prices[buy_idx]);
                        up = false;
                        buy_idx = -1;
                    }
                }
                else if(prices[i + 1] > prices[i] && !up){
                    buy_idx = i;
                    up = true;
                }
            }            
        }        
        return profit;
    }
};