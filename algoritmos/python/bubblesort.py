vector = [64, 34, 25, 12, 22, 11, 9]   

n = len(vector)
j = 0
for j in range(j, n-1):
    i = 0
    for i in range(i, n-j-1):
        if vector[i+1] < vector[i]:
            aux = vector[i]
            vector[i] = vector[i+1]
            vector[i+1] = aux
        
for i in range(n):
    num = vector[i]
    print(num)
