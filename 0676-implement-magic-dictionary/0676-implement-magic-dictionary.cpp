class TrieNode{
    public:
    char data;
    unordered_map<char, TrieNode*>children;
    bool isTerminal;
    TrieNode(char ch): data(ch), isTerminal(false){};
};

class Trie{
    TrieNode*root;
    void insertUtil(TrieNode* root, string& word, int i=0){
        if(i == word.size()){
            root->isTerminal = true;
            return;
        }
        if(root->children.find(word[i]) == root->children.end()){
            root->children[word[i]] = new TrieNode(word[i]);   //creates the node and connects it to the current node.
        }
        insertUtil(root->children[word[i]], word, i+1);  //Why pass i instead of using word.substr(1)? It avoids repeatedly creating new strings during recursion.
    }
    bool searchUtil(TrieNode* root, string& word, int i=0, bool mismatch = false){
        if(i == word.size()) {
            return mismatch && root->isTerminal;  //mismatch and root->isTerminal must be true
        }
        auto ch = word[i];
        if(root->children.find(ch) != root->children.end()){
            //match till u can
            if(searchUtil(root->children[ch], word, i+1, mismatch)){
                return true;
            }
        }
        //if im here, that means char didnt match
        if(mismatch == false){   //Check whether you have already changed a character, ajun kontahi char badalla nasel trch navin char try karaycha
            //exactly 1 mismatch try krunga
            for(auto &[childChar, childNode]:root->children){   //childChar is a possible next character in the Trie, childNode is the Trie node associated with that character.
                if(ch == childChar) continue;  // must be a different letter
                if(searchUtil(childNode, word, i+1, true)){
                    return true;  //pudche sagle char match zhale pahije karn ek char badalnyacha chance gela ahe
                }
            }
        }
        return false;
    }
    
    public:
    Trie(){
        root = new TrieNode('\0'); //means null
    }
    void insert(string &word){
        insertUtil(root, word);
    }
    bool search(string &word){
        return searchUtil(root, word);
    }
};


class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& word:dictionary){
            trie.insert(word);
        }
    }
    
    bool search(string searchWord) {
        return trie.search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */