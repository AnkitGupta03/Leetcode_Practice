class Node{
public:
    string val;
    Node *forward;
    Node *back;
    Node(string x){
        val = x;
        forward = nullptr;
        back = nullptr;
    }
};
class BrowserHistory {
public:
    Node *current;
    BrowserHistory(string homepage) {
       current = new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode = new Node(url);
        newNode -> back = current;
        current -> forward = newNode;
        current = newNode;
    }
    
    string back(int steps) {
        while(current->back && steps>0){
            steps--;
            current = current -> back;
        }
        return current->val;
    }
    
    string forward(int steps) {
        while(current->forward && steps>0){
            steps--;
            current = current -> forward;
        }
        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */