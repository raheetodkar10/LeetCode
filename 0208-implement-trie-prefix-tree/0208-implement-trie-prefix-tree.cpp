class TrieNode{  //own
    public:
        char data;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;

        TrieNode(char val){
            data = val;
            isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word){  //own
    //base case
    //agar me sare char trie me insert kr chuka hu, then abhi jis node pr khada hu vo ek terminal node he
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    //1 case
    char ch = word[0];   //first char
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present
        //move to that child
        child = root->children[ch];
    }
    else{
        //absent
        //create node
        child = new TrieNode(ch);
        //link
        root->children[ch] = child;
    }
    //baki recursion
    insertWord(child, word.substr(1)); //first elem sodun baki child vr rec
};

bool searchWord(TrieNode* root, string word){  //own, TC:O(n)
    //base case
    if(word.length() == 0){
        //me last last char wali node pr khada hu
        if(root->isTerminal == true){
            return true;
        }
        else{
            return false;
        }
        //instead of this if-else, we can just write: return root->isTerminal
    }
    //1 case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present
        child = root->children[ch];
    }
    else{
        //absent
        return false;
    }
    //baki recursion
    bool recKaAns = searchWord(child, word.substr(1));
    return recKaAns;
};

bool searchPrefix(TrieNode* root, string word){  //own
    //base case
    if(word.length() == 0){
        //me last last char wali node pr khada hu
        /*if(root->isTerminal == true){
            return true;
        }
        else{
            return false;
        }*/
        return true;
    }
    //1 case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present
        child = root->children[ch];
    }
    else{
        //absent
        return false;
    }
    //baki recursion
    bool recKaAns = searchPrefix(child, word.substr(1));
    return recKaAns;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {  //TC:O(n)
        insertWord(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }
    
    bool startsWith(string prefix) {
        //exact search wala logic fakt prefix sathi ethe terminal nai lagnar
        return searchPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */