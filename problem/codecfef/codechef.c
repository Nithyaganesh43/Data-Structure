
bool isPalindrome(struct ListNode* head) {
    int count = 0;
    struct ListNode *temp=head;
    struct ListNode *temp1=head;
    struct ListNode *temp2=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
while(count/2--){
     while(temp2->next!=NULL){
        temp2=temp2->next;
        }
        if(temp1->val==temp2->val){
            temp1=temp1->next;
            temp2->next=NULL;
        }else{
            return false;
        }

}
return true;
}
    
