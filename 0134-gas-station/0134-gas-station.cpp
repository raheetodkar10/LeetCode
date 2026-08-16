class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {  //TC:O(n)
        int start = 0;
        int deficit = 0;
        int balance = 0;

        for(int i=0;i<gas.size();i++){
            //ya to me aage ja sakta hu, ya to aage nai ja sakta
            if(balance + gas[i] < cost[i]){   //balance-> purana petrol, gas[i]-> current petrol 
                //deficit case, me aage nai ja sakta petrol kam padega
                deficit += balance + gas[i] - cost[i];    //deficit sathi he value negative yenar
                start = i+1;  //ex: 3 in our case, navin index pasun apn start karnar
                balance = 0;   //scratch pasun kartana balance 0 honar
            }
            else{
                //aage ja sakta hu, possible he petol jyada/extra ho
                balance = balance + gas[i] - cost[i];    //balance sathi he value positive yenar
            }
        }

        //we just need to compare deficit and balance
        if(balance + deficit >= 0){
            //balance ne deficit ko fill krdia ya fir exceed krdia, then we'll return starting index
            return start;
        }
        else{
            //petrol kam pad gaya
            return -1;
        } 
    }
};