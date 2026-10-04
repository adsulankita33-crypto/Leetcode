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
      ListNode*t1=l1;
      ListNode*t2=l2;
      ListNode*dummyNode=new ListNode(-1);
      ListNode*curr=dummyNode;
      int carry=0;
      while(t1!=0||t2!=0||carry!=0){
        int sum=carry;
        if(t1!=0){
            sum=sum+t1->val;
            t1=t1->next;
        }
        if(t2!=0){
            sum=sum+t2->val;
            t2=t2->next;
        }
        ListNode*newNode=new ListNode(sum%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
      }  
      return dummyNode->next;
    }
};