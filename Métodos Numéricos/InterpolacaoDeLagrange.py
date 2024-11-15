import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Lê o CSV
df = pd.read_csv('dados.csv')
# Exibe a linhas para verificar se os dados foram carregados
print("Primeiras linhas do DataFrame:")
print(df.head())
# Certificar-se de que as colunas 'dia' e 'demanda' são numéricas
df['dia'] = pd.to_numeric(df['dia'], errors='coerce')
df['demanda'] = pd.to_numeric(df['demanda'], errors='coerce')
# Extrair as colunas de 'dia' e 'demanda'
dias = df['dia'].values
demanda = df['demanda'].values
# Imprimir o conteúdo das variáveis
print("\nConteúdo de 'dias':", dias)
print("Conteúdo de 'demanda':", demanda)
# Função para interpolação de Lagrange
def lagrange(x, xi, yi):

    n = len(xi)
    resultado = 0
    for i in range(n):
        termo = yi[i]
        for j in range(n):
            if j != i:
                termo *= (x - xi[j]) / (xi[i] - xi[j])
        resultado += termo
    return resultado

# Testando a interpolação com os dias de exemplo
dias_interpolados = np.linspace(min(dias), max(dias), 500)
demanda_interpolada = [lagrange(x, dias, demanda) for x in dias_interpolados]

# Gráfico
plt.figure(figsize=(10, 6))
plt.plot(dias, demanda, 'o', label="Dados recebidos", markersize=6)  # Marca para os dados
plt.plot(dias_interpolados, demanda_interpolada, '-', label="Interpolação de Lagrange")
plt.xlabel('Dia')
plt.ylabel('Demanda')
plt.title('Previsão de Demanda com Interpolação de Lagrange')
plt.legend()
plt.grid(True)
plt.show()