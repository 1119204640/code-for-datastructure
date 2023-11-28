#include <iostream>
using namespace std;

#define INF 100000

int main() {
    const int n = 4;
    int A[n][n] = { {0, 2, INF, INF},
                    {INF, 0, 1, 6}  ,
                    {5, INF, 0, 4}  ,
                    {3, INF, INF, 0}};
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
        //检查数组
        cout << "add NO." << k << " vertex as transit: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << A[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
}