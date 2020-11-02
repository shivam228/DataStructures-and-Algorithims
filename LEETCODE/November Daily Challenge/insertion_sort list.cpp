class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode *temp  =head;
        ListNode *x = head->next ;
        
        while(x!=NULL)
        {
            int val = x->val;
            ListNode *y = head;
                while(y!=x && y->val<val)
                {
                y = y->next;    
                }
            while(y!=x) 
            {
			int prv = y->val;
			y->val = val;
			val = prv;

			y = y->next;
		}
		y->val =  val;

        x = x->next;
        }
        return head;
        
    }
};