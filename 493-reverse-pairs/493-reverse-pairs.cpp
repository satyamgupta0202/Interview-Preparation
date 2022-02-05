class Solution {
public:
    
    int ans = 0;
    void merge(vector<int>&nums, int low , int mid , int high){
        
        int i=low , j=mid+1;
        
        while(i<=mid){
            
            while(j<=high && nums[i]> (long)2*nums[j]){
                j++;
            }
            
            ans+= j-(mid+1);
            i++;
            
        }
        
        
        
        
        
        int temp[high-low+1];
        i = low ;
        j=mid+1;
        int k=0;
        
        while(i<=mid && j<=high){
            
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=high){
            temp[k++]=nums[j++];
        }

        for(int i=0;i<high-low+1;i++){
            nums[low+i]=temp[i];
        }
    }
    
    
    
    void mergeSort(vector<int>&nums, int low , int high){
        
        if(low>=high)return ;
        int mid = (low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    
    
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        mergeSort(nums,0,n-1);
        //   for(int i=0;i<nums.size();i++){
        //     cout<<nums[i];
        //     cout<<"\n";
        // }
        return ans;
    }
};