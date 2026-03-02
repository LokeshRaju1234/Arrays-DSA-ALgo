class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(char c : n){
            if(maxi<c-'0'){
                maxi=c-'0';
            }
        }
        return maxi;
        
    }
};