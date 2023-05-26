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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
        
        // declaring head and tail of resultant linked list
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        if(a->val <= b->val){
            head = tail = a;
            a = a->next;
        }
        else{
            head = tail = b;
            b = b -> next;
        }
        // head and tail has been initialised, now we will run a loop, till one of the linked list gets exhausted.
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                tail -> next = a;
                tail = a;
                a = a -> next;
            }
            else{
                tail -> next = b;
                tail = b;
                b = b -> next;
            }
        }
        // now when one of the linked list gets exhausted, link the whole other linked list to the tail.
        if(a == NULL)
            tail -> next = b;
        else
            tail -> next = a;
        
        return head;
    }
};