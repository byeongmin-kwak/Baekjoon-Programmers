def solution(s):
    answer = -1

    st = [s[0]]
    
    for i in range(1, len(s)):
        if len(st) == 0:
            st.append(s[i])
        else:
            if s[i] == st[-1]:
                st.pop()
            else:
                st.append(s[i])
    
    if len(st) == 0:
        answer = 1
    else:
        answer = 0
    
    return answer