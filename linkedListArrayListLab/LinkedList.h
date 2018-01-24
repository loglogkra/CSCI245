struct Node {
  struct Node* next;
  char* data;
};

struct LinkedList {
  struct Node* head;
};

struct LinkedList* create(char* data);
struct LinkedList* insertAfter(struct LinkedList* list, char* valueToFind, char* newValue);

/*
 * Returns 1 if the list named "list" contains a node whose value is sValue,
 * 0 if not
 */
int contains(struct LinkedList* list, char* sValue);

struct LinkedList* copy (struct LinkedList* src);
int insertBefore(struct LinkedList* list, char* sValue, char* value);

int delete(struct LinkedList* list, char* value);

/*
 * Visits each node of the list, calling the function pointed 
 * to be "visitFunc" for each node
 */

void visit(struct LinkedList* list, void(*visitFunc) (struct Node* value, void* d), void* data);
