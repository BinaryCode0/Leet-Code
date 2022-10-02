//2302. Count Subarrays With Score Less Than K

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int j=0;
        long long cnt=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            //cout<<(i-j)<<" ";
            while(j<=i && sum*(i-j+1)>=k)
            {
                sum-=nums[j];
                j++;
            }
            cnt += (i-j+1);
        }
        return cnt;
    }
};
