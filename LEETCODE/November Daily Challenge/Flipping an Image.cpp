class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++)
        {
           int j =0;
            int k = A[0].size()-1;
            while(j<=k)
            {
                swap(A[i][j],A[i][k]);
                j++;
                k--;
            }
            
                
        }
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j]==1)
                    A[i][j]=0;
                    else
                        A[i][j]=1;
            }
        }
           
        vector<vector<int>> res = A;
        return res;
    }
};