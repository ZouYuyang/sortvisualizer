### SORT-VISUALIZER BY ZOUYUYANG @ BUAA73

**FOR EDUCATION USE ONLY**

Sort-visualizer is a C program to visualize the sorting process of an array for freshman to understand the mystery sorting algorithm.

**Limitations:**

1. The type of elements should be `int` and should be no longer than 7 digits ( include '-' sign ).
2. Sort function should not be built-in function of C.
3. The Object (with the type of sortVis* ) might be required to define as a global variable.

**USAGE:**

1. CALL `sortVis* *name* = createVisualizer()` BEFORE SORTING PROCESS;

2. CALL `updateVisualizer()` **EVERY** TIME YOUR ALGORITHM (MIGHT) SWAP A PAIR OF ELEMENTS;

3. CALL `verifyVisualizer()` TO VERIFY THE SORT RESULT;

​		0 = Descending , 1 = Ascending order

​		CALLEE RETURN THE ID OF FIRST WRONG SORTED ELEMENT

3. CALL `killVisualizer()` WHEN SORTING PROCESS IS OVER;

    

COMPILE AND RUN TO STUDY THE MYSTERY SORTING PROCESS!