class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> level;
        level.push_back(1);
        result.push_back(level);
        if(numRows == 1) return result;
        
        level.push_back(1);
        result.push_back(level);
        if(numRows == 2) return result;
        level.clear();
        for(int i = 2; i < numRows; i++){
            level.resize(i+1, 0);
            for(int j = 0; j < i + 1; j++){
                if(j == 0 || j == i) level[j] = 1;
                else{
                    level[j] = result[i - 1][j - 1] + result[i - 1][j]; 
                }
            }
            result.push_back(level);
            level.clear();
        }
        return result;
    }
};