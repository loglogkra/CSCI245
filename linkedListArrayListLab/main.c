#include "LinkedList.h"
#include <stdio.h>
#include <string.h>

void printNode(struct Node*);
void totalLength(struct Node* node, void* data);

int main (int argc, char** argv) {
  struct LinkedList* list = create("Hello");
  insertAfter(list, "Hello", " ");
  insertAfter(list, " ", "World");
  insertAfter(list, "World", "\n");
  
  puts("\"Print Contents\" test:"); 
  printNodes(list);  
  //contains function
  puts("\n\"Contains\" test:");
  puts("Testing for char* \"Hello\":");
  printf("%d \n",contains(list,"Hello"));
  puts("Testing for char* \" \":");
  printf("%d \n",contains(list," "));
  puts("Testing for char* \"World\":");
  printf("%d \n",contains(list,"World"));
  puts("Testing for char* \"Goodbye\":");
  printf("%d \n\n",contains(list,"Goodbye"));

  //Copy function
  puts("\"Copy\" test:");
  puts("Printing nodes for original LinkedList");
  printNodesAt(list);
  struct LinkedList* newList =  copy(list);
  puts("\nPrinting nodes for copied Linkedlist");
  printNodesAt(newList);

  //insertBefore function
  puts("\n\"insertBefore\" test:");
  puts("Original list contents are:");
  printNodes(list);
  puts("Insert node \"big\" before node \"World\"\nReturns: "); 
  insertBefore(list, "World", "big ");
  puts("Nodes are now:");
  printNodes(list);
  puts("Insert node \"Good Morning\" before head-node \"Hello\"\nReturns: ");
  insertBefore(list,"Hello","Good Morning "); //space at end so we don't add another node of value " "
  puts("Nodes are now:");
  printNodes(list);
  puts("Insert node \"small\" before node \"population\" that is not in linked list\nReturns: ");
  insertBefore(list, "population","small");
  puts("Nodes are still:");
  printNodes(list);

  //delete function
  puts("\n\"Delete\" test:");
  puts("Delete head-node \"Good Morning\" from list");
  delete(list, "Good Morning ");
  puts("Nodes are now:");
  printNodes(list);
  puts("Delete node \"big\" from list");
  delete(list, "big ");
  puts("Nodes are now:");
  printNodes(list);
  
  //visit function
  int length = 0;
  visit(list, totalLength, &length);
  puts("\n\"Visit & Length\" tests:");
  printf("Total characters = %d\n", length);
}

void totalLength(struct Node* node, void* data){
  int* currentLength = (int *) data;
  if(node->data != NULL) {
    *currentLength += strlen(node->data);
  }
}

void printNode(struct Node* node){
  printf("%s\n", node->data);
}
