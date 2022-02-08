class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int d =0;
        
        if(n==0){
            return 0;
        }
        
        
        for(int i =0;i<n-1; i++ ){
            if(nums[i]==nums[i+1]){
                d++;
            }
        }
        
        if(d==0){
            return n;
        }
        
        
        int r= n-d;
        
        int j=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                cout<<"w";
                nums[j++]=nums[i];
            }
        }
        if(j>0 && nums[j-1]!=nums[n-1] ){
            cout<<"wow";
            nums[j]=nums[n-1];
        }
        
       
        return r;
    }
};