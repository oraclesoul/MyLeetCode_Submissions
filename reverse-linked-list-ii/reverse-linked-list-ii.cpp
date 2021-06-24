class Solution {
public:
    queue< int > q;
    int pos = 1;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        if(pos>right) head;
        if(pos<=right && pos>=left)
        q.push(head->val);
        pos++;
        reverseBetween(head->next,left,right);
        pos--;
        if(pos<=right && pos>=left)
        {
            head->val = q.front();
            q.pop();            
        }     
        return head;
    }
};