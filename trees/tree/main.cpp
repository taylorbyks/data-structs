//
//  main.cpp
//  tree
//
//  Created by Taylor Schinvelski on 19/04/21.
//

#include <iostream>

using namespace std;

class Tree {
  private:
    typedef struct Node {
      int content;
      Node *left;
      Node *right;
    } Node;

    Node *root;
    int size;

  void preorder(Node *root) {
    if(root){
      printf("%i ,", root->content);
      preorder(root->left);
      preorder(root->right);
    }
  }

  void inorder(Node *root) {
    if(root){
      inorder(root->left);
      printf("%i ,", root->content);
      inorder(root->right);
    }
  }

  void postorder(Node *root) {
    if(root){
      postorder(root->left);
      postorder(root->right);
      printf("%i ,", root->content);
    }
  }

  public:
    Tree() {
      root = nullptr;
      size = 0;
    }

    ~Tree() {

    }

    bool insert(int data) {
      Node *temp = (Node*) malloc(sizeof(Node));

      temp->content = data;
      temp->left = nullptr;
      temp->right = nullptr;

      if(root == nullptr) {
        root = temp;
      } else {
        Node *current = root;
        Node *parent = nullptr;

        while(true){
          parent= current;

          if(data < parent->content) {
            current = current->left;

            if(current == nullptr) {
              parent->left = temp;
              return true;
            }
          } else {
            current = current->right;

            if(current == nullptr) {
              parent->right = temp;
              return true;
            }
          }
        }
      }
      return true;
    }

    bool remove(Node *root, int key) {


    }

    void inorderTraversal() {
      inorder(root);
    }

    void preorderTraversal() {
      preorder(root);
    }

    void postorderTraversal(){
      postorder(root);
    }

    Node *Root(){
      return root;
    }

    void search(int value) {
      bool founded = searchRecursion(root, value);

      printf("Founded: %i \n", founded);
    }

    bool searchRecursion(Node *current, int key) {
      if(!current) {
        return false;
      }

      if (key == current->content){
        return true;
      } else if(key < current->content) {
        searchRecursion(current->left, key);
      } else {
        searchRecursion(current->right, key);
      }

    }
};

int main() {
  Tree BinaryTree;

  BinaryTree.insert(1);
  BinaryTree.insert(2);
  BinaryTree.insert(3);
  BinaryTree.insert(5);
  BinaryTree.insert(4);

  printf("Inorder \n");
  BinaryTree.inorderTraversal();

  printf("\nPreorder \n");
  BinaryTree.preorderTraversal();

  printf("\nPostorder \n");
  BinaryTree.postorderTraversal();
  printf("\n");

  BinaryTree.search(6);

  //BinaryTree.remove(2);

  return 0;
}
