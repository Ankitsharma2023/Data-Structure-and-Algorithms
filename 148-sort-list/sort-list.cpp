class Solution {
public:
    
      ListNode* findMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
   
    ListNode* mergesortList(ListNode* left, ListNode* right) {

        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(left != nullptr && right != nullptr) {

            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if(left != nullptr) {
            temp->next = left;
        }

        if(right != nullptr) {
            temp->next = right;
        }

        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
         if(head==nullptr || head->next==nullptr) return head;

         ListNode*middle = findMiddle(head);
         ListNode*right = middle->next;
         middle->next= nullptr;
         ListNode*left = head;

         left = sortList(left);
         right = sortList(right);
         
         return mergesortList(left,right);
    }
};