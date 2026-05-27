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
        ListNode* one=list1;
        ListNode* two=list2;
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(one && two){
            if(one->val>=two->val){
                tail->next=two;
                two=two->next;
            }else{
                tail->next=one;
                one=one->next;
            }
            tail=tail->next;
        }
        if(one)tail->next=one;
        else tail->next=two;
        return dummy->next;
    }
};
