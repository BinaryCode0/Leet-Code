class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(),max=0,out=0,in=0;
        if(n==0 || n==1){
            return n; 
        }
        int mag[128]={0};
        
        while(out<n){
            char r = s[out];
            mag[r]++;
            
            while(mag[r]>1){
                char l  = s[in];
                mag[l]--;
                in++;
            }
            
            max= max > out-in+1 ? max : out-in+1;
            out++;
        }
        
        return max;
    }
};
