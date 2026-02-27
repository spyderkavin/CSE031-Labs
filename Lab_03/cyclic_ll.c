#include <stdio.h>

typedef struct node {
  int value;
  struct node *next;
} node;

int has_cycle(node *head) {
  // 1. Start with two pointers at the head of the list
  node *slow = head;
  node *fast = head;

  // 2. On each iteration, increment the first pointer by one node and the second by two nodes
  // We check if fast and fast->next are not NULL to ensure we don't dereference a null pointer
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;          // Move slow pointer 1 step
    fast = fast->next->next;    // Move fast pointer 2 steps

    // 3. We know there is a cycle if:
    // a. The second pointer is the same as the first pointer
    // b. The next node of the second pointer is pointed to by the first pointer
    if (slow == fast) {
      return 1; // Cycle detected
    }
  }

  // If the loop ends, it's because of a null pointer, so there is no cycle
  return 0;
}

void test_has_cycle(void) {
  int i;
  node nodes[25]; //enough to run our tests
  for(i=0; i < sizeof(nodes)/sizeof(node); i++) {
    nodes[i].next = 0;
    nodes[i].value = 0;
  }
  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  printf("Checking first list for cycles. There should be none, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[0])?"a":"no");
  
  nodes[4].next = &nodes[5];
  nodes[5].next = &nodes[6];
  nodes[6].next = &nodes[7];
  nodes[7].next = &nodes[8];
  nodes[8].next = &nodes[9];
  nodes[9].next = &nodes[10];
  nodes[10].next = &nodes[4];
  printf("Checking second list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[4])?"a":"no");
  
  nodes[11].next = &nodes[12];
  nodes[12].next = &nodes[13];
  nodes[13].next = &nodes[14];
  nodes[14].next = &nodes[15];
  nodes[15].next = &nodes[16];
  nodes[16].next = &nodes[17];
  nodes[17].next = &nodes[14];
  printf("Checking third list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[11])?"a":"no");
  
  nodes[18].next = &nodes[18];
  printf("Checking fourth list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[18])?"a":"no");
  
  nodes[19].next = &nodes[20];
  nodes[20].next = &nodes[21];
  nodes[21].next = &nodes[22];
  nodes[22].next = &nodes[23];
  printf("Checking fifth list for cycles. There should be none, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[19])?"a":"no");