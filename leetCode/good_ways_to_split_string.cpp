class Solution {
public:
    bool isGoodSplit(vector<int> left, vector<int> right){
        int l = 0, r = 0;
        for(int i = 0; i < 26; i++){
            if(left[i])
                l++;
            if(right[i])
                r++;
        }
        return l == r;
    }
    
    int numSplits(string s) {
        vector<int> left(26, 0), right(26, 0);
        int ans = 0;
        for(auto x: s)
            right[x-'a']++;
        for(auto x: s){
            left[x-'a']++;
            right[x-'a']--;
            if(isGoodSplit(left, right))
                ans++;
        }
        return ans;
    }
};