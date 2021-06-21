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
      printf("Visiting element: ");

      printf("%d, ", root->content);

      if(key == root->left->content) {
        printf("f %d, ", root->left->content);
        return true;
      } else if(key == root->right->content) {
        printf("f %d, ", root->right->content);
        return true;
      } else if(key < root->content) {
        remove(root->left, key);
      } else if(key > root->content) {
        remove(root->right, key);
      }

      printf("Not found\n");
      return false;
    }

    void inorderTraversal(Node *root) {
      if(root){
        inorderTraversal(root->left);
        printf("%i ,", root->content);
        inorderTraversal(root->right);
      }
    }

    void preorderTraversal(Node *root) {
      if(root){
        printf("%i ,", root->content);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
      }
    }

    void postorderTraversal(Node *root) {
      if(root){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%i ,", root->content);
      }
    }

    Node *Root(){
      return root;
    }

    bool search(int value) {
      Node *current = root;
      printf("Visiting elements: ");

      while(current){
        printf("%d, ", current->content);

        if (value == current->content){
          printf("Found: %d", current->content);
          return true;
        } else if(value < current->content) {
          current = current->left;
        } else if(value > current->content) {
          current = current->right;
        }
      }

      printf("Not found\n");
      return false;
    }

    bool searchRecursion(Node *root, int key) {
      if(!root) {
        return false;
      }

      if (key == root->content){
        printf("Found: %d", root->content);
        return true;
      } else if(key < root->content) {
        searchRecursion(root->left, key);
      } else if(key > root->content) {
        searchRecursion(root->right, key);
      }

      return false;
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
  BinaryTree.inorderTraversal(BinaryTree.Root());
  printf("\nPreorder \n");
  BinaryTree.preorderTraversal(BinaryTree.Root());
  printf("\nPostorder \n");
  BinaryTree.postorderTraversal(BinaryTree.Root());
  printf("\n");

  BinaryTree.searchRecursion(BinaryTree.Root(), 4);

  BinaryTree.remove(2);

  return 0;
}
