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
int calcule_height_tree(node* root);

int main(){
    //height 0
    node* tree = create_node();
    
    //height 1
    tree->information = 1; //root
    insert_son(tree, 2);   //son of root
    insert_son(tree, 3);   //son of root
    
    //height 2
    node* son1 = tree->son;   //root = 2
    insert_son(son1, 4);      //son of 2
    insert_son(son1, 5);      //son of 2
    
    node* brother1 = son1->brother; //root = 3
    insert_son(brother1, 6);        //son of 3
    insert_son(brother1, 7);        //son of 3

    //height 3
    node* son2 = son1->son; //root = 4
    insert_son(son2, 8);    //son of 4
    insert_son(son2, 9);    //son of 4
    
    node* brother2 = son2->brother; //root = 5
    insert_son(brother2, 10);       //son of 5
    insert_son(brother2, 11);       //son of 5

    node* son3 = brother1->son; //root = 6
    insert_son(son3, 12);       //son of 6
    insert_son(son3, 13);       //son of 6

    node* brother3 = son3->brother; //root = 7
    insert_son(brother3, 14);       //son of 7    
    insert_son(brother3, 15);       //son of 7

    //height 4
    node* son4 = brother3->son; //root = 10
    insert_son(son4, 16);       //son of 10

    //height 5
    node* son5 = son4->son; //root = 16
    insert_son(son5, 17);   //son of 16

    cout<<"PRINT TREE:"<<endl;
    print_tree(tree);

    cout<<endl<<"HEIGHT OF TREE: "<<calcule_height_tree(tree)<<endl;
    return 0;
};

void input_tree(node* tree){
    int father, information;
    cout<<"Enter the [parent, value] from no to insert into the /tree:";
    cin>>father>>information;
    if ((father != 0) && (information != 0)){
        input_tree(tree);
    }
};

node* create_node(){
    node *nd = new node;
    nd->information = 0;
    nd->father = NULL;
    nd->brother = NULL;
    nd->son = NULL;
    return nd;
};

void insert_son(node* node_father, int information){
    if (node_father->son == NULL){
        node* node_son = create_node();
        node_son->information = information;
        node_son->father = node_father;
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
        cout<<tree->information<<" ";
        print_tree(tree->son);
        print_tree(tree->brother);
    } else {
        cout<<". ";
    }
};

int calcule_height_tree(node* root){ 
    if (root != NULL){
        int height_son = calcule_height_tree(root->son);
        int height_brother = calcule_height_tree(root->brother) - 1;
        return 1 + max(height_son, height_brother);
    } else{
        return -1;
    }
};