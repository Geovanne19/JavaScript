#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct Btree{
    Node *root;
} Btree;

// void InsertLeft(int num, Node *node){
//     if(node->left == NULL){
//         Node *NewNode = (Node*)malloc(sizeof(Node));
//         NewNode->num = num;
//         NewNode->left = NULL;
//         NewNode->right= NULL;
//         node->left = NewNode;
//     } else{
//         if(num < node->left->num){
//             InsertLeft(num, node->left);
//         } else InsertRight(num, node->left);
//     }
// }
// void InsertRight(int num, Node *node){
//     if(node->right == NULL){
//         Node *NewNode = (Node*)malloc(sizeof(Node));
//         NewNode->num = num;
//         NewNode->left = NULL;
//         NewNode->right= NULL;
//         node->right = NewNode;
//     } else{
//         if(num > node->right->num){
//             InsertRight(num, node->right);
//         } else InsertLeft(num, node->right);
//     }
// }


// void Insert(int num, Btree *btree){
//     if(btree->root == NULL){
//         Node *NewNode = (Node*)malloc(sizeof(Node));
//         NewNode->num = num;
//         NewNode->left = NULL;
//         NewNode->right= NULL;
//         btree->root = NewNode;
//     } else{
//         if(num < btree->root->num){
//             InsertLeft(num, btree->root);
//         } else InsertRight(num, btree->root);
//     }
// }

Node *ShortInsert(int num, Node *root){
    if(root == NULL){
        Node *NewNode = malloc(sizeof(Node));
        NewNode->num = num;
        NewNode->left = NULL;
        NewNode->right = NULL;
        return NewNode;
    } else{
        if(num < root->num){
            root->left = ShortInsert(num, root->left);
        } 
        if(num > root->num){
            root->right = ShortInsert(num, root->right);
        }
        return root;
    }
}

int Tamanho(Node *root){
    if(root==NULL){
        return 0;
    } else{
        return 1 + Tamanho(root->left) + Tamanho(root->right);
    }
}

int SearchNode(Node*root, int key){
    if(root == NULL){
        return 0;
    }else{
        if(root->num == key){
            return 1;
        } else{
            if(key < root->num){
                return SearchNode(root->left, key);
            } else{
                return SearchNode(root->right, key);
            }
        }
    }
}

void PrintTree(Node *root){
    if(root != NULL){
        PrintTree(root->left);
        printf("%d ", root->num);
        PrintTree(root->right);
    }
}

int main(){
    
    int op, num;
    Btree btree;
    btree.root = NULL;

    do{
        printf("\n\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Pesquisar\n\n");
        scanf("%d", &op);

        switch(op) {
            case 0:
                printf("Encerrando programa...\n");
                break;
            case 1:
                printf("Digite um número\n");
                scanf("%d", &num);
                btree.root = ShortInsert(num, btree.root);
                break;
            case 2:
                PrintTree(btree.root);
                printf("\n");
                printf("%d", Tamanho(btree.root));
                break;
            case 3:
                printf("Qual valor deseja buscar? ");
                scanf("%d", &num);
                printf("Resultado da pesquisa: %d", SearchNode(btree.root, num));
                break;
            default:
               printf("\nOpção Inválida\n");
        }
    } while(op != 0);
    
    return 0;
}
