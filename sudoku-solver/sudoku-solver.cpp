class Solution {
public:
    // vector<vector<char>>ans;
    int part(int a)
    {
        if(a<3) return 0;
        if(a<6) return 3;
        return 6;
    }
    bool isSafe(vector<vector<char>>& board,int i,int j,char ch)
    {
        for(int k=0;k<9;k++) if(board[i][k]==ch || board[k][j]==ch) return false;
        
        int row = part(i);
        int col = part(j);
        
        for(int x=row;x<=row+2;x++)
        {
            for(int y=col;y<=col+2;y++)
            {
                if(board[x][y]==ch) return false;
            }
        }
        
        return true;
    }
    bool solveBoard(vector<vector<char>>& board,int i,int j)
    {
        // cout<<i<<" "<<j<<endl;
        if(i>8)
        {
            // cout<<1<<endl;
            return true;
        }
        if(j>8)
        {
            // cout<<2<<endl;
           return solveBoard(board,i+1,0);
        }
        if(board[i][j]!='.')
        {
            // cout<<3<<endl;
            return solveBoard(board,i,j+1);
        }
        // cout<<4<<endl;
        for(char ch='1';ch<='9';ch++)
        {
            if(isSafe(board,i,j,ch))
            {
                board[i][j] = ch;
                bool ok = solveBoard(board,i,j+1);
                if(ok) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveBoard(board,0,0);
      
        return;
    }
};