a, n = list(map(int, input().split()))
b = 0
for i in range(1, n): 
    if a * i % n == 1:
        b = i
        break
print (b)