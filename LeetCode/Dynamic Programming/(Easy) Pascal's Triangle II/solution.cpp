class Solution {
private:
    map<pair<int, int>, int> table;
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i = 0; i < rowIndex + 1; i++){
            result.push_back(getCell(rowIndex, i));
        }
        return result;
    }
    
    int getCell(int row, int col){
        if(row == 0 || col == 0 || row == col) return 1;
        else if(table.find({row, col}) != table.end()) return table[{row, col}];
        else table[{row, col}] = getCell(row - 1, col - 1) + getCell(row - 1, col);
        return table[{row, col}];
    }
};