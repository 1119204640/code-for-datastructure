//线性表 顺序结构

#include <iostream>
using namespace std;

#define MAXSIZE 10
#define ElemType int

typedef struct
{
    ElemType *elem;
    int length;
}SqList;

void PrintList(SqList L);  //打印顺序表
bool InitList(SqList &L);   //初始化
bool Insert(SqList &L, ElemType e, int i); //插入e的值，到第i个位置
bool GetElem(SqList L, ElemType &e, int i); //取第i个元素的值，存储在e
int LocateElem(SqList L, ElemType e); //查找第一个与e的元素，若找到返回该元素的位置（下标-1），若找不到返回0
bool DeleElem(SqList &L, int i); //删除第i个元素

int main() {
    SqList L;
    InitList(L);

    Insert(L, 1, 1);
    Insert(L, 2, 2);
    Insert(L, 4, 3);
    Insert(L, 3, 3);

    PrintList(L);

    ElemType e;
    GetElem(L, e, 2);
    cout << endl << e << endl;

    cout << LocateElem(L, 3) << endl;

    DeleElem(L, 3);

    PrintList(L);
    
    return 0;
}

//初始化
bool InitList(SqList &L) {
    L.elem = new ElemType[MAXSIZE]; //keycode
    if (!L.elem) {
        return false;
    }
    L.length = 0; //顺序表初始长度为0
    return true;
}

//插入e的值，到第i个位置
bool Insert(SqList &L, ElemType e, int i) {
    if (i < 1 || i > L.length + 1) {
        cout << "number error!";
        return false;
    } //判断i是否越界

    if (L.length == MAXSIZE) {
        cout << "the list has been full!";
        return false;
    }//判断是否有空位
    
    for (int j = L.length; j >= i; j--) { //keycode
        L.elem[(j-1)+1] = L.elem[(j-1)];
    }//将第i个到第n个全部后移一位

    L.elem[i-1] = e; //插入e到第i个位置
    
    L.length ++; //更新顺序表长度

    return true;
} 

//取第i个元素的值，存储在e
bool GetElem(SqList L, ElemType &e, int i) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.elem[i-1];
    return true;
}

//查找第一个与e的元素，若找到返回该元素的位置（下标-1），若找不到返回0
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i+1;
        }
    }
    return 0;
}

//删除第i个元素
bool DeleElem(SqList &L, int i) {
    if (i < 1 || i > L.length) {
        return false;
    }
    for (int j = i + 1; j <= L.length; j++) {
        L.elem[(j-1)-1] = L.elem[j-1];
    }
    L.length --;
    return true;
}

//打印顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << ' ';
    }
}