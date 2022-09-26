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

  nMember.id = increase_number+1;
  
  list[size] = nMember;
  increase_number = increase_number + 1;
  return ;
}

void PrintMemberAll(MEMBER* temp){
  int size = increase_number;
  printf("\nlist of MEMBERS\n");
  printf("순번\t이름\t나이\t번호\t주소\n");
  for(int i=0; i<size; i++){
    printf("[%p]\n", &temp[i]);
    if(temp[i].id != 0){
      printf("%d\t%s\t%d\t%s\t%s\n", temp[i].id, temp[i].name, temp[i].age, temp[i].phone, temp[i].address);
    }
  }
  return ;
}

int CmpByName(const void* a, const void* b){
  char* name1 = ((MEMBER*)a)->name;
  char* name2 = ((MEMBER*)b)->name;
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

int CmpByAge(const void* a, const void* b){
  int age1 = ((MEMBER*)a)->age;
  int age2 = ((MEMBER*)b)->age;
  
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

void FindByName(char* tname){
  int size = increase_number;
  int match_count = 0;
  MEMBER* temp;
  int temp_count=0;
  for(int i=0; i<size; i++){
    if(strcmp(list[i].name, tname) == 0){
      match_count++;
    }
  }
  temp = (MEMBER*)malloc(sizeof(MEMBER)*match_count);
  for(int i=0; i<size; i++){
    if(strcmp(list[i].name, tname) == 0){
      temp[temp_count] = list[i];
      temp_count++;
    }
  }
  
  return ;
}

void FindByAge(int tage){
  
  return ;
}

void FindMember(){
  // 어떤 방식으로 찾을 것인지 내부적으로 옵션넣기
  // 이름으로 찾기, 나이로 찾기.
  int input;

  while(1){
    printf("1 - 이름으로 검색\n");
    printf("2 - 나이로 검색\n");
    printf("원하시는 검색방식을 선택하시오 -> ");
    scanf("%d", &input);

    if(input == 1){
      char* name;
      printf("삭제할 연락처의 ID를 입력하세요 : ");
      scanf("%s", name);
      FindByName(name);
      break;
    }
    else if(input == 2){
      int age;
      printf("삭제할 연락처의 ID를 입력하세요 : ");
      scanf("%d", &age);
      FindByAge(age);
      break;
    }
    else
      printf("1~2 중 다시 선택하시오.\n");
  }
  return ;
}

void  UpdateById(){
  int id;
  printf("업데이트할 ID를 입력하세요");
  scanf("%d", &id);
  
  printf("이름 입력 : ");
  scanf("%s", list[id-1].name);
  
  printf("나이 입력 : ");
  scanf("%d", &list[id-1].age);
  
  printf("휴대폰 번호 입력 : ");
  scanf("%s", list[id-1].phone);
  
  printf("주소 입력 : ");
  scanf("%s", list[id-1].address);

  printf("수정이 완료되었습니다.\n");
  return ;
}

void DeleteMemberAll(){
  free(list);
  list = NULL;
  increase_number = 0;
  return ;
}

void DeleteById(int id){
  list[id-1].id = 0;
  return ;
}

void DeleteMember(){
  // 선택삭제인지 전제삭제인지 고르기.
  int input;
  while(1){
    printf("1 - 전체삭제\n");
    printf("2 - ID로 삭제\n");
    printf("원하시는 삭제을 선택하시오 -> ");
    scanf("%d", &input);

    if(input == 1){
      DeleteMemberAll();
      break;
    }
    else if(input == 2){
      int id;
      printf("삭제할 연락처의 ID를 입력하세요 : ");
      scanf("%d", &id);
      DeleteById(id);
      break;
    }
    else
      printf("1~2 중 다시 선택하시오.\n");
  }
  return ;
}

void OptimizeMember(){ 
  // 삭제된 빈공간 최적화시키기.
  int size = increase_number;
  int opt_count=0;
  
  for(int i=0; i<size; i++){
    if(list[i].id == 0){
      opt_count++;
      printf("삭제된 %d번째 공간 발견!!\n", i+1);
      // for 문 안쪽의 변수를 j -> i로 설정해서 최적화가 안되는 버그가 발생했었음.
      for(int j=i; j<size-1; j++){
        //printf("삭제전 list[%d].id = %d, list[%d].id = %d\n", j, list[j].id, j+1, list[j+1].id);
        list[j].id = list[j+1].id;
        strcpy(list[j].name,list[j+1].name);
        list[j].age = list[j+1].age;
        strcpy(list[j].phone,list[j+1].phone);
        strcpy(list[j].address,list[j+1].address);
        
        //printf("삭제 후 list[%d].id = %d, list[%d].id = %d\n", j, list[j].id, j+1, list[j+1].id);
      }
    }
  }

  printf("%d개의 데이터를 최적화했습니다.\n", opt_count);
  
  increase_number -= opt_count;
  list = (MEMBER*)realloc(list, sizeof(MEMBER)*increase_number);
  return ;
}

void SaveList(){ 
  
  int size = increase_number;
  
  FILE* fp = fopen("list.txt","w"); //test파일을 w(쓰기) 모드로 열기

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d %s %d %s %s\n", list[i].id, list[i].name, list[i].age, list[i].phone, list[i].address); //문자열 입력
    }

  fclose(fp); //파일 포인터 닫기
  return ;
}

void LoadList(){ 
  // 주소록 불러오기
  FILE* fp = fopen("list.txt","r");
  int count=0;
  MEMBER nMember;

  if(list != NULL)
    DeleteMemberAll();

  //전체 라인 수를 체크하기 위한 코드
  while(fscanf(fp,"%d %s %d %s %s", &nMember.id, nMember.name, &nMember.age, nMember.phone, nMember.address) != EOF){
    //printf("%d %s %d %s %s\n", nMember.id, nMember.name, nMember.age, nMember.phone, nMember.address);
    count++;
  }

  //printf("count : %d\n", count);
  
  list = (MEMBER*)malloc(sizeof(MEMBER)*count);
  increase_number = count;

  //file pointer 초기화 후 읽어들이기.
  fp = fopen("list.txt","r");
  for(int i=0; i<count; i++){
    fscanf(fp,"%d %s %d %s %s", &list[i].id, list[i].name, &list[i].age, list[i].phone, list[i].address);
  }
  
  fclose(fp);
    
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
      UpdateById();
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
