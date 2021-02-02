#include<stdio.h>
#include<stdlib.h>
struct Dnode
{
int data;
struct Dnode *prev, *next
};
struct Dnode* head=NULL;
void add_at_beg(struct Dnode** p,int data);
void add_at_pos(struct Dnode** p,int data,int pos);
void add_at_end(struct Dnode** p,int data);
void add_before(struct Dnode** p,int data,int item);
void add_after(struct Dnode** p,int data,int item);
void del_at_beg(struct Dnode** p);
void del_at_pos(struct Dnode** p,int pos);
void del_at_end(struct Dnode** p);
void reverse_itr(struct Dnode** p);
void reverse_rec(struct Dnode* p);
void display(struct Dnode* p);
int main()
{
  /*  add_at_pos(&head,1,1);
     add_at_pos(&head,12,1);
    add_at_pos(&head,14,1);
    add_at_pos(&head,100,100);
    add_at_pos(&head,2,2);
    add_at_pos(&head,4,4);
    display(head);
  /*   add_before(&head,211,0);
     del_at_beg(&head);
     del_at_pos(&head,4);
     display(head);
     del_at_pos(&head,1);
     display(head);
     del_at_pos(&head,2);
     display(head);
     del_at_pos(&head,1);
     display(head); */

   /*  del_at_end(&head);
     display(head);
     del_at_end(&head);
     display(head);
     del_at_end(&head);
     display(head);
     del_at_end(&head);
     display(head); */
   /*  reverse_itr(&head);
     display(head);
     reverse_rec(head);
     display(head); */
     test(&head);
    return 0;
}
void add_at_beg(struct Dnode** p,int data)
{
     struct Dnode* temp=(struct Dnode*)malloc(sizeof(struct Dnode));
     temp->data=data;
     temp->prev=NULL;
     temp->next=*p;
     *p=temp;
    (*p)->prev=temp;
}

void add_at_pos(struct Dnode** p,int data,int pos)
{
    /* List is : 12 -> 13 -> 19
       add 17 at pos = 1,
       List is : 17 -> 12 -> 13 -> 19
    */

    struct Dnode* temp=(struct Dnode*)malloc(sizeof(struct Dnode));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;

    if(*p==NULL)
    *p=temp;

    else if(pos==1){
     temp->next=*p;
    (*p)->prev=temp;
    *p=temp;
    }
    else
    {   struct Dnode* ptr=*p;
        while(pos>2 && ptr!=NULL){
            ptr=ptr->next;
            pos--;
            if(ptr==NULL){
                free(temp);
                printf("Invalid pos\n");
                return;
            }
        }

            temp->next=ptr->next;
            ptr->next=temp;
            temp->prev=ptr;
            if(temp->next!=NULL){
                temp->next->prev=temp;
            }
    }
}
void add_at_end(struct Dnode** p,int data)
{
     struct Dnode *temp,*ptr;
     temp=(struct Dnode*)malloc(sizeof(struct Dnode));
     ptr=*p;
     temp->data=data;
     temp->next=NULL;
     if(ptr==NULL){
        *p=temp;
         temp->prev=NULL;
     }
     else{
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      temp->prev=ptr;
      ptr->next=temp;
     }
}
void add_after(struct Dnode** p,int data, int item)
{
    struct Dnode *temp,*ptr;
    temp=(struct Dnode*)malloc(sizeof(struct Dnode*));
    temp->data=data;
    ptr=*p;
    while(ptr!=NULL){

        if(ptr->data==item){
            temp->next=ptr->next;
            temp->prev=ptr;
            ptr->next=temp;
            if(temp->next!=NULL)
                temp->next->prev=temp;
            return;
        }
        ptr=ptr->next;
    }
    printf("%d is not found in the list\n",item);
}
void add_before(struct Dnode** p,int data, int item)
{
    struct Dnode *temp,*ptr;
    temp=(struct Dnode*)malloc(sizeof(struct Dnode));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    ptr=*p;

    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            if(ptr->prev==NULL){
                temp->prev=NULL;
                *p=temp;
            }
            else{
                ptr->prev->next=temp;
                temp->prev=ptr->prev;
             }

         temp->next=ptr;
         ptr->prev=temp;
         return;
        }
        ptr=ptr->next;
    }
    printf("%d is not found in the list\n",item);
}
void del_at_beg(struct Dnode** p)
{
    if(*p==NULL)
        printf("List is empty\n");
    else
        {
            struct Dnode* temp=*p;
            *p=(*p)->next;
            (*p)->prev=NULL;
            free(temp);
        }
}

void del_at_pos(struct Dnode** p,int pos)
{
    struct Dnode* ptr=*p;

    if(*p==NULL)        //for empty list
     printf("List is empty\n");

    else if(ptr->next==NULL){ // deletion of only node
        struct Dnode *temp=*p;
        *p=(*p)->next;
        free(temp);
    }
    else if(pos==1){ // Deletion of first node
        struct Dnode* temp=*p;
        *p=(*p)->next;
        (*p)->prev=NULL;
        free(temp);
    }
    else{ // Deletion in between or of last node
        struct Dnode* temp;
        while(pos>1 && ptr!=NULL){
            ptr=ptr->next;
            pos--;
        }
        if(pos==1){
        temp=ptr; //node to be deleted
        if(ptr->next!=NULL){
         ptr->next->prev=ptr->prev;
        }
        ptr->prev->next=ptr->next;
        free(temp);
        }
        else printf("Invalid pos\n");
    }
}
void del_at_end(struct Dnode** p)
{    struct Dnode* ptr=*p;
    if(ptr==NULL)
        printf("List is empty\n");
    else if(ptr->next==NULL){
        struct Dnode* temp;
        temp=ptr;
        free(temp);
        *p=NULL;
    }
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        struct Dnode* temp;
        temp=ptr;
        ptr->prev->next=NULL;
        free(temp);
    }
}
void reverse_itr(struct Dnode** p)
{   //*p denotes head
    struct Dnode *p1,*p2;
    p1=*p;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL){
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    *p=p1;
}
void reverse_rec(struct Dnode* p)
{
    if(p->next==NULL){
        head=p;
        p->next=p->prev;
        p->prev=NULL;
        return;
    }
    reverse_rec(p->next);
    struct Dnode* ptr;
    ptr=p->next;
    p->next=p->prev;
    p->prev=ptr;
}
void display(struct Dnode* p)
{
  struct Dnode* ptr=p;
  if(ptr==NULL){
    printf("List is empty\n");
    return;
  }
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}

