import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

sns.set()
sns.set_context("paper")

# Cargar los datos
datos0 = np.loadtxt("datos_0.txt")
datos1 = np.loadtxt("datos_1.txt")
datos2 = np.loadtxt("datos_2.txt")
datos3 = np.loadtxt("datos_3.txt")
datosfast = np.loadtxt("datos_fast.txt")

# Normalizacion
Nrec = datos0[20, 1]
Nfas = datos0[20, 2]

# Graficacion
fig, ax =plt.subplots(figsize= (10,5))
ax.plot(datos0[:, 0], datos0[:, 1] / Nrec, label="Opt0 - Recursive", linestyle="solid", color="blue", lw=2)
ax.plot(datos0[:, 0], datos0[:, 2] / Nfas, label="Opt0 - Fast", linestyle="dashed", color="blue", lw=2)
ax.plot(datos1[:, 0], datos1[:, 1] / Nrec, label="Opt1 - Recursive", linestyle="solid", color="green", lw=2)
ax.plot(datos1[:, 0], datos1[:, 2] / Nfas, label="Opt1 - Fast", linestyle="dashed", color="green", lw=2)
ax.plot(datos2[:, 0], datos2[:, 1] / Nrec, label="Opt2 - Recursive", linestyle="solid", color="red", lw=2)
ax.plot(datos2[:, 0], datos2[:, 2] / Nfas, label="Opt2 - Fast", linestyle="dashed", color="red", lw=2)
ax.plot(datos3[:, 0], datos3[:, 1] / Nrec, label="Opt3 - Recursive", linestyle="solid", color="purple", lw=2)
ax.plot(datos3[:, 0], datos3[:, 2] / Nfas, label="Opt3 - Fast", linestyle="dashed", color="purple", lw=2)
ax.plot(datosfast[:, 0], datosfast[:, 1] / Nrec, label="OptF - Recursive", linestyle="solid", color="orange", lw=2)
ax.plot(datosfast[:, 0], datosfast[:, 2] / Nfas, label="OptF - Fast", linestyle="dashed", color="orange", lw=2)
ax.set_yscale("log")
ax.set_xlabel(r"$n$")
ax.set_ylabel(r"Normalized Time (Respect to $n=2$ with optimization $0$)")

ax.set_title("Fibonacci sequence times with recursive and fast implementation for different optimization levels")
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig("Fib_sequence_times.pdf")
plt.show()
