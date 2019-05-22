#include <cstdio>
#include <iostream>

using namespace std;

struct node{
    int information;
    node *father;
    node *son;
    node *brother;
};

node* create_node(int value);
node* input_tree(node* tree);
node* insert_node(node* tree, int father, int value);
node* insert_brother(node* tree, int value);
void print_tree(node* tree);
int calcule_height_tree(node* root);

int main(){
    node* tree = NULL;
    int op;

    do {
        system("clear");
        cout<<"|-------------------------------------------------------|"<<endl;
        cout<<"| ----------------------- MENU -----------------------  |"<<endl;
        cout<<"| 1- Insert value for enter new value in abstract tree  |"<<endl;
        cout<<"| 2- Print tree                                         |"<<endl;
        cout<<"| 3- Calcule height tree                                |"<<endl;
        cout<<"|-------------------------------------------------------|"<<endl;
        cout<<"Insert operation: ";
        cin>>op;
        // op=1;

        switch (op)
        {
        case 1:
            tree = input_tree(tree);
            break;
        
        case 2:
            char aux;
            system("clear");
            print_tree(tree);
            cin>>aux;
            break;
        
        case 3:
            char aux2;
            system("clear");
            cout<<"Height of tree: "<<calcule_height_tree(tree)<<endl;
            cin>>aux2;
            system("pause");
        }
    } while((0 < op) && (op < 4));

    return 0;
};

node* create_node(int value){
    node *nd = new node;
    nd->information = value;
    nd->father = NULL;
    nd->brother = NULL;
    nd->son = NULL;
    return nd;
};

node* input_tree(node* tree){
    int father, value;
    node *no = NULL;
    
    system("clear");
    if (tree == NULL) {
        cout<<"Enter value from insert into tree: ";
        cin>>value;
        // value = 0;
        no = create_node(value);
    } else {
        cout<<"Enter father to insert son into tree: ";
        cin>>father;
        // father = 0;
        cout<<"Enter value from insert into tree: ";
        cin>>value;
        // value = 0;
        no = insert_node(tree, father, value);
    }
    
    return no;
};

node* insert_node(node* tree, int father, int value){
    if (tree != NULL) {
        if (tree->information == father) {
            if (tree->son == NULL) {
                tree->son = create_node(value);
                tree->son->father = tree;
            } else
                tree->son = insert_brother(tree->son, value);
        }
        else {
            if (tree->son != NULL)
                tree->son = insert_node(tree->son, father, value);
            
            else if (tree->brother != NULL)
                tree->brother = insert_node(tree->brother, father, value);
        }
    }
    return tree;
};

node* insert_brother(node* tree, int value){
    if (tree->brother == NULL) {
        node *no = create_node(value);
        no->father = tree->father;
        tree->brother = no;
    } else
        tree->brother = insert_brother(tree->brother, value);
    
    return tree;
};

void print_tree(node* tree){
    if (tree != NULL) {
        cout<<tree->information<<" "; 
        print_tree(tree->son);
        print_tree(tree->brother);
    } else
        cout<<". ";
};

int calcule_height_tree(node* tree){ 
    if (tree != NULL) {
        int height_son = calcule_height_tree(tree->son);
        int height_brother = calcule_height_tree(tree->brother) - 1;
        return 1 + max(height_son, height_brother);
    } else
        return -1;
};