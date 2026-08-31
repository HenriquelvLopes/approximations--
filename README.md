# Pi-Approximations

Numerical approximations of the mathematical constant $\pi$ using two different computational approaches: the **Gauss–Legendre algorithm** and the **Monte Carlo method**.

The project explores both *deterministic* and *stochastic* approaches to numerical computation, with implementations in C and Python.

Methods studied:

### **Gauss–Legendre algorithm**:
a deterministic iterative algorithm with extremely fast convergence.

### **Monte Carlo method**:
a stochastic method based on random sampling and geometric probability.

Although both methods approximate the same constant, their computational behavior is very different. Gauss–Legendre rapidly increases the number of correct digits with each iteration, while Monte Carlo convergence is considerably slower and depends on the statistical behavior of randomly generated samples.

## Methods

### 1. Gauss–Legendre Algorithm

The **Gauss–Legendre algorithm** is based on the arithmetic–geometric mean and generates sequences that rapidly converge toward a common value.

The algorithm begins with

$$
a_0 = 1,\qquad
b_0 = \frac{1}{\sqrt{2}},\qquad
t_0 = \frac{1}{4},\qquad
p_0 = 1.
$$

At each iteration, the following quantities are calculated:

$$
a_{n+1} = \frac{a_n + b_n}{2}
$$

$$
b_{n+1} = \sqrt{a_n b_n}
$$

$$
t_{n+1} = t_n - p_n(a_n-a_{n+1})^2
$$

$$
p_{n+1} = 2p_n
$$

After the iterations, $\pi$ is approximated by

$$
\pi \approx \frac{(a+b)^2}{4t}
$$

The use of **MPFR libary** allows the program to work with arbitrary-precision floating-point numbers, rather than the fixed precision of standard C floating-point types.

The current C implementation uses a precision of **400,000 bits**, performs **20 iterations**, and writes **100,000 decimal digits** of $\pi$ to a text file.

A Python implementation of the Gauss–Legendre algorithm is planned.

### 2. Monte Carlo Method

The Monte Carlo approximation is based on a simple geometric construction.

Consider a unit square containing a quarter of a unit circle.

The area of the square is

$$
A_{\text{square}} = 1
$$

while the area of the quarter circle is

$$
A_{\text{circle}} = \frac{\pi}{4}.
$$

Therefore, the probability that a uniformly distributed random point $(x,y)$ inside the square satisfies

$$
x^2 + y^2 \leq 1
$$

is

$$
P = \frac{\pi}{4}.
$$

Using a sufficiently large number of randomly generated points,

$$
\frac{N_{\text{inside}}}{N_{\text{total}}}
\approx
\frac{\pi}{4},
$$

which gives

$$
\pi \approx
4\frac{N_{\text{inside}}}{N_{\text{total}}}.
$$

The implementation generates random values of $x$ and $y$ in the interval $[0,1]$, determines whether each point lies inside the quarter circle, and uses the resulting ratio to estimate $\pi$.

The current implementations use large numbers of random samples to investigate the behavior of this approximation.

## Implementations

| Method | Language | Main tools | Samples / Iterations | Approx. digits |
|--------|----------|------------|----------------------|-----------|
| Gauss–Legendre | C | MPFR | 20 iterations | $10^5$ |
| Monte Carlo | C | Standard library | $10^7$ samples | 6 |
| Monte Carlo | Python | random | $10^{10}$ samples | 4 |
| Gauss–Legendre | Python | Coming soon | — | — |

## Deterministic vs. Stochastic Computation

One of the main motivations of the project is to compare two very different numerical approaches.

The difference becomes particularly clear when considering how much computation is required to obtain additional digits of accuracy.

Gauss–Legendre can obtain a very large number of correct digits with relatively few iterations. Monte Carlo, on the other hand, requires a very large number of samples because its statistical error decreases approximately as

$$
\mathcal{O}\left(\frac{1}{\sqrt{N}}\right)
$$

where $N$ is the number of samples.

Thus, increasing the number of Monte Carlo samples by a factor of 100 only improves the characteristic statistical error by approximately a factor of 10.

## How to Use

Usage instructions are currently being organized as the project structure is finalized.

### C / Monte Carlo

No external libraries are required.

### C / Gauss–Legendre

Requires `MPFR`.

### Python / Monte Carlo

Uses Python's standard `random` module.

### Python / Gauss–Legendre

Coming soon.

## References

The mathematical background of the project draws on standard results
from numerical analysis and probability.

- M. E. J. Newman and G. T. Barkema,
  *Monte Carlo Methods in Statistical Physics*,
  Oxford University Press, 1999.

Further references, implementation notes, and numerical experiments are
documented in `DEVELOPMENT.md`.

