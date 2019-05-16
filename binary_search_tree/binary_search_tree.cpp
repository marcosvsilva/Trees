#include <cstdio>
#include <iostream>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node* father;
};

node* create_node(int value);
void imput_tree(node* tree);
void insert_tree(node* tree, int value);
void insert_node(node* tree, node* no);
void insert_left(node* tree, node* no);
void insert_right(node* tree, node* no);
void print_tree(node* tree);
void remove_node(int value);

int main(){
    node* tree = NULL;
    imput_tree(tree);
    print_tree(tree);
    return 0;
};

node* create_node(int value){
    node* no = new node;
    no->value = value;
    no->left = NULL;
    no->right = NULL;
    no->father = NULL;
    return no;
};

void imput_tree(node* tree){
    int value;

    cout<<"Enter integer positive values in the tree (enter -1 to break the inserts): ";
    value = rand() % 100 -1;
    // cin>>value;

    if (value > 0){
        value = value;
        insert_tree(tree, value);
        imput_tree(tree);
    }
}

void insert_tree(node* tree, int value){
    node* no = create_node(value);

    if (tree == NULL) {
        tree = no;
    } else {
        insert_node(tree, no);
    } 
};

void insert_node(node* tree, node* no){
    if ((tree != NULL) && (tree->value != no->value)) {
        no->father = tree;
        no->value < tree->value ? insert_left(tree, no) : insert_right(tree, no);
    }
};

void insert_left(node* tree, node* no){
    if (tree->left == NULL)
        tree->left = no;
    else
        insert_node(tree->left, no);
}

void insert_right(node* tree, node* no){
    if (tree->right == NULL)
        tree->right = no;
    else
        insert_node(tree->right, no);
}

void print_tree(node* tree){
    if (tree != NULL) {
        if (tree->left != NULL)
            print_tree(tree->left);

        cout<<tree->value<<" ";

        if (tree->right != NULL)
            print_tree(tree->right);
    }
}