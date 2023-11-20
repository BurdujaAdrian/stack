#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>

using namespace std;
const int MAX_SIZE = 3;
int stacksize = 0;
int toptype[100];
int toptypeindex = 0;

class StackNode {
public:
    float data;
    StackNode* next;
};


StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    stacksize++;
    return stackNode;
}

void pushint(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    toptypeindex++;
    toptype[toptypeindex] = 1;
    cout << data << " pushed to stack\n";
}

void pushfloat(StackNode** root, float data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    toptypeindex++;
    toptype[toptypeindex] = 2;
    cout << data << " pushed to stack\n";
}

void pushchar(StackNode** root, char data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    toptypeindex++;
    toptype[toptypeindex] = 3;
    cout << data << " pushed to stack\n";
}


bool isEmpty(StackNode* root)
{
    return root==nullptr;
}
void Push(StackNode** root)
{
    cout << "\nChoose data type to push:";
    string choice;
    cin >> choice;
    if (choice == "int" || choice == "integer")
    {
        int i;
        cout << "\nInput the integer:";
        cin >> i;
        if (typeid(i) == typeid(int)) {
            pushint(root, i);
        }
        else {
            cout << "\nis not integer\n";
        }
    }else
    if (choice == "float")
    {
        float f;
        cout << "\nInput the float:";
        cin >> f;
        if (typeid(f) == typeid(float)) {
            pushfloat(root, f);
        }
        else {
            cout << "\nis not float\n";
        }
    }
    else
        if (choice == "char" || choice == "character")
        {
            char c;
            cout << "\nInput the char:";
            cin >> c;
            if (typeid(c) == typeid(char)) {
                pushchar(root, c);
            }
            else {
                cout << "\nis not char\n";
            }
        }
        else cout << "\ninvalid data type\n";
}




void pop(StackNode** root)
{
    if (isEmpty(*root))
        cout << "\nStack is empty";
    else if (toptype[toptypeindex] == 3)
    {
        StackNode* temp = *root;
        *root = (*root)->next;
        cout << "popped:" << char(temp->data);
        toptypeindex--;
        stacksize--;
        free(temp);
    }
    else if (toptype[toptypeindex] == 2)
    {
        StackNode* temp = *root;
        *root = (*root)->next;
        cout << "popped:" << float(temp->data);
        toptypeindex--;
        stacksize--;
        free(temp);
    }
    else
    {
        StackNode* temp = *root;
        *root = (*root)->next;
        cout << "popped:" << temp->data;
        toptypeindex--;
        stacksize--;
        free(temp);
    }


}

void peek(StackNode* root)
{
    if (isEmpty(root))
        cout << "\nThere is no to element\n";
    else if (toptype[toptypeindex] == 3)
        cout << char(root->data);
    else if (toptype[toptypeindex] == 2)
        cout <<float(root->data);
    else
        cout << root->data;
}


bool IsFull() 
{ 
    return stacksize==MAX_SIZE; 
}

int main()
{int c;
 
StackNode* root = NULL;

    bool r = true;
    while (r)
    {
        cout << "1.Push \n"
            << "2.Pop \n"
            << "3.Peek \n"
            << "4.IsEmpty \n"
            << "5.IsFull \n"
            << "0.Exit program \n"
            << "\n Enter your option:";

        cin >> c;

        switch (c)
        {
        case 1:
            if (!IsFull())
                Push(&root);
            else cout << "\nStack overflow\n";
            break;

        case 2:
            pop(&root); break;

        case 3:
            peek(root); break;

        case 4:
            if (isEmpty(root))
                cout << "\nStack is empty\n";
            else
                cout << "\nStack is not empty\n";
            break;

        case 5:
            if (IsFull())
                cout << "\nStack is full\n";
            else
                cout << "\nStack is not full\n";
            break;
        case 0:
            cout << "\n\nExiting the program.";
            r = false;
            return 0;

        default:
            cout << "\n invalid input \n";
        }

        cout << "\n\nStack Contents:";
        cout << stacksize << endl;
        cout << endl;
    }

    return 0;
}