
typedef struct node {
    void            *value;
    struct node     *next;
} node;

node *create_node(void *val);
node *append_node(node *n, void *val);
node *push_node(node **n, void *val);
int add_node(node *n, void *val, unsigned int index);
void *pop_node(node **n);
void *rightpop_node(node *n);
void clear_nodes(node *n);
void print_nodes(node *n);