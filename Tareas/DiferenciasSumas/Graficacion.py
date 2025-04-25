import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('data.txt')

fig, ax = plt.subplots(figsize = (10, 5))
ax.plot(data[:, 0], data[:, 3], 
        '-',
        label = r'$\left|1 - \frac{S_{1}}{S_{2}} \right|$', 
        color = 'purple',
        linewidth = 2,
        alpha = 0.7)
ax.set_xlabel(r'$N$')
ax.set_ylabel(r'Diferencia relativa $\Delta$')
ax.set_title('Diferencias numéricas en sumas')
# ax.set_xscale('log')
ax.set_yscale('log')
plt.legend(fontsize=12)
plt.tight_layout()
plt.grid(True, which='both', axis='y', linestyle='--', linewidth=0.5, alpha=0.7)
plt.savefig("DiferenciasSumas.pdf")
plt.show()