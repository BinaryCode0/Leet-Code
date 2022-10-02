//Leetcode : 2321. Maximum Score Of Spliced Array


class Solution {
public:
    vector<int> solve(vector<int> diff,int n)
    {
        int csum=diff[0],msum=diff[0];
        int ind1=0,ind2=0,j=0;
        for(int i=1;i<n;i++)
        {
            // cout<<diff[i]<<" ";
            if(csum<=0)
            {
                csum=diff[i];
                j=i;
            }
            else
                csum+=diff[i];
            if(msum<csum)
            {
                msum=csum;
                ind1=j;
                ind2=i;
            }
        }
        // cout<<msum;
         //cout<<ind1<<" "<<ind2;
        return {msum,ind1,ind2};
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> diff1(n),diff2(n);
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums1[i];
            sum2+=nums2[i];
            diff1[i]=nums2[i]-nums1[i];
            diff2[i]=nums1[i]-nums2[i];
        }
        
        vector<int> op1 = solve(diff1,n);
        vector<int> op2 = solve(diff2,n);
        
        int sum;
        
            if(op1[0]<=0)
            return sum1;
            for(int i=op1[1];i<=op1[2];i++)
            {
                //cout<<sum1<<" ";
                sum1-=nums1[i];
                //cout<<sum1<<" ";
                sum1+=nums2[i];
                //cout<<sum1<<" ";
            }    
            sum = sum1;
        
            if(op2[0]<=0)
            return sum2;
            for(int i=op2[1];i<=op2[2];i++)
            {
                //cout<<sum2<<" ";
                sum2-=nums2[i];
                //cout<<sum2<<" ";
                sum2+=nums1[i];
                //cout<<sum2<<" ";
            }
            sum = max(sum,sum2);
            
        
        
        return sum;
    }
};
