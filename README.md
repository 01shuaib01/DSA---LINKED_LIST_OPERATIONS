# DSA-LINKED_LIST_OPERATIONS
Introduction to Linked Lists

Linked lists are similar to arrays (Linear data structures)
Why Linked Lists?

Memory and the capacity of an array remains fixed.

In case of linked lists, we can keep adding and removing elements without any capacity constraints.

Drawbacks of Linked Lists
Extra memory space for pointers is required (for every node 1 pointer is needed)
Random access not allowed as elements are not stored in contiguous memory locations.

Insertion of a Node in a Linked List Data Structure
Insertion in this list can be divided into the following categories:

Case 1: Insert at the beginning

Case 2: Insert in between

Case 3: Insert at the end

Case 4: Insert after the node

For insertion of any type we first need to create that extra node, we want to insert and then rewire the connections to get the job done!

struct Node *ptr = (struct Node*) malloc (sizeof (struct Node))

The above syntax will create a node

ptr -> data = 9         // It will set the data

Case 1: Insert at the beginning
In order to insert the node at the beginning, we need to point the node to be inserted (ptr) to head and update the head to ptr.

Case 2: Insert in between
Assuming index starts from 0, we can insert an element at index i>0 as follows:
Bring a temporary pointer p before the element you want to insert in the linked list.
Since we want to insert between 9 and 11, we bring p to 9

Case 3: Insert at the end
In order to insert an element at the end of the linked list, we bring a temporary pointer to the last element

Case 4: Insert after a node
Similar to other cases, ptr can be inserted after a node as follows:


Deletion in a Linked List | Deleting a node from Linked List Data Structure

Deletion can be done for the following cases:

Deleting the first node
Deleting the node at the index
Deleting the last node
Deleting the first node with a given value
The deletion just like insertion is done by recurring the pointer connections, the only caveat being: we need to free the memory of the deleted node using free().
