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
    	if(fast->next != NULL && fast->next->next == NULL){
    		return slow;
    	}
    	while(fast != NULL && fast->next != NULL){
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	return slow;
    }  
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return ;
        }
        ListNode *middle = findmiddle(head);
        ListNode *end = middle->next;
        middle->next = NULL;
        ListNode *second = reverse(end);
        ListNode *first = head;
        ListNode *first_follow = first->next;
        ListNode *second_follow;
        while(first != NULL){
            if(second != NULL){
                second_follow = second->next;
		    }else{
		        break;
			}
            first->next = second;
            first = second;
            second = second_follow;
            if(first_follow != NULL){
                first->next = first_follow;
		    }else{
		        break;
		    }
            first = first->next;
            first_follow = first_follow->next;
        }
    }
};