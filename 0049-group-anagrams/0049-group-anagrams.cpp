class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string original = strs[i];
            string arrangement = original;
            sort(arrangement.begin(), arrangement.end());

            m[arrangement].push_back(original);    //ex: aet->ate,eat,tea
        }
        vector<vector<string>> ans;
        for(auto i : m){
            //i is representing a record in map m
            //i.fisrt=string , i.second=vector<string> . we want vector<string> in ans
            ans.push_back(i.second);
        }
        return ans;
    }
};