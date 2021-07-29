class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push(make_pair(i,j));
                    
                }
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            int x = front.first;
            int y = front.second;
            
            for(int i=0;i<4;i++)
            {
                int adjx = x + dx[i];
                int adjy = y + dy[i];
                
                if(adjx>=0 && adjx<n && adjy>=0 && adjy<m && ans[adjx][adjy] > ans[x][y]+1)
                {
                    ans[adjx][adjy] = ans[x][y]+1;
                    q.push(make_pair(adjx,adjy));
                }
            }
        }
        return ans;
    }
};
