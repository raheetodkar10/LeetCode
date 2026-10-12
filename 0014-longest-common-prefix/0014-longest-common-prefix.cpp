class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;
        int childCount;
        TrieNode(char val){
            data = val;
            isTerminal = false;
            childCount = 0;
        }
};

class Solution {
public:
    void insertWord(TrieNode* root, string str){
        //base case
        if(str.length() == 0){
            root->isTerminal = true;
            return;
        }
        //1 case
        char ch = str[0];
        TrieNode* child;
        if(root->children.find(ch) != root->children.end()){
            //present
            child = root->children[ch];
        } 
        else{
            //absent
            child = new TrieNode(ch);   //create
            root->children[ch] = child;  //link
            //dhyan rakhna
            root->childCount++; 
        }
        //baki rec
        insertWord(child, str.substr(1));
    }

    string findLCP(TrieNode* root, string word){
        string ans = "";
        //ethe me chuknar
        //jr empty string trie mde insert kela, tr it means root(-) la terminal mark keli
        if(root->isTerminal){   //if not written, gives wrong ans
            return ans;
        }
        //TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            //aage me sirf tabhi move krungi jab childCount 1 hoga
            if(root->childCount == 1){
                ans.push_back(ch);
                root = root->children[ch];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        //insert all nodes inside the trie
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            insertWord(root,str);
        }
        string ans = findLCP(root,strs[0]);
        return ans;
    }
};