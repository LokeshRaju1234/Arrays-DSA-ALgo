class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //to get 90 deg everytime i need to transpose and reverse the array

        //transpose the array
        int n = mat.size();
        vector<vector<int>>T(n,vector<int>(n));

        for(int r = 0;r < 4;r++)
        {
            if(equalMatrix(mat,target,n))
            {
                return true;
            }

            rotateBy90(mat,n);
        }

        return false;
    }

    void rotateBy90(vector<vector<int>>& mat,int n)
    {
        //transpose
        vector<vector<int>> T(n,vector<int>(n));

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                T[i][j] = mat[j][i];
            }
        }

        for(int i = 0;i < n;i++)
        {
            int start = 0,end = n - 1;

            while(start < end)
            {
                int temp = T[i][start];
                T[i][start] = T[i][end];
                T[i][end] = temp;

                start++;
                end--;
            }
        }

        mat = T;
    }
    bool equalMatrix(vector<vector<int>>& mat, vector<vector<int>>& target,int n)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(mat[i][j] != target[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};