#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute Force
class Solution{
    public:
    void reorderList(ListNode* head){
        if(!head) return;

        std::vector<ListNode*> nodes;
        ListNode* cur = head;
        while(cur){
            nodes.push_back(cur);
            cur = cur->next;
        }
        int i = 0, j = nodes.size()- 1;
        while(i < j){
            nodes[i] -> next = nodes[j];
            i++;
            if(i >= j) break;
            nodes[j] -> next = nodes[i];
            j--;
        }
        nodes[i] -> next = nullptr;
    }
};


// Reverse and Merge
class Solution2{
    public:
    void reorderList(ListNode* head){
        if (head == nullptr || head->next == nullptr) return;
        ListNode* low = head;
        ListNode* fast = head -> next;
        while(fast != nullptr && fast -> next != nullptr){
            low = low -> next;
            fast = fast -> next -> next;
        }
        ListNode* prev = nullptr;
        ListNode* cur = low -> next;
        low->next = nullptr;
        while(cur != nullptr){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};