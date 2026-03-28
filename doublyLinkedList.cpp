#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DLL
{
public:
    Node *Head;
    Node *Tail;
    DLL()
    {
        Head = NULL;
        Tail = NULL;
    }
    bool isEmpty()
    {
        return (Head == NULL);
    }
    void InsertFirst(int newItem)
    {
        Node *newNode = new Node();
        newNode->data = newItem;
        newNode->prev = NULL;
        if (isEmpty())
        {
            newNode->next = NULL;
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
    }
    void InsertLast(int newItem)
    {
        Node *newNode = new Node();
        newNode->data = newItem;
        newNode->next = NULL;
        if (isEmpty())
        {
            newNode->next = NULL;
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
        }
    }
    void ForwardDisplay()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *Tmp = Head;
        while (Tmp != NULL)
        {
            cout << Tmp->data << " ";
            Tmp = Tmp->next;
        }
        cout << endl;
    }
    void BackwardDisplay()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *Tmp = Tail;
        while (Tmp != NULL)
        {
            cout << Tmp->data << endl;
            Tmp = Tmp->prev;
        }
        cout << endl;
    }
    int count()
    {
        if (isEmpty())
            return 0;
        Node *Tmp = Head;
        int counter = 0;
        while (Tmp != NULL)
        {
            counter++;
            Tmp = Tmp->next;
        }
        return counter;
    }
    bool isFound(int key)
    {
        Node *Tmp = Head;
        while (Tmp != NULL)
        {
            if (Tmp->data == key)
                return true;
            Tmp = Tmp->next;
        }
        return false;
    }
    void InsertBefore(int existingItem, int newItem)
{
    if (isEmpty())
        return;

    Node *Tmp = Head;
    while (Tmp != NULL && Tmp->data != existingItem)
        Tmp = Tmp->next;

    if (Tmp == NULL)  // مش موجود
        return;

    // لو الـ node دي هي الـ Head
    if (Tmp == Head)
    {
        InsertFirst(newItem);
        return;
    }

    // الحالة العادية (middle)
    Node *newNode = new Node();
    newNode->data = newItem;

    newNode->next = Tmp;
    newNode->prev = Tmp->prev;
    Tmp->prev->next = newNode;
    Tmp->prev = newNode;
}
void DeleteNode(int item)
{
    if (isEmpty())
        return;

    Node *Tmp = Head;
    while (Tmp != NULL && Tmp->data != item)
        Tmp = Tmp->next;

    if (Tmp == NULL)  // مش موجود
        return;

    // حالة فيها node واحدة بس
    if (Tmp == Head && Tmp == Tail)
    {
        Head = NULL;
        Tail = NULL;
    }
    // حالة الـ Head
    else if (Tmp == Head)
    {
        Head = Head->next;
        Head->prev = NULL;
    }
    // حالة الـ Tail
    else if (Tmp == Tail)
    {
        Tail = Tail->prev;
        Tail->next = NULL;
    }
    // حالة الـ middle
    else
    {
        Tmp->prev->next = Tmp->next;
        Tmp->next->prev = Tmp->prev;
    }

    delete Tmp;
}
};

int main()
{
    DLL list;

    // اختبار InsertFirst
    cout << "=== InsertFirst ===" << endl;
    list.InsertFirst(30);
    list.InsertFirst(20);
    list.InsertFirst(10);
    list.ForwardDisplay();   // 10 20 30
    list.BackwardDisplay();  // 30 20 10

    // اختبار InsertLast
    cout << "=== InsertLast ===" << endl;
    list.InsertLast(40);
    list.InsertLast(50);
    list.ForwardDisplay();   // 10 20 30 40 50

    // اختبار Count
    cout << "=== Count ===" << endl;
    cout << "Count: " << list.count() << endl;  // 5

    // اختبار isFound
    cout << "=== isFound ===" << endl;
    cout << "isFound(30): " << list.isFound(30) << endl;  // 1
    cout << "isFound(99): " << list.isFound(99) << endl;  // 0

    // اختبار InsertBefore
    cout << "=== InsertBefore ===" << endl;
    list.InsertBefore(10, 5);   // قبل الـ Head
    list.InsertBefore(30, 25);  // في الـ middle
    list.ForwardDisplay();  // 5 10 20 25 30 40 50

    // اختبار DeleteNode
    cout << "=== DeleteNode ===" << endl;
    list.DeleteNode(5);   // حذف الـ Head
    list.DeleteNode(50);  // حذف الـ Tail
    list.DeleteNode(25);  // حذف من الـ middle
    list.ForwardDisplay();  // 10 20 30 40

    // اختبار حذف عنصر مش موجود
    cout << "=== Delete not found ===" << endl;
    list.DeleteNode(99);
    list.ForwardDisplay();  // 10 20 30 40

    // اختبار لحد ما تفضل node واحدة
    cout << "=== Delete till one node ===" << endl;
    list.DeleteNode(10);
    list.DeleteNode(20);
    list.DeleteNode(40);
    list.ForwardDisplay();  // 30

    // اختبار حذف آخر node
    cout << "=== Delete last node ===" << endl;
    list.DeleteNode(30);
    list.ForwardDisplay();  // List is empty

    return 0;
}