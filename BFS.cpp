#include <iostream>
using namespace std;

#define n 5

//循环队列，空：front == rear; 满：(rear + 1) % n == front
typedef struct A
{
    int top = 0;
    int rear = 0;
    int data[n];
}Queue;

int main() {
    int nums[n][n] = {{0,0,1,0,1},
                      {1,0,0,1,0},
                      {0,0,0,0,1},
                      {0,0,1,0,0},
                      {0,0,0,0,0}};
    int indeg[n] = {0};
    int res[n];
    int count = 0;
    Queue q;

    //create indegree
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (nums[i][j] == 1) {
                indeg[j]++;
            }
        }
    }

    // check indegree
    cout <<  "indegree: ";
    for (int i = 0; i < n; i++) {
        cout << indeg[i] << " ";
    }
    
    while (count < 5){
        for (int i = 0 ; i < n; i++) {
            if (indeg[i] == 0) {  //选入度为0的入队
                q.data[q.rear] = i;
                q.rear = (q.rear + 1) % n;
            }
        }
        while (q.top != q.rear) //队列非空
        {
            int curr = q.data[q.top];

            for (int j = 0; j < n; j++) {
                if (nums[curr][j] > 0) { //该点的出度不为0
                    indeg[j]--;
                }
            }
            res[count++] = curr;
            indeg[curr] = -1; //把已出答案的节点下标在入度表里减1
            q.top = (q.top + 1) % n;
        }
    }
    

    //check answer
    cout << endl <<  "BFS: ";
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    
    //check indegree
    cout << endl <<  "indegree: ";
    for (int i = 0; i < n; i++) {
        cout <<indeg[i] << " ";
    }
    return 0;
}