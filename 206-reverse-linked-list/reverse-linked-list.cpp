
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp = head;
        ListNode*prev =NULL;

        while(temp!=nullptr)
        {
            ListNode*curr= temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
};