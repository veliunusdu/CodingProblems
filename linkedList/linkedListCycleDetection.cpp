#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// HashSet
class Solution{ 
    public:
        bool hasCycle(ListNode* head){
            std::unordered_set<ListNode*> seen;
            ListNode* cur = head;
            while(cur) {
                if(seen.find(cur) != seen.end()){
                    return true;
                }
                seen.insert(cur);
                cur = cur->next;
            }
            return false;
        }
    };


// Fast and slow pointers
class Solution2{
    public:
        bool hasCycle(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast -> next != nullptr){
                slow = slow -> next;
                fast = fast -> next -> next;

                if(fast == slow){
                    return true;
                }
            }
            return false;
        }
};