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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *h1 = l1;
        ListNode *h2 = l2;

        ListNode *result = new ListNode();
        ListNode *head = result;

        int remember = 0;

        while(true) {

            int value1, value2;

            if(h1 == nullptr) {
                value1 = 0;
            } else {
                value1 = h1->val;
            }

            if(h2 == nullptr) {
                value2 = 0;
            } else {
                value2 = h2->val;
            }

            int sum = value1+value2;
            if(remember == 1) {
                sum += 1;
            }

            if(sum >= 10) {
                head->val = sum-10;
                remember = 1;
            } else {
                head->val = sum;
                remember = 0;
            }

            if(h1 != nullptr) {
                h1 = h1->next;
            }

            if(h2 != nullptr) {
                h2 = h2->next;
            }

            if(h1 == nullptr && h2 == nullptr) {
                if(remember == 1) {
                    head->next = new ListNode(1);
                    head = head->next;
                }
                break;
            }

            head->next = new ListNode();
            head = head->next;
        }

        
        /*
        head = result;
        
        while(head != nullptr) {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
        */
        return result;
    }
};