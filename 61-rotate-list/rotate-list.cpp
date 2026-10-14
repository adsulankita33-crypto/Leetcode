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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL||k==0){
            return head;
        }
        ListNode*temp=head;
        int length=1;
        while(temp->next!=NULL){
            temp=temp->next;
            length++;
        }
        k=k%length;
        if(k==0){
            return head;
        }
        temp->next=head;
        ListNode*newNode=head;
        for(int i=1;i<length-k;i++){
            newNode=newNode->next;
        }
        ListNode*newHead=newNode->next;
        newNode->next=NULL;
        return newHead;
    }
};