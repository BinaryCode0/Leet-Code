class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)
        {
            return true;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' && s[i+1]==')')
            {
                if(s.size()==2)
                {
                    return true;
                }
                s=s.substr(0,i)+s.substr(i+2,s.size()-(i+1));
               if(isValid(s)==true) return true;
                else return false;
            }
            else if(s[i]=='{' && s[i+1]=='}')
            {
                if(s.size()==2)
                {
                    return true;
                }
                s=s.substr(0,i)+s.substr(i+2,s.size()-(i+1));
                if(isValid(s)==true) return true;
                else return false;
            }
            else if(s[i]=='[' && s[i+1]==']')
            {
                if(s.size()==2)
                {
                    return true;
                }
                s=s.substr(0,i)+s.substr(i+2,s.size()-(i+1));
                if(isValid(s)==true) return true;
                else return false;
            }
            
        } return false;
    }
};
