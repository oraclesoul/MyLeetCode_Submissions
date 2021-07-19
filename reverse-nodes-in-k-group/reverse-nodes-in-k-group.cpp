class Solution {
public:
    bool rev(int k , int rpos,ListNode* rptr ,int &lpos, ListNode* &lptr)
    {
       if(rpos>k) return true;
       if(!rptr) return false;
       if(rev(k,rpos+1,rptr->next,lpos,lptr))
       {
          if(lpos<rpos)
          {
             swap(rptr->val,lptr->val);
             lpos++;
             lptr = lptr->next;
             return true;
          }
          return false;
                    
       }
       return false;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        while(head)
        {  
           int m = 1;
           ListNode* lptr = head;
           rev(k,1,head,m,lptr);
           for(int i=0;i<k;i++) 
           {
              if(head)
              {
                 head = head->next;
              }
           }
        }
        return ptr;
    }
};