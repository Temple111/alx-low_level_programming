#!/usr/bin/python3
largest_pal = 0

for a in range(999, 99, -1):
    for z in range(999, 99, -1):
        answer = a * z
        answer = str(answer)
        if (answer == answer[::-1]):
            answer = int(answer)
            if (answer > largest_pal):
                largest_pal = answer

print(largest_pal)
