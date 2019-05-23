#include <cstdio>
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node *father;
};

Node* create_node(int value);
Node* insert_node(Node* tree, Node* no);
Node* remove_node(Node* tree, int value);

void input_tree(Node* tree);
int input_remove();
void print_inorder(Node* tree);

int main(){
    Node *tree = NULL;
    input_tree(tree);
    return 0;
};

Node* create_node(int value){
    Node *no = new Node;
    no->value = value;
    no->left = NULL;
    no->right = NULL;
    no->father = NULL;
    return no;
};

Node* insert_node(Node* tree, int value){
    if ((tree != NULL) && (tree->value != value)){
        if (value > tree->value)
            tree->right = insert_node(tree->right, value);
        else
            tree->left = insert_node(tree->left, value);
    } else
        tree = create_node(value);
    
    return tree;
};

Node* remove_node(Node* tree, int value){
    if (tree != NULL) {
        if (tree->value == value) {
            Node *node_aux = NULL;

            if (tree->left != NULL) {
                node_aux = tree->left;
                
                if (tree->right != NULL)
                    node_aux->right = tree->right;
            }
            
            else if (tree->right != NULL)
                node_aux = tree->right;
            
            if (node_aux != NULL)
                node_aux -> father = tree->father;

            free(tree);
            tree = node_aux;
        }
        
        else if (tree->value > value)
            tree->left  = remove_node(tree->left, value);

        else
            tree->right = remove_node(tree->right, value);
    }

    return tree;
}

void input_tree(Node* tree){
    int value;

    system("clear");
    cout<<"|----------------------------------------------------------------------|"<<endl;
    cout<<"| Menu                                                                 |"<<endl;
    cout<<"| Enter integer positive values in the tree                            |"<<endl;
    cout<<"| Enter 0 to remove value tree                                         |"<<endl;
    cout<<"| Enter -1 to print tree                                               |"<<endl;
    cout<<"| Enter number < -1 to exit program                                    |"<<endl;
    cout<<"|----------------------------------------------------------------------|"<<endl;
    cout<<"Enter option: ";
    cin>>value;

    if (value > -2) {
        if (value > 0)
            tree = insert_node(tree, value);
        
        else if (value == 0)
            tree = remove_node(tree, input_remove());
        
        else
            print_inorder(tree);

        input_tree(tree);
    }
}

int input_remove(){
    int value_remove;
    system("clear");
    cout<<"Insert value for remove tree: ";
    cin>>value_remove;
    return value_remove;
}

void print_inorder(Node* tree){
    if (tree != NULL) {
        if (tree->left != NULL)
            print_inorder(tree->left);

        cout<<tree->value<<" ";

        if (tree->right != NULL)
            print_inorder(tree->right);
    }
}