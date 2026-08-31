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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = 0;

        while (curr->next != NULL) {

            ListNode* next = curr->next;

            // Check whether current node is a critical point
            bool critical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (critical) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);

                    // Distance from first critical point
                    maxDist = pos - first;
                }

                last = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        if (first == -1 || first == last)
            return ans;

        return {minDist, maxDist};
    }
};