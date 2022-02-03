//
// Created by 邹羽洋 on 2022-02-03.
//

/*
 * SORT-VISUALIZER BY ZOUYUYANG @ BUAA73
 * FOR EDUCATION USE ONLY
 * USAGE:
 * 1. CALL createVisualizer() BEFORE SORTING PROCESS;
 * 2. CALL updateVisualizer() **EVERY** TIME YOUR ALGORITHM (MIGHT) SWAP A PAIR OF ELEMENTS;
 * 3. CALL verifyVisualizer() TO VERIFY THE SORT RESULT;
 *      0 = Descending , 1 = Ascending order
 *      CALLEE RETURN THE ID OF FIRST WRONG SORTED ELEMENT
 * 3. CALL killVisualizer() WHEN SORTING PROCESS IS OVER;
 *
 * COMPILE AND RUN TO STUDY THE MYSTERY SORTING PROCESS!
*/

#ifndef SORT_SORTVISUALIZER_H
#define SORT_SORTVISUALIZER_H
typedef struct sA{
    int* array;
    int* lastArray;
    int N;
    int processID;
    char* specifier;
}sortVis;

sortVis* createVisualizer(int* targetArray,int nums,char* specifier);
void updateVisualizer(sortVis* obj);
void killVisualizer(sortVis* obj);
int verifyVisualizer(sortVis* obj,unsigned int method);
#endif //SORT_SORTVISUALIZER_H
