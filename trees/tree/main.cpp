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
  
    Node *newNode(int value) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->content = value;
      newNode->left = newNode->right = nullptr;
      return newNode;
    }

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
    
    Node *findMinimumValueNode(Node *current){
      while (current && current->left != nullptr)
        current = current->left;
   
      return current;
    }
    
    Node *removeNode(Node *root, int key) {
      if(root != nullptr){
        if (key == root->content){
          if (root->left == nullptr) {
              Node* temp = root->right;
              free(root);
              return temp;
          }
          else if (root->right == nullptr) {
              Node* temp = root->left;
              free(root);
              return temp;
          }
          
          Node* temp = findMinimumValueNode(root->right);
          root->content = temp->content;
          
          root->right = removeNode(root->right, temp->content);
        } else if(key < root->content) {
          root->left = removeNode(root->left, key);
        } else {
          root->right = removeNode(root->right, key);
        }
      }
      return root;
    }
    
    bool searchRecursion(Node *current, int key) {
      if(current) {
        if (key == current->content){
          printf("Encontrou");
          return true;
        } else if(key < current->content) {
          searchRecursion(current->left, key);
        } else {
          searchRecursion(current->right, key);
        }
      }
      return false;
    }

  public:
    Tree() {
      root = nullptr;
      size = 0;
    }

    ~Tree() {

    }

    bool insert(int data) {
      Node *temp = newNode(data);

      if(root == nullptr) {
        root = temp;
      } else {
        Node *current = root;
        Node *parent = nullptr;

        while(true){
          parent = current;

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

    void remove(int key) {
      removeNode(root, key);
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
};

int main() {
  Tree BinaryTree;

  BinaryTree.insert(1);
  BinaryTree.insert(2);
  BinaryTree.insert(3);
  BinaryTree.insert(5);
  BinaryTree.insert(4);
  BinaryTree.remove(1);

  printf("Inorder \n");
  BinaryTree.inorderTraversal();

  printf("\nPreorder \n");
  BinaryTree.preorderTraversal();

  printf("\nPostorder \n");
  BinaryTree.postorderTraversal();
  printf("\n");

  BinaryTree.search(2);
  BinaryTree.search(1);
  

  return 0;
}
