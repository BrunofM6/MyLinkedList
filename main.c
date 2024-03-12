#include <stdio.h>

typedef struct {
  int value;
  Node *next;
} Node;
typedef struct {
  void *head;
  Node *current;
} LinkedList;

void printMenu(){
    printf("Select what you want to do:\n");
    printf("1 - Add node to the beginning.\n");
    printf("2 - Add node to the end.\n");
    printf("3 - Remove head.");
    printf("4 - Remove tail.");
    printf("5 - Remove tail.");
    printf("6 - Add element at n position.");
    printf("7 - Remove element at n position.");
    printf("8 - Quit.")
}
int main(){
    LinkedList mainList;
    while(true){
        
    }
    return 0;
}