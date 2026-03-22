class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
     //you have four options here 
     //E - E = E
     //E - O = O
     //O - O = E
     //O - E = O  -->if you observe if an array contains odd number we can make array 
     //as either odd or even by doing this ope 
     //1) O - E = O and  O - O = E -->No matter what the input is we can adjust the parity
     //for all test cases 
     return true;
    }
};