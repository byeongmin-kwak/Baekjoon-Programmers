from collections import Counter

def solution(str1, str2):
    answer = 0
    
    li1 = []
    li2 = []
    
    for i in range(len(str1)-1):
        str = str1[i:i+2].lower()
        if (str.isalpha()):
            li1.append(str)
    
    for i in range(len(str2)-1):
        str = str2[i:i+2].lower()
        if (str.isalpha()):
            li2.append(str)
    
    c1 = Counter(li1)
    c2 = Counter(li2)
    
    inter = c1 & c2   
    union = c1 | c2   
    
    interSize = sum(inter.values())
    unionSize = sum(union.values())
    
    if unionSize == 0:
        answer = 65536
    else:
        answer = int(interSize / unionSize * 65536)
    
    
    return answer