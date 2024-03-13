#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int value;
  void *next;
} Node;

Node *head = NULL;

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

void addNodeBeg(int input){
  Node *newNode = malloc(sizeof(Node));
  newNode->value = input;
  newNode->next = head;
  head = newNode;
  return;
}

void addNodeEnd(int input){
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

void removeHead(){
  if(head == NULL){
    printf("List is already empty!");
  }
  head = head->next;
  return;
}

void removeTail(){
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
  return;
}

void addElementN(int n){
  Node *newNode = malloc(sizeof(Node));
  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
  }
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
  newNode->next = currentNode;
  newNode->value = n;
  return;
}

void removeElementN(int n){
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
  return;
}

void printCurrentList(){
  Node *currentNode = head;
  while(currentNode != NULL){
    printf("%d --> ", currentNode->value);
    currentNode = currentNode->next;
  }
  printf("NULL\n");
}

int main(){
  bool run = 1;
  while(run){
    printMenu();
    int option = -1;
    scanf("%d", &option);
    int input;
    switch (option){
      case 1:
        printf("Enter the integer value of the node: ");
        scanf("%d", &input);
        addNodeBeg(input);
        break;
      case 2:
        printf("Enter the integer value of the node: ");
        scanf("%d", &input);
        addNodeEnd(input);
        break;
      case 3:
        removeHead();
        break;
      case 4:
        removeTail();
        break;
      case 5:
        scanf("%d", &input);
        printf("Enter the integer value of the node: ");
        scanf("%d", &input);
        addElementN(input);
        break;
      case 6:
        scanf("%d", &input);
        print("Enter the value of the position of the node:");
        removeElementN(input);
        break;
      case 7:
        printCurrentList();
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