#include <stdio.h>
#include <stdlib.h>
/*
  入力する年齢を小さい順で並べる
   連鎖リスへのデータの整列挿入（頭なし）
*/
struct age_list{
  int age;
  struct age_list *next;
};
// malloc
struct age_list *get_cell(){
 struct age_list *p;
 if(NULL == (p = (struct age_list *)malloc(sizeof(struct age_list)))){
	printf("malloc error \n");
	exit(1);
 }	
 return p;
}
// add list

struct age_list *add_list(int year, struct age_list *head){
  struct age_list *p, *q, *tmp, *cell;
  p = head;
  cell = get_cell();
  cell->age = year;
  cell->next = NULL;
  // head  null
  if(NULL == p){
    p = cell;
  }else{
     // q
    if(NULL != p->next)
       q = p->next;
    if(year <= p->age){ // before head
        cell->next = p;
        p = cell;
     }else{
        if(NULL == p->next || year <= q->age){ // after p
           cell->next=NULL==p->next?NULL:q; 
           p->next = cell;
            
        }else{
           while(NULL != q && year > q->age){
              tmp = q;
              q = q->next;
           }
            cell->next = q;
            tmp->next=cell;
         // if(NULL == q){
          //  tmp->next = cell;
          //}else{
           // tmp->next= cell;
           // cell->next = q;
         // }
        
        }
     }
  }

  return p;
}

void print_struct(struct age_list *list){
   struct age_list *p;
   p = list;
   if(NULL == p){
     printf("list null");
     exit(1);
   }
 printf("the age's list is:\n");
  do{
    printf("%d\t", p->age);
    p = p->next;
   }while(NULL != p);
 printf("\n");
}
int main(){
  struct age_list *p=NULL;
  int age = 0;
  printf("input the age(exit by using negative value):\n");
  while(age >= 0){
    scanf("%d", &age);
    p = add_list(age, p);
    print_struct(p);
  }
}
