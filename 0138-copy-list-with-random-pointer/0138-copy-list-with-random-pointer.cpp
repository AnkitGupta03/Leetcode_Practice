/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //optimal solution without using extra space.
        Node *temp = head;
        //step 1. creating copyNodes and inserting them between the original nodes
        while(temp){
            Node *copyNode = new Node(temp->val);
            copyNode -> next = temp -> next;
            temp -> next = copyNode;
            temp = temp -> next -> next;
        }
        //step2. attaching random pointers in copyNodes.
        temp = head;
        while(temp){
            Node *copyNode = temp -> next;
            if(temp -> random) copyNode -> random = temp -> random -> next;
            else copyNode -> random = nullptr;
            temp = temp -> next -> next;
        }
        //step 3. attaching next pointers in copyNodes.
        temp = head;
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;
        while(temp){
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;
            res = res -> next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }
};