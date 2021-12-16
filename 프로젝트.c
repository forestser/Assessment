#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int size;

typedef struct BOOK{
	char name[100];
	int number;
	char kind[10];
	struct BOOK *link;
}BOOK;

typedef struct node{
	BOOK *head;
}list_head;

list_head *createnode(){
	list_head *newnode;
	newnode = (list_head *)malloc(sizeof(list_head));
	newnode -> head = NULL;
	return newnode;
}

void insertNode(char *name, int number, char *kind, list_head *L){
	BOOK *newNode;
	newNode = (BOOK *)malloc(sizeof(BOOK));
	strcpy(newNode -> name, name);
	newNode -> number = number;
	strcpy(newNode -> kind, kind);
	newNode -> link = NULL;
	if(L -> head == NULL){
		L -> head = newNode;
	}
	else{
		BOOK *temp;
		temp = L -> head;
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		temp -> link = newNode;
		
	}
	size++;
}


void printAll(list_head *L){
	BOOK *temp;
	temp = L -> head;
	while(temp){
		printf("%s %d %s\n", temp -> name, temp -> number, temp -> kind);
		temp = temp -> link;
	}
} 
 
void sort(list_head *L){
	BOOK *sh = L -> head;
	BOOK *temp;
	BOOK *b;
	for(int i = size - 1; i > 0; i--){
		sh = L -> head;
		b = L -> head;
		for(int j = 0; j < i; j++){
			if(sh -> number > sh -> link -> number){
				if(sh == L -> head){
					temp = sh -> link;
					sh -> link = sh -> link -> link;
					temp -> link = sh;
					L -> head = temp;
				}
				else {
					temp = sh -> link;
					sh -> link = sh -> link -> link;
					b -> link = temp;
					temp -> link = sh; 
				}
				b = temp;
				sh = temp -> link; 
			}
			else{
				b = sh;
				sh = sh -> link;
			}
		}
	}
}

void search(list_head *L, char *key){
	BOOK *p;
	int count = 1;
	for(p = L -> head; p!= NULL; p = p->link) {
        if(strcmp(p -> name, key) == 0) {
        	printf("찾으시는 책은 %d번째에 있습니다.\n", count);
        	return;
		}
		count++;
    }
    printf("찾으시는 책은 등록되어있지 않습니다.\n");
}

int main(){
	int a;
	list_head *L = createnode();
	char name[100];
	char find[100];
	char kind[10];
	int num;
	while(1){
		printf("-------------------------\n");
		printf("0 : 정보\n");
		printf("1 : 책등록\n");
		printf("2 : 책 정렬\n");
		printf("3 : 책 탐색\n");
		printf("4 : 등록된 책 모두 보기\n");
		printf("종료 : 5\n");
		printf("\n"); 
		printf("입력 : ");
		scanf("%d", &a);
		if(a == 5){
			break; 
		}
		else if(a > 5 || a < 0){
			printf("잘못된 값을 입력하셨습니다.\n");
			continue;
		}
		switch(a){
			case 0:
				printf("-------------------------\n");
				printf("책을 등록하실 때에는 이름과 번호, 종류를 입력해주세요.\n");
				printf("종류는 십진분류표로, 0번 부터 9번 까지 있습니다.\n");
				printf("0 : 총류 | 1 : 철학 | 2 : 종교 | 3 : 사회과학 | 4 : 자연과학\n");
				printf("5 : 기술과학 | 6 : 예술 | 7 : 언어 | 8 : 문학 | 9 : 역사\n");
				printf("\n");
				break;
			case 1:
				printf("책 이름과 번호와 종류를 입력하세요\n:");
				scanf("%s %d %s", name, &num, kind);
				insertNode(name, num, kind, L);
				printf("등록이 완료되었습니다 ! \n");
				break;
			case 2:
				sort(L);
				break;
			case 3:
				printf("찾을 책의 제목을 입력해주세요 : ");
				scanf("%s", find);
				search(L, find);
				break;
			default:
				printAll(L);
				break;
		}
	}
}

