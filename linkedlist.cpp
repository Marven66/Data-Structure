#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
};

class LinkedList
{
public:
    Node *Head;
    LinkedList()
    {
        Head = NULL;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *Tmp = Head;
        while (Tmp != NULL)
        {
            cout << Tmp->Data << " ";
            Tmp = Tmp->Next;
        }
        cout << endl;
    }

    int Count()
    {
        if (isEmpty())
            return 0;
        Node *Tmp = Head;
        int counter = 0;
        while (Tmp != NULL)
        {
            counter++;
            Tmp = Tmp->Next;
        }
        return counter;
    }

    bool isFound(int key)
    {
        Node *Tmp = Head;
        while (Tmp != NULL)
        {
            if (Tmp->Data == key)
                return true;
            Tmp = Tmp->Next;
        }
        return false;
    }

    bool isEmpty()
    {
        return (Head == NULL);
    }

    void InsertFirst(int newItem)
    {
        Node *newNode = new Node();
        newNode->Data = newItem;

        if (isEmpty())
        {
            newNode->Next = NULL;
            Head = newNode;
        }
        else
        {
            newNode->Next = Head;
            Head = newNode;
        }
    }

    void InsertBefore(int item, int newItem)
    {
        if (!isFound(item))
        {
            cout << "Item " << item << " not found" << endl;
            return;
        }
        Node *newNode = new Node();
        newNode->Data = newItem;
        if (Head->Data == item)
        {
            newNode->Next = Head;
            Head = newNode;
            return;
        }

        Node *Tmp = Head;
        while (Tmp->Next != NULL && Tmp->Next->Data != item)
        {
            Tmp = Tmp->Next;
        }
        newNode->Next = Tmp->Next;
        Tmp->Next = newNode;
    }

    void DeleteItem(int item)
    {
        if (isEmpty())
        {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        // إذا كان العنصر المراد حذفه هو العقدة الأولى
        if (Head->Data == item)
        {
            Node *temp = Head;
            Head = Head->Next;
            delete temp;
            cout << "Item " << item << " deleted successfully!" << endl;
            return;
        }

        // البحث عن العنصر في باقي القائمة
        Node *current = Head;
        while (current->Next != NULL && current->Next->Data != item)
        {
            current = current->Next;
        }

        // إذا تم العثور على العنصر
        if (current->Next != NULL)
        {
            Node *temp = current->Next;
            current->Next = current->Next->Next;
            delete temp;
            cout << "Item " << item << " deleted successfully!" << endl;
        }
        else
        {
            cout << "Item " << item << " not found in the list!" << endl;
        }
    }
};

int main()
{

    LinkedList lst;
    if (lst.isEmpty())
    {
        cout << "the list is empty" << endl;
    }

    lst.InsertFirst(50);
    lst.InsertFirst(30);
    lst.InsertFirst(20);

    cout << "Displaying list: ";
    lst.Display();

    cout << "Count: " << lst.Count() << endl;

    if (lst.isFound(50))
    {
        cout << "The item 50 is in the list" << endl;
    }
    else
    {
        cout << "50 NOT found" << endl;
    }

    if (lst.isFound(100))
    {
        cout << "The item 100 is in the list" << endl;
    }
    else
    {
        cout << "100 NOT found" << endl;
    }
    lst.InsertBefore(20, 70);
    lst.Display();
    lst.DeleteItem(30);
    lst.Display();

    return 0;
}