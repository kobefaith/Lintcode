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
    ListNode *findmiddle(ListNode *head){
        if (head == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                head->next = left;
                left = left->next;
            }else{
                head->next = right;
                right = right->next;
            }
             head = head->next;
        }
        if(left != NULL){
            head->next = left;
        }else{
            head->next = right;
        }
        return dummy->next;
    }
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *middle = findmiddle(head);
        ListNode *right = sortList(middle->next);
        middle->next = NULL;
        ListNode *left = sortList(head);
        return merge(left,right);
    }
};