
s = []
for _ in range(3):
    s.append(input())

for i in range(2, -1, -1):
    if s[i].isdigit():
        next = int(s[i])+(3-i)
        if next % 3 == 0 and  next % 5 == 0:
            print("FizzBuzz")
        elif next % 3 == 0:
            print("Fizz")
        elif next % 5 == 0:
            print("Buzz")
        else:
            print(next)
        break