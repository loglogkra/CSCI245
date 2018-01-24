#include <stdlib.h>
#include "ArrayList.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

/*
  Retrieves the string stored in the list at position index
  Prints an error message and returns INT_MIN if the index is outside the current bounds of the list
*/
int get(struct list* lst, int index) {
 if(index >= lst->capacity || index < 0){
  printf("ERROR: TRYING TO ACCESS OUT OF BOUNDS INDEX\n");
  return INT_MIN;
 } 
 return lst->address[index]; 
}

/*
  Creates a new list capable of holding the number of entries
  specified in the parameter initialCapacity
*/
struct list* initialize(int initialCapacity){
  struct list* lst = malloc(sizeof(struct list));
  lst->address = malloc(initialCapacity * sizeof(int));
  lst->capacity = initialCapacity;
  //loop through each value and set to intmin
  int i;
  for(i=0; i <lst->capacity; i++){  
    lst->address[i] = INT_MIN;
  }
 return lst;
}

/*set
 */
void set(struct list* lst, int index, int value){
  if(index<lst->capacity){
  lst->address[index] = value;
 }
  if(index>=lst->capacity){
  int* new = malloc(sizeof(int) * (index+1));
  if(new==NULL)
    return;
  int i;
  for(i=0; i<lst->capacity; i++)
    new[i] = lst->address[i];
  free(lst->address);
  lst->capacity = index+1;
  lst->address = new;
  set(lst,index,value);
}
}

/*
 * Reduces the capacity of the list pointed to by lst to the given value;
 * any data that ecists with index -value - or greater are lost
 */
void truncate(struct list* lst, int value){
  if(value==lst->capacity){
    return;
  }
  int* new = malloc(sizeof(int) * value);
  if(new==NULL)
    return;
  int i;
  for(i=0; i<value; i++){
   new[i]=lst->address[i];
  }
   lst->capacity = value;
   lst->address = new;
}

/*
 *Reduces the amount of memory being used by the list to match its size,
  by creating a new block of memory to hold exactly the right number of 
  elements, copying the elements of the existing list that have been set,
  and then freeing up the memory previously allocated to the list
*/
void compact(struct list* lst){
  int i;
  int count = 0;
  for(i=0; i<lst->capacity; i++){
    if(lst->address[i]!=INT_MIN){
      count++;
    }
  }
  int* new = malloc(sizeof(int) * count);
  if(new == NULL || lst->capacity == count)
    return;
  int j;
  int x = 0;
  if(lst->capacity!=count){
  for(j=0; j<lst->capacity; j++){
    if(lst->address[j]!=INT_MIN){
     new[x] = lst->address[j];
     x++;
    }  
  } 
  free(lst->address);
  lst->capacity = count;
  lst->address = new;
}
}
