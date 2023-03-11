# Diffusion_Finite_Diff

## Project description

This is a very simple piece of software that runs a simulation of the following equation :

```math
\begin{cases}

\frac{\partial T}{\partial t} = D\Delta T \text{ on }\Omega\\
T = T_{b} \text{ on } \partial\Omega

\end{cases}
```

Where $\Omega = [0,1]^3$. 

## Simulation method

In order discretize the problem, we introduce the length $L$ and the time $\Delta t$ and we discretize the domain $\Omega$ with steps of $\frac{1}{L}$ in space and $\frac{1}{\Delta t}$ in time. We also introduce the notation : 

```math
\forall (i,j, k) \in \left \lbrace 1...L \right \rbrace^2 \times \left\lbrace1...\Delta t \right\rbrace, T_{ij}^k = T\left(\frac{i}{L}, \frac{j}{L}, \frac{k}{\Delta t}\right)
```
