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
    ListNode* sortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        vector<int> a;
        ListNode* temp=head;
        while(temp!=nullptr){
            a.push_back(temp->val);
            temp=temp->next;
        }

        sort(a.begin(),a.end());



        ListNode* h=head;
        for(int i=0; i<a.size(); i++){
            h->val=a[i];
            h=h->next;
        }
        h=head;
        return head;
    }
};