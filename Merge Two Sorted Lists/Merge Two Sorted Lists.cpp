/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                head->next = l1;
                l1 = l1->next;
            }else{
                head->next = l2;
                l2 = l2->next;
            }
             head = head->next;
        }
        if(l1 != NULL){
            head->next = l1;
        }else{
            head->next = l2;
        }
        return dummy->next;
    }
};
