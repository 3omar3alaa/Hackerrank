#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    arr = []
    results = []
    for i in range(6):
        arr.append(list(map(int, input().rstrip().split())))
    #print(arr[3][3])
    #print(list[1:4])

    for i in range(1,5):
        for j in range(1,5):
            results.append(arr[i][j] + 
                            arr[i-1][j-1]+
                            arr[i-1][j]+
                            arr[i-1][j+1]+
                            arr[i+1][j-1]+
                            arr[i+1][j]+
                            arr[i+1][j+1])
    
    #print(results)
    print(max(results))
