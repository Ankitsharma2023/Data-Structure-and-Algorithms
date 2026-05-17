class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;

        while(head != NULL) {

            ListNode* nextNode = head->next;

            head->next = prev;

            prev = head;
            head = nextNode;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return;
        }

        // FIND MIDDLE

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // SPLIT

        ListNode* second = slow->next;
        slow->next = NULL;

        // REVERSE SECOND HALF

        second = reverseList(second);

        // MERGE

        ListNode* first = head;

        while(second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};