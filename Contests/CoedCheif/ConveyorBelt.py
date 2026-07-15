# There is a conveyor belt with N slots, numbered from  1 to N. There is also a collection point at each end of the belt, located at positions 0 and N+1.

# Each slot has a direction:
# L, which moves the object one position to the left;
# R, which moves the object one position to the right.
# An object will be placed at slot P. It repeatedly moves according to the direction of its current slot until it reaches one of the two collection points.

# Before placing the object, you may reverse the direction of any number of slots, changing L to R or R to L.

# Find the minimum number of slots whose directions must be reversed so that the object eventually reaches a collection point.

#Sample Input:        Sample Output:
# 3                   1
# 4 2                 0
# LRLR                2
# 5 3
# LLRRR
# 85
# RRLLRLRL

t = int(input())
for i in range(t):
    n, p = map(int, input().split())
    s = input()
    left_const = s[: p].count('R')
    right_const = s[p-1 :].count('L')
    print(min(left_const, right_const))
