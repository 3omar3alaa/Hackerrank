class Solution {
public:
    bool isRobotBounded(string instructions) {
        // repeat the instructions 4 times max to make sure it is a sqaure
        
        char direction = 'U';
        int x = 0;
        int y = 0;
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < instructions.length(); j++){
                if(instructions[j]== 'G'){
                    if(direction == 'U') y++;
                    else if(direction == 'R') x++;
                    else if(direction == 'D') y--;
                    else direction = x--;
                }
                else if(instructions[j] == 'L'){
                    if(direction == 'U') direction = 'L';
                    else if(direction == 'R') direction = 'U';
                    else if(direction == 'D') direction = 'R';
                    else direction = 'D';
                }
                else if(instructions[j] == 'R'){
                    if(direction == 'U') direction = 'R';
                    else if(direction == 'R') direction = 'D';
                    else if(direction == 'D') direction = 'L';
                    else direction = 'U';
                }
            }
            if(x == 0 && y == 0) return true;
        }
        
        return x == 0 && y == 0 ? true : false;
    }
};