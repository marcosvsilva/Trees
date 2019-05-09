#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct node{
    int information;
    node* father;
    node* son;
    node* brother;
};

void insert_son(node* node_father, int information);
void inser_brother(node* node_brother, int information);
void print_tree(node* tree);

int main(){
    node* tree = new node;
    tree->information = 1;
    insert_son(tree, 2);
    insert_son(tree, 3);
    print_tree(tree);
    return 0;
};

void insert_son(node* node_father, int information){
    if (node_father->brother == NULL){
        node* node_son = new node;
        node_son ->information = information;
        node_son->father = node_father;
        node_son->brother = NULL;
        node_father->son = node_son;
    } else{
        inser_brother(node_father->brother, information);
    }
};

void inser_brother(node* node_brother, int information){
    node* node_brother_new = new node;
    node_brother_new->information = information;
    node_brother_new->brother = NULL;
    node_brother_new->father = node_brother->father;
    node_brother->brother = node_brother_new;    
};

void print_tree(node* tree){
    if (tree != NULL){
        cout<<tree->information;
        
        if (tree->brother != NULL){
            print_tree(tree->brother);
        }   

        if (tree->son != NULL){
            print_tree(tree->son);
        }
    }
};