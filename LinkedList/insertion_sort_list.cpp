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
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sorted_head = new ListNode(0);
        ListNode *node = NULL, *temp = NULL;
        while(head)
        {
            node = sorted_head;
            while(node->next&&node->next->val<head->val)//找到比
            {
                node = node->next;
            }
            temp = head->next;
            head->next = node->next;
            node->next = head;
            head = temp;
        }
        return sorted_head->next;
    }
};