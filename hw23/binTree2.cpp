#include <iostream>
#include <limits.h>
#include <climits>
using namespace std;

int containCalls = 0;

struct treeNode {
  int val;
  treeNode *left;
  treeNode *right;
};

void initialize(treeNode *t, int n) {
  t->val = n;
  t->left = t->right = 0;
}

void insert(treeNode *t, int n) {
  cout << "insert t " << t->val << " n " << n << endl;
  treeNode **child;
  if (n <= t->val) child = &(t->left);
  else child = &(t->right);
  if (0 == *child) {  // create new node and store value
	*child = new treeNode;
	initialize(*child, n);
  } else { // recurse on the correct branch
	insert(*child, n);
  }
}

void remove(treeNode *t) {
  cout << "remove t " << t->val << endl;
  if (t->left) remove(t->left);  // get rid of left subtree
  if (t->right) remove(t->right); // get rid of right subtree
  delete t;
}

void preorderPrint( treeNode *t ) {
  // Print all the items in the tree to which t points.
  // The item in the root is printed first, followed by the
  // items in the left subtree and then the items in the
  // right subtree.
  if (t != NULL) { // (Otherwise, there's nothing to print.)
     cout << t->val << " ";   // Print the root item.
     preorderPrint(t->left);  // Print items in left subtree.
     preorderPrint(t->right); // Print items in right subtree.
  }
}

void postorderPrint( treeNode *t ) {
  // Print all the items in the tree to which t points.
  // The items in the left subtree are printed first, followed 
  // by the items in the right subtree and then the item in the
  // root node.
  if (t != NULL) {  // (Otherwise, there's nothing to print.)
    postorderPrint(t->left);   // Print items in left subtree.
    postorderPrint(t->right);  // Print items in right subtree.
    cout << t->val << " ";     // Print the root item.
  }
}

void inorderPrint( treeNode *t ) {
  // Print all the items in the tree to which t points.
  // The items in the left subtree are printed first, followed 
  // by the item in the root node, followed by the items in
  // the right subtree.
  if (t != NULL ) {  // (Otherwise, there's nothing to print.)
    inorderPrint(t->left);   // Print items in left subtree.
    cout << t->val << " ";    // Print the root item.
    inorderPrint(t->right);  // Print items in right subtree.
  }
}

bool treeContains(treeNode *t, int item) {
  containCalls++;

  if (t->val == item) {
    return true;

  } else if (t->val < item && t->right != NULL) {
    return treeContains(t->right, item);

  } else if (t->val > item && t->left != NULL) {
    return treeContains(t->left, item);

  } else {
    return false;
  }
}

bool isBST(treeNode *t, int min = INT_MIN, int max = INT_MAX) {
  if (t->val == NULL) {
    // At the end of the tree, this checks to see if min is indeed less than max, which would be a success
    if (min <= max) {
      return true;
    } else {
      return false;
    }

  } else {
    return isBST(t->left, min, t->val) && isBST(t->right, t->val, max);

  }
}


int main() {
  treeNode *t15 = new treeNode;
  treeNode *t31 = new treeNode;
  treeNode *t63 = new treeNode;
  treeNode *t127 = new treeNode;
  treeNode *t255 = new treeNode;

  int numList[10]; // to hold the five numbers for later

  // 15
  for (int i = 0; i < 15; i++) {
    int num = rand() % 100;
    insert(t15, num);
    insert(t31, num);
    insert(t63, num);
    insert(t127, num);
    insert(t255, num);

    if (i > 9) {
      numList[i - 10] = num;
    }
  }

  // 31
  for (int i = 0; i < 16; i++) {
    int num = rand() % 100;
    insert(t31, num);
    insert(t63, num);
    insert(t127, num);
    insert(t255, num);
  }

  // 63
  for (int i = 0; i < 32; i++) {
    int num = rand() % 100;;
    insert(t63, num);
    insert(t127, num);
    insert(t255, num);
  }

  // 127
  for (int i = 0; i < 64; i++) {
    int num = rand() % 100;
    insert(t127, num);
    insert(t255, num);
  }

  // 255
  for (int i = 0; i < 128; i++) {
    insert(t255, rand() % 100);
  }

  int rand1 = rand() % 1000 + 100;
  int rand2 = rand() % 1000 - 100;
  int rand3 = rand() % 1000 + 100;
  int rand4 = rand() % 10000 - 100;
  int rand5 = rand() % 10000;

  // 15 test - random

  cout << "RANDOM RESULTS" << endl;

  if (treeContains(t15, rand1)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, rand2)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, rand3)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, rand4)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, rand5)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  // 15 test - last 5 insertions, must be in list

  cout << "LAST FIVE ITEMS - MUST BE IN LIST" << endl;

  if (treeContains(t15, numList[0])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, numList[1])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, numList[2])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, numList[3])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t15, numList[4])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 15 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 15 nodes" << endl;
  }

  containCalls = 0;

  // Tests for other amounts of nodes

  cout << "OTHER TESTS ON DIFFERENT SIZED TREES" << endl;

  // 31 test

  cout << "31" << endl;

  if (treeContains(t31, rand() % 100)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 31 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 31 nodes" << endl;
  }

  containCalls = 0;

  cout << "CHECKING EXPECTED NUMBERS" << endl;

  if (treeContains(t31, numList[0])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 31 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 31 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t31, numList[1])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 31 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 31 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t31, numList[2])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 31 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 31 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t31, numList[3])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 31 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 31 nodes" << endl;
  }

  containCalls = 0;

  if (treeContains(t31, numList[4])) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 31 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 31 nodes" << endl;
  }

  containCalls = 0;

  // 63 test

  cout << "63" << endl;

  if (treeContains(t63, rand() % 100)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 63 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 63 nodes" << endl;
  }

  containCalls = 0;

  // 127 test

  cout << "127" << endl;

  if (treeContains(t127, rand() % 100)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 127 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 127 nodes" << endl;
  }

  containCalls = 0;

  // 255 test
  cout << "255" << endl;

  if (treeContains(t255, rand() % 100)) {
    cout << "treeContains was called " << containCalls << " times for an item that was FOUND in a BST with 255 nodes" << endl;
  } else {
    cout << "treeContains was called " << containCalls << " times for an item that was NOT FOUND in a BST with 255 nodes" << endl;
  }

  containCalls = 0;
 
  cout << "Checking for valid trees" << endl;
  
  // real trees

  if (isBST(t15)) {
    cout << "t15 is a valid tree!" << endl;
  } else {
    cout << "t15 is NOT a valid tree!" << endl;
  }

  if (isBST(t255)) {
    cout << "t255 is a valid tree!" << endl;
  } else {
    cout << "t255 is NOT a valid tree!" << endl;
  }

  // fake trees
  treeNode *tFake1 = new treeNode;
  insert(tFake1, 3);
  insert(tFake1, 1);
  insert(tFake1, 4);
  insert(tFake1, 2);
  
  cout << "about to change value of node" << endl;

  initialize(tFake1->left->right, 5); // no matter if I do it myself with pointers or go through initalize(), always have a segmentation fault when I make something wrong. I don't know how to test my function in the negative case.

  cout << "successful change" << endl;

  if (isBST(tFake1)) {
    cout << "tFake1 is a valid tree?!" << endl;
  } else {
    cout << "tFake1 is NOT a valid tree!" << endl;
  }

}
