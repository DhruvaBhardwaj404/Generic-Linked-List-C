#include<stdio.h>
#include<stdlib.h>




struct node{
    void *data;
    node *next;
    int is_arr=0;
    int type;
};


//1 = int
//2 =char
//3 =float

int ll_size=0;
node *start,*last;

void addNode(void *data,int s,int is_arr=0,int len=0){
    if(ll_size==0){
        node *new_node;
        new_node= (node*)malloc(sizeof(node));
        start=new_node;
        last=start;
        ll_size++;

        if(is_arr==0){
          switch(s){
            case 1: new_node->type=2;
                    break;

            case 2:new_node->type=1;
                   break;

            case 4:new_node->type=3;
                   break;

            }

            new_node->data=malloc(sizeof(s));
            new_node->data=data;
        }

        else{
            printf("%s",*((char*)data));
            new_node->data=calloc(len,sizeof(char));
            new_node->data=data;
            new_node->is_arr=1;
        }
      }

    else{
       node *last_node,*new_node;
       last_node=last;
       new_node=(node*)malloc(sizeof(node));
       last_node->next=new_node;
       ll_size++;
       last=new_node;

       if(is_arr==0){
         switch(s){
            case 1: new_node->type=2;
                    break;

            case 2:new_node->type=1;
                   break;

            case 4:new_node->type=3;
                   break;

            }
            new_node->data=malloc(sizeof(s));
            new_node->data=data;
       }
       else{
            printf("%c",*((char*)data));
            new_node->data=calloc(len,sizeof(char));
            new_node->data=data;
            new_node->is_arr=1;
       }
    }
}


void traverse(){
    node  *curr;
    curr= start;
    int dat;
    for(int i=0;i<ll_size;i++){
        dat=curr->type;
        if(curr->is_arr==0)
        switch(dat){
            case 1:printf("%d ",*((int*)curr->data));
                    break;

            case 2:printf("%c ",*((char*)curr->data));
                   break;

            case 3:printf("%f ",*((float*)curr->data));
                   break;


        }
        else{
            printf("%s ",(char*)curr->data);
        }
        curr=curr->next;
    }
}


int main(){
    int a=3;
    float b=2.23;
    char c='a';
    char d[10]="hello";
    int e=10;
    addNode(&a,2);
    addNode(&b,4);
    addNode(&c,1);
    addNode(d,1,1,10);
    addNode(&e,2);
    traverse();

}
