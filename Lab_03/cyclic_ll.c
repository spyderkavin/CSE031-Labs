#include <stdio.h>

typedef struct node {
  int value;
  struct node *next;
} node;

/**
 * Checks if a singly-linked list has a cycle using Floyd's 
 * Cycle-Finding Algorithm (Tortoise and the Hare).
 */
int has_cycle(node *head) {
  // 1. Start with two pointers at the head of the list
  node *slow = head;
  node *fast = head;

  // 2. On each iteration, increment the first pointer by one node 
  // and the second by two nodes. If we hit a NULL, there is no cycle.
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;          // Increment first pointer by one (Tortoise)
    fast = fast->next->next;    // Increment second pointer by two (Hare)

    // 3. We know there is a cycle if:
    // a. The second pointer is the same as the first pointer
    // b. The next node of the second pointer is pointed to by the first pointer
    if (fast == slow || (fast != NULL && fast->next == slow)) {
      return 1; // Cycle detected
    }
  }

  // If the loop ends, it's because of a null pointer, so there is no cycle
  return 0;
}



void test_has_cycle(void) {
  int i;
  node nodes[25]; // enough to run our tests
  for(i=0; i < sizeof(nodes)/sizeof(node); i++) {
    nodes[i].next = NULL;
    nodes[i].value = 0;
  }

  // Test 1: Linear list (No cycle)
  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  printf("Checking first list for cycles. There should be none, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[0]) ? "a" : "no");
  
  // Test 2: Circular list (Full cycle)
  nodes[4].next = &nodes[5];
  nodes[5].next = &nodes[6];
  nodes[6].next = &nodes[7];
  nodes[7].next = &nodes[8];
  nodes[8].next = &nodes[9];
  nodes[9].next = &nodes[10];
  nodes[10].next = &nodes[4];
  printf("Checking second list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[4]) ? "a" : "no");
  
  // Test 3: List with a "tail" leading into a cycle
  nodes[11].next = &nodes[12];
  nodes[12].next = &nodes[13];
  nodes[13].next = &nodes[14];
  nodes[14].next = &nodes[15];
  nodes[15].next = &nodes[16];
  nodes[16].next = &nodes[17];
  nodes[17].next = &nodes[14];
  printf("Checking third list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[11]) ? "a" : "no");
  
  // Test 4: Self-loop (Cycle of 1)
  nodes[18].next = &nodes[18];
  printf("Checking fourth list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[18]) ? "a" : "no");
  
  // Test 5: Another linear list
  nodes[19].next = &nodes[20];
  nodes[20].next = &nodes[21];
  nodes[21].next = &nodes[22];
  nodes[22].next = &nodes[23];
  printf("Checking fifth list for cycles. There should be none, has_cycle says it has %s cycle\n", 
    has_cycle(&nodes[19]) ? "a" : "no");
}

int main() {
  test_has_cycle();
  return 0;
}