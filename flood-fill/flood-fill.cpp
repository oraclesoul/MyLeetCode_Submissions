class Solution {
public:
    void fill(vector<vector<int>>&image,int i,int j,int &oldc , int &newc)
    {
       if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oldc) return;
       image[i][j] = newc;
       fill(image,i+1,j,oldc,newc);
       fill(image,i-1,j,oldc,newc);
       fill(image,i,j-1,oldc,newc);
       fill(image,i,j+1,oldc,newc); 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int oldc = image[sr][sc];
         if(newColor != oldc)
         fill(image,sr,sc,oldc,newColor);
         return image;
    }
};