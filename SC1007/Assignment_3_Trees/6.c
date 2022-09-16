#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}
void buildTree(BTNode** node, char* preO, char* postO)
{
    if (!(*preO) || !(*postO)) {
        return;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->id = *preO;
    root->left = NULL;
    root->right = NULL;
    *node = root;

    char* preTemp = preO;
    char left = *(++preTemp);

    char* postTemp = postO;
    while (*postTemp) {
        postTemp++;
    }
    postTemp -= 2;
    char right = *postTemp;
    right = right == left ? 0 : right;
    postTemp = postO;

    char* preOLeft = (char*)malloc(sizeof(char) * MAX_N);
    char* preORight = (char*)malloc(sizeof(char) * MAX_N);
    char* postOLeft = (char*)malloc(sizeof(char) * MAX_N);
    char* postORight = (char*)malloc(sizeof(char) * MAX_N);

    char* preOLeftTemp = preOLeft;
    char* preORightTemp = preORight;
    char* postOLeftTemp = postOLeft;
    char* postORightTemp = postORight;

    if (right) { // if right subtree exists
        while (*preTemp != right) {
            *preOLeftTemp++ = *preTemp++; 
        }
        while (*preTemp) {
            *preORightTemp++ = *preTemp++;
        }
        while (*postTemp != left) {
            *postOLeftTemp++ = *postTemp++;
        }
        *postOLeftTemp++ = *postTemp++;
        while (*postTemp != right) {
            *postORightTemp++ = *postTemp++;
        }
        *postORightTemp++ = *postTemp++;
        // printf("%s %s %s %s\n", preOLeft, postOLeft, preORight, postORight);
        buildTree(&(root->right), preORight, postORight);
        buildTree(&(root->left), preOLeft, postOLeft);
    } else {
        preOLeft = preTemp;
        while (*postTemp != left) {
            *postOLeftTemp++ = *postTemp++;
        }
        *postOLeftTemp++ = *postTemp++;
        buildTree(&(root->left), preOLeft, postOLeft);
        // printf("%s %s %s %s\n", preOLeft, postOLeft, preORight, postORight);
    }

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
}