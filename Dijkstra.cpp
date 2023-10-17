#include <limits.h>
#include <iostream>
using namespace std;

#define N 3

void Print(int* nums) {
    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }
}

void ShortestPath(int graph[N][N], int v0, bool* final, int* dist, int* path) {
    //初始化三个数组
    int v, w;
    for (v = 0; v < N; v++) {
        final[v] = false;   //每个顶点都未加入最后集合
        dist[v] = graph[v0][v]; //与v0相接的顶点距离
        if (dist[v] < INT_MAX && v != v0) {
            path[v] = v0;   //在路径上加入v0
        }else path[v] = -1;
    }
    final[v0] = true;   //把v0加入集合
    dist[v0] = 0;   //v0->v0距离为0

    cout << "dist: ";
    Print(dist);
    cout << endl;
    cout << "path: ";
    Print(path);
    cout << endl;

    for (int i = 1; i < N; i++) {
        int min = INT_MAX;
        for (w = 0; w < N; w++) {
            if (!final[w] && dist[w] < min) {   ////找出未被确定且与源点直接相连顶点中权值最小的顶点
                v = w;
                min = dist[w];
            }
        }
        final[v] = true;    //将v加入集合
        for (w = 0; w < N; w++) {   //更新：从起点经过点v，到每个点的最短距离
            if ((!final[w]) &&(dist[v] + graph[v][w] < dist[w])) {
                dist[w] = dist[v] + graph[v][w];
                path[w] = v;
            }
        }
        cout << endl;
        cout << "dist: ";
        Print(dist);
        cout << endl;
        cout << "path: ";
        Print(path);
        cout << endl;
    }
}



int main() {
    int graph[N][N] = {
        {0,10,5},
        {INT_MAX,0,2},
        {INT_MAX,3,0}
    };
    bool final[N];   //标记各顶点是否已找到最短路径
    int dist[N];    //最短路径长度
    int path[N];    //路径上的前驱
    ShortestPath(graph, 0, final, dist, path);

    // cout << "dist: ";
    // Print(dist);
    // cout << endl;
    // cout << "path: ";
    // Print(path);
    // cout << endl;
}