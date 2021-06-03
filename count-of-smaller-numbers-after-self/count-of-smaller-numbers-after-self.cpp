class Solution {
public:
    int counts[100000];
    vector< pair< int  , int > > v;

    void merge(int low,int mid,int high)
    {
      vector< pair< int  , int > > temp;      
      int i = low,j=mid+1;
      while(i<=mid && j<=high)
      {
         if(v[i].first>v[j].first)
         {
            temp.push_back(v[i]);
            counts[v[i].second]+=(high-j+1);
            i++;
         }else
         {
            temp.push_back(v[j]);
            j++;
         }
      }

      while(i<=mid)
      {
         temp.push_back(v[i]);
         i++;
      }
      while(j<=high)
      {
         temp.push_back(v[j]);
         j++;
      }

      i = low;
      for(auto k:temp) v[i]=k , i++;
    }

    void mergesort(int low,int high)
    {
      if(low<high)
      {
         int mid = low + (high-low)/2;
         mergesort(low,mid);
         mergesort(mid+1,high);
         merge(low,mid,high);
      }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        memset(counts,0,sizeof(counts));
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        mergesort(0,n-1);
        vector< int >ans;
        for(int i=0;i<n;i++) ans.push_back(counts[i]);
        return ans;
    }
};