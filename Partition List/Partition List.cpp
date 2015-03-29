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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy_less = new ListNode(-1);
        ListNode *dummy_great = new ListNode(-1);
        ListNode *less = dummy_less;
        ListNode *great = dummy_great;
         if (head == NULL){
             return NULL;
         }
        while(head != NULL){
            if (head->val < x){
                less->next = head;
                less = head;
            }else{
                great->next = head;
                great = head;
            }
            head = head->next;
        }
        great->next = NULL;
        less->next = dummy_great->next;
        return dummy_less->next;
    }
};