void reverse(){
    if(tail==NULL || tail->next==tail){
        return;
    }else{
        node *curt=tail->next;
        do{
            node *next=curt->next;
            curt->next=curt->prev;
            curt->prev=next;
            curt=next;
        }while(curt!=tail->next);
        tail=tail->next;
    }
}