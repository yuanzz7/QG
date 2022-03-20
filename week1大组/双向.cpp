#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#pragma warning(disable : 4996)
#pragma warning(disable : 26812)
#pragma warning(disable : 6011)
using namespace std;
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
    ElemType data;
    struct LNode* next;
    struct LNode* prior;
} LNode, * LinkedList;

//define Status
typedef enum Status {
    error,
    ok
} Status;
Status InitList(LinkedList* L);
void DestroyList(LinkedList* L);
Status DeleteList(LNode* p, ElemType* e);
Status InsertList(LNode* p, LNode* q);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, ElemType e);
/**************************************************************
*	Prototype Declare Section
**************************************************************/
char MenuText[8][20] = {
    "[A]   ��ʼ������   ",
    "[B]    ������    ",
    "[C]    ɾ������    ",
    "[D]    ɾ���ڵ�    ",
    "[E]    ��������    ",
    "[F]    ����Ԫ��    ",
    "[G]     �� ��      "

};
void displaymenu(int hilight)
{
    int i;
    printf("ѡ����һָ����ֱ��ʹ�÷������¼��������Ӧ����ĸ\nע��ʹ�÷������¼���ֱ������");
    printf("\n======================\n");
    for (i = 0; i < 7; i++) {
        if (i == hilight - 1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);  //����̨��ɫ�Ŀ���
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        printf("%s\n", MenuText[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("======================\n");

}
int main()
{
    LinkedList L = (LinkedList)malloc(sizeof(LinkedList));
    ElemType* e = (ElemType*)malloc(sizeof(int));
    char c = ' ';
    int sel = 1;
    displaymenu(sel);
    for (;;) {
        if (kbhit()) {
            c = getch();  //��ȡ����
            if (c == 42) {
                system("cls");
                displaymenu(sel);
            }
            if (GetAsyncKeyState(VK_UP)) {     //�жϰ���״̬
                sel = (sel > 1) ? sel - 1 : 7;
                Sleep(100);
                system("cls");
                displaymenu(sel);
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                sel = (sel < 8) ? sel + 1 : 1;
                Sleep(100);
                system("cls");
                displaymenu(sel);
            }

            if (c <= 'z' && c >= 'a')c = c - ('a' - 'A');   //�Զ������Сд
            if (c <= 'G' && c >= 'A') {            //ʹ����ĸѡ����
                switch (c)
                {
                case 'A': {  //��ʼ������
                    L->data = 1;
                    InitList(&L);
                    break; }
                case 'B': { int a, b;
                    cout << "������������������" << endl;
                    cin >> a;
                    cout << "������������뵽�ڼ���λ��" << endl;
                    cin >> b;
                    LNode* p, * q = (LNode*)malloc(sizeof(LNode));
                    q->data = a;
                    p = L;
                    for (int i = 0; i < b - 2; i++) {
                        p = p->next;
                    }
                    if (InsertList(p, q)) {
                        cout << "����ɹ�" << endl;
                    }
                    else cout << "����ʧ��" << endl;

                }
                case 'C':   DestroyList(&L);
                    cout << "ɾ���ɹ�" << endl;
                    break;
                case 'D':  int a;
                    cout << "����������Ҫɾ���Ľ��λ��" << endl;
                    cin >> a;
                    LNode* p;
                    p = L;
                    for (int i = 0; i < a - 2; i++) {
                        p = p->next;                    //��ָ�뵽��Ҫɾ���Ľ���ǰһ�����
                    }
                    DeleteList(p, e);
                    break;
                case 'E':  TraverseList(L);   break;
                case 'F':  SearchList(L, *e); break;
                case 'G':  break;
                default: cout << "�����������������ָ�" << endl;
                }
                sel = c - 'A' + 1;
            }
            else if (c == '\r') {        //ʹ�ûس���ѡ����
                if (sel == 7)return (0);
                switch ('A' + sel - 1)
                {
                case 'A': {  //��ʼ������
                    InitList(&L);
                    break; }
                case 'B': { int a, b;
                    cout << "������������������" << endl;
                    cin >> a;
                    cout << "������������뵽�ڼ���λ��" << endl;
                    cin >> b;
                    LNode* p, * q = (LNode*)malloc(sizeof(LNode));
                    q->data = a;
                    p = L;
                    for (int i = 0; i < b - 1; i++) {
                        p = p->next;
                    }
                    if (InsertList(p, q)) {
                        cout << "����ɹ�" << endl;
                    }
                    else cout << "����ʧ��" << endl;
                    break;
                }
                case 'C': DestroyList(&L);
                    cout << "ɾ���ɹ�" << endl;
                    break;
                case 'D': int a;
                    cout << "����������Ҫɾ���Ľ��λ��" << endl;
                    cin >> a;
                    LNode* p;
                    p = L;
                    for (int i = 0; i < a - 1; i++) {
                        p = p->next;
                    }
                    DeleteList(p, e);
                    break;
                case 'E': TraverseList(L);   break;
                case 'F': SearchList(L, *e); break;
                case 'G': break;
                default: break;
                }
            }
            if (c == 'G' || 'G' == 'A' + sel - 1) break;
        }
    }
}
Status InitList(LinkedList* L)//��ʼ������
{
    *L = (LinkedList)malloc(sizeof(LNode));
    (* L)->prior = NULL;
    int a;
    cout << "���������봴���Ľ�����" << endl;
    cin >> a;
    LinkedList q = *L;
    LinkedList p;
    for (int i = 0; i < a; i++) {
        p = (LinkedList)malloc(sizeof(LinkedList));
        p->data = 1;
        q->next = p;
        p->prior = q;
        q = p;
        p = NULL;
    }
    q->next = NULL;
    cout << "��ʼ������ɹ�" << endl;
    if (*L != NULL) {
        return ok;
    }
    else return error;
}
void DestroyList(LinkedList* L)//ɾ������
{
    LinkedList q;
    while (*L)
    {
        q = *L;
        *L = (*L)->next;
        free(q);
    }
}
Status InsertList(LNode* p, LNode* q)//������
{
    q->next = p->next;
    p->next = q;
    q->prior = p;
    (q->next)->prior = q;
    return ok;
}
Status DeleteList(LNode* p, ElemType* e)//ɾ���ڵ�
{
    LNode* q = p->next;
    *e = p->data;
    p->next = q->next;
    (q->next)->prior = p;
    q->next = NULL;
    q->prior = NULL;
    free(q);
    cout << "ɾ���ɹ�!" << endl;
    return ok;
}
void TraverseList(LinkedList L)
{
    cout << "�����е�����Ϊ�� ";
    LinkedList r=(LinkedList)malloc(sizeof(LNode));
    L = L->next;
    //������ʾ
    while (L)
    {
        cout << L->data;
        r = L; 
        L = L->next;
    }
    cout << endl;
    //������ʾ
    while (r->prior)
    {
        cout << r->data;
        r = r->prior;
    }
}
Status SearchList(LinkedList L, ElemType e)
{
    LinkedList p = L;
    int a = 0;
    cout << "��������Ҫ���ҵ�����" << endl;
    cin >> e;
    while (p->data != e) {
        p = p->next;
        a++;
        if (p == NULL) {
            cout << "δ�ҵ���Ҫ���ҵ����ݽ��" << endl;
            break;
        }

    }
    if (p != NULL)
        cout << "��Ҫ���ҵ����ݽڵ�Ϊ��" << a << "��" << endl;
    return ok;
}