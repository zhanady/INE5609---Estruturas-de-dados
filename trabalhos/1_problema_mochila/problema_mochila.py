entradas = []

while True:
    linha = input().strip()
    if linha == "-1 -1 -1":  
        break
    num = list(map(int, linha.split()))
    entradas.append(num)

capacidade = int(input())

res = []
tamanho = len(entradas)
i = 0

for i in range(i, tamanho):
    j = 0
    valor = entradas[i][j]/entradas[i][j+1]     
    res_form = (i, valor, entradas[i][2], entradas[i][1])
    res.append(res_form)    

for j in range(1, tamanho):
    i = j
    while i > 0 and res[i][1] > res[i-1][1]:
        temp = res[i]
        res[i] = res[i-1]
        res[i-1] = temp
        i -= 1

espaco_sobrando = capacidade 
soma = 0
form_saida = []
for i in range(0, tamanho):
    if espaco_sobrando >= res[i][3]:
        if espaco_sobrando >= res[i][3]*res[i][2]:
            espaco_sobrando -= res[i][3]*res[i][2]
            saida = (res[i][0], res[i][2])
            form_saida.append(saida)
        else:
            qtd = res[i][2]
            for qtd in range(qtd, 0, -1):
                if espaco_sobrando >= res[i][3]*qtd:
                    espaco_sobrando -= res[i][3]*qtd
                    saida = (res[i][0], qtd)
                    form_saida.append(saida)

    
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

