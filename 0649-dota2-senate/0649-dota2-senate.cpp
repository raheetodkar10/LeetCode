class Solution {
public:
    string predictPartyVictory(string senate) { //senate is assembly, 
        queue<int> radiantQ;
        queue<int> direQ;
        int pos=0;
        for(pos=0;pos<senate.size();pos++){
            char senator = senate[pos];
            if(senator == 'R') radiantQ.push(pos);
            if(senator == 'D') direQ.push(pos);
        }  //don Qs mde R and D values push kelya respectively

        while(!radiantQ.empty() && !direQ.empty()){
            int rFront = radiantQ.front();
            radiantQ.pop();

            int dFront = direQ.front();
            direQ.pop();

            if(rFront < dFront){    //ex: R0 and D2 asel tr R will band D as R pahila alay than D(0,2 are indices)
                //means R will ban D forever
                radiantQ.push(pos++);  //R chi value Q mde parat push honar for further comparisons ani index pn increase honar(pos++)
            }
            else{
                //D will ban R forever
                direQ.push(pos++);
            }
        }
        if(!radiantQ.empty()) return "Radiant";
        return "Dire";   //else case 
    }
};
//apn fakt R la push kartoy not to D or vice versa, so TC:O(n) & SC:O(n) as size of both Qs will be n
//single Q nai vaparla as jr RRRDD asta tr with 1st R sathi pudche 2R pop karave lagtil and then pop 1st D and then push those 2 popped R for comparison which will create confusion