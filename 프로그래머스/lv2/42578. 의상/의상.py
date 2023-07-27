def solution(clothes):
    answer = 1
    
    clothes_dict = {}
    for name, category in clothes:
        clothes_dict[category] = clothes_dict.get(category, 0) + 1
    
    for category in clothes_dict:
        answer *= clothes_dict[category] + 1
    
    return answer - 1