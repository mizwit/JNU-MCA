# CS-406: Numerical Methods Assignment - Solutions

#### 1. $y = x^3$, where $x = 2$, with error as $0.01$. Find approximate and relative error.
- Given, $y = x^3$, $x = 2$, and $dx = 0.01$.
- $f'(x) = 3x^2$
- $|dy| = |f'(x)|.|dx| = 3x^2.dx$
- $dy = 3 \times 2^2 \times 0.01$
- **Approximate error:** $|dy| = 0.12$
- $|\frac{dy}{y}| = |\frac{x.f'(x)}{f(x)}|.|\frac{dx}{x}|$
- $\frac{x.f'(x)}{f(x)} = \frac{x.3x^2}{x^3}= 3$
- $|\frac{dy}{y}| = 3 \times |\frac{dx}{x}| = 3 \times \frac{0.01}{2}$
- **Relative error:** $|\frac{dy}{y}| = 0.015 = 1.5\%$

---

#### 2. $z = x + y$, where $x = 10 \pm 0.1$ and $y = 20 \pm 0.2$. Find maximum error in $z$.
- $|dz| \le |dx| + |dy|$
- $|dz| \le 0.1 + 0.2$
- **Maximum absolute error:** $|dz| \le 0.3$

---

#### 3. $A = L.W$, where $L = 20 + 0.1$ cm and $W = 10 + 0.05$ cm. Find in A, the maximum error and relative error.
- $dz = y.dx + x.dy$
- $dz = 10(0.1) + 20(0.05)$
- **Maximum error:** $dz = 2 cm^2$
- $|\frac{dz}{z}| \le |\frac{dx}{x}| + |\frac{dy}{y}|$
- $|\frac{dz}{z}| \le \frac{0.1}{20} + \frac{0.05}{10}$
- **Relative error:** $|\frac{dz}{z}| = 0.01 = 1\%$

---

#### 4. Perform five iterations of the bisection method to find the approximate root of the equation $f(x) = \cos(x) - x.e^x = 0$.
- Initial interval $a = 0$ and $b = 1$
- $f(0) = \cos(0) - (0)e^0 = 1$
- $f(1) = \cos(1) - (1)e^1 = 0.540302 - 2.718282 = -2.177980$
- $f(0).f(1) < 0$.
- So, root lies in the interval $(0, 1)$.
- **Iteration 1:**
    - Midpoint, $c = \frac{0 + 1}{2} = 0.5$
    - $f(c) = f(0.5) = \cos(0.5) - (0.5)e^{0.5} = 0.877583 - 0.824361 = 0.053222$
    - $f(0.5).f(1) < 0$
    - So, root lies in the interval $(0.5, 1)$.
- **Iteration 2:**
    - Midpoint, $c = \frac{0.5 + 1}{2} = 0.75$
    - $f(c) = f(0.75) = \cos(0.75) - (0.75)e^{0.75} = 0.731689 - 1.587750 = -0.856061$
    - $f(0.5).f(0.75) < 0$
    - So, root lies in the interval $(0.5, 0.75)$.
- **Iteration 3:**
    - Midpoint, $c = \frac{0.5 + 0.75}{2} = 0.625$
    - $f(c) = f(0.625) = \cos(0.625) - (0.625)e^{0.625} = 0.810963 - 1.167654 = -0.356691$
    - $f(0.5).f(0.625) < 0$
    - So, root lies in the interval $(0.5, 0.625)$.
- **Iteration 4:**
    - Midpoint, $c = \frac{0.5 + 0.625}{2} = 0.5625$
    - $f(c) = f(0.5625) = \cos(0.5625) - (0.5625)e^{0.5625} = 0.845924 - 0.987218 = -0.141294$
    - $f(0.5).f(0.5625) < 0$
    - So, root lies in the interval $(0.5, 0.5625)$.
- **Iteration 5:**
    - Midpoint, $c = \frac{0.5 + 0.5625}{2} = 0.53125$
    - $f(c) = f(0.53125) = \cos(0.53125) - (0.53125)e^{0.53125} = 0.862176 - 0.903686 = -0.041510$
    - $f(0.5).f(0.53125) < 0$
    - So, root lies in the interval $(0.5, 0.53125)$.
- Approximate value of the root, $r \approx \frac{0.5 + 0.53125}{2} = 0.515625$

---

#### 5. Let $f(x) = x^3 - 5x + 1 = 0$. Assume an initial approximation of $x_0 = 0.5$. Perform four iterations using Newton-Raphson Method.
- $f'(x) = 3x^2 - 5$
- Initial approximation, $x_0 = 0.5$
- **Iteration 1:**
    - $f(x_0) = f(0.5) = (0.5)^3 - 5(0.5) + 1 = -1.375$
    - $f'(x_0) = f'(0.5) = 3(0.5)^2 - 5 = -4.25$
    - $x_1 = x_0 - \frac{f(x_0)}{f'(x_0)} = 0.5 - \frac{-1.375}{-4.25}$
    - $x_1 = 0.176471$
- **Iteration 2:**
    - $f(x_1) = f(0.176471) = (0.176471)^3 - 5(0.176471) + 1 = 0.123143$
    - $f'(x_1) = f'(0.176471) = 3(0.176471)^2 - 5 = -4.906574$
    - $x_2 = x_1 - \frac{f(x_1)}{f'(x_1)} = 0.176471 - \frac{0.123143}{-4.906574}$
    - $x_2 = 0.201567$
- **Iteration 3:**
    - $f(x_2) = f(0.201567) = (0.201567)^3 - 5(0.201567) + 1 = 0.000357$
    - $f'(x_2) = f'(0.201567) = 3(0.201567)^2 - 5 = -4.878113$
    - $x_3 = x_2 - \frac{f(x_2)}{f'(x_2)} = 0.201567 - \frac{0.000357}{-4.878113}$
    - $x_3 = 0.201640$
- **Iteration 4:**
    - $f(x_3) = f(0.201640) = (0.201640)^3 - 5(0.201640) + 1 = -0.000002$
    - $f'(x_3) = f'(0.201640) = 3(0.201640)^2 - 5 = -4.878023$
    - $x_4 = x_3 - \frac{f(x_3)}{f'(x_3)} = 0.201640 - \frac{-0.000002}{-4.878023}$
    - $x_4 = 0.201640$
- Approximate value of the root, $r \approx 0.201640$

---

#### 6. Approximate the value of $(17)^{\frac{1}{3}}$. Assume an initial approximation of $x_0 = 2$. Perform four iterations using Newton-Raphson Method.
- Let $(17)^{1/3} = x$. So, $f(x) = x^3 - 17 = 0$.
- $f'(x) = 3x^2$
- Initial approximation, $x_0 = 2$
- **Iteration 1:**
    - $f(x_0) = f(2) = (2)^3 - 17 = -9$
    - $f'(x_0) = f'(2) = 3(2)^2 = 12$
    - $x_1 = x_0 - \frac{f(x_0)}{f'(x_0)} = 2 - \frac{-9}{12}$
    - $x_1 = 2.75$
- **Iteration 2:**
    - $f(x_1) = f(2.75) = (2.75)^3 - 17 = 3.796875$
    - $f'(x_1) = f'(2.75) = 3(2.75)^2 = 22.6875$
    - $x_2 = x_1 - \frac{f(x_1)}{f'(x_1)} = 2.75 - \frac{3.796875}{22.6875}$
    - $x_2 = 2.582645$
- **Iteration 3:**
    - $f(x_2) = f(2.582645) = (2.582645)^3 - 17 = 0.226380$
    - $f'(x_2) = f'(2.582645) = 3(2.582645)^2 = 20.010159$
    - $x_3 = x_2 - \frac{f(x_2)}{f'(x_2)} = 2.582645 - \frac{0.226380}{20.010159}$
    - $x_3 = 2.571332$
- **Iteration 4:**
    - $f(x_3) = f(2.571332) = (2.571332)^3 - 17 = 0.000997$
    - $f'(x_3) = f'(2.571332) = 3(2.571332)^2 = 19.835241$
    - $x_4 = x_3 - \frac{f(x_3)}{f'(x_3)} = 2.571332 - \frac{0.000997}{19.835241}$
    - $x_4 = 2.571282$
- Approximate value of $(17)^{1/3} \approx 2.571282$

---

#### 7. Find $f(2.5)$ using Newton Forward Interpolation.

| $x$ | $1$ | $2$ | $3$ | $4$ |
| :-- | :-- | :-- | :-- | :-- |
| $y$ | $1$ | $8$ | $27$ | $64$ |

- $x_0 = 1$, $h=1 \Rightarrow p = \dfrac{2.5-1}{1} = 1.5$
- Difference table: $\Delta y_0 = 7$, $\Delta^2y_0 = 12$, $\Delta^3y_0 = 6$
- $P_3(2.5) = y_0 + p\Delta y_0 + \dfrac{p(p-1)}{2!}\Delta^2y_0 + \dfrac{p(p-1)(p-2)}{3!}\Delta^3y_0$
- $P_3(2.5) = 1 + (1.5)(7) + \dfrac{(1.5)(0.5)}{2}(12) + \dfrac{(1.5)(0.5)(-0.5)}{6}(6)$
- $P_3(2.5) = 1 + 10.5 + 4.5 - 0.375 = 15.625$
- $\therefore f(2.5) = 15.625$

---

#### 8. Find $f(12)$ using Newton Forward Interpolation.

| $x$ | $10$ | $15$ | $20$ | $25$ |
| :-- | :-- | :-- | :-- | :-- |
| $f(x)$ | $100$ | $225$ | $400$ | $625$ |

- $x_0 = 10$, $h=5 \Rightarrow p = \dfrac{12-10}{5} = 0.4$
- Difference table: $\Delta y_0 = 125$, $\Delta^2y_0 = 50$, $\Delta^3y_0 = 0$
- $P_3(12) = y_0 + p\Delta y_0 + \dfrac{p(p-1)}{2!}\Delta^2y_0 + \dfrac{p(p-1)(p-2)}{3!}\Delta^3y_0$
- $P_3(12) = 100 + (0.4)(125) + \dfrac{(0.4)(-0.6)}{2}(50) + 0$
- $P_3(12) = 100 + 50 - 6 = 144$
- $\therefore f(12) = 144$

---

#### 9. Explain why Newton Forward Interpolation is used when the required value is near the beginning of the equally spaced table.
- Newton Forward Interpolation builds its correction terms from $x_0$ (the **first** point in the table), using $p = \dfrac{x-x_0}{h}$. 
- When $x$ is close to $x_0$, $p$ is small (typically $|p|<1$), which makes each successive term in the series — $\dfrac{p(p-1)}{2!}\Delta^2y_0$, $\dfrac{p(p-1)(p-2)}{3!}\Delta^3y_0$, etc. rapidly shrink in magnitude, so the series converges quickly and only a few terms are needed for good accuracy. 
- If $x$ were instead near the *end* of the table, $p$ would be large, forcing many terms to be included for the same accuracy which is why **Newton Backward Interpolation** (built from $x_n$, the last point) is preferred in that case instead.

---

#### 10. Construct the difference table for the sequence of values $f(x) = (0, 0, 0, \epsilon, 0, 0, 0)$, where $\epsilon$ is an error. Also show that:
    1. The error spreads and increases in magnitude as the order of difference increases.
    2. The errors in each column have binomial coefficients.

| $x$ | $f(x)$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ | $\Delta^5 f$ | $\Delta^6 f$ |
| :-- | :-- | :-- | :-- | :-- | :-- | :-- | :-- |
| $x_0$ | $0$ | $0$ | $0$ | $\epsilon$ | $-4\epsilon$ | $10\epsilon$ | $-20\epsilon$ |
| $x_1$ | $0$ | $0$ | $\epsilon$ | $-3\epsilon$ | $6\epsilon$ | $-10\epsilon$ | |
| $x_2$ | $0$ | $\epsilon$ | $-2\epsilon$ | $3\epsilon$ | $-4\epsilon$ | | |
| $x_3$ | $\epsilon$ | $-\epsilon$ | $\epsilon$ | $-\epsilon$ | | | |
| $x_4$ | $0$ | $0$ | $0$ | | | | |
| $x_5$ | $0$ | $0$ | | | | | |
| $x_6$ | $0$ | | | | | | |

- Largest magnitude in each column: $\epsilon,\ 2\epsilon,\ 3\epsilon,\ 6\epsilon,\ 10\epsilon,\ 20\epsilon$ (increases with the order of difference).
- Coefficients in each column: 
    - $\Delta^2 f: \epsilon(1, -2, 1)$,
    - $\Delta^3 f: \epsilon(1, -3, 3, -1)$, 
    - $\Delta^4 f: \epsilon(-4, 6, -4)$ (part of $1, -4, 6, -4, 1$).

---

#### 11. Convert the following system into matrix form. Identify $A$, $X$ & $B$. Also write the augmented matrix.
- $2x + 3y - z = 5$
- $x - 2y + 4z = 7$
- $3x + y + 2z = 10$

- $\begin{bmatrix} 2 & 3 & -1 \\ 1 & -2 & 4 \\ 3 & 1 & 2 \end{bmatrix}\begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 5 \\ 7 \\ 10 \end{bmatrix}$
- Coefficient matrix: $A = \begin{bmatrix} 2 & 3 & -1 \\ 1 & -2 & 4 \\ 3 & 1 & 2 \end{bmatrix}$
- Unknown vector: $X = \begin{bmatrix} x \\ y \\ z \end{bmatrix}$
- Constant vector: $B = \begin{bmatrix} 5 \\ 7 \\ 10 \end{bmatrix}$
- Augmented matrix: $[A \mid B] = \left[\begin{array}{ccc|c} 2 & 3 & -1 & 5 \\ 1 & -2 & 4 & 7 \\ 3 & 1 & 2 & 10 \end{array}\right]$

---

#### 12. Classify the following system: $x + y = 4$ and $2x + 2y = 8$. Is it consistent? And how many solutions?
- $A = \begin{bmatrix} 1 & 1 \\ 2 & 2 \end{bmatrix}$, 
- $B = \begin{bmatrix} 4 \\ 8 \end{bmatrix}$
- $\det A = (1)(2) - (1)(2) = 0$, so $A$ is singular.
- Augmented matrix: $\left[\begin{array}{cc|c} 1 & 1 & 4 \\ 2 & 2 & 8 \end{array}\right]$
- $R_2 \to R_2 - 2R_1$:
$\left[\begin{array}{cc|c} 1 & 1 & 4 \\ 0 & 0 & 0 \end{array}\right]$
- The second row gives $0 = 0$, so there is no contradiction.
- Equation $2x + 2y = 8$ is the same as $x + y = 4$, so both equations represent the same line.
- $\therefore$ the system is consistent and has infinitely many solutions, given by $x + y = 4$ (e.g. $(0, 4), (1, 3), (2, 2), \dots$).

---

#### 13. Determine whether $2x + y = 3$, $4x + 2y = 10$ has a unique solution, no solution or infinitely many solutions.
- $A = \begin{bmatrix} 2 & 1 \\ 4 & 2 \end{bmatrix}$, 
- $B = \begin{bmatrix} 3 \\ 10 \end{bmatrix}$
- $\det A = (2)(2) - (1)(4) = 0$, so $A$ is singular and the system does not have a unique solution.
- Augmented matrix: $\left[\begin{array}{cc|c} 2 & 1 & 3 \\ 4 & 2 & 10 \end{array}\right]$
- $R_2 \to R_2 - 2R_1$:
$\left[\begin{array}{cc|c} 2 & 1 & 3 \\ 0 & 0 & 4 \end{array}\right]$
- The second row gives $0 = 4$, which is a contradiction.
- Equation $4x + 2y = 10$ is the same as $2x + y = 5$, which is parallel to $2x + y = 3$, so the lines are parallel and distinct.
- $\therefore$ the system is inconsistent and has no solution.

---

#### 14. Calculate the determinant of $A = \begin{bmatrix} 3 & 2 \\ 1 & 4 \end{bmatrix}$ and state whether the corresponding square system can have a unique solution.
- $\det A = (3)(4) - (2)(1) = 12 - 2 = 10$
- $\det A = 10 \neq 0$, so $A$ is non-singular.
- $\therefore$ the corresponding square system $AX = B$ has a unique solution.

---

#### 15. Solve using the Gaussian Elimination Method.
- $2x + y + z = 10$
- $4x - 8y + 3z = 2$
- $-2x + 7y + 2z = 13$

- Augmented matrix: $\left[\begin{array}{ccc|c} 2 & 1 & 1 & 10 \\ 4 & -6 & 3 & -2 \\ -2 & 7 & 2 & 13 \end{array}\right]$
- Step 1: Eliminate $x$ (first pivot $a_{11} = 2$)
    - $m_{21} = \dfrac{4}{2} = 2$, 
    - $m_{31} = \dfrac{-2}{2} = -1$
    - $R_2 \to R_2 - 2R_1$ and $R_3 \to R_3 + R_1$
    - $\left[\begin{array}{ccc|c} 2 & 1 & 1 & 10 \\ 0 & -8 & 1 & -22 \\ 0 & 8 & 3 & 23 \end{array}\right]$
- Step 2: Eliminate $y$ (second pivot $a_{22} = -8$)
    - $m_{32} = \dfrac{8}{-8} = -1$
    - $R_3 \to R_3 + R_2$
    - $\left[\begin{array}{ccc|c} 2 & 1 & 1 & 10 \\ 0 & -8 & 1 & -22 \\ 0 & 0 & 4 & 1 \end{array}\right]$
- Step 3: Solve $z$
    - $4z = 1$
    - $z = 0.25$
- Step 4: Solve $y$
    - $-8y + z = -22$
    - $-8y = -22 - 0.25 = -22.25$
    - $y = 2.78125$
- Step 5: Solve $x$
    - $2x + y + z = 10$
    - $2x = 10 - 2.78125 - 0.25 = 6.96875$
    - $x = 3.484375$
- $\therefore x = 3.484375,\ y = 2.78125,\ z = 0.25$

---

#### 16. Using the Gaussian Elimination Method, find $x$, $y$, $z$ and the pivot elements.
- $2x + 3y + z = 10$
- $4x + y + 2z = 12$
- $-2x + 2y + 3z = 5$

- Augmented matrix: $\left[\begin{array}{ccc|c} 2 & 3 & 1 & 10 \\ 4 & 1 & 2 & 12 \\ -2 & 2 & 3 & 5 \end{array}\right]$
- Step 1: Eliminate $x$ (first pivot $a_{11} = 2$)
    - $m_{21} = \dfrac{4}{2} = 2$, 
    - $m_{31} = \dfrac{-2}{2} = -1$
    - $R_2 \to R_2 - 2R_1$ and $R_3 \to R_3 + R_1$
    - $\left[\begin{array}{ccc|c} 2 & 3 & 1 & 10 \\ 0 & -5 & 0 & -8 \\ 0 & 5 & 4 & 15 \end{array}\right]$
- Step 2: Eliminate $y$ (second pivot $a_{22} = -5$)
    - $m_{32} = \dfrac{5}{-5} = -1$
    - $R_3 \to R_3 + R_2$
    - $\left[\begin{array}{ccc|c} 2 & 3 & 1 & 10 \\ 0 & -5 & 0 & -8 \\ 0 & 0 & 4 & 7 \end{array}\right]$
- Step 3: Solve $z$
    - $4z = 7$
    - $z = \dfrac{7}{4} = 1.75$
- Step 4: Solve $y$
    - $-5y = -8$
    - $y = \dfrac{8}{5} = 1.6$
- Step 5: Solve $x$
    - $2x + 3y + z = 10$
    - $2x + 4.8 + 1.75 = 10$
    - $2x = 3.45$
    - $x = \dfrac{69}{40} = 1.725$
- $\therefore x = \dfrac{69}{40} = 1.725,\ y = \dfrac{8}{5} = 1.6,\ z = \dfrac{7}{4} = 1.75$
- Pivot elements: $2,\ -5,\ 4$

---

#### 17. Explain why row interchange is necessary before applying to the following matrix $\begin{bmatrix} 0 & 2 & 1 \\ 4 & 5 & 6 \\ 2 & 3 & 4 \end{bmatrix}$
- The first pivot is $a_{11} = 0$.
- The multipliers are $m_{i1} = \dfrac{a_{i1}}{a_{11}}$:
    - $m_{21} = \dfrac{4}{0}$ and $m_{31} = \dfrac{2}{0}$, which are undefined (division by zero).
- So $R_i \to R_i - m_{i1}R_1$ cannot be performed, and $x_1$ cannot be eliminated from the rows below.
- Interchange $R_1 \leftrightarrow R_2$ (Operation 1) so that the pivot is non-zero:
- $\begin{bmatrix} 4 & 5 & 6 \\ 0 & 2 & 1 \\ 2 & 3 & 4 \end{bmatrix}$
- The first pivot is now $a_{11} = 4 \neq 0$.
    - $m_{21} = \dfrac{0}{4} = 0$, 
    - $m_{31} = \dfrac{2}{4} = \dfrac{1}{2}$
    - $R_3 \to R_3 - \dfrac{1}{2}R_1$
    - $\begin{bmatrix} 4 & 5 & 6 \\ 0 & 2 & 1 \\ 0 & \frac{1}{2} & 1 \end{bmatrix}$
- $\therefore$ elimination can now proceed.

---