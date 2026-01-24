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
        ListNode* removeNthFromEnd(ListNode* head, int n){
            std::vector<ListNode*> nodes;
            ListNode* cur = head;
            while (cur != nullptr){
                nodes.push_back(cur);
                cur = cur->next;
            }
            int removeIndex = nodes.size() - n;
            if(removeIndex == 0){
                return head->next;
            }
            nodes[removeIndex - 1]->next = nodes[removeIndex]->next;
            return head;
        }
};


// Two Pointer
class Solution1{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n > 0) {
            right = right->next;
            n--;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};