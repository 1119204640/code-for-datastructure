#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode, *LinkList;

//初始化
bool InitList(LinkList &L) {
    L = new LNode();
    L->next = NULL;
    return true;
}

//前插法
void CreateList_H(LinkList &L, int n) {
    L = new LNode();
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        LNode* p = new LNode();
        cout << "enter number:";
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//后插法
void CreateList_R(LinkList &L, int n) {
    L = new LNode;
    L->next = NULL;
    LNode *r = L;
    for (int i = 0; i < n; i++) {
        LNode *p = new LNode;
        cout << "enter number:";
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//取值
bool GetElem(LinkList L, int i, ElemType &e) {
    LNode *p = L->next;
    int j = 1;
    if (!p || i < 1) {
        return false;
    }
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    e = p->data;
    return true;
}

//查找
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

//删除
bool ListDelete(LinkList &L, int i) {
    LNode *p = L;
    int j = 0;
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if ((!p->next) || (j > i-1)) {
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

//删除第一个最大的元素
void DeleteMax(LinkList &L) {
    LNode *r = L;
    LNode *p = L->next;
    LNode *maxp = r->next;
    while (p != NULL) 
    {
        if (maxp->data < p->data) {
            maxp = p;
        }
        p = p->next;
    }
    while (r->next != maxp) {
        r = r->next;
    }
    r->next = maxp->next;
    free(maxp);
}

void Print(LinkList L) {
    LNode *p = L->next;
    while (p) {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}

int main(){
    LinkList L;
    // CreateList_H(L, 3);
    CreateList_R(L, 3);
    // ListDelete(L, 2);
    Print(L);
    DeleteMax(L);
    Print(L);
    return 0;
}