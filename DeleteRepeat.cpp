#include <iostream>
using namespace std;

typedef struct Sql
{
    int data[9];
    int length;
}SqList;

void DelRepeat_1(int x, SqList &L);
void DelRepeat_2(int x, SqList &L);
void Print(SqList L);

int main() {
    SqList L = {{1,2,3,4,1,5,6,7,8}, 9};
    DelRepeat_1(1,L);
    Print(L);
    return 0;
}

void DelRepeat_1(int x, SqList &L){
    int j = 0;
    for (int i = 0; i < L.length;i++) {
        if (L.data[i] != x) {
            L.data[j] = L.data[i];
            j++;
        }
    }
    L.length = j;
}

void Print(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
}