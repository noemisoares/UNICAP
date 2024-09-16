# Método da Falsa Posição - Otimização do Sinal da Antena - Métodos Numéricos
# Equipe: Kailane Lisley, Gabrielly Gouveia e Noemi Soares
import math
import time

def f(x):
    return x**2 - math.log(5)

def metodo_falsa_posicao(a, b, e):
    etapas = []

    if f(a) * f(b) >= 0:
        return None, etapas, False

    xi = (a * f(b) - b * f(a)) / (f(b) - f(a))
    etapas.append((a, b, xi, abs(b - a)))

    while abs(f(xi)) > e:
        if f(xi) == 0:
            break

        if f(a) * f(xi) < 0:
            b = xi
        else:
            a = xi

        xi = (a * f(b) - b * f(a)) / (f(b) - f(a))
        etapas.append((a, b, xi, abs(b - a)))

    return xi, etapas, True

def print_tabela(etapas):
    print(f"{'Iteração':<10} {'a':<20} {'b':<20} {'Xk':<20} {'CP':<20}")
    for i, (a, b, xk, cp) in enumerate(etapas, 1):
        print(f"{i:<10} {a:<20.10f} {b:<20.10f} {xk:<20.10f} {cp:<20.10f}")

def main():
    e = 0.000001
    a = float(input("Informe o valor de a (inferior): "))
    b = float(input("Informe o valor de b (superior): "))
    
    if a >= b:
        print("O valor de a deve ser menor que o valor de b.")
        return
    
    start_time = time.perf_counter()
    raiz, etapas, raiz_intervalo = metodo_falsa_posicao(a, b, e)
    end_time = time.perf_counter()

    if raiz is not None:
        print(f"Raiz aproximada: {raiz}")
        if not raiz_intervalo:
            print("Atenção: Os valores fornecidos não garantem que haja uma raiz nesse intervalo.")
        
        print("Tabela de etapas:")
        print_tabela(etapas)
    else:
        print("Não foi possível encontrar uma raiz no intervalo fornecido.")
    
    print(f"Tempo de execução: {end_time - start_time} segundos")

if __name__ == "__main__":
    main()