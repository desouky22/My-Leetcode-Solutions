/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* , int> mp;
        while(headA){mp[headA]++;headA=headA->next;}
        while(headB){
            mp[headB]++;
            if(mp[headB] == 2){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};