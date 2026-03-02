class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        vector<pair<int,int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int row = 0;
        int col = 0;
        int dirindx = 0;

        for(int number = 1;number<=n * n;number++)
        {
            matrix[row][col] = number;
            int nextrow = row + directions[dirindx].first;
            int nextcol = col + directions[dirindx].second;

            if(nextrow < 0 || nextrow >=n || nextcol < 0 || nextcol >= n || matrix[nextrow][nextcol] != 0)
            {
                dirindx = (dirindx + 1) % 4;//change directon
                nextrow = row + directions[dirindx].first;
                nextcol = col + directions[dirindx].second;

            }
            row = nextrow;
            col = nextcol;
        }

        return matrix;

    }
};