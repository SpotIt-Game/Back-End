#ifndef MY_LIST_INCLUDED
#define MY_LIST_INCLUDED
 
/**
  @file include/my_list.h
*/
 
typedef struct LIST {
  struct LIST *prev, *next;
  void *data;
} LIST;
 
typedef int (*list_walk_action)(void *, void *);
 
extern LIST *list_add(LIST *root, LIST *element);
extern LIST *list_delete(LIST *root, LIST *element);
extern LIST *list_cons(void *data, LIST *root);
extern LIST *list_reverse(LIST *root);
extern void list_free(LIST *root, unsigned int free_data);
extern unsigned int list_length(LIST *);
extern int list_walk(LIST *, list_walk_action action, unsigned char *argument);
 
#define list_rest(a) ((a)->next)
 
#endif  // MY_LIST_INCLUDED