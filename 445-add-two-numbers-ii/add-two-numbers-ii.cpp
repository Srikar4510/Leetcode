/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp){
           ListNode* front = temp->next;
           temp->next = prev;
           prev = temp;
           temp = front;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* dummyNode = new ListNode(0);
        ListNode* temp = dummyNode;
        int carry =0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int x = l1?l1->val : 0;
            int y = l2 ? l2->val :0;
            int sum = x+y+carry;
            carry = sum/10;

            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }

        return reverseList(dummyNode->next);
    }
};