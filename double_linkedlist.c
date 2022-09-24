#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE{
  char* data;

  struct NODE* next;
  struct NODE* prev;
}NODE;

NODE* head=0;
NODE* tail=0;

void PrintAtHead(){
  NODE* temp = head;
  while(temp != NULL){
    printf("[%p] : %s\n", temp, temp->data);
    temp = temp->next;
  }
  printf("\n");
  return ;
}

void PrintAtTail(){
  NODE* temp = tail;
  while(temp != NULL){
    printf("[%p] : %s\n", temp, temp->data);
    temp = temp->prev;
  }
  printf("\n");
  return ;
}

int IsEmpty(){
  if(head==0 && tail==0){
    return 1;
  }
  return 0;
}

void InsertAtHead(char* nData){
  NODE* pNode = (NODE*)malloc(sizeof(NODE));
  memset(pNode, 0, sizeof(NODE));
  pNode->data = (char*)malloc(sizeof(nData));
  memset(pNode->data, 0, sizeof(nData));
  
  strcpy(pNode->data, nData);
  
  if(IsEmpty()){
    head = pNode;
    tail = pNode;
  }else{
    head->prev = pNode;
    pNode->next = head;
    head = pNode;
  }
  printf("Insert %s at head\n", nData);
  return ;
}

void InsertAtTail(char* nData){
  NODE* pNode = (NODE*)malloc(sizeof(NODE));
  memset(pNode, 0, sizeof(NODE));
  pNode->data = (char*)malloc(sizeof(nData));
  memset(pNode->data, 0, sizeof(nData));

  strcpy(pNode->data, nData);

  if(IsEmpty()){
    head = pNode;
    tail = pNode;
  }else{
    tail->next = pNode;
    pNode->prev = tail;
    tail = pNode;
  }
  printf("Insert %s at tail\n", nData);
  return ;
}

NODE* FindData(char* nData){
  NODE* temp = head;
  while(temp != NULL){
      //printf("dest:[%p], src:[%p]\n", temp, nData);
    if(strcmp(temp->data, nData)==0){
      printf("%s is Found\n", nData);
      return temp;
    }
    temp = temp->next;
  }
  printf("%s is not Found\n", nData);
  return 0;
}

void DeleteData(char* nData){
  
  if(head == tail){
    free(head->data);
    free(head);
    head = 0;
    tail = 0;
  }
  else if(head->data == nData){
    NODE* temp = head->next;
    free(head->data);
    free(head);
    head = temp;
    head->prev = 0;
  }
  else if(tail->data == nData){
    NODE* temp = tail->prev;
    free(tail->data);
    free(tail);
    tail = temp;
    tail->next = 0;
  }
  else{
    NODE* delNode = FindData(nData);
    printf("delNode is [%p]\n", delNode);
    if(delNode == 0){
      printf("%s is not Found\n", nData);
      return ;
    }
    NODE* prevNode = delNode->prev;
    NODE* nextNode = delNode->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    
    free(delNode->data);
    free(delNode);
  }
  return ;
}


int main(void) {
  InsertAtHead("data01");
  InsertAtHead("data02");
  InsertAtTail("data03");
  InsertAtTail("data04");
  
  PrintAtHead();
  PrintAtTail();

  FindData("data03");

  DeleteData("data03");
  
  FindData("data03");

  PrintAtHead();
  PrintAtTail();
  
  return 0;
}
