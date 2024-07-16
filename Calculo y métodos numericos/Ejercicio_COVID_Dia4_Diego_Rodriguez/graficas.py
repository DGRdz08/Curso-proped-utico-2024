import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('datos_SIR.csv')

plt.figure(figsize=(10, 6))

plt.plot(data['t'], data['S'], label='Susceptibles (S)', color='blue')
plt.plot(data['t'], data['I'], label='Infectados (I)', color='red')
plt.plot(data['t'], data['R'], label='Recuperados (R)', color='green')

plt.xlabel('Tiempo (días)')
plt.ylabel('Número de personas')
plt.title('Modelo SIR para COVID-19')
plt.legend()

plt.grid(True)
plt.show()
