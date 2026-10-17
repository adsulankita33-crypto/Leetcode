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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            cout<<"LL is Empty:";
            return head;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==NULL){
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode*deleteNode=slow->next;
        slow->next=deleteNode->next;
        delete deleteNode;
        return head;
    }
};