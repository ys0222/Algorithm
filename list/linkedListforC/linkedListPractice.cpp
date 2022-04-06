#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//12-34-56-78-99 ��ũ�帮��Ʈ����

typedef int ElementType;
//int를 ElementType형으로 바꿔주겠다 즉 int = ElementType

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
//struct NODE *List 랑 같은 말 자기참조 구조체포인터

struct Node{
	ElementType Element;
	//데이터
	Position Next;
	//다음 노드의 주소를 저장할 자기 참조 구조체 포인터

};

List CreateList();
Position Insert(ElementType X, List L, Position P);
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
	//리스트 변수 선언
	L = (List)malloc(sizeof(struct Node));
	//노드 구조체 만큼 메모리르 할당
	L -> Element = 0;
	//머리 노드에는 데이터가 없음
	L -> Next = NULL;
	//L.Next 에 뒤에 null
	return L;
}
	
	
Position Insert(ElementType X, List L, Position P)
{
	Position Tmp;
	//노드 생성
	Tmp = (Position)malloc(sizeof(struct Node));
	//빈노드
	Tmp -> Element = X;
	//데이터 추가.
	Tmp -> Next = P -> Next;
	//이 노드에 머리노드의 다음 값 null을 지정해줌
	P -> Next = Tmp;
	//머리 노드 (p) 다음 노드 tmp를 지목
	return Tmp;
}

//해당하려는 노드를 찾으려면 그 전 노드를 찾아야한다
Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	//받아온 리스트에 다음 리스트 헤더를 가르키는 L 즉 L -> Next는 첫번째노드
	while(P->Next!=NULL  && P ->Next -> Element != X) 
		P = P-> Next;
	
	return P;
}

int Delete(ElementType X, List L)
{
	Position P, Tmp;
	//P와 Tmp 변수 선언
	P = FindPrevious(X,L);
	// p=삭제할 원소 불러오기 (56,L)
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


