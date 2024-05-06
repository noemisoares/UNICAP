#Exercício Operações entre Matrizes - Álgebra Linear
#Noemi Soares Gonçalves da Silva RA:00000851329 

import numpy as np 

def main():
    
    while True: 
    
        print("\nEscolha uma das opções de operações com matrizes abaixo:")
        print("   1 - Soma entre duas matrizes.")
        print("   2 - Subtração entre duas matrizes.")
        print("   3 - Multiplicação entre duas matrizes.")
        print("   4 - Multiplicação de uma matriz por um escalar.")
        print("   5 - Sair do progama")
        
        while True:
            
            opcao = int(input("Insira uma opção abaixo: "))
            
            if opcao >= 1 and opcao <= 5:
                break
        
            elif(opcao == 5): 
                break
            else:
                print("Entrada errada. Digite novamente.\n")
        
        if(opcao == 5):
            break
        
        print("\n")
        
        linhaA = int(input("Informe a quantidade de linhas da matriz A: "))
        colunaA = int(input("Informe a quantidade de colunas da matriz A: "))
        linhaB = int(input("Informe a quantidade de linhas da matriz B: "))
        colunaB = int(input("Informe a quantidade de colunas da matriz B: "))
        
        A = np.empty([linhaA, colunaA], dtype = float) 
        B = np.empty([linhaB, colunaB], dtype = float)
    
        print("\n")

        for i in range(0, linhaA):
            for j in range(0, colunaA):
                A[i][j] = float(input("Digite o elemento [{}][{}] da matriz A: ".format(i + 1,j + 1)))
        
        print("\n")

        for i in range(0, linhaB):
            for j in range(0, colunaB):
                B[i][j] = float(input("Digite o elemento [{}][{}] da matriz B: ".format(i + 1, j + 1)))
       
        print("\n")
 
        print("A matriz A é: \n{}".format(A))

        print("\n")

        print("A matriz B é: \n{}".format(B))

        if(opcao == 4):
            escalar = float(input("\nInforme um escalar: "))

        print("\n")
        
        if(opcao == 1):
            print("\nSoma:\n\n {}".format(soma(A, linhaA, colunaA, B, linhaB, colunaB)))
        
        elif(opcao == 2):
            print("\nSubtração: \n\n{}".format(subtracao(A, linhaA, colunaA, B, linhaB, colunaB)))
        
        elif(opcao == 3):
            print("\nMultiplicação: \n\n{}".format(multiplicacao(A, linhaA, colunaA, B, linhaB, colunaB)))
        
        elif(opcao == 4):
            print("\nMultiplicação de um escalar com uma matriz: \n\n{}".format(multiplicaEscalar(A, B, escalar)))
    
    return 0

def soma(matrizA, linhaA, colunaA, matrizB, linhaB, colunaB):

    if(linhaA != linhaB or colunaA != colunaB):
        
        return "operação com tais matrizes incompatíveis. Tente novamente."
     
    somando = matrizA + matrizB
    
    return somando

def subtracao(matrizA, linhaA, colunaA, matrizB, linhaB, colunaB):
     
    if(linhaA != linhaB or colunaA != colunaB):
        
        return "operação com tais matrizes incompatíveis. Tente novamente."
     
    subtraindo = matrizA - matrizB

    return subtraindo

def multiplicacao(matrizA, linhaA, colunaA, matrizB, linhaB, colunaB):
    
    if(linhaA != linhaB or colunaA != colunaB):
        
        return "operação com tais matrizes incompatíveis. Tente novamente."
        
    multiplicando = matrizA * matrizB
    
    return multiplicando
    
def multiplicaEscalar(matrizA, matrizB, escalar):

    escolha = input("Digite qual matriz você deseja multiplicar pelo escalar (A ou B): ")

    if escolha == "A":
        novaMatriz = matrizA * escalar
        print(f"Matriz A multiplicada pelo escalar {escalar}:\n{novaMatriz}")
    elif escolha == "B":
        novaMatriz = matrizB * escalar
        print(f"Matriz B multiplicada pelo escalar {escalar}:\n{novaMatriz}")
    else:
        print("Opção inválida. Digite apenas A ou B.")

    return novaMatriz
    
if __name__ == '__main__':
    main() 