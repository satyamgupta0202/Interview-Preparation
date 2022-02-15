class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0 , high = nums1.size();
        
        while(low<=high)
        {
            int cut1 = low + (high-low)/2;
            
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int l1 = cut1==0?INT_MIN:nums1[cut1-1];
            int l2 = cut2==0?INT_MIN:nums2[cut2-1];
            int h1 = cut1==n1?INT_MAX:nums1[cut1];
            int h2 = cut2==n2?INT_MAX:nums2[cut2]; 
            
            if(l1<=h2 && l2<=h1)
            {
                if((n1+n2)%2==0)
                {
                    return (double)(max(l1,l2)+min(h1,h2))/2.0;
                }
                else
                {
                    return (double)max(l1,l2);
                }
            }
            
            else if(l1>h2){
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
            
        }
        return 1.0;
        
    }
};