#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int increase_number=0;

typedef struct MEMBER {
  int id; // 순번
  char name[40];
  int age;
  char phone[40];
  char address[50];
} MEMBER;

MEMBER* list;

void InsertMember(){
  MEMBER nMember;
  int size = increase_number;
  
  list = (MEMBER*)realloc(list, sizeof(MEMBER)*(size+1));
  
  printf("이름 입력 : ");
  scanf("%s", nMember.name);
  
  printf("나이 입력 : ");
  scanf("%d", &nMember.age);
  
  printf("휴대폰 번호 입력 : ");
  scanf("%s", nMember.phone);
  
  printf("주소 입력 : ");
  scanf("%s", nMember.address);

  list[size] = nMember;
  increase_number = increase_number + 1;
  return ;
}

void PrintMemberAll(MEMBER* temp){
  int size = increase_number;
  printf("\nlist of MEMBERS\n");
  printf("순번 이름 나이 번호 주소 \n");
  for(int i=0; i<size; i++){
    printf("[%p]\n", &list[i]);
    printf("%d %s %d %s %s\n", i+1, list[i].name, list[i].age, list[i].phone, list[i].address);
  }
  return ;
}

int CmpByName(MEMBER* a, MEMBER* b){
  char* name1 = a->name;
  char* name2 = b->name;
  int res = strcmp(name1, name2);
  return res;
}

void PrintByName(){
  int size = increase_number;
  
  MEMBER* temp = (MEMBER*)malloc(sizeof(MEMBER)*size);
  memcpy(temp, list, sizeof(MEMBER)*size);
  
  qsort(temp, size, sizeof(MEMBER), CmpByName);

  PrintMemberAll(temp);
  
  free(temp);
  
  return ;
}

int CmpByAge(MEMBER* a, MEMBER* b){
  int age1 = a->age;
  int age2 = b->age;
  
  int res = age1 > age2;
  return res;
}

void PrintByAge(){
  int size = increase_number;
  
  MEMBER* temp = (MEMBER*)malloc(sizeof(MEMBER)*size);
  memcpy(temp, list, sizeof(MEMBER)*size);
  
  qsort(temp, size, sizeof(MEMBER), CmpByAge);

  PrintMemberAll(temp);
  
  free(temp);

  return ;
}

void PrintById(){
  PrintMemberAll(list);
  return ;
}

void PrintMember(){
  // 어떤 방식으로 print할 것인지 내부적으로 옵션넣기
  // 각 옵션따라 sort하여 print할것. temp배열사용
  // 최적화되지 않은 상태로 print 옵션도 넣을것.
  int input;
  while(1){
    printf("1 - 순번 출력\n");
    printf("2 - 이름 순 출력\n");
    printf("3 - 나이 순 출력\n");
    printf("원하시는 출력을 선택하시오 -> ");
    scanf("%d", &input);

    if(input == 1){
      PrintById();
      break;
    }
    else if(input == 2){
      PrintByName();
      break;
    }
    else if(input == 3){
      PrintByAge();
      break;
    }
    else
      printf("1~3 중 다시 선택하시오.\n");
  }
  return ;
}

void FindMember(){
  // 어떤 방식으로 찾을 것인지 내부적으로 옵션넣기
  // 이름으로 찾기, 나이로 찾기.
  
  return ;
}

void FindByName(){
  
  return ;
}

void FindByAge(){
  
  return ;
}

void  UpdateMember(){

  return ;
}

void DeleteMember(){
  // 선택삭제인지 전제삭제인지 고르기.

  return ;
}

void OptimizeMember(){ 
  // 삭제된 빈공간 최적화시키기.

  return ;
}

void SaveList(){ 
  
  int size = increase_number;
  
  FILE* fp = fopen("list.txt","w"); //test파일을 w(쓰기) 모드로 열기

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d %s %d %s %s\n", i+1, list[i].name, list[i].age, list[i].phone, list[i].address); //문자열 입력
    }

  fclose(fp); //파일 포인터 닫기
  return ;
}

void LoadList(){ 
  // 주소록 불러오기
  FILE* fp = fopen("list.txt","r");

  

  return ;
}



int main(){
  int input;
  while(1){
    printf("Menu\n");
    printf("<1> 주소록 등록\n");
    printf("<2> 주소록 출력\n");
    printf("<3> 주소록 검색\n");
    printf("<4> 주소록 수정\n");
    printf("<5> 주소록 삭제\n");
    printf("<6> 주소록 최적화\n");
    printf("<7> 주소록 저장\n");
    printf("<8> 주소록 불러오기\n");
    printf("<9> 프로그램 종료\n");
    printf("\n원하시는 메뉴를 선택하시오 -> ");
    scanf("%d", &input);
    
    if(input == 1) 
      InsertMember();
    else if(input == 2) 
      PrintMember();
    else if(input == 3) 
      FindMember();
    else if(input == 4) 
      UpdateMember();
    else if(input == 5)
      DeleteMember();
    else if(input == 6) 
      OptimizeMember();
    else if(input == 7) 
      SaveList();
    else if(input == 8) 
      LoadList();
    else if(input == 9) 
      break;
    else 
      printf("잘못 입력하셨습니다. 1~8중의 메뉴를 선택해주세요.\n");
  }
  return 0;
}
