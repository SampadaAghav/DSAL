 

 
#include <bits/stdc++.h>
using namespace std;

struct node
{
    char name[10];
    int childCount;
    node *child[10];
} * root;

class tree
{
public:
    tree()
    {
        root = NULL;
    }
    void createTree();
    void display(node *r);
};

void tree::createTree()
{
    root = new node;
    cout << "\nEnter the Books name:";
    cin >> root->name;

    cout << "Enter the number of the chapters:";
    cin >> root->childCount;
    for (int i = 0; i < root->childCount; i++)
    {
        root->child[i] = new node;
        cout << "Enter the "<<i<<" chapter name:";
        cin >> root->child[i]->name;
        cout << "Enter the Number of Sections in Chapter "<<root->child[i]->name;
        cin >> root->child[i]->childCount;

        for (int j = 0; j < root->child[i]->childCount; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter the "<<j<<" section name:";
            cin >> root->child[i]->child[j]->name;
            cout << "Enter the Number of subSections in Section "<<root->child[i]->child[j]->name;
            cin >> root->child[i]->child[j]->childCount;
        }
    }
}

void tree::display(node *r)
{
    if (r != NULL)
    {
        cout << "Book Name:" << r->name<<endl;
        for (int i = 0; i < r->childCount; i++)
        {
            cout << "Chapter" << i + 1 << " " << r->child[i]->name<<endl;
            for (int j = 0; j < r->child[i]->childCount; j++)
            {
                cout << "Section" << j + 1 << " " << r->child[i]->child[j]->name<<endl;
            }
        }
    }
}
int main()
{
    int choice;
    tree t;
    bool run = true;
    while (run)
    {
        cout << "Menu" << endl;
        cout << "[1] Create" << endl;
        cout << "[2] Display" << endl;
        cout << "[3] Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.createTree();
            break;
        case 2:
            t.display(root);
            break;
        case 3:
            run = false;
            break;
        default:
            cout << "Invalid Choice";
            break;
        }
    }
    return 0;
}
