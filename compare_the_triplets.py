#!/bin/python3

import math
import os
import random
import re
import sys

# 1st attempt
#
# Complete the 'compareTriplets' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

# def compareTriplets(a, b):
#     # Write your code here
#     alice = 0
#     bob = 0
    
#     # creating list array for each person according to input number data(int)
#     a = []
    
#     alice_num1 = int(input('alice1'))
#     a.append(alice_num1)
#     alice_num2 = int(input('alice2'))
#     a.append(alice_num2)
#     alice_num3 = int(input('alice3'))
#     a.append(alice_num3)
    
#     b = []
#     bob_num1 = int(input('bob1'))
#     b.append(bob_num1)
#     bob_num2 = int(input('bob2'))
#     b.append(bob_num2)
#     bob_num3 = int(input('bob3'))
#     b.append(bob_num3)
   
#     for i in range(0,3):
#         if a[i] > b[i]:
#             alice += 1
#         elif a[i] == b[i]:
#             alice += 0
#             bob += 0
#         else:
#             bob += 1
    
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'compareTriplets' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

# second attempt

def compareTriplets(a, b):
    # Write your code here
    alice = 0
    bob = 0
    
    for i in range(0,3):
        if a[i] > b[i]:
            alice += 1
        elif a[i] == b[i]:
            alice += 0
            bob += 0
        else:
            bob += 1
    return alice, bob
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = compareTriplets(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

