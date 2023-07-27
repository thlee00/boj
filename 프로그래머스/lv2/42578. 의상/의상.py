from collections import Counter
from functools import reduce

def solution(clothes):
    answer = 1
    
    counter = Counter([category for clothes, category in clothes])
    
    answer = reduce(lambda ans, cur: ans*(cur+1), counter.values(), 1)
    
    return answer - 1