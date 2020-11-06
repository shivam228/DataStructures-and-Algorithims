class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
       int l = 1, r = 1000000;
        int mid;
        int ans;
        while(l < r)
        {
            int sum = 0;
            mid = (l + r) / 2;
            for(int j=0;j<nums.size();j++)
            {
            if(nums[j]%mid==0)
            sum = sum+(nums[j]/mid);
            else
            sum = sum+(nums[j]/mid)+1;
            }
        if(sum<=threshold)
        {
            r =mid;
            ans =mid;
        }
            else
                l =mid+1;
            
        }
        return ans;
    }
};