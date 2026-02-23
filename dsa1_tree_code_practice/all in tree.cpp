#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>

struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;

int menu();
node* insert_bst(node *temp,node *nn);
node* min_node(node* temp);
node* delete_data(node* current,int key);
node* search_bst(node* temp,int n);
void in_order(node* temp);
void post_order(node* temp);
void pre_order(node* temp);
int sum_internal(node* root);
int sum_leaf(node* root);
void kth_smallest(node* root, int k, int *count, int *result);
int height(node* root);
void level_order(node* root);
int count_nodes(node* root);
int count_leaf(node* root);
int max_node(node* root);
int min_node_value(node* root);
int diameter(node* root, int* height);
bool is_balanced(node* root, int* height);
void kth_largest(node* root, int k, int *count, int *result);

int main(){
    node *root=NULL, *nn;
    int choice = menu();

    while(choice!=0){
        if(choice==1){
            nn = (node*)malloc(sizeof(node));
            nn->left = NULL;
            nn->right = NULL;
            printf("Enter Data: ");
            scanf("%d",&nn->data);
            root = insert_bst(root,nn);
        }
        else if(choice==2){
            int key;
            printf("Key: ");
            scanf("%d",&key);
            root = delete_data(root,key);
        }
        else if(choice==3){
            printf("Search Key? ");
            int n;
            scanf("%d",&n);
            if(search_bst(root,n)!=NULL){
                printf("Found!\n");
            }else{
                printf("Not Found!\n");
            }
        }
        else if(choice==4){
            printf("In-order: ");
            in_order(root);
            printf("\n");
        }
        else if(choice==5){
            printf("Pre-order: ");
            pre_order(root);
            printf("\n");
        }
        else if(choice==6){
            printf("Post-order: ");
            post_order(root);
            printf("\n");
        }
        else if(choice==7){
            printf("Sum of internal nodes = %d\n", sum_internal(root));
        }
        else if(choice==8){
            printf("Sum of leaf nodes = %d\n", sum_leaf(root));
        }
        else if(choice==9){
            int k;
            printf("Enter k: ");
            scanf("%d", &k);
            int count=0, result=-1;
            kth_smallest(root, k, &count, &result);
            if(result!=-1)
                printf("%d-th smallest element is: %d\n", k, result);
            else
                printf("There are less than %d elements.\n", k);
        }
        else if(choice==10){
            printf("Height of BST is: %d\n", height(root));
        }
        else if(choice==11){
            printf("Level-order: ");
            level_order(root);
            printf("\n");
        }
        else if(choice==12){
            printf("Total Nodes: %d\n", count_nodes(root));
        }
        else if(choice==13){
            printf("Total Leaf Nodes: %d\n", count_leaf(root));
        }
        else if(choice==14){
            printf("Depth (Height) of tree: %d\n", height(root));
        }
        else if(choice==15){
            printf("Maximum value: %d\n", max_node(root));
        }
        else if(choice==16){
            printf("Minimum value: %d\n", min_node_value(root));
        }
        else if(choice==17){
            int h=0;
            printf("Diameter of tree: %d\n", diameter(root,&h));
        }
        else if(choice==18){
            int h=0;
            if(is_balanced(root,&h))
                printf("Tree is Balanced.\n");
            else
                printf("Tree is Not Balanced.\n");
        }
        else if(choice==19){
            int k;
            printf("Enter k: ");
            scanf("%d", &k);
            int count=0, result=-1;
            kth_largest(root, k, &count, &result);
            if(result!=-1)
                printf("%d-th Largest Element is: %d\n", k, result);
            else
                printf("There are less than %d elements.\n", k);
        }
        else if(choice==20){
            printf("Number of levels: %d\n", height(root));
        }
        else{
            printf("Invalid Input!\n");
        }
        choice = menu();
    }
    return 0;
}

