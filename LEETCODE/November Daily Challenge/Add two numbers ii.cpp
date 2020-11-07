class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr  =l1;
         ListNode* prev  =NULL;
         ListNode* next  =NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l1 = prev;
         curr =l2;
         prev  =NULL;
         next  =NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l2 = prev;
        
        ListNode* head = NULL;
        ListNode* x  = NULL;
         ListNode* temp =NULL;
        int carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int sum =0;
            if(l1!=NULL)
                sum = sum +l1->val;
            if(l2!=NULL)
                sum = sum+l2->val;
            sum  = sum+carry;
            if(sum>9)
            carry  =1;
            else 
                carry =0;
            sum = sum%10;
             temp = new ListNode(sum);
            if(head==NULL)
                head = temp;
            else
                x->next = temp;
            x = temp;
            if(l1!=NULL)
                l1 = l1->next;
            if(l2!=NULL)
            l2 = l2->next;
            
        }
        if(carry!=0)
        {
            x->next = new ListNode(carry);
        }
        curr =head;
         prev  =NULL;
         next  =NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};