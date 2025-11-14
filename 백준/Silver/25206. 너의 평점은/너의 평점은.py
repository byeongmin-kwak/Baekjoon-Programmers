grade = {"A+": 4.5, "A0": 4.0, "B+": 3.5, "B0": 3.0, "C+": 2.5, "C0": 2.0, "D+": 1.5, "D0": 1.0, "F": 0.0}

answer = 0
total = 0
cnt = 0

for _ in range(20):
    name, credit, score = input().split()
    if score != "P":
        total += float(credit) * grade[score]
        cnt += float(credit)
    
answer = total / cnt
print(answer)

