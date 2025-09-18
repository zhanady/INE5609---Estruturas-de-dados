

entradas = []

while True:
    linha = input().strip()
    if linha == "-1 -1 -1":  # condição de parada
        break
    num = list(map(int, linha.split()))
    entradas.append(num)

capacidade = int(input())

#print("Entradas lidas:")
#for e in entradas:
#    print(e)

#valor = entradas[0]/entradas[1]

res = []
#org = []
n = len(entradas)
i = 0

for i in range(i, n):
    j = 0
    valor = entradas[i][j]/entradas[i][j+1]     
    res_form = (i, valor, entradas[i][2], entradas[i][1])
    res.append(res_form)    

#print(res)
#print(res[0])

for j in range(1, n):
    i = j
    while i > 0 and res[i][1] > res[i-1][1]:
#for i in range(0, n-1):
 #   if res[i][1] < res[i+1][1]:
        temp = res[i]
        res[i] = res[i-1]
        res[i-1] = temp
        i -= 1

#print(res)
espaco_sobrando = capacidade 
soma = 0
form_saida = []
for i in range(0, n):
    if espaco_sobrando >= res[i][3]:
        if espaco_sobrando >= res[i][3]*res[i][2]:
            espaco_sobrando -= res[i][3]*res[i][2]
            saida = (res[i][0], res[i][2])
            form_saida.append(saida)
        else:
            k = res[i][2]
            for k in range(res[i][2], 0, -1):
                if espaco_sobrando >= res[i][3]*k:
                    espaco_sobrando -= res[i][3]*k
                    saida = (res[i][0], k)
                    form_saida.append(saida)

                #espaco_sobrando -= res[i][3]
                #saida = (res[i][0], 1)
                #form_saida.append(saida)
            
    elif espaco_sobrando == 1 and res[i][3] > 1:
        for z in range(i, n):
            if res[z][3] == 1:
                espaco_sobranco -= 1
                saida = (res[i][0], 1)
                form_saida.append(saida)
    
    elif espaco_sobrando == 0:
        break
    
for item_id, qtd in form_saida:
    print(item_id, qtd)


#o indice 0 eh o tipo, o indice 1 eh o valor (ut/peso), o indice 2 eh a qtd e o indice 3 eh o peso

    #se a soma é parcial, pode tbm

    # se eu tenho uma capacidade de 5
    # meu espaco sobrando eh 5
    # tenho 1 tipo de 4
    # 1 tipo de 2
    # 1 tipo de 3

    #coloquei o do tipo 4, ficou 1
    # coloco 1 do tipo 2
    # para colocar 1 do tipo 2 tenho que ver que o espaco sobrando eh == 1 e somar 1 somentesss

