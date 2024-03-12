#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int value;
  void *next;
} Node;

Node* head = NULL;

void printMenu(){
  printf("Select what you want to do:\n");
  printf("1 - Add node to the beginning.\n");
  printf("2 - Add node to the end.\n");
  printf("3 - Remove head.\n");
  printf("4 - Remove tail.\n");
  printf("5 - Add element at n position.\n");
  printf("6 - Remove element at n position.\n");
  printf("7 - Print current List.\n");
  printf("8 - Clear list.\n");
  printf("9 - Quit.\n");
}

void addNodeBeg(Node *head, int input){
  Node *newNode = malloc(sizeof(Node));
  newNode->value = input;
  newNode->next = head;
  head = newNode;
  return;
}

void addNodeEnd(Node *head, int input){
  Node *newNode = malloc(sizeof(Node));
  if(newNode == NULL){
    printf("Memory allocation went wrong!");
  }
  newNode->value = input;
  if(head == NULL){
    head = newNode;
    newNode->next = NULL;
    return;
  }
  Node *currentNode = head;
  while(currentNode->next != NULL){
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
  return;
}

void removeHead(Node *head){
  if(head == NULL){
    printf("List is already empty!");
  }
  Node * oldHead = head;
  head = head->next;
  free(oldHead);
  return;
}

void removeTail(Node *head){
  if(head == NULL){
    printf("List is already empty!");
  }
  Node *currentNode1 = head;
  Node *currentNode2;
  currentNode1->next = head->next;
  while(currentNode1->next != NULL){
    currentNode2 = currentNode1;
    currentNode1 = currentNode1->next;
  }
  currentNode2->next = NULL;
  free(currentNode1);
  return;
}

void addElementN(Node *head, int n){
  Node *currentNode = head;
  while(n != 0){
    if(currentNode->next == NULL){
      break;
    }
    n--;
    currentNode = currentNode->next;
  }
  if(n != 0){
    printf("The list doesn't have enough elements.");
    return;
  }
  Node *newNode = malloc(sizeof(Node));
  newNode->next = currentNode->next;
  currentNode->next = newNode;
  currentNode->value = n;
  return;
}

void removeElementN(Node *head, int n){
  Node *currentNode = head;
  Node *behindNode;
  while(n != 0){
    if(currentNode->next == NULL){
      break;
    }
    n--;
    behindNode = currentNode;
    behindNode->next = currentNode->next;
    currentNode = currentNode->next;
  }
  if(n != 0){
    printf("The list doesn't have enough elements.");
    return;
  }
  behindNode->next = currentNode->next;
  free(currentNode);
  return;
}

void printCurrentList(Node *head){
  Node *currentNode = head;
  while(currentNode->next != NULL){
    printf("%d --> ", currentNode->value);
  }
  printf("%d \n", head->value);
}

int main(){
  bool run = 1;
  while(run){
    printMenu();
    int option = -1;
    scanf("%d", &option);
    switch (option){
      int n = -1;
      int input;
      case 1:
        printf("Enter the integer value of the node: ");
        scanf("%d", &input);
        addNodeBeg(head, input);
        break;
      case 2:
        printf("Enter the integer value of the node: ");
        scanf("%d", &input);
        addNodeEnd(head, input);
        break;
      case 3:
        removeHead(head);
        break;
      case 4:
        removeTail(head);
        break;
      case 5:
        scanf("%d", &n);
        if(n != -1){
            addElementN(head, n);
        }
        else{
            printf("Something went wrong!\n");
        }
        break;
      case 6:
        scanf("%d", &n);
        if(n != -1){
          removeElementN(head, n);
        }
        else{
          printf("Something went wrong!\n");
        }
        break;
      case 7:
        printCurrentList(head);
        break;
      case 8:
        break;
      case 9:
        run = 0;
        break;
    }
  }
          
    return 0;
}