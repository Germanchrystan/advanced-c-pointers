# Common pointer problems
## Why do pointers cause problems?
The fact of the matter is that pointers are one of the major sources of error in C programs. pointers can point to anything, even thing it has no business pointing at. It can get at bits of memory that it really should not be messing about with. That can cause memory corruption, memory leaks, and even catastrophic program crashes.

## Deep and shallow copies
In the previous queues examples, we saw an function that copies one list into another. It did that by removing the elements from one list before adding them to the second one. Why didn't we just add those element onto the second list and also leave in list one? We did that to avoid having to deal with one of the common problems when copying lists.

When two lists contain the same elements, or rather pointers to the same elements, any operation done to the elements in one list can have unintended side effects on the other list. For example, if we deleted an element from list two, list one might continue to try to use that same element. If two lists contain pointers to the same elements, or if any of the elements i two ists contain pointers to the same data, then when the data is changed or freed by one list, it can have unpredictable effects on the other list.

It is important to understand that there are two ways of making a copy of some data.
- The first is to create a pointer to ta bit of existing data. That is called a **shallow copy**.
There is one bit of data, but two pointers to it.
- The second is to make a new copy of the data itself, and that is called a **deep copy**.