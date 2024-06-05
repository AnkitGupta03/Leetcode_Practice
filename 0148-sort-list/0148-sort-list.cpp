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
    ListNode* findMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* merge(ListNode *head1, ListNode *head2){
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        while(head1 && head2){
            if(head1 -> val <= head2 -> val){
                temp -> next = head1;
                head1 = head1 -> next;
                temp = temp -> next;
            }
            else{
                temp -> next = head2;
                head2 = head2 -> next;
                temp = temp -> next;
            }
        }
        if(head1) temp -> next = head1;
        if(head2) temp -> next = head2;
        return dummyNode -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *middleNode = findMiddle(head);
        ListNode *leftHead = head;
        ListNode *rightHead = middleNode -> next;
        middleNode -> next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead, rightHead);
    }
};