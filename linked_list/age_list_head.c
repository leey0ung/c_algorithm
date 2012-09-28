#include <stdio.h>
#include <stdlib.h>
/*
  入力する年齢を小さい順で並べる
   連鎖リスへのデータの整列挿入（頭付き）
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
  struct age_list *p, *q, *cell;
  p = head;
  cell = get_cell();
  cell->age = year;

  if(NULL == p->next){
     cell->next = NULL;
     p->next = cell;
     return p;
  } 
 // q = p;
 // p = p->next;
  do{
    q = p;
    p = p->next;
  } while(NULL != p && year > p->age);
  cell->next = p;
  q->next = cell;
  return head;
}

//create head  
struct age_list *create_list(){
   struct age_list *h;
   h = get_cell();
   h->age= -1;
   h->next = NULL;
   return h;
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
 // create dummy
  p = create_list();
 
  printf("input the age(exit by using negative value):\n");
  while(age >= 0){
    scanf("%d", &age);
    p = add_list(age, p);
    print_struct(p);
  }
}
