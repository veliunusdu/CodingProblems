class Node{
    public:
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#include <unordered_map>

// HashMap(two pass)
class Solution{
    public:
    Node* copyRandomList(Node* head){
        std::unordered_map<Node*, Node*> oldToCopy;
        
        Node* cur = head;
        while(cur != NULL){
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while(cur != NULL){
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
        }
        return oldToCopy[head];
    }
};


// Space Optimized II
class Solution2{
    public:
    Node* copyRandomList(Node* head){
        if(!head){
            return nullptr;
        }
        // 1) Interleave copied nodes with original nodes
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        // 2) Assign random pointers for copied nodes
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            } else {
                curr->next->random = nullptr;
            }
            curr = curr->next->next;
        }
        // 3) Separate the lists and restore original list
        curr = head;
        Node* newHead = head->next;
        while(curr){
            Node* copy = curr->next;
            curr->next = copy->next;
            copy->next = (copy->next) ? copy->next->next : nullptr;
            curr = curr->next;
        }

        return newHead;
    }
};