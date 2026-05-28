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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        cout<<"Start!"<<endl;

        if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *result = new ListNode();
        ListNode *head = result;

        int value1, value2;
        while(true) {

            if(head1 != nullptr) {
                value1 = head1->val;
            } else {
                value1 = 101;
            }

            if(head2 != nullptr) {
                value2 = head2->val;
            } else {
                value2 = 101;
            }

            if(value1 < value2) {
                head->val = value1;
                //cout<<value1<<endl;

                if(head1 != nullptr) {
                    head1 = head1->next;
                }
            
            } else {
                head->val = value2;
                //cout<<value2<<endl;

                if(head2 != nullptr) {
                    head2 = head2->next;
                }
             
            }

            if(head1 == nullptr && head2 == nullptr) {
                break;
            }
            head->next = new ListNode();
            head = head->next;

        }
        
        delete head1, head2;
        return result;
    }
};