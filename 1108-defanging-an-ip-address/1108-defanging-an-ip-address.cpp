class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                address.replace(i,1,"[.]");  //Syntax : string.replace(position, length, newString);  (1 → how many characters to remove)
                i = i+2;   //The newly inserted [.] occupies 3 positions, so we move past those 3 characters
            }
        }
        return address;
    }
};