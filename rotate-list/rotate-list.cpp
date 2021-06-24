class Solution {
public:
   
   int nodeCount(ListNode* head)
   {
      int cnt = 0;
      while (head)
      {
         cnt++;
         head=head->next;
      }
      return cnt;
   }
   ListNode* rotateRight(ListNode* head, int k) {
      if(!head) return head;
       int n = nodeCount(head);
      k = k%n;
      k = n-k;

      ListNode* oldhead = head;
      ListNode* newhead = head;
      ListNode* end = head;
      int pos = 0;
      while(end->next) end = end->next;
      end->next = oldhead;

      for(int i=0;i<k-1;i++)
      {
         newhead = newhead->next;
      }

      ListNode* tptr = newhead;
      newhead = newhead->next;
      tptr->next = NULL;
      return newhead;
   }
};