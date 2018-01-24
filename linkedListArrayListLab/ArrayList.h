struct list {
  int* address;
  int capacity;
 };

 /*
 this function should change the value stored at a particular index in the array, extending the 
 capacity if of the array if necessary. 
 */
void set(struct list* lst, int index, int value);

/*
  Retrieves the string stored in the list at position index
  Prints an error message and returns INT_MIN if the index is outside the current bounds of the list
*/
int get(struct list* lst, int index);

/*
  Creates a new list capable of holding the number of entries
  specified in the parameter initialCapacity
*/
struct list* initialize(int initialCapacity);

/*
  Reduces the capacity of the list pointed to by lst 
  to the given value; any data that exists with index -capacity- or 
  greater are lost
*/
void truncate(struct list* lst, int capacity);

/*
  Reduces the amount of memory being used by the list to match its size,
  by creating a new block of memory to hold exactly the right number of 
  elements, copying the elements of the existing list that have been set,
  and then freeing up the memory previously allocated to the list
*/
void compact (struct list* lst);
