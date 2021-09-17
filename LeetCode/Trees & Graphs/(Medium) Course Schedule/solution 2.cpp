class Solution {
public:
    // pass the function parameters by reference so not to take so much time in copying the 
    // value if sent by value
    
    bool hasCycleDFS(int course, vector<vector<int>>& dict, vector<int>& visited){      
        if(dict[course].size() == 0) return false;
        visited[course] = 1;
        
        for(int i = 0; i < dict[course].size(); i++){
            if(visited[dict[course][i]] == 1) return true;
            
            if(!visited[dict[course][i]])
                if(hasCycleDFS(dict[course][i], dict, visited))
                    return true;
        }
        
        // checked[course] = false;
        visited[course] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
        // dictionary to be an adjaceny list
        // unordered_map<int, vector<int>> dict;
        vector<vector<int>> dict(numCourses);
        
        for(vector<int> v : prerequisites){
            dict[v[1]].push_back(v[0]);
        }
        
        // visited array
        // the node will be true when all it's adjacency list is visited
        // but the adjacency list won't be visited
        vector<int> visited(numCourses, 0);
        
        /* checked array
        the node and it's adjacency list node will be true every time we loop over them
        then return to false after the loop
        the purpose of this array is to tackle the case when multiple node point to a single node
        for example 5 [[1,4],[2,4],[3,1],[3,2]]
        */
        // vector<bool> checked(numCourses, false);
        //  we could use only a sinle array (visited) but make it an array of int
        // where 0 - not visited, 1 - checked, 2 - visited
        
        
        // make a DFS funtion and start with the first course
        for(int i = 0; i < numCourses; i++){
            if(!visited[i])
                if(hasCycleDFS(i, dict, visited))
                    return false;
        }
        return true;
    }
};