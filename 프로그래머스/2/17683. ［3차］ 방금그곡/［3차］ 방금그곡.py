def solution(m, musicinfos):
    # 1. # 처리된 음을 소문자로 변환
    def convert(melody):
        return melody.replace("C#", "c").replace("D#", "d") \
                     .replace("F#", "f").replace("G#", "g") \
                     .replace("A#", "a").replace("B#", "b")

    m = convert(m)  # 듣고 싶은 멜로디 변환

    answer = []
    for idx, info in enumerate(musicinfos):
        start, end, title, melody = info.split(",")
        
        # 2. 시간 계산 (분 단위)
        sh, sm = map(int, start.split(":"))
        eh, em = map(int, end.split(":"))
        play_time = (eh * 60 + em) - (sh * 60 + sm)

        # 3. 멜로디 변환
        melody = convert(melody)

        # 4. 실제 재생 멜로디 생성
        played = (melody * (play_time // len(melody) + 1))[:play_time]

        # 5. 멜로디 포함 여부 확인
        if m in played:
            answer.append((play_time, idx, title))

    # 6. 조건에 따라 정렬
    if not answer:
        return "(None)"
    answer.sort(key=lambda x: (-x[0], x[1])) 
    return answer[0][2]
