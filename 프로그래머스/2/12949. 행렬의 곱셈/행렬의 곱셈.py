def solution(arr1, arr2):
    answer = [[0] * len(arr2[0]) for _ in range(len(arr1))] 
    
    print(answer)
    for i in range(len(arr1)):
        for j in range(len(arr2[0])):
            element = 0;
            for k in range(len(arr2)):
                element += arr1[i][k] * arr2[k][j]
            
            answer[i][j] = element
            
    return answer