def time_to_minute(time):
    
    minute = int(time[:2])*60 + int(time[3:])  
    
    return minute
    
def minute_to_time(minute):
    
    time = ''
    
    hour = str(minute // 60)
    if len(hour) == 1:
        hour = '0' + hour
        
    minute = str(minute % 60)
    if len(minute) == 1:
        minute = '0' + minute
        
    time = hour + ':' + minute
    
    return time

def solution(n, t, m, timetable):
    answer = ''
    
    # 셔틀 시간 계산 -> 앞차부터 계산해서 그 차에 몇명이 타는지 계산, 그 차에 타려면 몇시에 타야하는지 계산 -> 마지막 차까지 계산해서 제일 늦은 시간 찾기
    
    timetable.sort()
    
    # 셔틀 시간 계산
    
    idx = -1
    for i in range(n):
        minute = time_to_minute("09:00") + i*t
        time = minute_to_time(minute)
        
        people = 0 

        for i in range(idx+1, len(timetable)):
            if timetable[i] <= time and people < m:
                people += 1
                idx = i
            else:
                break
        
        if people < m:
            answer = time
        else:
            flag = False
            for i in range(m-1):
                if timetable[idx-i] != timetable[idx-i-1]:
                    answer = minute_to_time(time_to_minute(timetable[idx-i]) - 1)
                    flag = True
                    break
            if not flag:
                answer = minute_to_time(time_to_minute(timetable[idx-m+1]) - 1)
    
    return answer