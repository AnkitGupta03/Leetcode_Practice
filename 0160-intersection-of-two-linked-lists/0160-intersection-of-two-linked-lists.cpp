/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> mpp;
        ListNode *temp = headA;
        while(temp){
            mpp[temp] = 1;
            temp = temp -> next;
        }
        temp = headB;
        while(temp){
            if(mpp[temp] == 1) return temp;
            temp = temp -> next;
        }
        return nullptr;
    }
};