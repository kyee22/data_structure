        q=(struct node*)malloc(sizeof(struct node));
        q->next=NULL;
        q->data=lst[i];
        if(list==NULL){
            list=p=q;
        }
        else{
            p->next=q;
            p=p->next;
        }