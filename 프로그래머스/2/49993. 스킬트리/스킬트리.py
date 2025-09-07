def solution(skill, skill_trees):
    answer = 0
    
    skill_list = []
    for i in range(len(skill)):
        skill_list.append(skill[i])
    
    for elem in skill_trees:
        check = [False] * 26
        flag = False
        for i in range(len(elem)):
            if elem[i] in skill_list:
                for j in range(len(skill_list)):
                    if skill_list[j] == elem[i]:
                        if j == 0 or check[j-1]:
                            check[j] = True
                            break
                        else:
                            flag = True
            
        if not flag:
            answer += 1
        
    return answer