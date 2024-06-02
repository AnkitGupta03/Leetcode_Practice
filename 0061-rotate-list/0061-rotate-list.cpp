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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode *tailNode = head;
        int n = 1;
        while(tailNode -> next){
            n++;
            tailNode = tailNode -> next;
        }
        tailNode -> next = head;
        int x = n - (k%n);
        ListNode *temp = head;
        int count = 1;
        while(count < x){
            count++;
            temp = temp -> next;
        }
        head = temp -> next;
        temp -> next = nullptr;
        return head;
    }
};