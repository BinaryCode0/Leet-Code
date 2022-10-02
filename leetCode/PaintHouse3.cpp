//Leetcode : 1473. Paint House III


class Solution {
public:
    int res;
    void solve(vector<int>& houses, vector<vector<int>>& cost,int ind,int prev,int ng,int op)
    {
        if(ind==houses.size())
        {
            //cout<<op<<" ";
            if(ng==0)
                res=min(res,op);
            return;
        }
        
        if(houses[ind]!=0)
        {
            if(prev==houses[ind])
                solve(houses,cost,ind+1,houses[ind],ng,op);
            else
                solve(houses,cost,ind+1,houses[ind],ng-1,op);      
        }
        else
        {
            for(int i=1;i<=cost[0].size();i++)
            {
                if(i==prev)
                    solve(houses,cost,ind+1,i,ng,op+cost[ind][i-1]);
                else
                    solve(houses,cost,ind+1,i,ng-1,op+cost[ind][i-1]);
            }
        }
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
                
        vector<vector<int>> dp(n+1,vector<int> (target+1,INT_MAX));
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        
        for(int i = 0;i<m;i++)
        {
            vector<vector<int>> tmp(n+1,vector<int>(target+1,INT_MAX));
            
            for(int j=1;j<n+1;j++)
            {
                for(int k=1;k<=target;k++)
                {
                    if(houses[i]>0)
                    {
                        if(houses[i]==j)
                        for(int l=1;l<n+1;l++)
                        {
                            if(l==j)
                                tmp[j][k]= min(tmp[j][k],dp[l][k]);
                            else
                                tmp[j][k]= min(tmp[j][k],dp[l][k-1]);
                        }
                    }
                    else
                    {
                        for(int l=1;l<n+1;l++)
                        {
                            if(l==j)
                            {
                                if(dp[l][k]!=INT_MAX)
                                tmp[j][k]= min(tmp[j][k],dp[j][k]+cost[i][j-1]);
                            }
                            else 
                            {
                                if(dp[l][k-1]!=INT_MAX)
                                tmp[j][k]= min(tmp[j][k],dp[l][k-1]+cost[i][j-1]);
                            }
                        }
                    }
                    //cout<<tmp[j][k]<<" ";
                }
               // cout<<endl;
            }
            //cout<<endl;
            dp=tmp;
        }
        int res=INT_MAX;
        for(int j=0;j<n+1;j++)
        {
            res=min(dp[j][target],res);       
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};
