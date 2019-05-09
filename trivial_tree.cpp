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
void inser_brother(node* node_son, int information);
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
    if (node_father->son == NULL){
        node* node_son = new node;
        node_son->information = information;
        node_son->father = node_father;
        node_son->brother = NULL;
        node_father->son = node_son;
    } else{
        inser_brother(node_father->son, information);
    }
};

void inser_brother(node* node_son, int information){
    node* node_brother = new node;
    node_brother->information = information;
    node_brother->father = node_son->father;
    node_son->brother = node_brother;    
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