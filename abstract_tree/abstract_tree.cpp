#include <cstdio>
#include <iostream>

using namespace std;

struct node{
    int information;
    node* father;
    node* son;
    node* brother;
};

node* create_node();
void input_tree(node* tree);
void insert_son(node* node_father, int information);
void inser_brother(node* node_son, int information);
void print_tree(node* tree);

int main(){
    node* tree = create_node();
    tree->information = 1;
    insert_son(tree, 2);
    insert_son(tree, 3);
    print_tree(tree);
    return 0;
};

void input_tree(node* tree){
    int father, information;
    cout<<"Enter the [parent, value] from no to insert into the tree:";
    cin>>father>>information;
    if ((father != 0) && (information != 0){
        input_tree(tree)
    }
}

node* create_node(){
    node *nd = new node;
    nd->information = 0;
    nd->father = NULL;
    nd->brother = NULL;
    nd->son = NULL;
    return nd;
}

void insert_son(node* node_father, int information){
    if (node_father->son == NULL){
        node* node_son = create_node();
        node_son->information = information;
        node_son->father = node_father;
        node_son->brother = NULL;
        node_father->son = node_son;
    } else{
        inser_brother(node_father->son, information);
    }
};

void inser_brother(node* node_son, int information){
    node* node_brother = create_node();
    node_brother->information = information;
    node_brother->father = node_son->father;
    node_son->brother = node_brother;    
};

void print_tree(node* tree){
    if (tree != NULL){
        printf("%d\n",  tree->information);
        
        if (tree->brother != NULL){
            print_tree(tree->brother);
        }   

        if (tree->son != NULL){
            print_tree(tree->son);
        }
    }
};