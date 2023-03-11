# Diffusion_Finite_Diff

## Project description

This is a very simple piece of software that runs a simulation of the following equation :

```math
\begin{cases}

\frac{\partial T}{\partial t} = D\Delta T \text{ on }\Omega\\
T = T_{b} \text{ on } \partial\Omega

\end{cases}
```

Where $\Omega = [0,1]^3$