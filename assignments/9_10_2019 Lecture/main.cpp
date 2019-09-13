#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d, Node *n = NULL)
    {
        data = d;
        next = n;
    }
};

class List
{
public:
    List()
    {
        first = NULL;
        last = NULL;
    }

    void add(int ndata)
    {
        if (last != NULL)
        {
            // list is not empty, place at the end
            last->next = new Node(ndata);
            last = last->next;
        }
        else
        {
            // list is empty
            first = new Node(ndata);
            last = first;
        }
    }

    void del(int key)
    {
        Node *temp = first;
        while (temp->data != key) //removed a "-> data" because it was skipping a node after loop completed
        {
            temp = temp->next;
        }
        Node *temp_del = temp->next;
        *temp = *temp->next; //added * to arguement for both instances of temp
        delete temp_del;     //i'm assuming its because we lose the register and thats why it loops infinitley
        cout << "this is the current node " << temp->data << endl; //added to check to make sure we were on the correct node by the end of the function
    }

    void print()
    {
        Node *temp = first;
        while (temp->next != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

private:
    Node *first;
    Node *last;
};

int main()
{
    // Node second(91);
    // Node first(17, &second);

    // // default constructor
    // Node def;
    // cout << def.data << ' ' << def.next << endl;

    // cout << first.next->data << endl;

    List myList;
    srand(42);
    for (int i = 0; i < 10; i++)
    {
        myList.add(rand() % 100 + 1);
    }
    myList.print();
    myList.del(84);
    myList.print();
}