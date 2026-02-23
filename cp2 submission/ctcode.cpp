#include<stdio.h>

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
int sum_subtree(node* root);
void special_operation(node* root);
void execute_operation(node* root);

int main(){
    node *root=NULL, *nn;
    int choice = menu();

    while(choice!=0){
        if(choice==1){
            nn = new node();
            nn->left = NULL;
            nn->right = NULL;
            printf("Enter Data:");
            scanf("%d",&nn->data);
            root = insert_bst(root,nn);
        }else if(choice==2){
            int key;
            printf("key:");
            scanf("%d",&key);
            root = delete_data(root,key);
        }else if(choice==3){
            printf("Search Key?");
            int n;
            scanf("%d",&n);
            if(search_bst(root,n)!=NULL){
                printf("Found!\n");
            }else{
                printf("Not Found!\n");
            }
        }else if(choice==4){
            printf("In-order:\n");
            in_order(root);
            printf("\n");
        }else if(choice==5){
            printf("Pre-order:\n");
            pre_order(root);
            printf("\n");
        }else if(choice==6){
            printf("Post-order:\n");
            post_order(root);
            printf("\n");
        }else if(choice==7){
            special_operation(root);
        }else if(choice==8){
            execute_operation(root);
        }else{
            printf("Invalid Input!\n");
        }
        choice = menu();
    }

    return 0;
}

int menu(){
    printf("\n");
    printf("1)Insert\n");
    printf("2)Delete\n");
    printf("3)Search\n");
    printf("4)In-order\n");
    printf("5)Pre-order\n");
    printf("6)Post-order\n");
    printf("7)Special Operation\n");
    printf("8)Execute Operation\n");
    printf("0)Exit!\n");
    int choice;
    printf("Enter choice:");
    scanf("%d",&choice);
    return choice;
}

void post_order(node* root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->data);
    }
}

void pre_order(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(node* root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

node* search_bst(node* temp,int n){
    if(temp==NULL || temp->data==n){
        return temp;
    }else if(n < temp->data){
        return search_bst(temp->left,n);
    }else{
        return search_bst(temp->right,n);
    }
}

node* delete_data(node* current,int key){
    if(current==NULL){
        return current;
    }else if(key<current->data){
        current->left = delete_data(current->left, key);
    }else if(key>current->data){
        current->right = delete_data(current->right, key);
    }else{
        if(current->left==NULL){
            node* temp = current->right;
            return temp;
        }else if(current->right==NULL){
            node* temp=current->left;
            return temp;
        }

        node* minNode = min_node(current->right);
        current->data = minNode->data;
        current->right = delete_data(current->right,minNode->data);
    }
    return current;
}

node* min_node(node* temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* insert_bst(node *temp,node *nn){
    if(temp==NULL){
        return nn;
    }else if(nn->data < temp->data){
        temp->left = insert_bst(temp->left,nn);
    }else{
        temp->right = insert_bst(temp->right,nn);
    }
    return temp;
}

int sum_subtree(node* root){
    if(root == NULL) return 0;
    return root->data + sum_subtree(root->left) + sum_subtree(root->right);
}

void special_operation(node* root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    int left_sum = sum_subtree(root->left);
    int right_sum = sum_subtree(root->right);
    printf("Left Subtree Sum: %d\n", left_sum);
    printf("Right Subtree Sum: %d\n", right_sum);
    printf("Root Node Value: %d\n", root->data);
}

void execute_operation(node* root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    int left_sum = sum_subtree(root->left);
    int right_sum = sum_subtree(root->right);
    int result = left_sum - root->data - right_sum;
    printf("Operation Result (Left - Root - Right): %d\n", result);
}
