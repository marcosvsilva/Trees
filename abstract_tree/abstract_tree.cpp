#include <cstdio>
#include <iostream>

using namespace std;

struct node{
    int value;
    node *father;
    node *son;
    node *brother;
};

node* create_node(int value);
node* input_tree(node* tree);
node* search_node(node* tree, int value);
node* insert_node(node* tree, int father, int value);
node* remove_node(node* tree, int value);
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
        cout<<"| 2- Remove value for                                   |"<<endl;
        cout<<"| 3- Calcule height tree                                |"<<endl;
        cout<<"| 4- Print tree                                         |"<<endl;
        cout<<"|-------------------------------------------------------|"<<endl;
        cout<<"Insert operation: ";
        cin>>op;

        switch (op)
        {
        case 1:
            tree = input_tree(tree);
            break;

        case 2:
            int value;
            system("clear");
            cout<<"Insert value for remove tree: ";
            cin>>value;
            tree = remove_node(tree, value);
            break;           
        
        case 3:
            char aux2;
            system("clear");
            cout<<"Height of tree: "<<calcule_height_tree(tree)<<endl;
            cin>>aux2;
            break;

        case 4:
            char aux;
            system("clear");
            print_tree(tree);
            cin>>aux;
            break;
        }
    } while((0 < op) && (op < 5));

    return 0;
};

node* create_node(int value){
    node *nd = new node;
    nd->value = value;
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
        no = create_node(value);
    } else {
        cout<<"Enter father to insert son into tree: ";
        cin>>father;
        cout<<"Enter value from insert into tree: ";
        cin>>value;
        no = insert_node(tree, father, value);
    }
    
    return no;
};

node* insert_node(node* tree, int father, int value){
    if (tree != NULL){
        if (tree->value == father) {
            if (tree->son == NULL) {
                tree->son = create_node(value);
                tree->son->father = tree;
            } else
                tree->son = insert_brother(tree->son, value);
        } else {
            tree->son = insert_node(tree->son, father, value);
            tree->brother = insert_node(tree->brother, father, value);
        }
    }
    return tree;
};

node* insert_brother(node* tree, int value){
    if (tree->brother == NULL) {
        tree->brother = create_node(value);
        tree->brother->father = tree->father;
    } else
        tree->brother = insert_brother(tree->brother, value);
    
    return tree;
};

node* remove_node(node* tree, int value){
    if (tree != NULL) {
        if (tree->value == value) {
            node *no = tree->father;
            
            if (no->son == tree) {
                if (tree->brother != NULL)
                    no->son = tree->brother;
                
                else if (tree->son != NULL)
                    no->son = tree->son;
                
                free(tree);
                return no->son;
            } else {
                if (tree->brother != NULL)
                    no->brother = tree->brother;
                
                else if (tree->son != NULL)
                    no->brother = tree->son;
                
                free(tree);
                return no->brother;
            }
        } else {
            tree->son = remove_node(tree->son, value);
            tree->brother = remove_node(tree->brother, value);
        }
    }
    return tree;
};

void print_tree(node* tree){
    if (tree != NULL) {
        cout<<tree->value<<" "; 
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