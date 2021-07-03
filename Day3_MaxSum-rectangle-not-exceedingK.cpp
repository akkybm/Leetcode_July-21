class Solution {
public:
    int best_cumulative_sum(vector<int> ar,int N,int K) 
    { 
        set<int> cumset; 
        cumset.insert(0); 

        int best=INT_MIN,cum=0; 

        for(int i=0;i<N;i++) 
        { 
            cum+=ar[i]; 
            set<int>::iterator sit=cumset.lower_bound(cum-K); 
            if(sit!=cumset.end())best=max(best,cum-*sit); 
            cumset.insert(cum); 
        } 
        return best;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        vector<vector<int>>& premat(matrix);
        for(int i=0;i<premat.size();i++)
        for(int j=1;j<premat[i].size();j++)
            premat[i][j]=premat[i][j]+premat[i][j-1];
        int res=INT_MIN;
        for(int l=0;l<matrix[0].size();l++)
        for(int r=l;r<matrix[0].size();r++)
        {
            vector<int>temp;
            for(int i=0;i<matrix.size();i++)
            {
                int t=0;
                if(l>0)
                    t=premat[i][l-1];
                temp.push_back(premat[i][r]-t);
            }
            res=max(res,best_cumulative_sum(temp,temp.size(),k));
        }
        return res;
        
    }
};
