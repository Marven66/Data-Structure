#include <iostream>
using namespace std;

class arraylist
{
private:
    int *arr;
    int mz; // max size
    int index;

public:
    arraylist(int s)
    {
        if (s < 0)
            mz = 10;
        else
            mz = s;
        index = 0;
        arr = new int[mz];
    }

    ~arraylist()
    {
        delete[] arr;
    }

    bool isEmpty() { return index == 0; }
    bool isFull() { return index == mz; }
    int getSize() { return index; }
    void print()
    {
        for (int i = 0; i < index; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void InsertAt(int pos, int element) // pos = position
    {
        if (isFull())
        {
            cout << "List is Full" << endl;
        }
        else if (pos < 0 || pos > index)
        {
            cout << "out of the range" << endl;
        }
        else
        {
            for (int i = index; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            index++;
        }
    }

    void insertLast(int element)
    {
        if (isFull())
        {
            cout << "List is Full" << endl;
        }
        else
        {
            arr[index] = element;
            index++; 
        }
    }

    void RemoveAt(int pos)
    {
        if (isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else if (pos < 0 || pos >= index) 
        {
            cout << "out of the range" << endl;
        }
        else
        {
            for (int i = pos; i < index - 1; i++) 
            {
                arr[i] = arr[i + 1];
            }
            index--;
        }
    }

    void search(int e)
    {
        for (int i = 0; i < index; i++)
        {
            if (arr[i] == e)
                cout << i << " "; // Added space for better output
        }
        cout << endl; // Added newline
    }
};

int main()
{
    arraylist al(10);
    al.insertLast(1);
    al.insertLast(2);
    al.insertLast(3);
    al.insertLast(4);
    al.insertLast(5);
    al.InsertAt(2, 30);
    al.print(); // Should output: 1 2 30 3 4 5
    return 0;
}
