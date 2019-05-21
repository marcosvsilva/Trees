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
void input_tree(node* tree);
void insert_tree(node* tree, int value);
void insert_node(node* tree, node* no);
void insert_left(node* tree, node* no);
void insert_right(node* tree, node* no);
int input_node_remove();
void remove_node(int value);
void print_tree(node* tree);

int main(){
    node* tree = create_node(-1);
    input_tree(tree);
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

void input_tree(node* tree){
    int value;

    cout<<"|----------------------------------------------------------------------|"<<endl;
    cout<<"| Menu                                                                 |"<<endl;
    cout<<"| Enter integer positive values in the tree                            |"<<endl;
    cout<<"| Enter 0 to remove value tree                                         |"<<endl;
    cout<<"| Enter -1 to print tree                                               |"<<endl;
    cout<<"| Enter number < -1 to exit program                                    |"<<endl;
    cout<<"|----------------------------------------------------------------------|"<<endl;
    cout<<"Enter option: ";
    cin>>value;

    if (value > -1) {
        if (value > 0) {
            insert_tree(tree, value);
        } else if (value = 0) {
            remove_node(input_node_remove());
        } else {
            print_tree(tree);
        }

        input_tree(tree);
    }
}

void insert_tree(node* tree, int value){
    if (tree->value < 0) {
        tree->value = value;
    } else {
        node* no = create_node(value);
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

int imput_node_remove(){
    int value_remove;
    system("clear");
    cout<<"Insert value for remove tree: ";
    cin>>value_remove;
    return value_remove;
}

void remove_node(int value){

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