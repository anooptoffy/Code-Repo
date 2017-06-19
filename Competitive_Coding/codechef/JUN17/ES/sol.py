import math

N = int(input())
N = N + 1
i = 1
sum = 0
while i != N:
	sum = sum + math.floor(i * 2.7182818284)
	i = i + 1

print(sum)
