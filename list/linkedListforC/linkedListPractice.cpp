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
	ElementType ElementS;
	Position Next;
};

List CreateList();
Position Insert(ElementType A, List L, Position P);
Position FindPrevious(ElementType X);
int Delete(ElementType X, List L);
void PrintList(List L);

int main(){
	List L;
	
	L = CreateList();
	printf("Linked list was created \n");
	
	Insert(99,L,L);
	Insert(78,L,L);
	Insert(56,L,L);
	Insert(34,L,L);
	Insert(12,L,L);
	
	PrintList(L);
	printf("\n\n==============================\n\n");
	Delete(56,L);
	
	printf("delete 56\n\n");
	PrintList(L);
	
	
	return 0;
}
	
List CreateList()
{
	List L;
	L = (List)malloc(sizeof(struct Node));
	//메모리의 크기만큼 할당 
	L -> ElementS = 0;
	L -> Next = NULL;
	return L;
}
	
	
Position Insert(ElementType X, List L, Position P)
{
	Position Tmp;
	Tmp = (Position)malloc(sizeof(struct Node));
	Tmp -> ElementS = X;
	Tmp -> Next = P -> Next;
	P -> Next = Tmp;
	return Tmp;
}

Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while(P->Next!=NULL && P -> Next-> ElementS != X) P = P-> Next;
	return P;
}

int Delete(ElementType X, List L)
{
	Position P, Tmp;
	P = FindPrevious(X,L);
	Tmp = P -> Next;
	P->Next = Tmp -> Next;
	free(Tmp);
	//티엠피 지우 
	return 1;
	
}

void PrintList(List L)
{
	Position P = L -> Next;
	while(P!=NULL){
		printf("%d", P -> ElementS);
		P = P -> Next;
		if(P != NULL)
		{
		printf("->");
		}
	}
 } 
