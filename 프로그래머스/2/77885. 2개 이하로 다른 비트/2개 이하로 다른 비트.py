def solution(numbers):
    answer = []
    
    for number in numbers:
        if number % 2 == 0:
            answer.append(number + 1)
        else:
            binary = list('0' + bin(number)[2:]) 
            for i in range(len(binary)-1, -1, -1):
                if binary[i] == '0':
                    binary[i] = '1'     
                    binary[i+1] = '0'    
                    break
            answer.append(int(''.join(binary), 2))

    
    return answer