int menu(){
    printf("\n\n=== BST MENU ===\n");
    printf("1) Insert\n2) Delete\n3) Search\n4) In-order\n5) Pre-order\n6) Post-order\n7) Sum of Internal Nodes\n8) Sum of Leaf Nodes\n9) K-th Smallest\n10) Height\n11) Level-order\n12) Count Nodes\n13) Count Leaf\n14) Depth\n15) Max Node\n16) Min Node\n17) Diameter\n18) Balanced Tree\n19) K-th Largest\n20) Number of Levels\n0) Exit\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);
    return choice;
}

node* insert_bst(node *temp,node *nn){
    if(temp==NULL) return nn;
    if(nn->data < temp->data)
        temp->left = insert_bst(temp->left,nn);
    else
        temp->right = insert_bst(temp->right,nn);
    return temp;
}

node* min_node(node* temp){
    while(temp->left!=NULL) temp=temp->left;
    return temp;
}

node* delete_data(node* current,int key){
    if(current==NULL) return current;
    if(key<current->data)
        current->left = delete_data(current->left, key);
    else if(key>current->data)
        current->right = delete_data(current->right, key);
    else{
        if(current->left==NULL){
            node* temp = current->right;
            free(current);
            return temp;
        }else if(current->right==NULL){
            node* temp=current->left;
            free(current);
            return temp;
        }
        node* minNode = min_node(current->right);
        current->data = minNode->data;
        current->right = delete_data(current->right,minNode->data);
    }
    return current;
}

node* search_bst(node* temp,int n){
    if(temp==NULL || temp->data==n) return temp;
    if(n < temp->data) return search_bst(temp->left,n);
    else return search_bst(temp->right,n);
}

void in_order(node* root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

void pre_order(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(node* root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->data);
    }
}

int sum_internal(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    return root->data + sum_internal(root->left) + sum_internal(root->right);
}

int sum_leaf(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return root->data;
    return sum_leaf(root->left) + sum_leaf(root->right);
}

void kth_smallest(node* root, int k, int *count, int *result){
    if(root==NULL) return;
    kth_smallest(root->left, k, count, result);
    (*count)++;
    if(*count==k){ *result=root->data; return; }
    kth_smallest(root->right, k, count, result);
}

int height(node* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh>rh ? lh : rh) + 1;
}

void level_order(node* root){
    if(root==NULL) return;
    node* queue[100];
    int front=0, rear=0;
    queue[rear++] = root;
    while(front < rear){
        node* temp = queue[front++];
        printf("%d ", temp->data);
        if(temp->left) queue[rear++] = temp->left;
        if(temp->right) queue[rear++] = temp->right;
    }
}

int count_nodes(node* root){
    if(root==NULL) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_leaf(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

int max_node(node* root){
    if(root==NULL) return INT_MIN;
    while(root->right!=NULL) root=root->right;
    return root->data;
}

int min_node_value(node* root){
    if(root==NULL) return INT_MAX;
    while(root->left!=NULL) root=root->left;
    return root->data;
}

int diameter(node* root, int* height){
    if(root==NULL){ *height=0; return 0; }
    int lh=0, rh=0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);
    *height = (lh>rh ? lh:rh) + 1;
    int current_d = lh + rh + 1;
    return (ld > rd ? (ld > current_d ? ld : current_d) : (rd > current_d ? rd : current_d));
}

bool is_balanced(node* root, int* height){
    if(root==NULL){ *height=0; return true; }
    int lh=0, rh=0;
    bool lb = is_balanced(root->left, &lh);
    bool rb = is_balanced(root->right, &rh);
    *height = (lh>rh ? lh : rh) + 1;
    if(abs(lh-rh)>1) return false;
    return lb && rb;
}

void kth_largest(node* root, int k, int *count, int *result){
    if(root==NULL) return;
    kth_largest(root->right, k, count, result);
    (*count)++;
    if(*count==k){ *result=root->data; return; }
    kth_largest(root->left, k, count, result);
}

