class Solution {
public:
    int partition( vector< int > &v , int low , int high)
    {
        // taking first element 
        // putting v[low] at its correct position
        int i = low+1;
        for(int j=low+1;j<=high;j++)
        {
            if(v[j]<v[low])
            {
                swap(v[j],v[i]);
                i++;
            }
        }
        swap(v[low],v[i-1]);
        return i-1;
    }

    void quickSort( vector< int > &v , int low , int high)
    {
        if(low<high)
        {
            int pivotIdx = partition(v,low,high);
            quickSort(v,low,pivotIdx-1);
            quickSort(v,pivotIdx+1,high);
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums,0,n-1);
    }
};