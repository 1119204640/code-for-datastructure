#include <iostream>
using namespace std;

// #define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define MAXSIZE 20

typedef char VertexType;
typedef int VRType;
typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct Graph
{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arc;
    int vexnum, arcnum;
}Graph;
typedef struct Queue
{
    int *data;
    int front, rear;
}Queue;

void InitQueue(Queue &Q) {
    Q.data = (int*) malloc(sizeof(int) * MAXSIZE);
    Q.front = 0;
    Q.rear = 0;
}

bool IsFull(Queue Q) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        return true;
    }
    return false;
}

bool IsEmpty(Queue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

int EnQueue(Queue &Q, int v) {
    if (!IsFull(Q)) { //若队列非满则入队
        Q.data[Q.rear] = v;
        Q.rear = (Q.rear + 1) % MAXSIZE;
        return 1;
    }
    return  -1;
}

int DeQueue(Queue &Q) {
    if (!IsEmpty(Q)) {  //若队列非空则出队
        int e = Q.data[Q.front];
        Q.front = (Q.front + 1) % MAXSIZE;
        return e;
    }
    return -1;
} 

void Initial(Graph &G) {
    cout << "enter the vertex number: ";
    cin >> G.vexnum;
    cout << "enter the arc number: ";
    cin >> G.arcnum;
    cout << endl;

    //加入顶点
    for (int i = 0; i < G.vexnum; i++) {
        cout << "enter NO." << i+1 << " vertex's data(only one letter): ";
        cin >> G.vexs[i];
    }
    cout << endl;

    //初始化邻接矩阵
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.arc[i][j] = 0;
        }
    }

    //加入边
    for (int i = 0; i < G.arcnum; i++) {
        int start, end;
        cout << "enter the start, end index and the value of NO." << i+1 << " arc: ";
        cin >> start >> end;
        G.arc[start][end] = 1;
    }
    cout << endl;
}

void Print(Graph G) {
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            cout << G.arc[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//返回下标为v的结点的指向的第一个结点的下标
int FirstNeightbor(Graph G, int v) {
    for (int w = 0; w < G.vexnum; w++) {
        if (G.arc[v][w] != 0) {
            return w;
        }
    }
    return -1;
}

//返回下标为v的结点里面，下标为w的下一个结点下标
int NextNeightbor(Graph G, int v, int w) {
    for (int i = w+1; i < G.vexnum; ++i) {
        if (G.arc[v][i] != 0)
            return i;
    }
    return -1;
}

void BFS(Graph G, int v, bool visited[], Queue &Q) {
    cout << G.vexs[v] << ",";
    visited[v] = true;
    EnQueue(Q, v);
    while (!IsEmpty(Q)) {
        int u = DeQueue(Q);
        for (int w = FirstNeightbor(G,u); w >=0; w = NextNeightbor(G,u,w)) {
            if (!visited[w]) {
                cout << G.vexs[w] << ",";
                visited[w] = true;
                EnQueue(Q,w);
            }

        }
    }
}

void BFSTraverse(Graph G) {
    bool visited[G.vexnum];
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; //初始化标记数组
    }
    Queue Q;
    InitQueue(Q);
    for (int v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            BFS(G,v,visited,Q);
        }
    }

}

int main() {
    Graph G;
    Initial(G);
    Print(G);
    BFSTraverse(G);
    return 0;
}

