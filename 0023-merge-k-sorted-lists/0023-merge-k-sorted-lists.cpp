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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto it: lists){
          if(it) pq.push({it->val, it});
        }
        while(!pq.empty()){
            ListNode *nd = pq.top().second;
            pq.pop();
            temp -> next = nd;
            temp = temp -> next;
           if(nd -> next) pq.push({nd->next->val, nd -> next});
        }
        return dummyNode -> next;
    }
};