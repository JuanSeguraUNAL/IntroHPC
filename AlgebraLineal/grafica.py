import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

sns.set()
sns.set_context("paper")

THREADS = np.array([1, 2, 4, 8, 16])

fig, ax = plt.subplots(figsize=(10,5))
for ii in THREADS:
    datos = np.loadtxt(f"datos_{ii}.txt")
    M = datos[:,0]
    mw = datos[:,1]
    sw = datos[:,2]
    mc = datos[:,3]
    sc = datos[:,4]

    ax.errorbar(M, mw, yerr=sw, label=f"THREADS={ii} Wall time")
    ax.errorbar(M, mc, yerr=sc, label=f"THREADS={ii} CPU time")
ax.set_xlabel("Matrix size")
ax.set_ylabel("Time")
ax.set_title("CPU and Wall time for linear systems")
fig.tight_layout()
plt.grid(True)
plt.legend()
fig.savefig("MatrixesTime.pdf")