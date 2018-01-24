#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <stdio.h>

struct Node* createNode (char* data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->next = NULL;
  node->data = data;
  return node;
}

struct LinkedList* create (char* data) {
  struct LinkedList* newList = (struct LinkedList*) malloc(sizeof(struct LinkedList));
  newList->head = createNode(data);
  return newList;
}

struct LinkedList* insertAfter (struct LinkedList* list, char* insertNodeValue, char* newValue) {
  struct Node* currentNode = list->head;
  while (currentNode != NULL && strcmp(currentNode->data, insertNodeValue) != 0) {
    currentNode = currentNode->next; 
  }
  
  //  If we didn't find the value, return NULL to indicate that fact
  if (currentNode == NULL) {
    return NULL;
  }
  
  //  Otherwise, create a new node, and set up the pointers appropriately
  struct Node* newNode = createNode(newValue);
  newNode->next = currentNode->next;
  currentNode->next = newNode;
  return list;
}

/*
 * Print contents of all nodes in linkedlist
 */
void printNodes(struct LinkedList* list){
  struct Node* tmp = list->head;

  while(tmp!=NULL){
    printf("%s", tmp->data);
    tmp=tmp->next;
  }
}

void printNodesAt(struct LinkedList* list){
  struct Node* tmp = list->head;
  while(tmp!=NULL){
  if(strcmp(tmp->data,"\n")==0)
    break;
  if(strcmp(tmp->data," ")==0)
    printf("Char* \"%s\" located at 0x%x\n", tmp->data,(unsigned int) tmp);
  else 
     printf("Char* %s located at 0x%x\n", tmp->data,(unsigned int) tmp);
  tmp=tmp->next;
  }
}

/*
 * Returns 1 if the list name "list" contains a node whose value
 * is sValue, 0 if not
*/
int contains(struct LinkedList* list, char* sValue){
  struct Node* tmp = list->head;
  
  while(tmp!=NULL){
    if(strcmp(tmp->data,sValue)==0)
      return 1;
    tmp=tmp->next;
  }
  return 0;
}

struct LinkedList* copy (struct LinkedList* src){
  struct LinkedList* newList=create(src->head->data);
   if(newList == NULL)
     return;
  insertAfter(newList, newList->head->data, src->head->next->data); 
  insertAfter(newList, newList->head->next->data, src->head->next->next->data);
  return newList;
}

/*
 * Inserts a new node with value "value" into the list referenced by "list" so that 
 * the new node comes before the node with value "sValue"
 *
 * return 0 if no node with value "sValue"can be found. Returns -1 if no memory can
 * be allocated for a new node, and returns 1 if the new node
 */
int insertBefore(struct LinkedList* list, char* sValue, char* value){
  if(!contains(list,sValue)){ 
     puts("0");
     return 0;
    }
  if(contains(list,sValue)){
   struct Node* currentNode = list->head;
   struct Node* prev = createNode(NULL);
   struct Node* newNode  = createNode(value);
   if(newNode==NULL){
     puts("-1");
     return -1;
    }
   if(strcmp(sValue, list->head->data)==0){
     newNode->next = list->head;
     list->head = newNode;
   } 
   else{
   while(currentNode!=NULL&&strcmp(currentNode->data, sValue)!=0){
     prev = currentNode;
     currentNode = currentNode->next;
   }
   newNode->next = currentNode;
   prev->next = newNode;
   }
   puts("1");
   return 1;
  }
  return -1;
}

/*
 * Deletes the node in the list with value "value" 
 * returns 0 if sucj a node cannot be found; otherwise returns 1
 */
int delete(struct LinkedList* list, char* value){
  struct Node* currentNode = list->head;
  struct Node* prev = createNode(NULL);
  if(!contains(list, value)){
  return 0;
  }
  if(strcmp(value, list->head->data)==0){
  struct Node* tmp = list->head;
  list->head = list->head->next;
  free(tmp);
  }
  else{
  while(currentNode!=NULL && strcmp(currentNode->data, value)!= 0){
    prev=currentNode;
    currentNode=currentNode->next;
  }
   prev->next = currentNode->next;
   free(currentNode);
 }
 return 1;
}

void visit(struct LinkedList* list, void (*visitFunc)(struct Node* value, void* d), void* data) {
  struct Node* current = list->head;
  while(current != NULL){
    visitFunc(current, data);
    current = current->next;
  }
 }
