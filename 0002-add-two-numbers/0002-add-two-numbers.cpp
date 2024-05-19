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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *curr = dummyNode;
        while(l1 || l2){
            if(l1 && l2){
                int newval1 = (l1 -> val + l2 -> val + carry);
                int newval = newval1 % 10;
                ListNode *newNode = new ListNode(newval);
                curr -> next = newNode;
                curr = curr -> next;
                carry = 0;
                if((newval1) > 9) carry = 1;
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if(l1 == nullptr){
                int newval1 = (l2 -> val + carry);
                int newval = newval1 % 10;
                ListNode *newNode = new ListNode(newval);
                curr -> next = newNode;
                curr = curr -> next;
                carry = 0;
                if((newval1) > 9) carry = 1;
                l2 = l2 -> next;
            }
            else if(l2 == nullptr){
                int newval1 = (l1 -> val + carry);
                int newval = newval1 % 10;
                ListNode *newNode = new ListNode(newval);
                curr -> next = newNode;
                curr = curr -> next;
                carry = 0;
                if((newval1) > 9) carry = 1;
                l1 = l1 -> next;
            }
        }
        if(carry == 1){
            ListNode *newNode = new ListNode(carry);
            curr -> next = newNode;
            curr = curr -> next;
        }
        return dummyNode -> next;
    }
};