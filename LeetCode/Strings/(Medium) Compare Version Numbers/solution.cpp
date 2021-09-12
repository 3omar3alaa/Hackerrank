class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i = 0;
        int j = 0;
        string v1 = "";
        string v2 = "";
        while(i < version1.length() && j < version2.length()){            
            while(isdigit(version1[i])){
                v1+=version1[i++];
            }
            while(isdigit(version2[j])){
                v2+=version2[j++];
            }            
            if(stoi(v1) > stoi(v2)) return 1;
            else if (stoi(v1) < stoi(v2)) return -1;
            i++;
            j++;
            v1 = "";
            v2 = "";
        }
        // if version 2 isn't yet finished
        if(i >= version1.length() && j < version2.length()){
            while(j < version2.length()){
                while(isdigit(version2[j])){
                    v2+=version2[j++];
                }
                if(stoi(v2) > 0) return -1;
                j++;
                v2 = "";
            }            
        }
        // if version 1 isn't yet finished 
        else if(i < version1.length() && j >= version2.length()){
            while(i < version1.length()){
                while(isdigit(version1[i])){
                    v1+=version1[i++];
                }
                if(stoi(v1) > 0) return 1;
                i++;
                v1 = "";
            }
        }
        return 0;
    }
};