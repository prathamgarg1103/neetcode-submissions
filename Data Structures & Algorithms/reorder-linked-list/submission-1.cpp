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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        // 1) Find middle
        ListNode* mid = getmid(head);

        // 2) Reverse second half
        ListNode* second = reverse(mid->next);
        mid->next = NULL;   // break list

        // 3) Merge two halves
        merge(head, second);
    }

    ListNode* getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2){
        while(l1 && l2){
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;

            l1->next = l2;
            l2->next = t1;

            l1 = t1;
            l2 = t2;
        }
    }

};
