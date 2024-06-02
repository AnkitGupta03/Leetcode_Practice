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
    ListNode* reverse(ListNode* head) {
        ListNode *temp = head, *prev = nullptr;
        while(temp){
            ListNode *front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* findKthnode(ListNode *temp, int k){
        while(temp && k > 1){
            k--;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *nextNode = nullptr, *prevNode = nullptr;
        while(temp){
            ListNode *kthNode = findKthnode(temp, k);
            if(kthNode == nullptr){
                break;
            }
            nextNode = kthNode -> next;
            kthNode -> next = nullptr;
            ListNode *newHead = reverse(temp);
            if(temp == head){
                head = newHead;
            }
            else{
                prevNode -> next = newHead;
            }
            prevNode = temp;
            temp -> next = nextNode;
            temp = nextNode; 
        }
        return head;
    }
};