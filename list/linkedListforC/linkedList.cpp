#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node{
	char name[100];
	int student_ID;
	int status;
	Position Next;
};

List CreateList();
Position Insert(const char *name_,int student_ID_,int status_, List L);
Position Find(int student_ID, List L);
int Delete(ElementType X, List L);
void PrintList(List L);
Position PrintNode(int student_ID, List L);
Position FindPrevious(int student_ID,List L);
Position StatusCheck(int status,List L);

int main(){
	List L;
	
	L = CreateList();
	printf("Linked list was created \n");
	Insert("Gildong Hong",123456789,0,L);
	Insert("Gildong Kim",234567891,0,L);
	Insert("Yunseong Lee",201821261,1,L);
	Insert("Gildong Lee",345678912,1,L);
	Insert("Gildong Park",456789123,0,L);
	Insert("Gildong Choi",567891234,0,L);
	PrintList(L);
	printf("\n");
	printf("PrintNode---------------------------\n");
	PrintNode(201821261,L);
	printf("\n");
	Delete(1,L);
	printf("Delete---------------------------\n");

	PrintList(L);

	return 0;
}
	
List CreateList()
{
	List L;
	L = (List)malloc(sizeof(struct Node));
	strcpy(L -> name,"");
	L -> student_ID = 0;
	L -> status = 0;
	L -> Next = NULL;
	return L;
}
	
	
Position Insert(const char *name,int student_ID,int status,Position P)
{
	Position Tmp;
	Tmp = (Position)malloc(sizeof(struct Node));
	strcpy(Tmp -> name,name);
	Tmp -> student_ID = student_ID;
	Tmp -> status = status;

	Tmp -> Next = P -> Next;
	P -> Next = Tmp;
	return Tmp;
}

Position FindPrevious(int status,List L)
{
	Position P = L;
	while(P -> Next != NULL && P -> Next -> status != status)
		P = P -> Next;
	return P;
}
Position StatusCheck(int status, List L)
{
		Position P = L;
		Position tmp;
		while(P!=NULL){
		
		if(P ->status == status){
			
		tmp = FindPrevious(P -> status,L);
		tmp -> Next = P -> Next;
		free(tmp);
		}	 
		P = P -> Next;
		}

}

int Delete(int status, List L)
{
	Position P= L;
	
	while(P!=NULL){
		StatusCheck(status,L);
		P = P -> Next;
	}	
	return 1;
}

void PrintList(List L)
{
	Position P = L -> Next;
	while(P!=NULL){
		printf("%s %d %d\n", P -> name,P->student_ID,P->status);
		P = P -> Next;

	}
} 

Position PrintNode(int student_ID,List L)
{
	Position P = L;
	while(P->Next!=NULL) 
		if(P -> student_ID == student_ID )
		{
			printf("%s %d %d\n", P -> name,P->student_ID,P->status);
			P = P -> Next;
		}
		else 
			P = P -> Next;
	return P;
}
