class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(auto li: lists){
            while(li){
                arr.push_back(li->val);
                li = li->next;
            }
                
        }
        ListNode *head;
        ListNode *newNode = head = new ListNode(0);
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size();i++){
            newNode->next = new ListNode(arr[i]);
            newNode =newNode->next;
        }
        return head->next;
    }
};
