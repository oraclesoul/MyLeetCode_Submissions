class NumArray {
public:
        static const int N = 1e6;
        int seg[N];
        int n;

        // build 
        void build(vector<int>&a,int v , int low , int high)
        {
            if(low==high)
            {
                seg[v] = a[low];
                return;
            }
            int mid = low + (high-low)/2;
            build(a,2*v+1,low,mid);
            build(a,2*v+2,mid+1,high);
            seg[v] = seg[2*v+1] + seg[2*v+2];
            return; 
        }

        // query

        int query(int v,int low,int high,int qlow,int qhigh)
        {
            if(qlow>qhigh) return 0;
            if(qlow==low && high==qhigh) return seg[v];
            int mid = low + (high-low)/2;
            return query(2*v+1,low,mid,qlow,min(qhigh,mid))+query(2*v+2,mid+1,high,max(qlow,mid+1),qhigh);
        }

        // update
        void updateval(int v,int low , int high , int pos , int val)
        {
            if(low == high)
            {
                seg[v] = val;
                return; 
            }
            int mid =  low + (high-low)/2;
            if(pos<=mid)
            {
                updateval(2*v+1,low,mid,pos,val);
            }else
            {
                updateval(2*v+2,mid+1,high,pos,val);
            }
            seg[v] = seg[2*v+1] + seg[2*v+2];
        }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        memset(seg,0,sizeof(seg));
        build(nums,0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        updateval(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */