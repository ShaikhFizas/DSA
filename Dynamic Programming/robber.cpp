//  Q.1 https://naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM

// 	So here what basically used the logic of pick and not to pick for recursion and the base condition is when target ==0 then return 1
// 	Also if ind==0 and arr[0]==target return 1 else 0
// 	Call on pick to not pick return OR of it ||
// 	For transition into memorization check how many parameter are changing according to that declare dp array
// 	Same for tabulation check how many state are changing that many nested for loop will come

#include <bits/stdc++.h> 
bool helper(vector<int>&arr,int target,int ind,vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(ind==0)
    {
        if(arr[0]==target) return true;
        return false;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    bool nottake=helper(arr,target,ind-1,dp);
    bool take=false;
    if(target>= arr[ind])
    {
        take=helper(arr,target-arr[ind],ind-1,dp);
    }
    
    dp[ind][target]= take|| nottake;
    return dp[ind][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    // return helper(arr,k,n-1,dp);

    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }

    dp[0][arr[0]]=true;

    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool nottake=dp[ind-1][target];
            bool take=false;

            if(target>=arr[ind])
            {
                take=dp[ind-1][target-arr[ind]];
            }

            dp[ind][target]=take || nottake;
        }
    }

    return dp[n-1][k];
}


// Recursion :  TC:-O(2^n) SC:O(N)
// Memo : TC:-O(N*target) SC:O(N*target) dp+O(N) recursion stack space
// Tab: TC:O(N*target)  SC:O(N*target)

