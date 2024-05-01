//1. Write the following menu driven program for the binary search tree 
//---------------------------------------- 
//Binary Search Tree Menu 
//---------------------------------------- 
//0. create 
//1. Count number of leaf nodes in the tree 
//2. count number of non-leaf nodes in the tree. 
//3. find number of nodes in the tree. 
//4. find sum of all nodes of the tree. 
//5. print height and depth of the tree. 
//6. find nodes which are at maximum depth in the tree. 

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* insert(node* root, int data);
void inorder(node* root);
int countLeaf(node* root);
int countNonLeaf(node* root);
int countNode(node* root);
int sumNode(node* root);
int height(node* root);
void maxDepth(node* root, int level, int depth);

node* insert(node* root, int data) {
    if (root == NULL) {
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if (root->data < data) {
        root->right = insert(root->right, data);
    } else if (root->data > data) {
        root->left = insert(root->left, data);
    }

    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int countLeaf(node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

int countNonLeaf(node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

int countNode(node* root) {
    return countNonLeaf(root) + countLeaf(root);
}

int sumNode(node* root) {
    if (root == NULL) {
        return 0;
    }
    return (root->data + sumNode(root->left) + sumNode(root->right));
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int ldepth = height(root->left);
        int rdepth = height(root->right);
        return (ldepth > rdepth) ? ldepth + 1 : rdepth + 1;
    }
}

void maxDepth(node* root, int level, int depth) {
    if (root == NULL) {
        return;
    }

    if (level == depth) {
        printf("%d\t", root->data);
        return;
    }

    maxDepth(root->left, level + 1, depth);
    maxDepth(root->right, level + 1, depth);
}

int main() {
    int value, choice;
    node* root = NULL;

    while (1) {
        printf("\n1. Enter element in tree\n");
        printf("2. Count total number of leaf nodes\n");
        printf("3. Count no of non-leaf nodes\n");
        printf("4. Count total number of nodes in tree\n");
        printf("5. Sum of all nodes\n");
        printf("6. Print height of binary tree\n");
        printf("7. Print all nodes at max depth of the tree\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 4:
                printf("Number of nodes = %d\n", countNode(root));
                break;
            case 2:
                printf("Number of leaf nodes = %d\n", countLeaf(root));
                break;
            case 3:
                printf("Number of non-leaf nodes = %d\n", countNonLeaf(root));
                break;
            case 5:
                printf("Sum of all nodes = %d\n", sumNode(root));
                break;
            case 6:
                printf("Height of tree = %d\n", height(root));
                break;
            case 7:
                printf("Nodes at max depth: ");
                maxDepth(root, 0, height(root) - 1);
                printf("\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
