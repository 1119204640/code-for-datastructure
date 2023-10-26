#include <limits.h>
#include <iostream>
using namespace std;

// #define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

// typedef int VRType;
typedef char VertexType;

// //邻接矩阵的结构
// typedef struct ArcCell
// {
//     VRType adj;
// }ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// typedef struct
// {
//     VertexType vexs[MAX_VERTEX_NUM];
//     AdjMatrix arc;
//     int vexnum, arcnum;
// }Graph;

//邻接表的结构
typedef struct ArcNode{
    int adjvex;  //该边所指向的那个顶点的下标
    struct ArcNode *nextarc;
    // char info[];    //边上权值，相当于邻接矩阵里面的VRType
}ArcNode;

typedef struct VNode
{
    VertexType data;  //结点元素
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}Graph;

void InitialGraph(Graph &G) {
    // G.vexnum = 2;
    // G.arcnum = 1;
    // G.vertices[0].data = 'A';
    // G.vertices[0].firstarc = (ArcNode*) malloc(sizeof(ArcNode));
    // G.vertices[0].firstarc->adjvex = 1;
    // G.vertices[0].firstarc->nextarc = NULL;
    // G.vertices[1].data = 'B';
    // G.vertices[1].firstarc = NULL;

    cout << "enter the vertex number: ";
    cin >> G.vexnum;
    cout << "enter the arc number: ";
    cin >> G.arcnum;
    cout << endl;

    //加入顶点
    for (int i = 0; i < G.vexnum; i++) {
        cout << "enter NO." << i+1 << " vertex's data(only one letter): ";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << endl;

    //加入边
    for (int i = 0; i < G.arcnum; i++) {
        int start, end;
        cout << "enter the start and end index of NO." << i+1 << " arc: ";
        cin >> start >> end;

        ArcNode* newArc = (ArcNode*) malloc(sizeof(ArcNode));
        newArc->adjvex = end;
        newArc->nextarc = G.vertices[start].firstarc;
        G.vertices[start].firstarc = newArc;    //头插法增加边
    }
    cout << endl;
}

void Print(Graph G) {
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.vertices[i].data << "->";
        for (ArcNode* temp = G.vertices[i].firstarc; temp != NULL; temp = temp->nextarc) {
            cout << temp->adjvex << "->";
        }
        cout << endl;
    }
    cout << endl;
}

//返回下标为v的结点的指向的第一个结点的下标
int FirstNeightbor(Graph G, int v) {
    if (G.vertices[v].firstarc != NULL) {
        return G.vertices[v].firstarc->adjvex;
    }
    return -1;
}

//返回下标为v的结点里面，下标为w的下一个结点下标
int NextNeightbor(Graph G, int v, int w) {
    ArcNode* temp;
    for (temp = G.vertices[v].firstarc; temp != NULL; temp = temp->nextarc) {
        if (temp->adjvex == w) {
            ArcNode* next = temp->nextarc;
            if (next != NULL) {
                return next->adjvex;
            }
        }
    }
    return -1;
}

void DFS(Graph G, int v, bool visited[]) {
    cout << G.vertices[v].data << ",";
    visited[v] = true;
    for (int w = FirstNeightbor(G, v); w >= 0; w = NextNeightbor(G, v, w)) {
        if (visited[w] != true) {
            DFS(G, w, visited);
        }
    }    
}

void DFSTraverse(Graph G) {
    bool visited[G.vexnum];
    for (int v = 0; v < G.vexnum; v++) {
        visited[v] = false; //初始化标记数组
    }
    for (int v = 0; v < G.vexnum; v++) {    //从0号结点开始DFS
        if (!visited[v]) {
            DFS(G, v, visited);
        }
    }
}

int main() {
    Graph G;
    InitialGraph(G);
    Print(G);
    DFSTraverse(G);
    return 0;
}