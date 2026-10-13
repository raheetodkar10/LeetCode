class Solution {
    /*int code(char c){  //appr 2:
        switch(c){
            case 'A': return 0;  //00
            case 'C': return 1;  //01
            case 'G': return 2;  //10
            case 'T': return 3;  //11
            default: return 3;  //00  
        }
    }*/
public:
    vector<string> findRepeatedDnaSequences(string s) {  //TC:O(n)
        unordered_map<string, int> seqCount;  //stores exactly 10 sized sequence
        vector<string>ans;
        if(s.size()<10) return {};
        for(int i=0;i<=s.size()-10;i++){    //magun 10 char sodun
            auto currSubstring = s.substr(i,10);  //from i to 10 size
            seqCount[currSubstring]++;
        }
        //iterate over freq map
        for(auto [substr,freq]: seqCount){  //ethe auto& pn pass kru shakto cause string operations are heavy so make their copy. substr receives the key, and freq receives its corresponding value.
            if(freq > 1){
                ans.push_back(substr);
            }
        }
        return ans; 
        /*appr 2: Rolling hash:
        unordered_map<int, int> seqCount;
        vector<string>ans;
        if(s.size()<10) return {};
        const int MASK = 0xFFFFF;   //0000.....00001111....111111-> total 20 1's
        int x = 0;  //encoded number for current window
        //building 1st window hash:
        for(int i=0;i<10;i++){
            x = (x<<2) | code(s[i]);  //code(s[i]) will either select A,C,G,T
        }
        seqCount[x]++;
        for(int i=10;i<s.size();i++){
            //roll forward
            x = ((x << 2) & MASK) | code(s[i]);
            if(seqCount.find(x) != seqCount.end()){
                if(seqCount[x] == 1){
                    ans.push_back(s.substr(i-10+1, 10));
                }
            }
            seqCount[x]++;
        }
        return ans;*/
    }
};