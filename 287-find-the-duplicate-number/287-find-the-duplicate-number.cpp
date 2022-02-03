class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};



/**                Array Gets Modified!!!!

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[nums[i]%n]+=n;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=2*n)return i;
        }
        return 0;
    }
}
**/