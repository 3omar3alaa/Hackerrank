class Solution {
public:
    bool hasCycleDFS(int course, vector<vector<int>>& dict, vector<bool>& visited, vector<bool>& checked){      
        if(dict[course].size() == 0) return false;
        checked[course] = true;
        
        for(int i = 0; i < dict[course].size(); i++){
            if(checked[dict[course][i]]) return true;
            
            if(!visited[dict[course][i]])
                if(hasCycleDFS(dict[course][i], dict, visited, checked))
                    return true;
        }
        
        checked[course] = false;
        visited[course] = true;
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
        vector<bool> visited(numCourses, false);
        
        /* checked array
        the node and it's adjacency list node will be true every time we loop over them
        then return to false after the loop
        the purpose of this array is to tackle the case when multiple node point to a single node
        for example 5 [[1,4],[2,4],[3,1],[3,2]]
        */
        vector<bool> checked(numCourses, false);

        // make a DFS funtion and start with the first course
        for(int i = 0; i < numCourses; i++){
            if(!visited[i])
                if(hasCycleDFS(i, dict, visited, checked))
                    return false;
        }
        return true;
    }
};