class Solution {
public:
    int maxPower(string s) {
        int count =1;
        int res = 1;
        for(int i=0;i<s.length()-1;i++)
        {
            while(s[i]==s[i+1])
            {
                count++;
                i++;
            }
            res = max(res,count);
            count =1;
        }
        return res;
        
    }
};