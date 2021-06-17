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

    void inorderTraversal(Node *root) {
      if(root){
        inorderTraversal(root->left);
        printf("%i", root->content);
        inorderTraversal(root->right);
      }
    }
  
  Node *Root(){
    return root;
  }
  
  void search(int value) {
    Node *current = root;
    printf("Visiting elemnets: ");
    
    while(current){
      printf("%d, ", current->content);
      
      if(value < current->content) {
        current = current->left;
      } else if(value > current->content) {
        current = current->right;
      } else {
        printf("Found: %d", current->content);
        return;
      }
    }
  }
};

int main() {
  Tree BinaryTree;

  BinaryTree.insert(12);
  BinaryTree.insert(10);
  BinaryTree.insert(5);
  BinaryTree.insert(18);
  BinaryTree.insert(22);

  BinaryTree.inorderTraversal(BinaryTree.Root());
  
  BinaryTree.search(22);

  return 0;
}
