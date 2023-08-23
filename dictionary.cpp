/*Dictionary stores keywords & its meanings. Provide
facility for adding new keywords, deleting keywords, updating values of any entry. Provide
facility to display whole data sorted in ascending/ Descending order. Also find how many
maximum comparisons may require for finding any keyword. Use Binary Search Tree for
implementation.
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    char k[20], v[20];
    node *left, *right;
};

class dict
{
public:
    node *root;
    void create();
    void display(node *);
    void insert(node *root, node *temp);
    int search(node *, char[]);
    int update(node *, char[]);
    node *del(node *, char[]);
    node *min(node *);
};

void dict::create()
{
    node *temp;
    temp = new node;
    cout << "\nEnter the Key:";
    cin >> temp->k;
    cout << "\nEnter the Value:";
    cin >> temp->v;

    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else
        insert(root, temp);
}

void dict::display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << "\nKey :" << root->k;
        cout << "\nValue :" << root->v;
        display(root->right);
    }
}

void dict::insert(node *root, node *temp)
{
    if (strcmp(temp->k, root->k) < 0)
    {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else
    {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

int dict::search(node *root, char k[20])
{
    int count = 0;
    while (root != NULL)
    {
        count++;
        if (strcmp(k, root->k) == 0)
        {
            cout << "\nNumber of comparisons:" << count;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

int dict::update(node *root, char k[20])
{
    while (root != NULL)
    {
        if (strcmp(k, root->k) == 0)
        {
            cout << "\nEnter the new value for the key " << root->k << ":";
            cin >> root->v;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

node *dict::del(node *root, char k[20])
{
    node *temp;
    if (root == NULL)
    {
        cout << "\nNo Dictionary Found";
        return root;
    }
    if (strcmp(k, root->k) < 0)
    {
        root->left = del(root->left, k);
        return root;
    }
    if (strcmp(k, root->k) > 0)
    {
        root->right = del(root->right, k);
        return root;
    }
    if (root->right == NULL && root->left == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }
    else if (root->left == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    temp = min(root->right);
    strcpy(root->k, temp->k);
    root->right = del(root->right, temp->k);
    return root;
}

node *dict::min(node *n)
{
    while (n->left != NULL)
        n = n->left;
    return n;
}

void clear(){
    try
    {
        system("cls");
    }
    catch(const std::exception& e)
    {
        system("clear");
        std::cerr << e.what() << '\n';
    }
    
}

int main()
{
    clear();
    int choice;
    dict d;
    d.root = NULL;
    bool run = true;
    while (run)
    {
        cout << "\nMenu" << endl;
        cout << "[1] Create" << endl;
        cout << "[2] Display" << endl;
        cout << "[3] Search" << endl;
        cout << "[4] Update" << endl;
        cout << "[5] Delete" << endl;
        cout << "[6] Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL)
                cout << "\nNo Dictionary Found";
            else
                d.display(d.root);
            break;
        case 3:
            if (d.root == NULL)
                cout << "\nNo Dictionary Found";
            else
            {
                cout << "\nEnter the key to be found:";
                char k[20];
                cin >> k;
                if (d.search(d.root, k) == 1)
                    cout << "\nKeyword Found";
                else
                    cout << "\nNo Keyword Found";
            }
            break;
        case 4:
            if (d.root == NULL)
                cout << "\nNo Dictionary Found";
            else
            {
                cout << "\nEnter the key to be Updated:";
                char k[20];
                cin >> k;
                if (d.update(d.root, k) == 1)
                    cout << "\nMeaning for the given Keyword Updated!";
                else
                    cout << "\nMeaning not Updated!";
            }
            break;
        case 5:
            if (d.root == NULL)
                cout << "\nNo Dictionary Found";
            else
            {
                cout << "\nEnter the key to be Deleted:";
                char k[20];
                cin >> k;
                d.root = d.del(d.root, k);
                cout << "\nKeyword Deleted!";
            }
            break;
        case 6:
            run = false;
            exit(0);
        default:
            cout<<"Invalid Choice!";
            break;
        }
    }
    return 0;
}
