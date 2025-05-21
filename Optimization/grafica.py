import numpy as np
import matplotlib.pyplot as plt

datos0 = np.loadtxt("data-0.txt")
datos1 = np.loadtxt("data-1.txt")
datos2 = np.loadtxt("data-2.txt")
datos3 = np.loadtxt("data-3.txt")

fig, ax = plt.subplots()
ax.plot(datos0[:,1], datos0[:,3], label="OPT = 0")
ax.plot(datos1[:,1], datos1[:,3], label="OPT = 1")
ax.plot(datos2[:,1], datos2[:,3], label="OPT = 2")
ax.plot(datos3[:,1], datos3[:,3], label="OPT = 3")
ax.set_xlabel("csize")
ax.set_ylabel("Time for transposition cache-block")
ax.set_xscale("log")
plt.legend()
plt.grid()
plt.tight_layout()
plt.show()