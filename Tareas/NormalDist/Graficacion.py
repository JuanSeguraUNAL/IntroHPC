import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('datos1.txt')
data2 = np.loadtxt('datos2.txt')
data5 = np.loadtxt('datos5.txt')

colors = plt.cm.Blues(np.linspace(0.5, 1, 3))
x = np.linspace(2.7, 4.6)
Normal = np.exp(-((x - 3.5) / 0.4)**2 / 2) / (0.4 * np.sqrt(2 * np.pi))
alfa = 1

fig, ax = plt.subplots(figsize = (10, 5))
ax.plot(x, Normal, '-.', label = 'Distribucion Normal', color = 'red', linewidth = 2, alpha = alfa)
ax.plot(data1[:, 0], data1[:, 1], '-',label = 'Seed 1', color = colors[0], linewidth = 2, alpha = alfa)
ax.plot(data2[:, 0], data2[:, 1], '-',label = 'Seed 2', color = colors[1], linewidth = 2, alpha = alfa)
ax.plot(data5[:, 0], data5[:, 1], '-',label = 'Seed 5', color = colors[2], linewidth = 2, alpha = alfa)
ax.set_xlabel(r'$x$')
ax.set_ylabel(r'f(x)')
ax.set_title('Probability Density Function')

plt.legend(fontsize=12)
plt.tight_layout()
plt.grid(True, which='both', linestyle='--', linewidth=0.5, alpha=0.7)
plt.savefig("DistribucionNormal.pdf")
plt.show()