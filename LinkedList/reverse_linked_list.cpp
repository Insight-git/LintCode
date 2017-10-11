/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */

    ListNode * reverse(ListNode * head) {
    	ListNode *new_head = new ListNode(0);
    	ListNode *temp = NULL;
        while(head)
        {
        	temp = head->next;
        	head->next = new_head->next;
        	new_head->next = head;
        	head = temp;
        }
        return new_head->next;
    }
};