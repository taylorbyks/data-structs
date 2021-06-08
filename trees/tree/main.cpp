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
      // left = nullptr;
      // right = nullptr;
      // tail = nullptr;
      // size = 0;
    }

    ~Tree() {

    }

    Node* insert(int data) {
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
              return root;
            }
          } else {
            current = current->right;

            if(current == nullptr) {
              parent->right = temp;
              return root;
            }
          }
        }
      }
      return root;
    }
};

int main() {

  return 0;
}
