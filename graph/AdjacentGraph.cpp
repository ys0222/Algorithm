#include <stdio.h>
#include <stdlib.h>

struct Node;
struct List;
struct Graph;

typedef struct Node *PtrToNode;
typedef PtrToNode AdjListNode;
typedef struct List *PtrToList;
typedef PtrToList AdjList;
typedef struct Graph *PtrToGraph;
typedef PtrToGraph GraphList;

struct Node {
	int NodeNum;
	AdjListNode next;
};

struct List {
	AdjListNode head;
};

struct Graph {
	int V;
	AdjList array;
};

AdjListNode newAdjListNode(int NodeNum)
{
	AdjListNode newNode;
	newNode = (AdjListNode)malloc(sizeof(struct Node));
	newNode->NodeNum = NodeNum;
	newNode->next = NULL;
	return newNode;
}

GraphList createGraph(int V)
{
	GraphList graph;
	graph =(GraphList)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (AdjList)malloc(V * sizeof(struct List));
	
	for (int i=0; i<V; i++){
		graph -> array[i].head = newAdjListNode(i);
	}
	return graph;
}

void addEdge(GraphList graph,int from, int to)
{
	AdjListNode newNode;
	newNode = newAdjListNode(to);
	newNode->next = graph->array[from].head ->next;
	graph->array[from].head -> next = newNode;
}

void printGraph(GraphList graph)
{
	AdjListNode a;
	for(int i=0;i<graph->V;i++){
		a = graph->array[i].head;
		while (a){
			printf("%d ->",a->NodeNum);
			if (a->next == NULL){
				printf("NULL");	
			}
			a = a->next;
		}
		printf("\n");
	}
}

int main(){
	int V=5;
	GraphList graph = createGraph(V);
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,0,3);
	addEdge(graph,1,2);
	addEdge(graph,1,4);
	addEdge(graph,2,4);
	addEdge(graph,3,4);
	
	printGraph(graph);
	
	return 0;
	
}
