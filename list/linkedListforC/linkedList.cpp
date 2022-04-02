#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//12-34-56-78-99 링크드리스트구현

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
Position Insert(const char *name_,int student_ID_,int status_, List L, Position P);
Position FindPrevious(ElementType X,List L);
int Delete(ElementType X, List L);
void PrintList(List L);

int main(){
	List L;
	
	L = CreateList();
	printf("Linked list was created \n");
	
	

	
	return 0;
}
	
List CreateList()
{
	List L;
	L = (List)malloc(sizeof(struct Node));
	//메모리의 크기만큼 할당 
	strcpy(L -> name,"")
	
	L -> Next = NULL;
	return L;
}
	
	
Position Insert(const char *name_,int student_ID_,int status_,Position P)
{
	Position Tmp;
	Tmp = (Position)malloc(sizeof(struct Node));
	Tmp -> name[100] = X;
	Tmp -> student_ID = X;
	Tmp -> status = X;

	Tmp -> Next = P -> Next;
	P -> Next = Tmp;
	return Tmp;
}

Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while(P->Next!=NULL && P -> Next-> Element != X) P = P-> Next;
	return P;
}

int Delete(ElementType X, List L)
{
	Position P, Tmp;
	P = FindPrevious(X,L);
	Tmp = P -> Next;
	P->Next = Tmp -> Next;
	free(Tmp);
	return 1;
	
}

void PrintList(List L)
{
	Position P = L -> Next;
	while(P!=NULL){
		printf("%d", P -> Element);
		P = P -> Next;
		if(P != NULL)
		{
		printf("->");
		}
	}
 } 
