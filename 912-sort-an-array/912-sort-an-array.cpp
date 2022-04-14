class Solution {
public:
    
    void merge(vector<int>&nums , int l , int mid , int h)
    {
        int temp[h-l+1];
        int k=0;
        int i=l , j=mid+1;
        
        while(i<=mid && j<=h)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        
        while(i<=mid)
        {
            temp[k++]=nums[i++];
        }
        while(j<=h)
        {
            temp[k++]=nums[j++];
        }
        
        for(int i=0;i<h-l+1;i++)
        {
            nums[l+i]=temp[i];
        }
    }
    
    
    void mergesort(vector<int>&nums , int l , int h)
    {
        
        if(l>=h)return;
        
        
        int mid = (l+h)/2;
        
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,h);
        merge(nums,l,mid,h);
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) 
    {
        int n = nums.size();
        mergesort(nums,0,n-1);
        
        return nums;
    }
};