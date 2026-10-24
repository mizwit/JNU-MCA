# CS-406: Numerical Methods Assignment - Questions

1. $y = x^3$, where $x = 2$, with error as $0.01$. Find approximate and relative error.

2. $z = x + y$, where $x = 10 \pm 0.1$ and $y = 20 \pm 0.2$. Find maximum error in $z$.

3. $A = L.W$, where $L = 20 + 0.1$ cm and $W = 10 + 0.05$ cm. Find in A, the maximum error and relative error.

4. Perform five iterations of the bisection method to find the approximate root of the equation $f(x) = \cos(x) - x.e^x = 0$.

5. Let $f(x) = x^3 - 5x + 1 = 0$. Assume an initial approximation of $x_0 = 0.5$. Perform four iterations using Newton-Raphson Method.

6. Approximate the value of $(17)^{\frac{1}{3}}$. Assume an initial approximation of $x_0 = 2$. Perform four iterations using Newton-Raphson Method.

7. Find $f(2.5)$ using Newton Forward Interpolation.

    | $x$ | $1$ | $2$ | $3$ | $4$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $y$ | $1$ | $8$ | $27$ | $64$ |

8. Find $f(12)$ using Newton Forward Interpolation.

    | $x$ | $10$ | $15$ | $20$ | $25$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $f(x)$ | $100$ | $225$ | $400$ | $625$ |

9. Explain why Newton Forward Interpolation is used when the required value is near the beginning of the equally spaced table.

10. Construct the difference table for the sequence of values $f(x) = (0, 0, 0, \epsilon, 0, 0, 0)$, where $\epsilon$ is an error. Also show that:
    1. The error spreads and increases in magnitude as the order of difference increases.
    2. The errors in each column have binomial coefficients.

11. Convert the following system into matrix form. Identify $A$, $X$ & $B$. Also write the augmented matrix.
    - $2x + 3y - z = 5$
    - $x - 2y + 4z = 7$
    - $3x + y + 2z = 10$

12. Classify the following system: $x + y = 4$ and $2x + 2y = 8$. Is it consistent? And how many solutions?

13. Determine whether $2x + y = 3$, $4x + 2y = 10$ has a unique solution, no solution or infinitely many solutions.

14. Calculate the determinant of $A = \begin{bmatrix} 3 & 2 \\ 1 & 4 \end{bmatrix}$ and state whether the corresponding square system can have a unique solution.

15. Solve using the Gaussian Elimination Method.
    - $2x + y + z = 10$
    - $4x - 8y + 3z = 2$
    - $-2x + 7y + 2z = 13$

16. Using the Gaussian Elimination Method, find $x$, $y$, $z$ and the pivot elements.
    - $2x + 3y + z = 10$
    - $4x + y + 2z = 12$
    - $-2x + 2y + 3z = 5$

17. Explain why row interchange is necessary before applying to the following matrix $\begin{bmatrix} 0 & 2 & 1 \\ 4 & 5 & 6 \\ 2 & 3 & 4 \end{bmatrix}$

18. Solve using Gauss-Jordan Method
    - $2x + y - z = 8$
    - $x + 2y + z = 7$
    - $3x - y + 2z = 7$

19. Solve using L.U. Decomposition.
    - $2x + y = 5$
    - $4x + 3y = 11$

20. Why is LU Decomposition particularly useful when several systems have the same coefficient matrix but different right hand side vectors?

21. Use Fixed Point Iteration to solve $x^2 + x - 2 = 0$, using $x = (2 - x)^{1/2}$ and $x_0 = 1.5$, and perform 3 iterations.

22. Explain why choosing a different rearrangement of the same equation may change convergence.

23. Construct a quadratic spline for $(0, 1), (1, 2), (2, 5)$ using $F''(0) = 0$.