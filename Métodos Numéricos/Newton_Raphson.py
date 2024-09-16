# Método de Newton-Raphson - Otimização do Sinal da Antena - Métodos Numéricos
# Equipe: Kailane Lisley, Gabrielly Gouveia e Noemi Soares
import math
import time

def f(x):
    return x**2 - math.log(5)

def df(x):
    return 2*x

def m_newton_raphson(x0, e):
    etapas = []
    
    while abs(f(x0)) > e:
        x1 = x0 - f(x0) / df(x0)
        etapas.append((x0, x1, abs(f(x1))))
        x0 = x1

    return x0, etapas

def main():
    e = 0.000001
    x0 = float(input("Informe o valor inicial (x0): "))

    if df(x0) == 0:
        print("Método não converge: A derivada se anula no ponto inicial.")
        return
    
    start_time = time.time()
    raiz, etapas = m_newton_raphson(x0, e)
    end_time = time.time()

    print(f"Raiz aproximada: {raiz}")

    print(f"{'Iteração':<10} {'x_k':<20} {'x_k+1':<20} {'Erro':<20}")
    for i, (xk, xk1, erro) in enumerate(etapas, 1):
        print(f"{i:<10} {xk:<20.10f} {xk1:<20.10f} {erro:<20.10f}")

    print(f"Tempo de execução: {end_time - start_time} segundos")

if __name__ == "__main__":
    main()