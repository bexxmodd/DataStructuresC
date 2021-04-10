#include <stdbool.h>

typedef struct node {
    void            *value;
    struct node     *next;
} node;

node *create_node(void *val);
node *append_node(node *n, void *val);
node *push_node(node **n, void *val);
node *create_linkedlist(int *arr, unsigned int size); // update to void
node *reverse_nodes(node **n);
int add_node(node *n, void *val, unsigned int index);
int count_nodes(node *n);
int count_occurances(node *nd, void *val);
void *pop_node(node **n);
void *rightpop_node(node *n);
void *removei_node(node **n, unsigned int index);
void *remove_node(node **n, void *val);
void *get_node(node *n, unsigned int index);
void clear_nodes(node **n);
void print_nodes(node *n);
bool contains_node(node *n, void *val);