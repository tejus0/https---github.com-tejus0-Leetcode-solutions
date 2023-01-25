// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    long dp(int ind,vector<int> &prices, int buy , int n,vector<vector<long>> &check){
        
        if(ind==n){
            return 0;
        }
        if(check[ind][buy]!=-1){
            return check[ind][buy];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+dp(ind+1,prices,0,n,check),0+dp(ind+1,prices,1,n,check));
        }
        else{
            profit=max(prices[ind]+dp(ind+1,prices,1,n,check),0+dp(ind+1,prices,0,n,check));
        }
        return check[ind][buy]=profit;
    }
    
    long maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<long>> check(n+1,vector<long>(2,-1));
        return dp(0,prices,1,n,check);
            }
};