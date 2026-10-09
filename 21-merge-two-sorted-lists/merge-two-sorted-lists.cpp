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
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode*t1=list1;
        ListNode*t2=list2;
        if(t1->val<=t2->val){
            t1->next=mergeTwoLists(t1->next,t2);
            return t1;
        }
        else{
            t2->next=mergeTwoLists(t1,t2->next);
            return t2;
        }
        return t1;
    }
};