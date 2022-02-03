//
// Created by 邹羽洋 on 2022-02-03.
//
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortVisualizer.h"

sortVis* createVisualizer(int* targetArray,int nums,char* specifier){
    sortVis* ptr = malloc(sizeof(sortVis));
    ptr->array = targetArray;
    ptr->lastArray = malloc(nums*sizeof(int));
    ptr->specifier = specifier;
    //check the length of input elements
    for(int i = 0;i<nums;i++){
        if(targetArray[i]>10000000||targetArray[i]<-999999){
            printf("SORT %s ELEMENTS %d OUT OF BOUNDS, USE ELEMENTS NO MORE THAN 8 DIGITS!",specifier,i);
            abort();
        }
    }
    //backup array
    memcpy(ptr->lastArray,ptr->array,nums*sizeof(int));
    ptr->N = nums;
    ptr->processID = 1;
    printf("sortVisualizer %s Initialized Successfully with %d elements\n",specifier,nums);
    return ptr;
}

void updateVisualizer(sortVis* obj){
    int ABRTSIGNAL = 0;
    printf("\n######Process %d of sort %s:######",obj->processID,obj->specifier);
    int swapID[2] = {-1,-1};
    int t = 0;
    for(int i = 0;i<obj->N;i++){
        //check the number of modified elements
        if(obj->array[i]!=obj->lastArray[i]){
            if(t<2){
                swapID[t] = i;
                t++;
            }else {
                printf("\nERROR: AT LEAST 3 ELEMENTS ARE CHANGED!\nPossible reasons:1. Wrong sort algorithm.\n                 2. Failed to call updateVisualizer() every time array updated.\n");
                ABRTSIGNAL = 1;
                break;
            }
        }
    }
    if(t==0){
        printf("\nNOTHING CHANGED, NEXT STEP!\n");
    }else if(t==1){
        printf("\nERROR: ONLY ONE ELEMENTS IS CHANGED!\nPossible reasons:1. Wrong sort algorithm.\n                 2. Failed to call updateVisualizer() every time array updated.\n");
        ABRTSIGNAL = 1;
    }else if(t==2){
        if(obj->array[swapID[0]]==obj->lastArray[swapID[1]]){
            printf("\nSwap element %d with element %d\n",swapID[0],swapID[1]);
        }else{
            printf("\nERROR: UNSUCCESSFUL SWAP! CONSIDER WRONG ALGORITHM!\n");
            ABRTSIGNAL = 1;
        }
    }
    //display before and current array
    printf("Before:\n");
    for(int i = 0;i<obj->N;i++){
        printf("%d\t|",obj->lastArray[i]);
    }
    printf("\n");
    for(int i = 0;i<obj->N;i++){
        if(obj->array[i]!=obj->lastArray[i]){
            printf("*\t ");
        }else{
            printf("\t ");
        }
    }
    printf("\nCurrent Array:\n");
    for(int i = 0;i<obj->N;i++){
        printf("%d\t|",obj->array[i]);
    }
    printf("\n");
    for(int i = 0;i<obj->N;i++){
        if(obj->array[i]!=obj->lastArray[i]){
            printf("*\t ");
        }else{
            printf("\t ");
        }
    }
    printf("\n");
    if(ABRTSIGNAL)
        abort();
    memcpy(obj->lastArray,obj->array,obj->N*sizeof(int));
    obj->processID++;
    return;
}

int verifyVisualizer(sortVis* obj,unsigned int method){
    int FAILSIG = -1;
    printf("\n######Verify Sort %s:\n",obj->specifier);
    for(int i = 0;i<(obj->N);i++){
        printf("%d\t|",obj->array[i]);
    }
    //analyze the array
    printf("\n");
    for(int i = 0;i<(obj->N)-1;i++){
        if(obj->array[i]<=obj->array[i+1]){
            if(method==1){
                printf("y\t ");
            }else{
                printf("n\t ");
                if(FAILSIG==-1)
                    FAILSIG = i;
            }
        }
        else if(obj->array[i]>=obj->array[i+1]){
            if(method==0){
                printf("y\t ");
            }else{
                printf("n\t ");
                if(FAILSIG==-1)
                    FAILSIG = i;
            }
        }
    }
    //result
    if(FAILSIG!=-1){
        printf("\nINCORRECT SORT @ ELEMENT %d OF SORT %s\n\n",FAILSIG,obj->specifier);
        return FAILSIG;
    }else{
        printf("\n%s SORT CORRECTLY\n\n",obj->specifier);
    }
}

void killVisualizer(sortVis* obj){
    free(obj->lastArray);
    free(obj);
}