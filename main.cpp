#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* next;
};

Node* head = NULL;

void addWord(string word)
{
    Node* newNode = new Node();
    newNode->data = word;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = NULL;
    }
}

void undo()
{
    if(head == NULL)
    {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    string word;

    while(true)
    {
        cout << "Enter word: ";
        cin >> word;

        if(word == "EXIT")
        {
            break;
        }
        else if(word == "UNDO")
        {
            undo();
        }
        else
        {
            addWord(word);
        }

        display();
    }

    return 0;
}
