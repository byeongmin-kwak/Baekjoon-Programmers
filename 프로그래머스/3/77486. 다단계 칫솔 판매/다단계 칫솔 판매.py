def money(profit, name_to_profit, name_to_referral, name):
    if name == "-" or profit == 0:
        return
    
    if name in name_to_profit:
        name_to_profit[name] += profit - profit // 10
    else:
        name_to_profit[name] = profit - profit // 10
    
    money(profit // 10, name_to_profit, name_to_referral, name_to_referral[name])
    
    return
    

def solution(enroll, referral, seller, amount):
    answer = []
    
    name_to_referral = {}
    name_to_profit = {}
    
    for i in range(len(enroll)):
        name_to_referral[enroll[i]] = referral[i]
        
    # seller마다 이익금 업데이트
    for i in range(len(seller)):
        profit = amount[i] * 100
        name = seller[i]
        
        money(profit, name_to_profit, name_to_referral, name)
            
    # answer에 답 넣기
    for name in enroll:
        if name in name_to_profit:
            answer.append(name_to_profit[name])
        else:
            answer.append(0)
    
    return answer