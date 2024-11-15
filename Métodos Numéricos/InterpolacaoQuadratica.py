import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Carregar dados do CSV
def pegar_dados(arquivo):
    dado = pd.read_csv(arquivo)
    return dado['dia'].values, dado['demanda'].values

# Calcular coeficientes da interpolação quadrática
def interpolacao_quadratica(x, y):
    A = np.array([
        [x[0]**2, x[0], 1],
        [x[1]**2, x[1], 1],
        [x[2]**2, x[2], 1]
    ])
    b = np.array(y)
    coef = np.linalg.solve(A, b)
    return coef

# Calcular valor do polinômio
def calcular_polinomio(coef, x):
    a2, a1, a0 = coef
    return a2 * x**2 + a1 * x + a0

# Estimar terceira derivada
def estimar_terceira_derivada(x, y):
    if len(x) >= 4:
        h = x[1] - x[0]
        f3 = (y[3] - 3 * y[2] + 3 * y[1] - y[0]) / (h**3)
        return f3
    return 0

# Calcular erro de truncamento
def calcular_erro_truncamento(x, x_interpolacao, terceira_derivada):
    x0, x1, x2 = x_interpolacao
    novo_x = x[-1] + 1
    erro_trunc = ((novo_x - x0) * (novo_x - x1) * (novo_x - x2) * terceira_derivada) / 6
    return erro_trunc

# Plotar gráfico
def plot_interpolacao(x, y, coef, novo_x, previsto_y):
    x_plot = np.linspace(min(x)-1, max(x)+1, 100)
    y_plot = calcular_polinomio(coef, x_plot)
    plt.figure(figsize=(10, 6))
    plt.scatter(x, y, color='blue', label='Pontos conhecidos')
    plt.plot(x_plot, y_plot, color='red', label='Interpolação Quadrática')
    plt.scatter(novo_x, previsto_y, color='green', label='Previsão', marker='x', s=100)
    plt.xlabel('Dia')
    plt.ylabel('Demanda')
    plt.title('Previsão de Demanda usando Interpolação Quadrática')
    plt.legend()
    plt.grid(True)
    plt.show()

# Função principal
def main():
    arquivo = 'dados.csv'
    x, y = pegar_dados(arquivo)
    x_interpolacao = x[-3:]
    y_interpolacao = y[-3:]
    coef = interpolacao_quadratica(x_interpolacao, y_interpolacao)
    print(f"Coeficientes: a2 = {coef[0]:.2f}, a1 = {coef[1]:.2f}, a0 = {coef[2]:.2f}")
    novo_x = x[-1] + 1
    previsto_y = calcular_polinomio(coef, novo_x)
    print(f"Previsão dia {novo_x}: demanda = {previsto_y:.2f}")
    terceira_derivada = estimar_terceira_derivada(x, y)
    erro_trunc = calcular_erro_truncamento(x, x_interpolacao, terceira_derivada)
    print(f"Erro de truncamento: {erro_trunc:.2f}")
    plot_interpolacao(x, y, coef, novo_x, previsto_y)

if __name__ == "__main__":
    main()