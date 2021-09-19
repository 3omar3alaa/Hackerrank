struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};
    

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = this -> root;
        for(char c: word){
            if(current -> children.find(c) == current -> children.end())
                current -> children[c] = new TrieNode();
            current = current -> children[c];
        }
        current -> isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = this -> root;
        for(char c: word){            
            if(current -> children.find(c) == current -> children.end())
                return false;            
            current = current -> children[c];
        }        
        return current -> isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // Get the prefix node, then for each of its children , if there is a word return true else return false
        TrieNode* current = this -> root;
        for(char c: prefix){            
            if(current -> children.find(c) == current -> children.end())
                return false;            
            current = current -> children[c];
        }
        
        // now current stands at the last value of the prefix        
        return checkChildren(current);   
    }
    
    bool checkChildren(TrieNode* current){
        if(current -> isWord) return true;
        
        bool isWord = false;
        for(auto& c : current -> children){
            isWord |= checkChildren(c.second);
        }        
        return isWord;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */