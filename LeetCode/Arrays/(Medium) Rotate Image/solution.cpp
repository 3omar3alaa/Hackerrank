class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		// My solution 
        int left = 0;
        int right = matrix.size() - 1;
        
        while(left < right){
            int top = left;
            int bottom = right;
            
            for(int i = 0; i < right - left; i++){                
                int temp = matrix[top][left + i];
                
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }    
            
            left++;
            right--;
        }

		/*
		Faster solution is about reversing elements along the diagonal
		then reversing each row
		
		int n = matrix.size();
        for (int i = 0; i < n; i++) 
        {
            for (int j = i+1; j < n; j++) 
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n / 2; j++) 
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
		
		*/        
    }
};