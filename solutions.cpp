class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int m=0, i=0;
        bool found= true;
    
    //base case
    if (k==0) return true;//go or no gaps doesnt matter
        
    //if first number is zero
    if (nums[0] == 0) m=1;
    
    while( (i++ != nums.size()-1) ){
        if (nums[i]==0) m++;
        if (nums[i]==1 && i !=0){
            if (m<k) {
               found = false; 
                break;
            }
            m=0;   
        }
    }
    return found;
    }
};