class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != -1){ //jr part string milali tr erase it
            s.erase(s.find(part), part.length());
        }
    return s;    
    }
};