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
        
        vector<int>result;

        int remember = 0;

        while(true) {

            if(h1 == nullptr && h2 == nullptr) {
                if(remember == 1) {
                    result.push_back(1);
                }
                break;
            }

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
                result.push_back(sum-10);
                remember = 1;
            } else {
                result.push_back(sum);
                remember = 0;
            }

            if(h1 != nullptr) {
                h1 = h1->next;
            }

            if(h2 != nullptr) {
                h2 = h2->next;
            }
        }

        ListNode *results = new ListNode();
        ListNode *head = results;
        int n = result.size();

        for(int i = 0; i < n; i++) {
            head->val = result[i];
            if(i == n-1) {
                break;
            }
            head->next = new ListNode();
            head = head->next;
        }
        /*
        head = results;
        
        while(head != nullptr) {
            //cout<<head->val<<" ";
            head = head->next;
        }
        //cout<<endl;
        */
        return results;
    }
};