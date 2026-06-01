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
        ListNode*t1= list1;
        ListNode*t2= list2;
        vector<int>ans;
        while(t1){
            ans.push_back(t1->val);
            t1=t1->next;
        }
        while(t2){
            ans.push_back(t2->val);
            t2=t2->next;
        }
        sort(ans.begin(),ans.end());
         ListNode dummy(-1);
        ListNode* temp = &dummy;

        for(int x : ans) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }return dummy.next;
    }
};
