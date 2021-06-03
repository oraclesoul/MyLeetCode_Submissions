class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
       bool zRow[200],zCol[200];
       memset(zRow,false,sizeof(zRow));
       memset(zCol,false,sizeof(zCol));
       for(int i=0;i<matrix.size();i++)
       {
           for(int j=0;j<matrix[i].size();j++)
           {
               if(matrix[i][j]==0) zRow[i]=true,zCol[j]=true;
           }
       }
        
       for(int i=0;i<matrix.size();i++)
       {
           if(zRow[i])
           {
               for(int j=0;j<matrix[i].size();j++) matrix[i][j]=0;
           }
       }
        
        for(int i=0;i<matrix[0].size();i++)
        {
           if(zCol[i])
           {
               for(int j=0;j<matrix.size();j++) matrix[j][i]=0;
           }
        } 
        return;
        
    }
};