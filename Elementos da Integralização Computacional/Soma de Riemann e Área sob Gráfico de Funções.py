#Exercício Soma de Riemann e Área sob Gráfico de Funções - Elementos da Integralização Computacional
#Noemi Soares Gonçalves da Silva RA:00000851329 

# 1 - f(x) = 2x, no intervalo [0,1].
def f(x):
  return 2 * x

a = 0
b = 1
n = 1000
soma_riemann = 0
area = 0

dx = (b - a) / n

for i in range(n):
  x = a + i * dx
  soma_riemann += f(x) * dx
  area += f(x) * dx / 2

print(f"Função f(x) = 2x, intervalo [0, 1]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área abaixo da curva: {area}")

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 1000)
plt.plot(x, f(x))
plt.axhline(color="black")
plt.fill_between(x, f(x), where=[(x >= a) and (x <= b) for x in x])
plt.show()


# 2 - g(x) = x^2, no intervalo [1,3].
def g(x):
  return x**2

a = 1
b = 3
n = 1000
soma_riemann = 0
area = 0

dx = (b - a) / n

for i in range(n):
  x = a + i * dx
  soma_riemann += g(x) * dx
  area += g(x) * dx / 2

print(f"Função g(x) = x^2, intervalo [1, 3]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área abaixo da curva: {area}")
 
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 1000)
plt.plot(x, g(x))
plt.axhline(color="black")
plt.fill_between(x, g(x), where=[(x >= a) and (x <= b) for x in x])
plt.show()


# 3 - h(x) = (x^2/3)+2, no intervalo [0,3].
def h(x):
  return (x**2) / 3 + 2

a = 0
b = 3
n = 1000
soma_riemann = 0
area = 0

dx = (b - a) / n

for i in range(n):
  x = a + i * dx
  soma_riemann += h(x) * dx
  area += h(x) * dx / 2

print(f"Função h(x) = (x^2/3) + 2, intervalo [0, 3]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área abaixo da curva: {area}")
 
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 1000)
plt.plot(x, h(x))
plt.axhline(color="black")
plt.fill_between(x, h(x), where=[(x >= a) and (x <= b) for x in x])
plt.show()


# 4 - p(x) = (x^3)-4x, no intervalo [-2,0].
def p(x):
  return x**3 - 4 * x

a = -2
b = 0
n = 1000
soma_riemann = 0
area = 0

dx = (b - a) / n

for i in range(n):
  x = a + i * dx
  soma_riemann += p(x) * dx
  area += p(x) * dx / 2

print(f"Função p(x) = x^3 - 4x, intervalo [-2, 0]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área abaixo da curva: {area}")
 
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 1000)
plt.plot(x, p(x))
plt.axhline(color="black")
plt.fill_between(x, p(x), where=[(x >= a) and (x <= b) for x in x])
plt.show()


# 5 - q(x) = (x^2)+x+2, no intervalo [-1,2].
def q(x):
  return x**2 + x + 2

a = -1
b = 2
n = 1000
soma_riemann = 0
area = 0

dx = (b - a) / n

for i in range(n):
  x = a + i * dx
  soma_riemann += q(x) * dx
  area += q(x) * dx / 2

print(f"Função q(x) = x^2 + x + 2, intervalo [-1, 2]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área abaixo da curva: {area}")
 
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 1000)
plt.plot(x, q(x))
plt.axhline(color="black")
plt.fill_between(x, q(x), where=[(x >= a) and (x <= b) for x in x])
plt.show()

# 6 - r(x) = (cos(x))^2, no intervalo [0,1].
import math

def r(x):
  return math.cos(x)**2

a = 0
b = 1
n = 1000
soma_riemann = 0
area = 0

dx = (b - a) / n
y = []

for i in range(n):
  x = a + i * dx
  y.append(r(x)) 
  soma_riemann += y[i] * dx
  area = 1 - math.exp(-b) 

print(f"Função r(x) = cos(x)^2, intervalo [0, 1]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área exata abaixo da curva: {area}")

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 1000)

y_positive = [y_i if y_i >= 0 else 0 for y_i in y]

plt.plot(x, y)
plt.axhline(color="black")
plt.fill_between(x, y_positive, where=[(x >= a) and (x <= b) for x in x])
plt.show()

# 7 - t(x) = e^(-x), no intervalo [0,3].
import math

def t(x):
  return math.exp(-x)

a = 0
b = 3
n = 10000  
soma_riemann = 0
area = 0

dx = (b - a) / n
y = []   

for i in range(n):
  x = a + i * dx
  y.append(t(x))  
  soma_riemann += y[i] * dx
  area = 1 - math.exp(-b)   

print(f"Função t(x) = e^(-x), intervalo [0, 3]:")
print(f"Soma de Riemann: {soma_riemann}")
print(f"Área exata abaixo da curva: {area}")

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(a, b, 10000)
y = [t(x_i) for x_i in x]  

plt.plot(x, y)
plt.axhline(color="black")
plt.fill_between(x, y, where=[(x >= a) and (x <= b) for x in x])
plt.show()
