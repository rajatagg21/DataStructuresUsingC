#include<stdio.h>
#include<stdlib.h>
struct Snode{
int data;
struct Snode* next;
};
struct Snode* head=NULL;
struct Snode* create();
void add_at_beg(struct Snode** p,int data);
void add_at_pos(struct Snode** p,int data,int pos);
void add_at_end(struct Snode** p,int data);
void del_at_beg(struct Snode** p);
void del_at_pos(struct Snode** p,int pos);
void del_at_end(struct Snode** p);
void reverse_itr(struct Snode** p);
void reverse_rec(struct Snode* p);
void display(struct Snode* p);

int main()
{
     add_at_beg(&head,1);
     add_at_beg(&head,2);
     add_at_beg(&head,3);
     add_at_end(&head,4);
     add_at_end(&head,5); 
     add_at_pos(&head,10,1);
   //  add_at_pos(&head,12,2);
     add_at_pos(&head,13,3);
     display(head);
  /*   del_at_beg(&head);
     display(head);
     del_at_end(&head);
     display(head);
     del_at_pos(&head,3);
     display(head);
     del_at_pos(&head, 4);
     display(head);
     del_at_pos(&head,2);
     display(head);
     del_at_pos(&head, 82);  */
     reverse_rec(head);
     display(head);
     return 0;
}
 struct Snode* create()  // create a Snode
{
 struct Snode* temp=(struct Snode*)malloc(sizeof(struct Snode));
 if(temp==NULL) return NULL;
 return temp;
}

void add_at_beg(struct Snode** head,int data) //insertion at beginning
{
   struct Snode* temp=create();
   if(temp==NULL)
    printf("\nmemory not available\n");
   temp->data=data;
   temp->next=*head;
   *head=temp;
}

void add_at_pos(struct Snode** head,int data, int pos)  //insertion at given position
{
  struct Snode* ptr=*head,*temp;
  temp=create();
  if(temp==NULL)
    printf("memory not available\n");
  temp->data=data;
  temp->next=NULL;
  if(pos==1)
  {
      temp->next=*head;
      *head=temp;
  }
  else{
  while(pos>2){
    ptr=ptr->next;
    pos--;
    if(ptr==NULL){
        printf("Invalid pos\n");
        free(temp);
        return;
    }
  }
  if(pos==2){
  temp->next=ptr->next;
  ptr->next=temp;}
 }
}

void add_at_end(struct Snode** head, int data)  //insertion at the end
{
    struct Snode *ptr, *temp;
    ptr=*head; temp=create();
    if(temp==NULL)
    printf("memory not available\n");
    temp->data=data;
    temp->next=NULL;

    if(ptr==NULL)
      head=temp;

    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    temp->next=NULL;
}

void del_at_beg(struct Snode** head) //deletion in the beginning
{
    struct Snode *ptr=*head,*temp;
    if(ptr==NULL){
        printf("List is Empty\n");
    }
    else{
        temp=*head;
       *head = temp->next;
        free(temp);
    }
}

void del_at_end(struct Snode** head) // deletion in the end
{
    struct Snode *ptr=*head;
    if(ptr==NULL)
        printf("Invalid - list is empty.\n");
    else if(ptr->next==NULL)
    {
        free(ptr);
        *head=NULL;
    }
    else{
        while(ptr->next->next!=NULL)
            ptr=ptr->next;

        struct Snode* temp=ptr->next;
        ptr->next=temp->next;
        free(temp);
    }
}

void del_at_pos(struct Snode** head, int pos) // deletion in any given position
{
    struct Snode* ptr=*head;
    if(pos<=0 || ptr==NULL)
        printf("Invalid - list is empty or pos is out of range\n");
    else if(pos==1 && ptr->next==NULL)
    {
        free(ptr);
        *head=NULL;
    }
    else{
        while((pos-2)>0 && ptr->next->next!=NULL){
            ptr=ptr->next;
            pos--;
        }
        if(pos-2==0){
        struct Snode* temp = ptr->next;
        ptr->next=temp->next;
        free(temp);
        }
        else
            printf("Invalid pos\n");

    }

}
void display(struct Snode* head) // traverse the list
{
    struct Snode* ptr=head;
    while(ptr!=NULL)
    {
      printf("%d  ",ptr->data);
      ptr=ptr->next;
    }
    printf("\n");
}

void reverse_itr(struct Snode** head) //reversing the list(iterative version)
{

    struct Snode *curr,*prev=NULL,*ptr;
    curr=*head;
    while(curr!=NULL){
     ptr=curr->next;
     curr->next=prev;
     prev=curr;
     curr=ptr;
    }
    *head=prev;
}

void reverse_rec(struct Snode* p)  //reversing the list(recursive version)
{
   if(p->next==NULL){
    head=p;
    return;
   }

   reverse_rec(p->next);

   struct Snode* q=p->next;
   q->next=p;
   p->next=NULL;
}


























