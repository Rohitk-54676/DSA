#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtBegining(struct Node** head,int val){
    struct Node* newNode=createNode(val);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}
void insertAtLast(struct Node** head,int val){
    struct Node* newNode=createNode(val);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAtPosition(struct Node** head,int val,int pos){
    struct Node* newNode=createNode(val);
    if(*head==NULL && pos==1){
        *head=newNode;
        return;
    }
    if(*head==NULL && pos>1){
        printf("Invalid Postion");
        return;
    }
    if(pos==1){
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    int i=1;
    while(temp!=NULL && i<pos-1){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("Invalid position");
        return;
    }
    if(temp->next==NULL){
        temp->next=newNode;
        newNode->prev=temp;
        return;
    }
    temp->next->prev=newNode;
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;

}
void deleteFromBegining(struct Node** head){
   if(*head==NULL){
    printf("List is already empty");
    return;
   }
   if((*head)->next==NULL){
    *head=NULL;
    return;
   }
   struct Node* temp=*head;
   *head=(*head)->next;
   if(*head!=NULL){
       (*head)->prev=NULL;
    }
    free(temp);
}
void deleteFromLast(struct Node** head){
    if(*head==NULL){
     printf("List is already empty");
     return;
    }
    if((*head)->next==NULL){
     *head=NULL;
     return;
    }
    struct Node* temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    
}
void deleteFromPosition(struct Node** head,int pos){
    if(*head==NULL){
     printf("List is already empty");
     return;
    }
    if((*head)->next==NULL && pos==1){
        *head=NULL;
        return;
    }
    if((*head)->next==NULL && pos>1){
        printf("Invalid pos");
        return;
    }
    if(pos==1){
        *head=(*head)->next;
        (*head)->prev=NULL;
        return;
    }
    struct Node* temp=*head;
    struct Node* prev=NULL;
    int i=1;
    while(temp!=NULL && i<pos){
        prev=temp;
        i++;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position");
        return;
    }
    if (temp->next != NULL) {
    temp->next->prev = prev;
    }
    prev->next=temp->next;

}
void display(struct Node* head){
   if(head==NULL){
        printf("LIST IS EMPTY \n\n\n");
        return;
    }
    printf("LIST: ");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n\n\n");
}
int main(){
    struct Node* head=NULL;
    int choice;
    int val;
    int pos;
    while(choice!=8){
        printf("ENTER YOUR CHOICE \n 1.insert at begining \n 2.insert at last\n3.insert at position\n4.delete from begining \n5.delete from end\n6.deleteing from at given posotion\n7.display list\n8.exiting\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        printf("You choose insert at begining\n Enter value");
        scanf("%d",&val);
        insertAtBegining(&head,val);
        break;
        case 2:
        printf("You choose insert at last\n Enter value");
        scanf("%d",&val);
        insertAtLast(&head,val);
        break;
        case 3:
        printf("You choose insert at position\n Enter value");
        scanf("%d",&val);
        printf("\nenter Position");
        scanf("%d",&pos);
        insertAtPosition(&head,val,pos);
        break;
        case 4:
        printf("You choose to delete element from the begining \n");
        deleteFromBegining(&head);
        break;
        case 5:
        printf("You choose delete from last");
        deleteFromLast(&head);
        break;
        case 6:
        printf("You choose to delete st position\nenter the postion");
        scanf("%d",&pos);
        deleteFromPosition(&head,pos);
        break;
        case 7:
        printf("You choose to display\n\n\n");
        display(head);
        break;
        case 8:
        return 0;
        break;
        default:
        printf("XXXXX Enter a Valid opertions XXXX\n");
        break;
    }
    }
    return 0;
}