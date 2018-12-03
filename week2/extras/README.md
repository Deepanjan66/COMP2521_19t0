# Basics of GDB

So, let's try and wrap our heads around gdb. We'll use the following simple program for our analysis

```c
 1	#include <stdio.h>
 2	#include <stdlib.h>
 3
 4	typedef struct node* Node;
 5
 6	struct node {
 7	   int item;
 8	   Node next;
 9	};
10
11
12	Node new_node(int item);
13
14	int main(int argc, char* argv[]) {
15
16	   printf("===== fun with gdb =====\n");
17	   Node head = new_node(1);
18	   head->next = new_node(2);
19	   head->next->next = new_node(3);
20
21	   free(head->next->next);
22	   free(head->next);
23	   free(head);
24
25	   return EXIT_SUCCESS;
26	}
27
28	Node new_node(int item) {
29	   Node curr = malloc(sizeof(*curr));
30
31	   curr->item = item;
32	   curr->next = NULL;
33
34	   return curr;
35	}
```

## Open

To run the binary with gdb, do

```c
gdb ./test_gdb
```

Once you do that, gdb will open up the binary. If you wanna get rid of the pesky messages at the top, just run

```c
gdb -q ./test_gdb
```

## Run

To run the executable inside gdb, just do

```c
(gdb) run
```

or `r` would also do. You will notice that this runs the program and shows you all the output. In
this program, we only have one print statement. So, that gets printed to standard output.

```
==== fun with gdb ====
[Inferior 1 (process 20087) exited normally]
```

## List / Show code

To look at the code from inside gdb, use `list`.

```gdb
(gdb) list 20
```

will list 5 lines before and 5 lines after line 20.

Output:

```c
15
16	   printf("==== fun with gdb ====\n");
17	   Node head = new_node(1);
18	   head->next = new_node(2);
19	   head->next->next = new_node(3);
20
21	   return EXIT_SUCCESS;
22	}
23
24	Node new_node(int item) {
```

## Break

So, we can run the executable and look at actual lines of code inside gdb. But let's see how we can pause execution for further inspection.

Let's break at line 17

```c
(gdb) b 17
```

Output:
```
Breakpoint 1 at 0x565555e0: file gdb_test.c, line 17.
```

This will create a breakpoint for us at line 17. Now, if we run the program, the execution will stop at line 17.

```
(gdb) run
```

Output:
```
Breakpoint 1, main (argc=1, argv=0xffffd954) at gdb_test.c:17
17	   Node head = new_node(1);
```

So, the execution has paused at our breakpoint. To see all 
the local variables within the scope of the current function, do

```
(gdb) info local
```

Output:
```
head = 0x56555691 <__libc_csu_init+33>
```

Notice that line 17 hasn't been executed yet. Hence, head has a random
value inside. To verify this, if you do

```
(gdb) print head->item
```
Ouptut:
```
$5 = -18054259
```

## Next
Typing in next executes the current line and halts execution at the
next instruction line.

```
(gdb) next
```

Output:
```
18	   head->next = new_node(2);
```

As you can see, we have moved on to the next line and paused there.
Line 17 has now been executed. So, if you do

```
(gdb) print head->item
```
Output:
```
$6 = 1
```

Which is the item we created the node with.

## Step

You can use step to jump into a function call. Recall that we
are paused at line 18 now.

```
18	   head->next = new_node(2);
```

If you want to jump inside the `new_node` funtion, run

```
(gdb) step
```
Output:
```
25	   Node curr = malloc(sizeof(*curr));
```

```
(gdb) list 25
20
21	   return EXIT_SUCCESS;
22	}
23
24	Node new_node(int item) {
25	   Node curr = malloc(sizeof(*curr));
26
27	   curr->item = item;
28	   curr->next = NULL;
29
```

As you can see, we have now moved to line 25 which is inside the 
`new_node` function. You can do

```
(gdb) next
```
Output:
```
27	   curr->item = item;
```

to run the current line and halt at the next instruction line.

# Conclusion

At this point, you should be fairly confident with GDB. There's a lot more
that you can do with GDB and hopefully, you can pick them up with less
overhead now that you understand the basics. 

Don't hesitate to ask us questions about GDB if you want to learn more.
