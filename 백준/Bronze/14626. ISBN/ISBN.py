ISBN = input()
 
idx = 0
total = 0
for i in range(len(ISBN)):
    if ISBN[i] == '*':
        idx = i 
        continue
    else:
        if i % 2 == 0:
            total += int(ISBN[i])
        else:
            total += 3 * int(ISBN[i])

for x in range(10):
    if idx % 2 == 0:
        if (total + x) % 10 == 0:
            print(x)
            break
    else:
        if (total + 3 * x) % 10 == 0:
            print(x)
            break
        
