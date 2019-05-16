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
void insert_tree(node* tree, int value);
void insert_node(node* tree, node* no);
void insert_left(node* tree, node* no);
void insert_right(node* tree, node* no);
void print_tree(node* tree);
void remove_node(int value);

int main(){
    node* tree = create_node(28);

    insert_tree(tree, 04);
    insert_tree(tree, 30);
    insert_tree(tree, 27);
    insert_tree(tree, 29);
    insert_tree(tree, 50);
    insert_tree(tree, 02);
    insert_tree(tree, 15);
    insert_tree(tree, 13);
    insert_tree(tree, 92);
    insert_tree(tree, 14);
    insert_tree(tree, 22);
    insert_tree(tree, 17);
    insert_tree(tree, 16);
    insert_tree(tree, 54);
    insert_tree(tree, 07);
    insert_tree(tree, 01);
    insert_tree(tree, 11);
    
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

void insert_tree(node* tree, int value){
    node* no = create_node(value);
    insert_node(tree, no);
};

void insert_node(node* tree, node* no){
    if (tree != NULL) {
        no->father = tree;
        no->value < tree->value ? insert_left(tree, no) : insert_right(tree, no);
    }
};

void insert_left(node* tree, node* no){
    if (tree->left == NULL) {
        tree->left = no;
    } else {
        insert_node(tree->left, no);
    }
}

void insert_right(node* tree, node* no){
    if (tree->right == NULL) {
        tree->right = no;
    } else {
        insert_node(tree->right, no);
    }
}

void print_tree(node* tree){
    if (tree->left != NULL)
        print_tree(tree->left);

    cout<<tree->value<<" ";

    if (tree->right != NULL)
        print_tree(tree->right);
}