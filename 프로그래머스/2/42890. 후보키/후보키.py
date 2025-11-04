from itertools import combinations

def solution(relation):
    num_rows = len(relation)
    num_cols = len(relation[0])
    
    # 1. 모든 가능한 속성 조합 생성
    all_combos = []
    for i in range(1, num_cols + 1):
        # (0), (1), ..., (0, 1), ... 등 모든 조합을 추가
        all_combos.extend(combinations(range(num_cols), i))
        
    # 2. 진짜 후보키를 담을 리스트 (이 리스트가 '전역' 저장소 역할을 함)
    candidate_keys = []
    
    # 3. 모든 조합을 하나씩 검사
    for combo in all_combos:
        
        # 4. [유일성 검사]
        temp_tuples = set()
        for row in range(num_rows):
            temp_list = []
            for col_idx in combo:
                temp_list.append(relation[row][col_idx])
            
            temp_tuples.add(tuple(temp_list))
        # 유일성 실패 (중복이 있음) -> 다음 조합으로
        if len(temp_tuples) != num_rows:
            continue
            
        # 5. [최소성 검사] (유일성 통과 시)
        is_minimal = True
        current_key_set = set(combo) # 예: {0, 1}
        
        # 2번 리스트에 이미 저장된 키(key)들을 확인
        for key in candidate_keys:
            # key(예: {0})가 current_key_set(예: {0, 1})의 부분집합인가?
            if set(key).issubset(current_key_set):
                is_minimal = False # 최소성 위배!
                break
                
        # 6. 유일성과 최소성을 모두 만족하면 정답 리스트에 추가
        if is_minimal:
            candidate_keys.append(combo)
            
    # 7. 최종 개수 반환
    return len(candidate_keys)