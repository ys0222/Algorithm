
#트리

★트리의 개념

트리는 노드로 이루어진 자료구조 이다.

1. 트리는 하나의 루트 노드를 갖는다.
2. 루트 노드는 0개 이상의 자식 노드를 갖고 있다.
3. 그 자식 노드 또한 0개 이상의 자식 노드를 갖고 있고, 이는 반복적으로 정의된다.

노드들과 노드를 연결해주는 간선으로 구성되어있다.
● 트리에는 사이클이 존재할 수 없다.
● 노드들은 특정 순서로 나열될 수도 있고 아닐 수도 있다.
● 각 노드는 부모 노드로의 연결이 있을 수 있고 없을 수도 있다.
● 노드는 어느한 자료형으로도 표현 가능하다.

비선형 자료구조로 계층적 관계를 표현한다.

★트리에 관한 용어

루트노드 : 부모가 없는 노드, 트리는 하나의 루트노드로만 구성되어있다.
단말노드 : 자식이 없는 노드.
내부노드 : 단말노드가 아닌 노드.
간선 : 노드를 연결하는 선.
형제 : 같은 부모노드를 가진 노드.
노드의 크기 : 자신을 포함한 모든 자손 노드의 개수
노드의 깊이 : 루트에서 어떤 노드까지 도달하기 위한 간선의 길이.
노드의 레벨 : 트리의 특정 깊이를 가지는 노드의 집합, 루트노드 level:0부터 시작.
노드의 차수 : 노드가 지닌 가지의수 = 하위트리개수 / 간선 수.
트리의 차수 : 트리의 최대 차수.
트리의 높이 : 루트 노드에서 가장 깊숙히 있는 노드의 깊이.

★트리의 특징

그래프의 한종류, '최소 연결 트리'라고도 불린다.
트리는 계층 모델이다.
트리는 DAG(방향성이 있는 비순환 그래프)의 한 종류이다.
노드가 n개인 트리는 항상 n-1개의 간선을 가진다.
루트에서 어떤 노드로 가는 경로는 유일하다.
한 개의 루트노드만 존재하고 자식 노드는 한개의 부모 노드만을 가진다.
순회는 Pre-order, In-order 아니면 Post-order로 이루어진다. 이 3가지 모두 DFS/BFS/안에 있다.

트리는 이진트리, 이진탐색트리, 균형트리, 이진힙 등이 있다.

★트리 구현을 위한 기본적인 코드

class Tree {
    constructor(value){
    //Node생성.
        this.value = value; 
        this.children = []; //자식노드들을 담을 배열
}

//노드 삽입
insertNode(value) {
    const childNode = new Tree(value); //자식노드 생성
    this.children.push(childNode); //배열에 자식노드 푸시
} 

//트리안에 해당 값이 포함 되어 있는지 확인
contains(value){
    if (this.value == value){
        return true;
    }
    //값을 찾을때까지 children배열을 돌아 childNode탐색
else{
    for(let i=0;i<this.children.length;i++){
        const childNode = this.children[i];
        if(childNode.contains(value)){
        return true;
        }
    }
}
return false;
    }
}

사용예시

const rootNode = new Tree(null);

for(let i = 0; i <= 4; i++) {
  if(rootNode.children[i])
  //자식 노드가 있는지 확인.
  {
    rootNode.children[i].insertNode(i)
  }
 rootNode.insertNode(i); 
}

★트리 BFS 탐색

BFS은 시작점의 인접한 정점들을 차례로 모두 방문한 후, 방문했던 정점을 다시 시작점으로 설정해 반복하는 방식이고, 너비 우선 탐색이라고 부른다.

let bfs = function (node) {

    let values = [node.value] //노드의 값
    let queue = [node] //노드

    while(queue.length != 0) {
        let search = queue.shift(); //탐색 시작할 노드 빼기
        for (let i=0; i< search.childeren.length; i++) { //노드의 children 순회
            values.push(search.childeren[i].value) //값을 values에 푸시
            queue.push(search.childeren[i]) //children노드는 또 탐색을 위해 queue에 푸시
        
        }
    }
    return values; //차례대로 출력
};

★트리 DFS 탐색

DFS는 루트 노드나 임의의 노드에서 시작해 최대로 깊게 진입해 탐색한 후 다른 노드로 탐샌하는 방식이고 깊이 우선 탐색이라고 부른다.

let dfs = function (node) {
    let values = [node.value] //노드 방문

    for(let i=0; i<node.children.length; i++){
        valeus = values.concat(dfs(node.children[i]))
    }
    return values;

}

출처 : https://gmlwjd9405.github.io/2018/08/12/data-structure-tree.html,
https://velog.io/@devjade/
