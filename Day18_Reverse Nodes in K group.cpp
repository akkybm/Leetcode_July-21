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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL)
        {
            ListNode* temp = curr;
            int i=0;
            while(temp!=NULL && i<k)
            {
                temp = temp->next;
                i++;
            }
            if(i%k == 0)
            {
                i=0;
                while(curr != NULL && i<k)
                {
                    st.push(curr);
                    curr=curr->next;
                    i++;
                }
                while(!st.empty())
                {
                    if(prev == NULL)
                    {
                        prev = st.top();
                        head = prev;
                        st.pop();
                    }
                    else
                    {
                        prev->next = st.top();
                        st.pop();
                        prev = prev->next;
                    }
                }
            }
            else
            {
                while(curr != NULL)
                {
                    prev->next = curr;
                    curr = curr->next;
                    prev = prev->next;
                }
            }
        }
        prev->next = NULL;
        return head;
    }
};
