// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        int ans=0;
        for(auto& it : tasks){
            freq[it]++;
        }
        for(auto& it: freq ){
            if(it.second==1)
                return -1;
            if(it.second%3==0)
                ans += it.second/3;
            else
                ans += it.second/3 +1; 
        }
        return ans;
    }
};