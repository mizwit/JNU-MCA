# CS 406: Numerical Methods

Taught by [Prof. Anuj Sachan](https://www.jnu.ac.in/content/anujsachan)

### References
- [Numerical Methods for Scientific and Engineering Computation by M. K. Jain, S. R. K. Iyengar, and R. K. Jain](https://archive.org/details/numericalmethods00jain_0)
- [Advanced Engineering Mathematics by Erwin Kreyszig](https://archive.org/details/advancedengineer0000krey_v5q8)
- [Numerical Methods for Engineers by Steven C. Chapra and Raymond P. Canale](https://archive.org/details/numericalmethods0000chap_q8b1)
- [Numerical Methods for Engineers Course by IIT Madras](https://nptel.ac.in/courses/127106019)
- [Numerical Methods Course by IIT Roorkee](https://drive.google.com/file/d/13vU8ZtrwjDmCOr-UY4g0DISWkARl3YeT/view)

<br>

> Numerical Methods is a branch of mathematics that designs, analyses and implements algorithms to obtain approximate numerical solutions to complex problems that cannot be solved exactly using analytical formulae.

---

# Finite Data Representation
Since computers have limited memory, it cannot store a number with infinite digits such as $\pi$ or $\frac{1}{3}$. This introduces the fundamental concept of **Finite Data Representation**.

### Fixed Point Numbers
- A method where a specific number of digits is permanently assigned to the integer part and a specific to the fractional part.
- The decimal part never moves.
- Examples:
    - $1234.6251 = 1234 + 0.6251$
    - $1234 = 1 \times 10^3 + 2 \times 10^2 + 3 \times 10^1 + 4 \times 10^0$
    - $0.6251 = 6 \times 10^{-1} + 2 \times 10^{-2} + 5 \times 10^{-3} + 1 \times 10^{-4}$

#### Decimal Number System
- Decimal Number System has **base 10** with digits $0, 1, 2, 3, 4, 5, 6, 7, 8, 9$.
- Any decimal number $N$ can be written as
    - $N = d_{n-1}d_{n-2}...d_{1}d_{0}.d{-1}{-2}...d_{-m}$
    - $(N)_{10} = d_{n-1} \times 10^{n-1} + ... + d_1 \times 10^{1} + d_{0} \times 10^{0} + d_{-1} \times 10^{-1} + ... + d_{-m} \times 10^{-m}$

#### Binary Number System
- Binary Number System has **base 2** with digits $0, 1$ called as **bits**.
- Any binary number $N$ can be written as
    - $N = b_{n-1}b_{n-2}...b_{1}b_{0}.b{-1}{-2}...b_{-m}$
    - $(N)_{2} = b_{n-1} \times 2^{n-1} + ... + b_1 \times 2^{1} + b_{0} \times 2^{0} + b_{-1} \times 2^{-1} + ... + b_{-m} \times 2^{-m}$
- Exercises:
    - Binary to Decimal conversion and vice versa.

#### Octal Number System
- Octal Number System has **base 8** with digits $0, 1, 2, 3, 4, 5, 6, 7$.
- Any octal number $N$ can be written as
    - $N = o_{n-1}o_{n-2}...o_{1}o_{0}.o{-1}{-2}...o_{-m}$
    - $(N)_{8} = o_{n-1} \times 8^{n-1} + ... + o_1 \times 8^{1} + o_{0} \times 8^{0} + o_{-1} \times 8^{-1} + ... + o_{-m} \times 8^{-m}$
- Exercises:
    - Octal to Decimal conversion and vice versa.
    - Octal to Binary conversion and vice versa.

#### Hexadecimal Number System
- Hexadecimal Number System has **base 16** with digits $0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F$.
- Any hexadecimal number $N$ can be written as
    - $N = h_{n-1}h_{n-2}...h_{1}h_{0}.h{-1}{-2}...h_{-m}$
    - $(N)_{16} = h_{n-1} \times 16^{n-1} + ... + h_1 \times 16^{1} + h_{0} \times 16^{0} + h_{-1} \times 16^{-1} + ... + h_{-m} \times 16^{-m}$
- Exercises:
    - Hexadecimal to Decimal conversion and vice versa.
    - Hexadecimal to Binary conversion and vice versa.
    - Hexadecimal to Octal conversion and vice versa.

### Floating Point Numbers
- A method where the decimal part can float or move to adapt to the scale of the number.
- $x = \pm m \times b^e$, where $m$ is mantissa, $b$ is base, and $e$ is exponent.
- Example: $1234.56 = 1.23456 \times 10^3$
- Exercise: Subtract two floating point numbers $0.36143447 \times 10^7$ and $0.36132346 \times 10^7$
    - $0.36143447 \times 10^7 - 0.36132346 \times 10^7 = 0.00011101 \times 10^7$
- **Normalized floating point numbers** are numbers whose fractional part has been shifted to remove any redundant zeroes and save space
    - Example: $0.00011101 \times 10^7 \rightarrow 0.11101 \times 10^4$
- Exercise: Add two floating point numbers $0.123 \times 10^3$ and $0.456 \times 10^2$
    - $0.123 \times 10^3 \rightarrow 1.23 \times 10^2$
    - $0.123 \times 10^3 + 0.456 \times 10^2 = 1.686 \times 10^2$
    - $1.686 \times 10^2 \rightarrow 0.1686 \times 10^3$
    - $0.1686 \times 10^3 \approx 0.169 \times 10^3$ (by roundoff)
    - $0.1686 \times 10^3 \approx 0.168 \times 10^3$ (by chopping)

---

# The Propagation of Error
- In numerical computation, the values used in a calculation are often approximated. 
- So, the error $e$ is $e = x - \overline{x}$, where $x$ is the **true value** and $\overline{x}$ is the **approximated value**.
- In terms of magnitude, $|e| = |x - \overline{x}|$
- The error which is machine dependent is called **machine epsilon**.

### Inherent Error
It is the quantity which is already present in the statement of the problem before its solution.

### The Round-off Error
It is the quantity $R$ which must be added to the finite representation of a computed number in order to make it the true representation of that number.

### The Truncation Error
It is the quantity $t$ that must be added to the true representation of the quantity in order for the result to be exactly equal to the quantity we are seeking to generate.

### Propagation of Error in One Variable
- Consider $y = f(x)$. If $x$ contains an error, then the calculated value of $y$ will also contain an error.
- The propagation of an error is the process by which errors present in input data or intermediate computations effect the accuracy of the final computed result.

### Absolute Error
- Let $y = f(x)$ and $x$ contain a small error $dx$.
- From Taylor Expansion, $f(x + dx) \approx f(x) + f'(x).dx$
- We know, $dy = f(x + dx) - f(x)$
- So, $dy \approx f'(x).dx$
- Therefore, $|dy| = |f'(x)|.|dx|$
- Example: Let $y = x^2$, $x = 10$, and $x = 0.1$.
    - $dy = f'(x).dx$
    - $f'(x) = 2x$
    - $dy = (2 \times 10) \times 0.1$
    - $dy = 2$

### Relative Error
- $|\frac{dy}{y}| = |\frac{x.f'(x)}{f(x)}|.|\frac{dx}{x}|$
- From the previous example:
    - $\frac{x.f'(x)}{f(x)} = \frac{x.2x}{x^2} = 2$
    - $\frac{dy}{y} = 2 \times \frac{dx}{x} = 2 \times \frac{0.1}{10}$
    - $\frac{dy}{y} = 0.02$
    - Approximately $2\%$ error in  $x^2$.

### Propagation of Error in Several Variables
- Consider, $z = f(x, y)$
- $dz = \frac{\partial f}{\partial x}.dx + \frac{\partial f}{\partial y}.dy$
- The maximum possible absolute error can be computed as:
    - $|dz| \approx |\frac{\partial f}{\partial x}|.|dx| + |\frac{\partial f}{\partial y}|.|dy|$
- Generalization, $z = f(x_1, x_2, ... , x_n)$
    - $|dz| \approx \sum_{i=1}^{n} |\frac{\partial f}{\partial x_i}|.|dx_i|$

| Addition | Subtraction | Multiplication | Division |
| :--- | :--- | :--- | :--- |
| $z = x + y$ | $z = x - y$ | $z = x.y$ | $z = \frac{x}{y}$ |
| $dz = dx + dy$ | $dz = dx - dy$ |  $\frac{dz}{z} = \frac{dx}{x} + \frac{dy}{y}$ | $\frac{dz}{z} = \frac{dx}{x} - \frac{dy}{y}$ |
| Max absolute error: | Max absolute error: | Relative error: | Relative error: |
| $\vert dz \vert \le \vert dx \vert + \vert dy \vert$ | $\vert dz \vert \le \vert dx \vert + \vert dy \vert$ |  $\vert \frac{dz}{z} \vert \le \vert \frac{dx}{x} \vert + \vert \frac{dy}{y} \vert$ | $\vert \frac{dz}{z} \vert \le \vert \frac{dx}{x} \vert + \vert \frac{dy}{y} \vert$ |

### Error Propagation Exercises

#### Exercise 1
$x = \sqrt{10} = 3.16227766$ and by chopping/rounding off, we get $\overline{x} = 3.1623$. Find the absolute error, relative error and percentage error.
- Absolute error $= |x - \overline{x}| = 3.16227766 - 3.1623 = 0.00002234$.
- Relative error $= \frac{2.234 \times 10^{-5}}{3.16227766} = 7.06 \times 10^{-6}$
- Percentage error $= 7.06 \times 10^{-4}\%$.

#### Exercise - HW

1. $y = x^3$, where $x = 2$, with error as $0.01$. Find approximate and relative error.
2. $z = x + y$, where $x = 10 \pm 0.1$ and $y = 20 \pm 0.2$. Find maximum error in $z$.
3. $A = L.W$, where $L = 20 + 0.1$ cm and $W = 10 + 0.05$ cm. Find in A, the maximum error and relative error.

### Accuracy
It refers to how close an approximate value is to the true or exact value.

### Precision
It refers to the degree of consistency or fineness of the numerical representation or measurements.

> If measurements are close to one another, they are precise, but they are not necessarily accurate.

---

# Solutions of Non-linear Equations (Root Finding Methods)
- Non-linear equations are equations that can be generally written as $f(x) = 0$, where $f(x)$ is non-linear in $x$.
- Examples:
    - $x^2 - x = 0$
    - $x^3 - x- 1 = 0$
    - $e^x - x - 2 = 0$
    - $\sin(x - \frac{x}{2}) = 0$
- **Root:** A number $r$ is called a root or zero of $f(x)$ if $f(r) = 0$.
    - Example: $x^2 - 4 = 0$
    - For $x = 2$, $f(2) = 0$
    - For $x = -2$, $f(-2) = 0$
    - So, roots are $\pm 2$

### Geometrical Interpretation
- Let $y = f(x)$ and $f(x) = 0$. So, $y = 0$. Therefore, a root is the point where $y = f(x)$ intersects the x-axis.
- Consider $y = f(x) = x^3 - x - 1 = 0$
    - f(1) = 1 - 1 - 1 = -1
    - f(2) = 8 - 2 - 1 = 5
    - Function changes from negative to positive between $1$ and $2$.
    - So, we know a root exists somewhere in $1 \lt x \lt 2$
- **Root finding problem:** Given $f(x)$, find $x = r$ such that $f(r) = 0$.

### Types of Root Finding Methods

1. **Bracketing Method:** In this method, first we identify the interval $[a, b]$ such that a root is known to lie inside it.
    - Example: Bisection Method

2. **Open Methods:** These methods do not necessarily maintain interval containing the root.
    - Example: Newton-Raphson Method, Secant Method, Fixed Point Iteration.
    - They converge much faster but they may also fail if the initial approximation is not suitable.

### Initial Approximations
- Initial approximations to the root are often known from the physical consideration of the problem. Otherwise, graphical methods are generally used to obtain initial approximations to the root.
- Another commonly used method to obtain the initial approximation to the root is based on intermediate value theorem.
- **The Intermediate Value Theorem** states that if $f(x)$ is a continuous function on some interval $[a, b]$ and $f(a).f(b) \lt 0$, then the equation $f(x) = 0$ has at least one real root or an odd number of real roots in the interval $[a, b]$.
- Example 1: 
    - The equation $8x^3 - 12x^2 -2x + 3 = 0$ has three real roots. Find the intervals each of unit length containing each one of those roots.

| **x** | -2 | -1 | 0 | 1 | 2 | 3 |
| :-- | :-- | :-- | :-- | :-- | :-- | :-- |
| **f(x)** | -105 | 15 | 3 | -3 | 13 | 105 |

-   - From the above, we find that equation $f(x) = 0$ has roots in the intervals $(-1, 0)$, $(0, 1)$, and $(1, 2)$.
    - The exact roots are $-0.5$, $0.5$, and $1.5$.
- Example 2: 
    - Obtain intervals which contain the root of the equation $f(x) = \cos(x) - x.e^x$

| **x** | 0 | 0.5 | 1 | 1.5 | 2 |
| :-- | :-- | :-- | :-- | :-- | :-- |
| **f(x)** | 1 | 0.0532 | -2.1700 | -6.6518 | -13.1982 |

-   - The above equation has roots in the interval $(0.5, 1)$.
    - The exact root is $0.5177573637...$

---

## Bisection Method
This method is used on the repeated applications of the intermediate value theorem.

### Pseudocode
- Given $f(x)$, $a$, $b$:
- Check $f(a).f(b) \lt 0$
- Repeat $c = \frac{a + b}{2}$
- If $f(c) = 0$:
    - Return $c$
- If $f(a).f(c) \lt 0$:
    - $b = c$
- Else:
    - $a = c$
- Until stopping criteria is satisfied,
- Return $c$

### Exercises on Bisection Method

#### Exercise 1
Perform four iterations of the bisection method to find the approximate root of the equation $f(x) = x^3 - x - 1 = 0$.
- Initial intervals $a = 1$ and $b = 2$
- $f(1) = -1$, $f(2) = 5$
- $f(1).f(2) \lt 0$. 
- So, root lies in the interval $(1, 2)$.
- **Iteration 1:**
    - Midpoint, $c = \frac{1 + 2}{2} = 1.5$
    - $f(c) = f(1.5) = (1.5)^3 - (1.5) - 1 = 0.875$
    - $f(1).f(1.5) \lt 0$
    - So, root lies in the interval $(1, 1.5)$.
- **Iteration 2:**
    - Midpoint, $c = \frac{1 + 1.5}{2} = 1.25$
    - $f(c) = f(1.25) = (1.25)^3 - (1.25) - 1 = -0.296875$
    - $f(1.25).f(1.5) \lt 0$
    - So, root lies in the interval $(1.25, 1.5)$.
- **Iteration 3:**
    - Midpoint, $c = \frac{1.25 + 1.5}{2} = 1.375$
    - $f(c) = f(1.375) = (1.375)^3 - (1.375) - 1 = 0.22461$
    - $f(1.25).f(1.375) \lt 0$
    - So, root lies in the interval $(1.25, 1.375)$.
- **Iteration 4:**
    - Midpoint, $c = \frac{1.25 + 1.375}{2} = 1.3125$
    - $f(c) = f(1.3125) = (1.3125)^3 - (1.3125) - 1 = -0.0515$
    - $f(1.3125).f(1.375) \lt 0$
    - So, root lies in the interval $(1.3125, 1.375)$.
- Approximate value of the root, $r \approx \frac{1.3125 + 1.375}{2} = 1.34375$

#### Exercise 2
Perform five iterations of the bisection method to obtain the smallest possible positive root of the equation $f(x) = x^3 - 5x + 1 = 0$.
- Initial intervals $a = 0$ and $b = 1$
- $f(0) = (0)^3 - 5(0) + 1 = 1$
- $f(1) = (1)^3 - 5(1) + 1 = -3$
- $f(0).f(1) < 0$.
- So, root lies in the interval $(0, 1)$.
- **Iteration 1:**
    - Midpoint, $c = \frac{0 + 1}{2} = 0.5$
    - $f(c) = f(0.5) = (0.5)^3 - 5(0.5) + 1 = -1.375$
    - $f(0).f(0.5) < 0$
    - So, root lies in the interval $(0, 0.5)$.
- **Iteration 2:**
    - Midpoint, $c = \frac{0 + 0.5}{2} = 0.25$
    - $f(c) = f(0.25) = (0.25)^3 - 5(0.25) + 1 = -0.234375$
    - $f(0).f(0.25) < 0$
    - So, root lies in the interval $(0, 0.25)$.
- **Iteration 3:**
    - Midpoint, $c = \frac{0 + 0.25}{2} = 0.125$
    - $f(c) = f(0.125) = (0.125)^3 - 5(0.125) + 1 = 0.376953$
    - $f(0.125).f(0.25) < 0$
    - So, root lies in the interval $(0.125, 0.25)$.
- **Iteration 4:**
    - Midpoint, $c = \frac{0.125 + 0.25}{2} = 0.1875$
    - $f(c) = f(0.1875) = (0.1875)^3 - 5(0.1875) + 1 = 0.069092$
    - $f(0.1875).f(0.25) < 0$
    - So, root lies in the interval $(0.1875, 0.25)$.
- **Iteration 5:**
    - Midpoint, $c = \frac{0.1875 + 0.25}{2} = 0.21875$
    - $f(c) = f(0.21875) = (0.21875)^3 - 5(0.21875) + 1 = -0.083282$
    - $f(0.1875).f(0.21875) < 0$
    - So, root lies in the interval $(0.1875, 0.21875)$.
- Approximate value of the root, $r \approx \frac{0.1875 + 0.21875}{2} = 0.203125$

#### Exercise - H.W
1. Perform five iterations of the bisection method to find the approximate root of the equation $f(x) = \cos(x) - x.e^x = 0$.

### Error Bound for Bisection Method
- How accurate is the Bisection Method?
- For the initial interval $(a, b)$, the interval length is $b - a$. 
- After one iteration, the interval length becomes $\frac{b - a}{2}$.
- After two iterations, it is $\frac{b - a}{2^2}$.
- After $n$ iterations, it is $\frac{b - a}{2^n}$.
- This gives us the direct error bound.
- Since the root lies inside any $(\pm , \pm)$ interval, the maximum distance between the midpoint and the root is half the interval length.
- Therefore, after $n$ iterations, $|x_n - r| \le \frac{b - a}{2^{n+1}}$, where $x_n$ is the approximate root and $r$ is the actual root.

#### Finding the Error Bound
- Let $a = 1$ and $b = 2$. Find the error bound after five iterations.
- $|x_n - r| \le \frac{b - a}{2^{n+1}}$
- $|x_n - r| \le \frac{2 - 1}{2^{6}}$
- $|x_n - r| \le \frac{1}{64}$
- $|x_n - r| \le 0.015625$

#### Number of Iterations Required
- Let us assume that we want an error bound, $|x_n - r| \le \epsilon$.
- So, we require $\frac{b - a}{2^{n+1}} \le \epsilon$.
- $2^{n+1} \ge \frac{b - a}{\epsilon}$
- $n + 1 \ge \frac{\log(\frac{b - a}{\epsilon})}{\log(2)}$
- So, $n \ge \frac{\log(\frac{b - a}{\epsilon})}{\log(2)} - 1$.

### Priori Error in Bisection Method
- **Priori Error** is an error estimate defined before or independently of the actual approximation.
- For bisection method, $|x_n - r| \le \frac{b - a}{2^{n+1}}$

### Posteriori Error in Bisection Method
- **Posteriori Error** is an estimate based on the current numerical results.
- For bisection method, if the current interval is $(a_n, b_n)$, then $|x_n - r| \le \frac{b_n - a_n}{2}$.
- This tells us how accurate our current approximation is.

### Convergence of Bisection Method
- Bisection is a convergent method under standard assumptions that:
    1. $f(x)$ is a continuous function between the interval $(a, b)$.
    2. $f(a).f(b) \lt 0$.
- Therefore, $\lim_{n \to \infty} (b_n - a_n) = 0$
- Bisection method has guaranteed convergence under the continuity and sign change conditions.

---

## Secant Method
- If $f(x)$ is a first degree equation in $x$, then it can be readily solved. The iteration method which will produce the exact results whenever function of $f(x) = 0$ is a first degree equation is given by:
    - $f(x) = a_0x + a_1 = 0$
    - $x = -\frac{a_1}{a_0}$
- If $x_{k - 1}$ and $x_k$ are two approximations to the root, then we determine $a_0$ and $a_1$ by using the following equations:
    - $f_{k - 1} = a_0x_{k - 1} + a_1$
    - $f_{k} = a_0x_{k} + a_1$
    - Where, $f_{k - 1} = f(x_{k - 1})$ and $f_k = f(x_k)$.
    - $\therefore a_0 = \frac{f_k - f_{k - 1}}{x_k - x_{k - 1}}$ and $a_1 = \frac{x_k.f_{k - 1} - x_{k - 1}.f_k}{x_k - x_{k - 1}}$
- The two approximations are:
    - $x_{k - 1} \to f(x_{k - 1})$
    - $x_{k} \to f(x_{k})$
- Now, instead of taking the midpoint, draw a straight line using the following two points $(x_{k - 1}, f(x_{k - 1}))$ and $(x_k, f(x_k))$.
- The point where this line intersects the x-axis is taken as the next approximation.

### Derivation of the Secant Formula:
- The slope between the two points $(x_{k - 1}, f(x_{k - 1}))$ and $(x_k, f(x_k))$ is given by $m = \frac{f(x_k) - f(x_{k - 1})}{x_k - x_{k - 1}}$.
- The equation of the line through $(x_k, f(x_k))$ is given by $y - f(x_k) = m(x - x_k)$.
- $y - f(x_k) = \frac{f(x_k) - f(x_{k - 1})}{x_k - x_{k - 1}}(x - x_k)$
- At the root of the secant line, $y = 0$.
- $\therefore - f(x_k) = \frac{f(x_k) - f(x_{k - 1})}{x_k - x_{k - 1}}(x - x_k)$
- $x - x_k = \frac{-f(x_k)(x_k - x_{k - 1})}{f(x_k) - f(x_{k - 1})}$
- $x_{k + 1} = x_k - \frac{(x_k - x_{k - 1})}{f(x_k) - f(x_{k - 1})}.f(x_k)$

### Advantages of the Secant Method
- Does not require derivative $f'(x)$.
- Usually much faster than bisection method.
- Uses function values more intelligently than bisection method.
- Easy to implement.

### Limitations of the Secant Method
- Convergence is not guaranteed for arbitrary initial guesses.
- The approximation can move away from the root.
- It may encounter division by a very small quantity if $f(x_k) - f(x_{k - 1})$ is approximately zero.

> If the approximations are such that $f_k.f_{k-1} \lt 0$, then the other method is known as **Regula Falsi Method**.

### Exercises on Secant and Regula Falsi Methods
The real root of the equation $f(x) = x^3 - 5x + 1 = 0$ lies in the interval $(0, 1)$. Perform four iterations of the Secant Method and the Regula Falsi Method to obtain the root.

#### Using Secant Method
- Let $x_0 = 0$ and $x_1 = 1$.
- $f(x_0) = f(0) = 1$
- $f(x_1) = f(1) = -3$
- **Iteration 1:** 
    - $x_2 = x_1 - \frac{(x_1 - x_0)}{f(x_1) - f(x_0)}.f(x_1)$
    - $x_2 = 1 - \frac{(1 - 0)}{-3 - 1}(-3)$
    - $x_2 = x_1 - \frac{(x_1 - x_0)}{f(x_1) - f(x_0)}.f(x_1)$
    - $x_2 = 1 - \frac{(1 - 0)}{-3 - 1}(-3)$
    - $x_2 = 1 - 0.75 = 0.25$
    - $f(x_2) = f(0.25) = (0.25)^3 - 5(0.25) + 1 = -0.234375$
- **Iteration 2:**
    - $x_3 = x_2 - \frac{(x_2 - x_1)}{f(x_2) - f(x_1)}.f(x_2)$
    - $x_3 = 0.25 - \frac{(0.25 - 1)}{-0.234375 - (-3)}(-0.234375)$
    - $x_3 = 0.25 - 0.063560 = 0.186440$
    - $f(x_3) = f(0.186440) = (0.186440)^3 - 5(0.186440) + 1 = 0.074281$
- **Iteration 3:**
    - $x_4 = x_3 - \frac{(x_3 - x_2)}{f(x_3) - f(x_2)}.f(x_3)$
    - $x_4 = 0.186440 - \frac{(0.186440 - 0.25)}{0.074281 - (-0.234375)}(0.074281)$
    - $x_4 = 0.186440 + 0.015296 = 0.201736$
    - $f(x_4) = f(0.201736) = (0.201736)^3 - 5(0.201736) + 1 = -0.000470$
- **Iteration 4:**
    - $x_5 = x_4 - \frac{(x_4 - x_3)}{f(x_4) - f(x_3)}.f(x_4)$
    - $x_5 = 0.201736 - \frac{(0.201736 - 0.186440)}{-0.000470 - 0.074281}(-0.000470)$
    - $x_5 = 0.201736 - 0.000096 = 0.201640$
- Approximate value of the root, $r \approx 0.201640$

#### Using Regula Falsi Method
- Let $x_0 = 0$ and $x_1 = 1$.
- $f(x_0) = 1$, $f(x_1) = -3$
- $f(x_0).f(x_1) < 0$.
- So, root lies in the interval $(0, 1)$.
- **Iteration 1:**
    - $x_2 = x_1 - \frac{(x_1 - x_0)}{f(x_1) - f(x_0)}.f(x_1)$
    - $x_2 = 1 - \frac{(1 - 0)}{-3 - 1}(-3) = 0.25$
    - $f(x_2) = f(0.25) = -0.234375$
    - $f(x_0).f(x_2) < 0$
    - So, root lies in the interval $(0, 0.25)$.
- **Iteration 2:**
    - $x_3 = x_2 - \frac{(x_2 - x_0)}{f(x_2) - f(x_0)}.f(x_2)$
    - $x_3 = 0.25 - \frac{(0.25 - 0)}{-0.234375 - 1}(-0.234375)$
    - $x_3 = 0.25 - 0.047468 = 0.202532$
    - $f(x_3) = f(0.202532) = -0.004352$
    - $f(x_0).f(x_3) < 0$
    - So, root lies in the interval $(0, 0.202532)$.
- **Iteration 3:**
    - $x_4 = x_3 - \frac{(x_3 - x_0)}{f(x_3) - f(x_0)}.f(x_3)$
    - $x_4 = 0.202532 - \frac{(0.202532 - 0)}{-0.004352 - 1}(-0.004352)$
    - $x_4 = 0.202532 - 0.000877 = 0.201655$
    - $f(x_4) = f(0.201655) = -0.000074$
    - $f(x_0).f(x_4) < 0$
    - So, root lies in the interval $(0, 0.201655)$.
- **Iteration 4:**
    - $x_5 = x_4 - \frac{(x_4 - x_0)}{f(x_4) - f(x_0)}.f(x_4)$
    - $x_5 = 0.201655 - \frac{(0.201655 - 0)}{-0.000074 - 1}(-0.000074)$
    - $x_5 = 0.201655 - 0.000015 = 0.201640$.
- Approximate value of the root, $r \approx 0.201640$

---

## Newton-Raphson Method
Instead of using a second line secant through the two points, Newton-Raphson uses the tangent line at the current point to estimate where the function crosses the x-axis.
- Let us consider a current approximation $x_k$.
- Instead of considering the entire curve, i.e., $y = f(x)$, we draw its tangent line.
- The point on the curve is $(x_k, f(x_k))$.
- The slope of the tangent at this point is given by, $f'(x_k)$.
- So, the equation of the tangent line is given by, $y - f(x_k) = f'(x_k).(x - x_k)$.
- At the root of the tangent line, $y = 0$.
- $\therefore -f(x_k) = f'(x_k).(x - x_k)$
- $x_{k + 1} = x_k - \frac{f(x_k)}{f'(x_k)}$, where $x_k$ is the initial approximation and $x_{k + 1}$ is the new approximation.

### Convergence of Newton-Raphson Method
- Newton-Raphson is a fast method, but it is not globally guaranteed to converge for initial guesses.
- Its excellent convergence behaviour is mainly a local property near a suitable root.
- A poor initial sum can cause the method to diverge, oscillate, move towards another root, or maybe encounter a point where the derivative of $f$, $f'(x) = 0$ make very large jumps.

### Advantages of Newton-Raphson Method
- Very fast near the root.
- Usually requires fewer iterations.
- Simple iteration formula.
- Does not require bracketing intervals like bisection or Regula falsi methods.
- Useful for many non-linear problems.

### Limitations of Newton-Raphson Method
- Derivative is required.
- Poor initial guess can cause failure.
- Derivative can become zero or very small.
- Multiple roots can reduce the usual conversions rates.

### Exercises on Newton-Raphson Method

#### Exercise 1
Let $f(x) = x^3 - x - 1 = 0$. Assume an initial approximation of $x_0 = 1.5$. Perform four iterations using Newton-Raphson Method.
- $f'(x) = 3x^2 - 1$
- Initial approximation, $x_0 = 1.5$
- **Iteration 1:**
    - $f(x_0) = f(1.5) = (1.5)^3 - 1.5 - 1 = 0.875$
    - $f'(x_0) = f'(1.5) = 3(1.5)^2 - 1 = 5.75$
    - $x_1 = x_0 - \frac{f(x_0)}{f'(x_0)} = 1.5 - \frac{0.875}{5.75}$
    - $x_1 = 1.347826$
- **Iteration 2:**
    - $f(x_1) = f(1.347826) = (1.347826)^3 - 1.347826 - 1 = 0.100361$
    - $f'(x_1) = f'(1.347826) = 3(1.347826)^2 - 1 = 4.449896$
    - $x_2 = x_1 - \frac{f(x_1)}{f'(x_1)} = 1.347826 - \frac{0.100361}{4.449896}$
    - $x_2 = 1.325271$
- **Iteration 3:**
    - $f(x_2) = f(1.325271) = (1.325271)^3 - 1.325271 - 1 = 0.002536$
    - $f'(x_2) = f'(1.325271) = 3(1.325271)^2 - 1 = 4.269023$
    - $x_3 = x_2 - \frac{f(x_2)}{f'(x_2)} = 1.325271 - \frac{0.002536}{4.269023}$
    - $x_3 = 1.324677$
- **Iteration 4:**
    - $f(x_3) = f(1.324677) = (1.324677)^3 - 1.324677 - 1 = -0.000178$
    - $f'(x_3) = f'(1.324677) = 3(1.324677)^2 - 1 = 4.264301$
    - $x_4 = x_3 - \frac{f(x_3)}{f'(x_3)} = 1.324677 - \frac{-0.000178}{4.264301}$
    - $x_4 = 1.324719$
- Approximate value of the root, $r \approx 1.324719$

#### Exercise - H.W
1. Let $f(x) = x^3 - 5x + 1 = 0$. Assume an initial approximation of $x_0 = 0.5$. Perform four iterations using Newton-Raphson Method.
2. Approximate the value of $(17)^{\frac{1}{3}}$. Assume an initial approximation of $x_0 = 2$. Perform four iterations using Newton-Raphson Method.

#### Exercise - Matrix Iteration
Obtain the complex roots of the equation $f(z) = z^3 + 1 = 0$ correct to eight decimal places. Use the initial approximation of the root as $(x_0, y_0) = (0.25, 0.25)$. Compare the exact values of the roots which is $(1 \pm \frac{i\sqrt{3}}{2})$.
- Substituting $z = x + iy$ in the eqaution:
    - $(x + iy)^3 + 1 = (x^3 - 3xy^2 + 1) + i(3x^2y - y^3) = 0$
    - Here, $U(x, y) = x^3 - 3xy^2 + 1$ and $V(x,y) = 3x^2y - y^3$
- Formulating the Jacobian Matrix:
    - $J = \begin{bmatrix} U_x && U_y \\ V_x && V_y \end{bmatrix} = \begin{bmatrix} \frac{\partial U}{\partial x} && \frac{\partial U}{\partial y} \\ \frac{\partial V}{\partial x} && \frac{\partial V}{\partial y} \end{bmatrix}$
    - Here, $\frac{\partial U}{\partial x} = 3x^2 - 3y^2$, $\frac{\partial U}{\partial y} = -6xy$, $\frac{\partial V}{\partial x} = 6xy$, and $\frac{\partial V}{\partial y} = 3x^2 - 3y^2$.
    - $\therefore J = \begin{bmatrix} 3x^2 - 3y^2 && -6xy \\ 6xy && 3x^2 - 3y^2 \end{bmatrix}$
- Determinant of $J$: 
    - $D_J = (3x^2 - 3y^2)(3x^2 - 3y^2) + 36x^2y^2$
    - $D_J = 9(x^2 - y^2)^2 + 36x^2y^2$
    - $D_J = 9(x^2 + y^2)^2$
- Inverse of $J$:
    - $J^{-1} = \frac{1}{D_J}Adj$
    - $J^{-1} = \frac{1}{9(x^2 + y^2)^2}\begin{bmatrix} 3x^2 - 3y^2 && 6xy \\ -6xy && 3x^2 - 3y^2 \end{bmatrix}$
- Newton-Raphson Matrix Iteration Formula:
    - $\begin{bmatrix} x_{k + 1} \\ y_{k + 1} \end{bmatrix} = \begin{bmatrix} x_{k} \\ y_{k} \end{bmatrix} - J^{-1}\begin{bmatrix} U(x_k, y_k) \\ V(x_k, y_k) \end{bmatrix}$
    - $\begin{bmatrix} x_{k + 1} \\ y_{k + 1} \end{bmatrix} = \begin{bmatrix} x_{k} \\ y_{k} \end{bmatrix} - \frac{1}{9(x_k^2 + y_k^2)^2}\begin{bmatrix} 3x_k^2 - 3y_k^2 && 6x_ky_k \\ -6x_ky_k && 3x_k^2 - 3y_k^2 \end{bmatrix} \begin{bmatrix} x_k^3 - 3x_ky_k^2 + 1 \\ 3x_k^2y_k - y_k^3 \end{bmatrix}$
- **Iteration 1:**
    - $D_0 = 9(0.25^2 + 0.25^2)^2 = 9(0.125)^2 = 0.140625$
    - $\begin{bmatrix} x_{1} \\ y_{1} \end{bmatrix} = \begin{bmatrix} 0.25 \\ 0.25 \end{bmatrix} - \frac{1}{0.140625} \begin{bmatrix} 0 && 0.375 \\ -0.375 && 0 \end{bmatrix} \begin{bmatrix} 0.96875 \\ 0.03125 \end{bmatrix}$
    - $\begin{bmatrix} x_{1} \\ y_{1} \end{bmatrix} = \begin{bmatrix} 0.16666667 \\ 2.83333333 \end{bmatrix}$
- **Iteration 2**:
    - $D_1 = 9(x_1^2 + y_1^2)^2 = 9(0.16666667^2 + 2.83333333^2)^2 = 584.02777778$
    - $U(x_1,y_1) = -3.00925926$, $\quad V(x_1,y_1) = -22.50925926$
    - $\begin{bmatrix} x_{2} \\ y_{2} \end{bmatrix} = \begin{bmatrix} 0.16666667 \\ 2.83333333 \end{bmatrix} - \dfrac{1}{584.02777778} \begin{bmatrix} -24 && 2.83333333 \\ -2.83333333 && -24 \end{bmatrix} \begin{bmatrix} -3.00925926 \\ -22.50925926 \end{bmatrix}$
    - $\begin{bmatrix} x_{2} \\ y_{2} \end{bmatrix} = \begin{bmatrix} 0.15220505 \\ 1.89374026 \end{bmatrix}$
- **Iteration 3**:
    - $D_2 = 9(x_2^2 + y_2^2)^2 = 9(0.15220505^2 + 1.89374026^2)^2 = 117.25111943$
    - $U(x_2,y_2) = -0.63401099$, $\quad V(x_2,y_2) = -6.65981678$
    - $\begin{bmatrix} x_{3} \\ y_{3} \end{bmatrix} = \begin{bmatrix} 0.15220505 \\ 1.89374026 \end{bmatrix} - \dfrac{1}{117.25111943} \begin{bmatrix} -10.68925735 && 1.72942095 \\ -1.72942095 && -10.68925735 \end{bmatrix} \begin{bmatrix} -0.63401099 \\ -6.65981678 \end{bmatrix}$
    - $\begin{bmatrix} x_{3} \\ y_{3} \end{bmatrix} = \begin{bmatrix} 0.19263553 \\ 1.27724322 \end{bmatrix}$
- **Iteration 4**:
    - $D_3 = 9(x_3^2 + y_3^2)^2 = 9(0.19263553^2 + 1.27724322^2)^2 = 25.05378984$
    - $U(x_3,y_3) = 0.06438032$, $\quad V(x_3,y_3) = -1.94144150$
    - $\begin{bmatrix} x_{4} \\ y_{4} \end{bmatrix} = \begin{bmatrix} 0.19263553 \\ 1.27724322 \end{bmatrix} - \dfrac{1}{25.05378984} \begin{bmatrix} -4.78272540 && 1.47625459 \\ -1.47625459 && -4.78272540 \end{bmatrix} \begin{bmatrix} 0.06438032 \\ -1.94144150 \end{bmatrix}$
    - $\begin{bmatrix} x_{4} \\ y_{4} \end{bmatrix} = \begin{bmatrix} 0.31932197 \\ 0.91041889 \end{bmatrix}$

---

## Summary of Root-Finding Methods

| **Feature** | **Bisection** | **Secant** | **Regula Falsi** | **Newton-Raphson** |
| :--- | :--- | :--- | :--- | :--- |
| **Type** | Bracketing | Open | Bracketing | Open |
| **Basic idea** | Midpoint | Secant line | Secant + Bracket | Tangent line |
| **Initial values** | $(a, b)$ | $(x_0, x_1)$ | $(a, b)$ | $(x_0)$ |
| **Sign Change required** | Yes | No | Yes | No |
| **Derivative required** | No | No | No | **Yes** |
| **Maintains bracket** | Yes | No | Yes | No |
| **Convergence guarantee** | Under standard conditions | No | Under standard conditions | No, globally |
| **Speed near root** | Slow | Fast | Moderate/ variable | **Very fast** |
| **Approx order** | $(1)$ | $(1.618)$ | Variable/ typically linear | $(2)$ locally |

### Final Summary of Root-Finding Methods

| **Method** | **Bracket?** | **Derivative?** | **Convergence** | **Main Strength** |
| :--- | :--- | :--- | :--- | :--- |
| **Bisection** | Yes | No | Linear | Reliability |
| **Regula Falsi** | Yes | No | Generally linear | Reliability + Interpolation |
| **Secant** | No | No | Superlinear, $(p \approx 1.618)$ | Speed without derivative |
| **Newton-Raphson** | No | Yes | Quadratic, $(p = 2)$ locally | Very fast convergence |

---

## Muller's Method
Instead of fitting a straight line, it fits a quadratic, polynomial through three points.

- Lets consider a function $f(x) = a_0x^2 + a_1x + a_2 = 0$, which is a polynomial of degree two.
- $a_0$, $a_1$, and $a_2$ are three arbitrary parameters to be determined by prescribing three approximate conditions $f(x)$ and/or its derivates.
- If $x_{k - 2}$, $x_{k - 1}$, and $x_k$ are three approximations to the root of $f(x) = 0$, then we may determine $a_0$, $a_1$, and $a_2$ by using the condition as:
    - $f_{k-2} = a_0x_{k-2}^{2} + a_1x_{k-2} + a_2$
    - $f_{k-1} = a_0x_{k-1}^{2} + a_1x_{k-1} + a_2$
    - $f_{k} = a_0x_{k}^{2} + a_1x_{k} + a_2$

- Determining $a_0$, $a_1$, and $a_2$ from the equation,
$$\begin{vmatrix} f(x) & x^2 & x & 1 \\ f_{k-2} & x^2_{k-2} & x_{k-2} & 1 \\ f_{k-1} & x^2_{k-1} & x_{k-1} & 1 \\ f_{k} & x^2_{k} & x_{k} & 1 \end{vmatrix}$$

- $f(x) = \frac{(x - x_{k-1})(x - x_k)}{(x_{k-2} - x_{k-1})(x_{k-2} - x_k)}.f_{k-2} + \frac{(x - x_{k-2})(x - x_k)}{(x_{k-1} - x_{k-2})(x_{k-1} - x_k)}.f_{k-1} + \frac{(x - x_{k-2})(x - x_{k-1})}{(x_{k} - x_{k-2})(x_{k} - x_{k-1})}.f_{k} = 0$

- When, $h = x - x_k$, $h_k = x_k - x_{k-1}$, and $h_{k-1} = x_{k-1} - x_{k-2}$,
- $\frac{h(h + h_k)}{h_{k-1}(h_{k-1} + h_k)}.f_{k-2} - \frac{h(h + h_k + h_{k-1})}{h_k.h_{k-1}}.f_{k-1} + \frac{(h + h_k)(h + h_k + h_{k-1})}{h_k(h_k + h_{k-1})}.f_k = 0$

- $\lambda = \frac{h}{h_k}$, $\lambda_{k} = \frac{h_k}{h_{k-1}}$, and $\partial_{k} = 1 + \lambda_{k}$
- $C_k\lambda^{2} + g_k\lambda + \partial_{k} f_k = 0$,
- Where, $g_k = \lambda^2_{k}f_{k-2} - \partial^2_{k}f_{k-1} + (\lambda_{k} + \partial_{k})f_k$
- And, $C_k = \lambda_{k}(\lambda_{k}f_{k-2} - \partial_k f_{k-1} + f_k)$

- $\lambda = \frac{-g_k \pm \sqrt{g_k^2 - 4\partial_k f_k C_k}}{2C_k}$
- Or, $\lambda = \frac{-2\partial_k f_k}{g_k \pm \sqrt{g^2_{k} - 4\partial_k f_k C_k}}$
- Choosing the sign in the denominator to maximize magnitude.
    - If $g_2 < 0 \implies \text{minus sign}$
    - If $g_2 > 0 \implies \text{plus sign}$

- $\lambda_{k+1} = \frac{h}{h_k} = \frac{x - x_k}{x_k - x_{k-1}}$
- $x_{k+1} = x_k + (x_k - x_{k-1})\lambda_{k+1}$
- Or, $x_{k+1} = x_k + h_k\lambda_{k+1}$

#### Exercise 1
Perform three iterations of the Muller's Method to find the smallest positive root of the equation $f(x) = x^3 - 5x + 1 = 0$
- The smallest root lies in the interval $(0, 1)$.
- Let $x_0 = 0$, $x_1 = 0.5$, and $x_2 = 1$.
- So, $f_0​ = 1$, $f_1​ = −1.375$, and $f_2 ​= −3$.
- **Iteration 1:**
    - $h_1 = x_1 - x_0 = 0.5$, $h_2 = x_2 - x_1 = 0.5$
    - $\lambda_2 = \frac{h_2}{h_1} = \frac{0.5}{0.5} = 1$
    - $\partial_2 = 1 + \lambda_2 = 1 + 1 = 2$
    - $g_2 = 1^2(1) - 2^2(-1.375) + (1 + 2)(-3) = -2.5$
    - $C_2 = 1(1(1) - 2(-1.375) + (-3)) = 0.75$
    - Since, $g_2 < 0$:
    - $\lambda_3 = \frac{-2(2)(-3)}{-2.5 - \sqrt{(-2.5)^2 - 4(2)(-3)(0.75)}}$
    - $\lambda_3 = \frac{12}{-2.5 - \sqrt{24.25}} \approx -1.616286$
    - $x_3 = x_2 + h_2\lambda_3 = 1 + 0.5(-1.616286) = 0.191857$
    - $f_3 = f(x_3) = (0.191857)^3 - 5(0.191857) + 1 \approx 0.047777$
- **Iteration 2:**
    - $h_2 = 0.5$, $h_3 = x_3 - x_2 = -0.808143$
    - $\lambda_3 = \frac{h_3}{h_2} = \frac{-0.808143}{0.5} = -1.616286$
    - $\partial_3 = 1 + \lambda_3 = 1 - 1.616286 = -0.616286$
    - $g_3 = (-1.616286)^2(-1.375) - (-0.616286)^2(-3) + (-1.616286 - 0.616286)(0.047777) \approx -2.559261$
    - $C_3 = -1.616286((-1.616286)(-1.375) - (-0.616286)(-3) + 0.047777) \approx -0.680961$
    - Since, $g_3 < 0$:
    - $\lambda_4 = \frac{-2(-0.616286)(0.047777)}{-2.559261 - \sqrt{(-2.559261)^2 - 4(-0.616286)(0.047777)(-0.680961)}}$
    - $\lambda_4 \approx -0.011540$
    - $x_4 = x_3 + h_3\lambda_4 = 0.191857 + (-0.808143)(-0.011540) = 0.201183$
    - $f_4 = f(x_4) = (0.201183)^3 - 5(0.201183) + 1 \approx 0.002230$
- **Iteration 3:**
    - $h_3 = -0.808143$, $h_4 = x_4 - x_3 = 0.009326$
    - $\lambda_4 = \frac{h_4}{h_3} = \frac{0.009326}{-0.808143} = -0.011540$
    - $\partial_4 = 1 + \lambda_4 = 1 - 0.011540 = 0.988460$
    - $g_4 = (-0.011540)^2(-3) - (0.988460)^2(0.047777) + (-0.011540 + 0.988460)(0.002230) \approx -0.044902$
    - $C_4 = -0.011540((-0.011540)(-3) - (0.988460)(0.047777) + 0.002230) \approx 0.000120$
    - Since, $g_4 < 0$:
    - $\lambda_5 = \frac{-2(0.988460)(0.002230)}{-0.044902 - \sqrt{(-0.044902)^2 - 4(0.988460)(0.002230)(0.000120)}}$
    - $\lambda_5 \approx 0.049093$
    - $x_5 = x_4 + h_4\lambda_5 = 0.201183 + (0.009326)(0.049093) = 0.201641$
- Approximate value of root, $r \approx 0.201641$

### Advantages of Muller's Method
- Does not require derivative.
- Uses quadratic approximations.
- Can find complex roots.
- Does not require a bracketing interval.
- Can be applied to general non-linear equations.

### Limitations of Muller's Method
- Requires three initial approximations.
- More computationally complicated.
- Numerical issues can occur.
- No general global convergence guaranteed.

---

## Fixed-Point Iteration Method

In this method, we will transform an equation into a suitable form and repeatedly substitute the previous approximation to obtain the next approximation.

### Fixed Point
- Suppose we have a function $g(x)$. 
- A number $r$ is called a fixed point of $g(x)$ if $g(r) = r$.
- Ex: $g(x) = \dfrac{x+2}{3}$
    - At a fixed point, $g(x) = x$.
    - Therefore, $\dfrac{x+2}{3} = x \Rightarrow x + 2 = 3x \Rightarrow x = 1$.
    - $g(1) = \dfrac{1+2}{3} = 1$.
    - Hence, $x = 1$ is a fixed point.

### Conversion of an Equation into Fixed Point Form
- Let us assume we have an equation $f(x) = 0$.
- First, we rearrange it into the form $x = g(x)$.
- The root of the original equation is then a fixed point of $g(x)$, provided the rearrangement preserves the relevant solutions.
- Ex: $x^3 - x - 1 = 0 \to x^3 = x + 1 \to x = (x+1)^{1/3}$
- The fixed point iteration formula is
$$x_{n+1} = g(x_n)$$

### Algorithm of Fixed Point Iteration Method
- **Step 1:** Choose an initial guess $x_0$.
- **Step 2:** Rewrite $f(x) = 0$ as $x = g(x)$.
- **Step 3:** Calculate $x_{n+1} = g(x_n)$.
- **Step 4:** Check whether $|x_{n+1} - x_n| < \epsilon$.
- **Step 5:** If satisfied, stop; otherwise repeat Step 3.

### Example
Find the root of $x^3 - x - 1 = 0$ using the fixed-point iteration method. Take $x_0 = 1$ and perform 5 iterations.
- $x^3 - x - 1 = 0 \Rightarrow x^3 = x + 1 \Rightarrow x = (x+1)^{1/3}$
- $g(x) = (x+1)^{1/3}$
- **Iteration 1:**
    - $x_0 = 1$
    - $x_1 = g(x_0) = (1+1)^{1/3} = (2)^{1/3} \approx 1.259921$
- **Iteration 2:**
    - $x_1 = 1.259921$
    - $x_2 = g(x_1) = (1.259921+1)^{1/3} = (2.259921)^{1/3} \approx 1.312294$
- **Iteration 3:**
    - $x_2 = 1.312294$
    - $x_3 = g(x_2) = (1.312294+1)^{1/3} = (2.312294)^{1/3} \approx 1.322354$
- **Iteration 4:**
    - $x_3 = 1.322354$
    - $x_4 = g(x_3) = (1.322354+1)^{1/3} = (2.322354)^{1/3} \approx 1.324269$
- **Iteration 5:**
    - $x_4 = 1.324269$
    - $x_5 = g(x_4) = (1.324269+1)^{1/3} = (2.324269)^{1/3} \approx 1.324633$
- Approximate value of the root, $r \approx 1.324633$

### Convergence of Fixed Point Iteration Method
- Convergence depends on the choice of $g(x)$ and the initial approximation.
- A common sufficient condition for convergence is $|g'(x)| \le K < 1$ throughout the interval containing the fixed point, with $g$ mapping that interval into itself.
- This condition means that the magnitude of the derivative must remain below $1$ throughout the interval.
- If $|g'(r)| < 1$, the fixed point is locally attracting, under the usual differentiability assumptions.
- If $|g'(r)| > 1$, the fixed point is locally repelling.
- If $|g'(r)| = 1$, this test is inconclusive; further analysis is needed.

### Advantages of Fixed Point Iteration
- Simple to understand and implement.
- Does not require direct evaluation of $f'(x)$.
- Each iteration is straightforward.
- Can be effective when a suitable rearrangement is available.

### Limitations of Fixed Point Iteration
- The method may diverge for an unsuitable $g(x)$.
- The choice of rearrangement can determine whether the method converges.
- Convergence may be slow.
- A small change between successive approximations does not, by itself, guarantee that the true error is small.

### Exercises - H.W.
1. Use Fixed Point Iteration to solve $x^2 + x - 2 = 0$, using $x = (2 - x)^{1/2}$ and $x_0 = 1.5$, and perform 3 iterations.
2. Explain why choosing a different rearrangement of the same equation may change convergence.

---

# Interpolation

Let us assume we know some values of function $(x_0, y_0), (x_1, y_1), (x_2, y_2) \dots$. But we do not know the value of that function at some point lying in between the known points. **Interpolation** is the process of estimating that unknown value.
- **Definition:** Interpolation is the process of estimating the value of a function at an intermediate point using known data points.
- **Need for Interpolation:**
    - In practical numerical problems, we frequently have tabulated or measured data rather than an explicit mathematical function. 
    - For example: Temperature, population data, experimental observations, vehicle speeds at different times, sensor measurements, travel time data, etc.

> **Interpolation** estimates a value *inside* the range of known data points. Example: $x = 10$ and $x = 30$ are given, find $x = 20$.
> 
> **Experpolation** estimates a value *outside* the known range. Example: $x = 10$ and $x = 30$ are given, find $x = 60$.

### Polynomial Interpolation
- Suppose we have '$n + 1$' data points, $(x_0, y_0), (x_1, y_1), (x_2, y_2), \dots (x_n, y_n)$.
- Based on that we can construct a polynomial of degree at most $n$:
    - $P_n(x) = a_0 + a_1x + a_2x^2 + \dots a_nx^n$
    - Such that, $P_n(x_i) = y_i \forall i = 0, 1, 2, \dots n$.
- Example: 
    - A polynomial of degree at most 1: $P_1(x) = a_0 + a_1x$.
    - A polynomial of degree at most 2: $P_2(x) = a_0 + a_1x + a_2x^2$.

#### Exercise: Two Point Interpolation
Let $f(1) = 2$ and $f(3) = 6$. Find $f(2)$ using linear interpolation.
- We know, $P_1(x) = a + bx$
- $P(1) = 2, \therefore a + b = 2$
- $P(3) = 6, \therefore a + 3b = 6$
- Subtracting them, $2b = 4, \therefore b = 2$
- Substituing $b$ we get, $a = 0$

## Linear Interpolation
- For two data points $(x_0, y_0)$ and $(x_1, y_1)$, the linear interpolation formula is:
    - $y = y_0 + \frac{x - x_0}{x_1 - x_0}(y_1 - y_0)$

---

## Larange Interpolation
- Suppose we have $(n + 1)$ data points, $(x_0, y_0), (x_1, y_1), (x_2, y_2), \dots (x_n, y_n)$.
- The Larange Interpolation Formula:
    - $P_n(x) = \Sigma_{i = 0}^{n} y_iL_i(x)$
    - Where, $L_i(x) = \Pi_{j = 0, j \ne i}^{n} \frac{x - x_j}{x_i - x_j}$
- Example: For three points $(x_0, y_0), (x_1, y_1), and (x_2, y_2)$.
    - $L_0 = \frac{(x - x_1)(x - x_2)}{(x_0 - x_1)(x_0 - x_2)}$
    - $L_1 = \frac{(x - x_0)(x - x_2)}{(x_1 - x_0)(x_1 - x_2)}$
    - $L_2 = \frac{(x - x_0)(x - x_1)}{(x_2 - x_0)(x_2 - x_1)}$
    - $P_2(x) = y_0L_0(x) + y_1L_1(x) + y_2L_2(x)$

### Exercises

#### Exercise 1

| $x$ | $1$ | $2$ | $4$ |
| :-- | :-- | :-- | :-- |
| $y$ | $1$ | $4$ | $16$ |

Find f(3) using Linear Interpolation.
- $L_0 =  \frac{(3 - 2)(3 - 4)}{(1 - 2)(1 - 4)} = -\frac{1}{3}$
- $L_1 = \frac{(3 - 1)(3 - 4)}{(2 - 1)(2 - 4)} = 1$
- $L_2 = \frac{(3 - 1)(3 - 2)}{(4 - 1)(4 - 2)} = \frac{1}{3}$
- $P_2(3) = 1 \times -\frac{1}{3} + 4 \times 1 + 16 \times \frac{1}{3} = \frac{27}{3}$
- $\therefore f(3) = 9$

### Advantages of Larange Interpolation
- Simple direct formula.
- No need to solve simultaneous equations for the coefficients.
- Works with unequally spaced data points.
- Easy to use when only one interpolation value is required.

### Limitations of Larange Interpolation
- Formula becomes lengthy when many points are used.
- If a new data point is added, the polynomial generally has to be reconstructed.
- Repeated calculations can become combursome.
- For many data points, Newton divided differences are often more convinient.

---

## Newton Forward Interpolation
- Suppose the values of the data points are $x_0, x_1, x_2, \dots x_n$ and $x_1 - x_0 = x_2 - x_1 = x_3 - x_2 = \dots x_n - x_{n - 1} = h$, then the data is called **equally spaced**.

| $x$ | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ |
| :-- | :-- | :-- | :-- | :-- | :-- | :-- | :-- |
| $f(x)$ | $1$ | $4$ | $6$ | $10$ | $15$ | $17$ | $22$ |

- Therefore, $x_i = x_0 + ih \forall i = 0, 1, 2, \dots n$.

### Forward Difference Operator
- The forward difference operator is represented by $\Delta$, and $\Delta f(x) = f(x+h) - f(x)$.
- For a set of equally spaced data $(x_0,y_0), (x_1,y_1), \dots, (x_n,y_n)$:

| $x$ | $x_0$ | $x_1$ | $x_2$ | $x_3$ |
| :-- | :-- | :-- | :-- | :-- |
| $y$ | $y_0$ | $y_1$ | $y_2$ | $y_3$ |

- **First forward difference:** $\Delta y_i = y_{i+1} - y_i$
    - $\Delta y_0 = y_1 - y_0$
    - $\Delta y_1 = y_2 - y_1$
    - $\Delta y_2 = y_3 - y_2$
- **Second forward difference:** $\Delta^2 y_i = \Delta y_{i+1} - \Delta y_i$
    - $\Delta^2 y_0 = \Delta y_1 - \Delta y_0$
    - $\Delta^2 y_1 = \Delta y_2 - \Delta y_1$
- **Third forward difference:** $\Delta^3 y_i = \Delta^2 y_{i+1} - \Delta^2 y_i$
    - $\Delta^3 y_0 = \Delta^2 y_1 - \Delta^2 y_0$

### Forward Difference Table

| $x$ | $0$ | $1$ | $2$ | $3$ | $4$ |
| :-- | :-- | :-- | :-- | :-- | :-- |
| $y$ | $1$ | $2$ | $5$ | $10$ | $17$ |

- **1st forward differences:**
    - $\Delta y_0 = 2 - 1 = 1$
    - $\Delta y_1 = 5 - 2 = 3$
    - $\Delta y_2 = 10 - 5 = 5$
    - $\Delta y_3 = 17 - 10 = 7$
- **2nd forward differences:**
    - $\Delta^2 y_0 = 3 - 1 = 2$
    - $\Delta^2 y_1 = 5 - 3 = 2$
    - $\Delta^2 y_2 = 7 - 5 = 2$
- **3rd forward differences:**
    - $\Delta^3 y_0 = 2 - 2 = 0$
    - $\Delta^3 y_1 = 2 - 2 = 0$
- **4th forward difference:**
    - $\Delta^4 y_0 = 0 - 0 = 0$

**Final difference table:**

| $n$ | $y$ | $\Delta y$ | $\Delta^2y$ | $\Delta^3y$ |
| :-- | :-- | :-- | :-- | :-- |
| $0$ | $1$ | $1$ | $2$ | $0$ |
| $1$ | $2$ | $3$ | $2$ | $0$ |
| $2$ | $5$ | $5$ | $2$ |  |
| $3$ | $10$ | $7$ |  |  |
| $4$ | $17$ |  |  |  |

- Constant 1st differences indicate a polynomial of degree $1$, that means a linear polynomial.
- Constant 2nd differences indicate a polynomial of degree $2$, that means a quadratic polynomial.
- Constant 3rd differences indicate a polynomial of degree $3$, that means a cubic polynomial.
- In this example, since $\Delta^2y$ is constant at $2$, the underlying function is exactly quadratic.

### Newton Forward Interpolation Formula (N.F.I.F)
- Suppose the knows data points $(x_0,y_0), (x_1,y_1), \dots, (x_n,y_n)$ with equal spacing $h$:
    - $p = \frac{x - x_0}{h}$
- Then the **N.F.I.F** is:
$$f(x) \approx P_n(x) = y_0 + p\,\Delta y_0 + \frac{p(p-1)}{2!}\Delta^2 y_0 + \frac{p(p-1)(p-2)}{3!}\Delta^3 y_0 + \cdots + \frac{p(p-1)(p-2)\cdots(p-n+1)}{n!}\Delta^n y_0$$

### Exercises

#### Exercise 1
Find $f(1.5)$ using N.F Interpolation, using the table above where $x_0=0$ and $h=1$.
- $p = \dfrac{x - x_0}{h} = \dfrac{1.5 - 0}{1} = 1.5$
- $f(1.5) \approx P_n(1.5) = y_0 + p\,\Delta y_0 + \dfrac{p(p-1)}{2!}\Delta^2y_0$
- $f(1.5) = 1 + (1.5)(1) + \dfrac{(1.5)(0.5)}{2}(2)$
- $f(1.5) = 1 + 1.5 + 0.75 = 3.25$
- $\therefore f(1.5) = 3.25$

#### Exercise 2

| $x$ | $10$ | $20$ | $30$ | $40$ | $50$ |
| :-- | :-- | :-- | :-- | :-- | :-- |
| $y$ | $100$ | $400$ | $900$ | $1600$ | $2500$ |

Find $f(25)$ using N.F.I method.
- $x = 25$, $x_0=10$, $h=10 \Rightarrow p = \dfrac{25-10}{10} = 1.5$
- $\Delta y_0 = 300$, $\Delta^2y_0 = 200$ (from the difference table; $\Delta^3y_0=0$ since $y=x^2$ is exactly quadratic)
- $f(25) \approx 100 + (1.5)(300) + \dfrac{(1.5)(0.5)}{2}(200)$
- $f(25) = 100 + 450 + 75 = 625$
- $\therefore f(25) = 625$

#### Exercises - H.W
1. Find $f(2.5)$ using Newton Forward Interpolation.

    | $x$ | $1$ | $2$ | $3$ | $4$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $y$ | $1$ | $8$ | $27$ | $64$ |

2. Find $f(12)$ using Newton Forward Interpolation.

    | $x$ | $10$ | $15$ | $20$ | $25$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $f(x)$ | $100$ | $225$ | $400$ | $625$ |

3. Explain why Newton Forward Interpolation is used when the required value is near the beginning of the equally spaced table.

---

## Newton Backward Interpolation

- Suppose the data points $x_0, x_1, x_2, \dots x_n$ are equally spaced with $x_i = x_0 + ih$, as before.
- Newton Backward Interpolation builds the polynomial starting from the last point $(x_n, y_n)$, so it is used when the required value lies near the end of the table.

    | $x$ | $0$ | $1$ | $2$ | $3$ | $4$ |
    | :-- | :-- | :-- | :-- | :-- | :-- |
    | $f(x)$ | $1$ | $2$ | $5$ | $10$ | $17$ |

### Backward Difference Operator
- The backward difference operator is represented by $\nabla$, and $\nabla f(x) = f(x) - f(x-h)$.
- For a set of equally spaced data $(x_0,y_0), (x_1,y_1), \dots, (x_n,y_n)$:

    | $x$ | $x_0$ | $x_1$ | $x_2$ | $x_3$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $y$ | $y_0$ | $y_1$ | $y_2$ | $y_3$ |

- First backward difference: $\nabla y_i = y_i - y_{i-1}$
    - $\nabla y_1 = y_1 - y_0$
    - $\nabla y_2 = y_2 - y_1$
    - $\nabla y_3 = y_3 - y_2$
- Second backward difference: $\nabla^2 y_i = \nabla y_i - \nabla y_{i-1}$
    - $\nabla^2 y_2 = \nabla y_2 - \nabla y_1$
    - $\nabla^2 y_3 = \nabla y_3 - \nabla y_2$
- Third backward difference: $\nabla^3 y_i = \nabla^2 y_i - \nabla^2 y_{i-1}$
    - $\nabla^3 y_3 = \nabla^2 y_3 - \nabla^2 y_2$

### Backward Difference Table
- 1st backward differences:
    - $\nabla y_1 = 2 - 1 = 1$
    - $\nabla y_2 = 5 - 2 = 3$
    - $\nabla y_3 = 10 - 5 = 5$
    - $\nabla y_4 = 17 - 10 = 7$
- 2nd backward differences:
    - $\nabla^2 y_2 = 3 - 1 = 2$
    - $\nabla^2 y_3 = 5 - 3 = 2$
    - $\nabla^2 y_4 = 7 - 5 = 2$
- 3rd backward differences:
    - $\nabla^3 y_3 = 2 - 2 = 0$
    - $\nabla^3 y_4 = 2 - 2 = 0$

- **Final difference table:**

    | $x$ | $y$ | $\nabla y$ | $\nabla^2 y$ | $\nabla^3 y$ |
    | :-- | :-- | :-- | :-- | :-- |
    | 0 | 1 | | | | |
    | 1 | 2 | 1 | | |
    | 2 | 5 | 3 | 2 | |
    | 3 | 10 | 5 | 2 | 0 |
    | 4 | 17 | 7 | 2 | 0 |

### Newton Backward Interpolation Formula (N.B.I.F)
- Suppose the known data points $(x_0,y_0), (x_1,y_1), \dots, (x_n,y_n)$ with equal spacing $h$:
    - $p = \dfrac{x - x_n}{h}$
- Then the N.B.I.F is:

$$f(x) \approx P_n(x) = y_n + p\,\nabla y_n + \frac{p(p+1)}{2!}\nabla^2 y_n + \frac{p(p+1)(p+2)}{3!}\nabla^3 y_n + \cdots + \frac{p(p+1)(p+2)\cdots(p+n-1)}{n!}\nabla^n y_n$$

### Exercises

#### Exercise 1
Find $f(3.5)$ using N.B. Interpolation, using the table above.
- $p = \dfrac{x - x_n}{h} = \dfrac{3.5 - 4}{1} = -0.5$
- $f(3.5) \approx P_n(3.5) = y_n + p\,\nabla y_n + \dfrac{p(p+1)}{2!}\nabla^2y_n$
- $f(3.5) = 17 + (-0.5)(7) + \dfrac{(-0.5)(0.5)}{2}(2)$
- $f(3.5) = 17 - 3.5 - 0.25 = 13.25$
- $\therefore f(3.5) = 13.25$

---

## Newton Divided Difference Interpolation

- First divided difference: 
    - $f[x_0, x_1] = \frac{f(x_1) - f(x_0)}{x_1 - x_0}$
- Second divided difference: 
    - $f[x_0, x_1, x_2] = \frac{f[x_1, x_2] - f[x_0, x_1]}{x_2 - x_0}$
- General divided difference: 
    - $f[x_i, \cdots x_{i + k}] = \frac{f[x_{i + 1}, \cdots x_{i + k}] - f[x_i, \cdots x_{i + k - 1}]}{x_{i + k} - x_i}$

    | $x$ | $1$ | $2$ | $4$ | $7$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $f(x)$ | $1$ | $4$ | $16$ | $19$ |

### Divided Difference Table
- First divided difference: 
    - $f[1, 2] = \frac{f(2) - f(1)}{2 - 1} = 3$
    - $f[2, 4] = \frac{f(4) - f(2)}{4 - 2} = 6$
    - $f[4, 7] = \frac{f(7) - f(4)}{7 - 4} = 1$
- Second divided difference:
    - $f[1, 2, 4] = \frac{f[2, 4] - f[1, 2]}{4 - 1} = 1$
    - $f[2, 4, 7] = \frac{f[4, 7] - f[2, 4]}{7 - 2} = -1$
- Third divided difference:
    - $f[1, 2, 4, 7] = \frac{f[2, 4, 7] - f[1, 2, 4]}{7 - 1} = -\frac{1}{3}$

- **Final Difference Table:**

    | $x$ | $y$ | $\Delta y$ | $\Delta^2 y$ | $\Delta^3 y$ |
    | :-- | :-- | :-- | :-- | :-- |
    | $1$ | $1$ | $3$ | $1$ | -$\frac{1}{3}$ |
    | $2$ | $4$ | $6$ | $-1$ | |
    | $4$ | $16$ | $1$ | | |
    | $7$ | $19$ | | | |

### Divided Difference Formula
$$P_n(x) = f[x_0] + (x - x_0)f[x_0, x_1] + (x - x_0)(x - x_1)f[x_0, x_1, x_2] + (x - x_0)(x - x_1)(x - x_2)f[x_0, x_1, x_2, x_3] + \cdots (x - x_0) \cdots (x - x_{n - 1})f[x_0, x_1, \cdots x_n]$$

### Exercises

#### Exercise 1
Construct the divided difference table for the data
    
| $x$ | $0.5$ | $1.5$ | $3.0$ | $5.0$ | $6.5$ | $8.0$ |
| :-- | :-- | :-- | :-- | :-- | :-- | :-- |
| $f(x)$ | $1.625$ | $5.875$ | $31.0$ | $131.0$ | $282.125$ | $521.0$ |

Hence, find the interpolating polynomial and approximation to the value of $f(7)$.
- Frst divided differences:
    - $f[0.5, 1.5] = \frac{5.875 - 1.625}{1.5 - 0.5} = 4.25$
    - $f[1.5, 3.0] = \frac{31.0 - 5.875}{3.0 - 1.5} = 16.75$
    - $f[3.0, 5.0] = \frac{131.0 - 31.0}{5.0 - 3.0} = 50$
    - $f[5.0, 6.5] = \frac{282.125 - 131.0}{6.5 - 5.0} = 100.75$
    - $f[6.5, 8.0] = \frac{521.0 - 282.125}{8.0 - 6.5} = 159.25$
- Second divided differences:
    - $f[0.5, 1.5, 3.0] = \frac{16.75 - 4.25}{3.0 - 0.5} = 5$
    - $f[1.5, 3.0, 5.0] = \frac{50 - 16.75}{5.0 - 1.5} = 9.5$
    - $f[3.0, 5.0, 6.5] = \frac{100.75 - 50}{6.5 - 3.0} = 14.5$
    - $f[5.0, 6.5, 8.0] = \frac{159.25 - 100.75}{8.0 - 5.0} = 19.5$
- Third divided differences:
    - $f[0.5, 1.5, 3.0, 5.0] = \frac{9.5 - 5}{5.0 - 0.5} = 1$
    - $f[1.5, 3.0, 5.0, 6.5] = \frac{14.5 - 9.5}{6.5 - 1.5} = 1$
    - $f[3.0, 5.0, 6.5, 8.0] = \frac{19.5 - 14.5}{8.0 - 3.0} = 1$
- Fourth divided differences:
    - $f[0.5, 1.5, 3.0, 5.0, 6.5] = \frac{1 - 1}{6.5 - 0.5} = 0$
    - $f[1.5, 3.0, 5.0, 6.5, 8.0] = \frac{1 - 1}{8.0 - 1.5} = 0$
- Fifth divided difference:
    - $f[0.5, 1.5, 3.0, 5.0, 6.5, 8.0] = \frac{0 - 0}{8.0 - 0.5} = 0$

- Divided difference table:

    |$x$ | $f[x]$ | 1st | 2nd | 3rd | 4th | 5th |
    | :-- | :-- | :-- | :-- | :-- | :-- | :-- |
    | $0.5$ | $1.625$ | $4.25$ | $5$ | $1$ | $0$ | $0$ |
    | $1.5$ | $5.875$ | $16.75$ | $9.5$ | $1$ | $0$ | |
    | $3.0$ | $31.0$ | $50$ | $14.5$ | $1$ | | |
    | $5.0$ | $131.0$ | $100.75$ | $19.5$ | | | |
    | $6.5$ | $282.125$ | $159.25$ | | | | |
    | $8.0$ | $521.0$ | | | | | |

- $P_3(x) = 1.625 + 4.25(x - 0.5) + 5(x - 0.5)(x - 1.5) + 1\cdot(x - 0.5)(x - 1.5)(x - 3.0)$
    - $5(x-0.5)(x-1.5) = 5x^2 - 10x + 3.75$
    - $(x-0.5)(x-1.5)(x-3) = x^3 - 5x^2 + 6.75x - 2.25$
- $P_3(x) = x^3 + (5-5)x^2 + (4.25 - 10 + 6.75)x + (1.625 - 2.125 + 3.75 - 2.25)$
- $\therefore P_3(x) = x^3 + x + 1$
- Approximation of $f(7)$:
    - $P_3(7) = 7^3 + 7 + 1 = 351$


#### Exercise - H.W
1. Construct the difference table for the sequence of values $f(x) = (0, 0, 0, \epsilon, 0, 0, 0)$, where $\epsilon$ is an error. Also show that:
    1. The error spreads and increases in magnitude as the order of difference increases.
    2. The errors in each column have binomial coefficients.

---

# System of Linear Equations

### Linear Equation
- A linear equation in one variable has the form $ax = b$, where $a$ and $b$ are known constants and $x$ is unknown.
- Ex: $2x = 6 \Rightarrow x = 3$.
- A linear equation in two variables is $a_1x_1 + a_2x_2 = b$.
- A linear equation in three variables is $a_1x_1 + a_2x_2 + a_3x_3 = b$.
- A linear equation contains variables only to the first power.
- No product of variables such as $xy$.
- No powers such as $x^2, x^3$, etc.
- No functions such as $\sin(x), e^x$, etc.
- Ex:
    - $2x + 3y = 5$ is a linear equation.
    - $x^2 + 6 = y$ is not a linear equation.
    - $xy + z = 6$ is not a linear equation.
    - $x\sin x + y$ is not a linear equation.

### System of Linear Equations
- Suppose we have more than one linear equation involving the same unknowns.
- Ex: $2x + y = 5$ and $x - y = 1$.
- General form:
    - $a_{11}x_1 + a_{12}x_2 = b_1$
    - $a_{21}x_1 + a_{22}x_2 = b_2$

### Matrix Form
- Writing all equations separately becomes inconvenient when $n$ becomes large. 
- Therefore, we use matrices.
- Ex: $2x + 3y = 8$ and $4x + 5y = 14$.
- The coefficients of $x$ and $y$ form the matrix 
    - $A = \begin{bmatrix} 2 & 3 \\ 4 & 5 \end{bmatrix}$.
- The unknowns form the vector 
    - $X = \begin{bmatrix} x \\ y \end{bmatrix}$.
- The right hand side forms 
    - $B = \begin{bmatrix} 8 \\ 14 \end{bmatrix}$.
- Matrix form: $AX = B$, where
    - $A \to$ coefficient matrix $= \begin{bmatrix} a_{11} & a_{12} & \cdots & a_{1n} \\ a_{21} & a_{22} & \cdots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{n1} & a_{n2} & \cdots & a_{nn} \end{bmatrix}$
    - $X \to$ unknown / variable vector $= \begin{bmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{bmatrix}$
    - $B \to$ constant / right hand vector $= \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_n \end{bmatrix}$
- Ex: Convert the following equations to matrix form.
    - $3x + 2y - z = 7$
    - $x - 4y + 2z = -1$
    - $2x + y + 3z = 12$
    - $\begin{bmatrix} 3 & 2 & -1 \\ 1 & -4 & 2 \\ 2 & 1 & 3 \end{bmatrix}\begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 7 \\ -1 \\ 12 \end{bmatrix}$

### Augmented Matrix
- There is another very useful representation.
- Ex: $2x + 3y = 8$ and $4x + 5y = 14$.
    - $A = \begin{bmatrix} 2 & 3 \\ 4 & 5 \end{bmatrix}$,
    - $B = \begin{bmatrix} 8 \\ 14 \end{bmatrix}$
- $[A \mid B] = \left[\begin{array}{cc|c} 2 & 3 & 8 \\ 4 & 5 & 14 \end{array}\right]$

### Direct vs Iterative Methods

#### Direct Methods
- Direct methods attempt to obtain the solution through a finite sequence of algebraic operations.
- Examples: 
    1. LU Decomposition
    2. Gauss-Jordan
    3. Gaussian Elimination

#### Iterative Methods
- Iterative methods start with an initial approximation and repeatedly improve it.
- Eg: $x^{(0)} \to x^{(1)} \to x^{(2)} \to x^{(3)} \to \cdots$
- Until the solution satisfies our chosen tolerance.
- Eg: Jacobi method, Gauss-Seidel method.

### Geometrical Interpretation
- Consider $a_1x + b_1y = c_1$ and $a_2x + b_2y = c_2$. 
- Each equation represents a straight line.
- There are 3 possibilities:
    1. Unique solution
    2. No solution
    3. Infinitely many solutions

#### I. Unique Solution:
- Two lines intersect at exactly one point.
- Eg: $x + y = 5$, $x - y = 1$.
- The lines intersect at $(3, 2)$.

#### II. No Solution:
- Two lines are parallel and distinct.
-vEg: $x + y = 2$ and $x + y = 5$.

#### III. Infinitely Many Solutions:
- Two equations represent the same line.
- Eg: $x + y = 2$ and $2x + 2y = 4$.

### Consistent and Inconsistent Systems
- A system is consistent if it has at least one solution (unique or infinitely many solutions). Otherwise it is inconsistent.
- A system is called inconsistent if it has no solution.

### Square and Non-Square Systems
- Square: number of unknowns is the same as the number of equations given.
- Non-square: number of equations given is less than the number of unknowns $\to$ cannot find a unique solution.

### Determinant and Uniqueness
- For a square system $AX = B$:
- If $\det A \neq 0$, then $A$ is non-singular and the system has a unique solution.
- If $\det A = 0$, then $A$ is singular and the system does not have a unique solution.
- Eg: $2x + y = 5$, $x - y = 1$.
    - $A = \begin{bmatrix} 2 & 1 \\ 1 & -1 \end{bmatrix}$
$\det A = (2)(-1) - (1)(1) = -3 \neq 0$
    - $\therefore$ the system has a unique solution.

### Exercises - H.W
1. Convert the following system into matrix form. Identify $A$, $X$ & $B$. Also write the augmented matrix.
    - $2x + 3y - z = 5$
    - $x - 2y + 4z = 7$
    - $3x + y + 2z = 10$
2. Classify the following system: $x + y = 4$ and $2x + 2y = 8$. Is it consistent? And how many solutions?
3. Determine whether $2x + y = 3$, $4x + 2y = 10$ has a unique solution, no solution or infinitely many solutions.
4. Calculate the determinant of $A = \begin{bmatrix} 3 & 2 \\ 1 & 4 \end{bmatrix}$ and state whether the corresponding square system can have a unique solution.

---

## Gaussian Elimination Method

- Suppose we have,
    - $a_{11}x_1 + a_{12}x_2 + a_{13}x_3 = b_1$
    - $a_{21}x_1 + a_{22}x_2 + a_{23}x_3 = b_2$
    - $a_{31}x_1 + a_{32}x_2 + a_{33}x_3 = b_3$
- First, eliminate $x_1$ from equations 2 and 3.
- Then eliminate $x_2$ from equation 3.
- Then we obtain,
    - $u_{11}x_1 + u_{12}x_2 + u_{13}x_3 = c_1$
    - $u_{22}x_2 + u_{23}x_3 = c_2$
    - $u_{33}x_3 = c_3$
- This is an upper triangular system.

### Elementary Row Operations
- **Operation 1:** Interchange two rows. $R_1 \leftrightarrow R_2$
    - Ex: $\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix} \leftrightarrow \begin{bmatrix} 3 & 4 \\ 1 & 2 \end{bmatrix}$
- **Operation 2:** Multiply a row by a non-zero constant. $R_2 \to kR_2$, $k \neq 0$
    - Ex: $R_2 \to 2R_2$
- **Operation 3:** Add a multiple of one row to another row. $R_i \to R_i + kR_j$
    - Ex: $R_2 \to R_2 - 2R_1$

#### Example
Find the solution using the Gaussian Elimination Method.
    - $x + y + z = 6$
    - $2x + 3y + z = 11$
    - $x + 2y + 3z = 14$
- Augmented matrix: $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 2 & 3 & 1 & 11 \\ 1 & 2 & 3 & 14 \end{array}\right]$
- Step 1: Eliminate $x$
    - $R_2 \to R_2 - 2R_1$ and $R_3 \to R_3 - R_1$
    - $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 1 & 2 & 8 \end{array}\right]$
- Step 2: Eliminate $y$
    - $R_3 \to R_3 - R_2$
    - $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 0 & 3 & 9 \end{array}\right]$
- Step 3: Solve $z$
    - $3z = 9$
    - $z = 3$
- Step 4: Solve $y$
    - $y - z = -1$
    - $y - 3 = -1$
    - $y = 2$
- Step 5: Solve $x$
    - $x + y + z = 6$
    - $x + 5 = 6$
    - $x = 1$
- $\therefore x = 1,\ y = 2,\ z = 3$

### General Gaussian Elimination Algorithm
- For $AX = B$, we transform the augmented matrix $[A \mid B]$ into $[U \mid C]$, where $U$ is the upper triangular matrix.
- For the first pivot $a_{11}$:
- Calculate the multiplier $m_{i1} = \dfrac{a_{i1}}{a_{11}}$ and perform $R_i \to R_i - m_{i1}R_1$ for $i = 2, 3, \dots, n$.
- Then move to the second pivot $a_{22}^{(new)}$ and eliminate the elements below it.

>> **Pivot:**
>> A pivot is the key element which is used to eliminate the entries below it.
>> For $\begin{bmatrix} 2 & 1 & -1 \\ 0 & 3 & 4 \\ 0 & 0 & 5 \end{bmatrix}$, the pivots are $2, 3, 5$.

### Exercises - H.W
1. Solve using the Gaussian Elimination Method.
    - $2x + y + z = 10$
    - $4x - 6y + 3z = -2$
    - $-2x + 7y + 2z = 13$
2. Using the Gaussian Elimination Method, find $x$, $y$, $z$ and the pivot elements.
    - $2x + 3y + z = 10$
    - $4x + y + 2z = 12$
    - $-2x + 2y + 3z = 5$
3. Explain why row interchange is necessary before applying to the following matrix $\begin{bmatrix} 0 & 2 & 1 \\ 4 & 5 & 6 \\ 2 & 3 & 4 \end{bmatrix}$

---

## Gauss-Jordan Method
$$[A \mid B] \to [I \mid X]$$
- In Gauss-Jordan, we continue eliminating both:
    - below the pivot, and
    - above the pivot.
- The coefficient matrix becomes the identity matrix.
- $I = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}$
- Therefore, $[A \mid B] \to [I \mid X]$.

### Elementary Row Operations
- **Operation 1:** Interchange rows. $R_i \leftrightarrow R_j$
- **Operation 2:** Multiply a row by a non-zero constant. $R_i \to kR_i$, $k \neq 0$
- **Operation 3:** Add a multiple of one row to another. $R_i \to R_i + kR_j$

### Example
- Solve using Gauss-Jordan Method
    - $x + y + z = 6$
    - $2x + 3y + z = 11$
    - $x + 2y + 3z = 14$
- Form augmented matrix: $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 2 & 3 & 1 & 11 \\ 1 & 2 & 3 & 14 \end{array}\right] \to \left[\begin{array}{ccc|c} 1 & 0 & 0 & 1 \\ 0 & 1 & 0 & 2 \\ 0 & 0 & 1 & 3 \end{array}\right]$
- $R_2 \to R_2 - 2R_1$
    - $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 1 & 2 & 3 & 14 \end{array}\right]$
- Then, $R_3 \to R_3 - R_1$
    - $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 1 & 2 & 8 \end{array}\right]$
- Then, $R_3 \to R_3 - R_2$
    - So, $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 0 & 3 & 9 \end{array}\right]$
- Then, $R_3 \to \dfrac{1}{3}R_3$
    - So, $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 0 & 1 & 3 \end{array}\right]$
- Then, $R_2 \to R_2 + R_3$
    - So, $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & 0 & 2 \\ 0 & 0 & 1 & 3 \end{array}\right]$
- Then, $R_1 \to R_1 - R_3$
    - So, $\left[\begin{array}{ccc|c} 1 & 1 & 0 & 3 \\ 0 & 1 & 0 & 2 \\ 0 & 0 & 1 & 3 \end{array}\right]$
- Now, $R_1 \to R_1 - R_2$
    - $\left[\begin{array}{ccc|c} 1 & 0 & 0 & 1 \\ 0 & 1 & 0 & 2 \\ 0 & 0 & 1 & 3 \end{array}\right]$
- Therefore, $x = 1$, $y = 2$ and $z = 3$.

### General Structure of Gauss-Jordan Method
- $[A \mid B]$ for an $n \times n$ system.
- We perform row operations until: $[I \mid X]$
- For a $3 \times 3$ system:
    - $\left[\begin{array}{ccc|c} a_{11} & a_{12} & a_{13} & b_1 \\ a_{21} & a_{22} & a_{23} & b_2 \\ a_{31} & a_{32} & a_{33} & b_3 \end{array}\right]$ 
    - becomes $\left[\begin{array}{ccc|c} 1 & 0 & 0 & x \\ 0 & 1 & 0 & y \\ 0 & 0 & 1 & z \end{array}\right]$

### Exercises - H.W
1. Solve using Gauss-Jordan Method
    - $2x + y - z = 8$
    - $x + 2y + z = 7$
    - $3x - y + 2z = 7$

---

## LU Decomposition
$$A = LU$$
- $A \to$ original coefficient matrix
- $L \to$ lower triangular matrix
- $U \to$ upper triangular matrix

### Basic Concept
- $AX = B$
- Using LU Decomposition:
    - $AX = B \Rightarrow LUX = B$
- Let $UX = Y$
- Then, we get two systems:
    - $LY = B$ to find $Y$
    - $UX = Y$ to find $X$

### General Structure of LU Decomposition
- For a $3 \times 3$ system, $A = LU$ where:
    - $A = \begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{bmatrix}$
    - $L = \begin{bmatrix} 1 & 0 & 0 \\ l_{21} & 1 & 0 \\ l_{31} & l_{32} & 1 \end{bmatrix}$,
    - $U = \begin{bmatrix} u_{11} & u_{12} & u_{13} \\ 0 & u_{22} & u_{23} \\ 0 & 0 & u_{33} \end{bmatrix}$
- $u_{11} = a_{11}$, $\quad u_{12} = a_{12}$, $\quad u_{13} = a_{13}$
- $l_{21} = \dfrac{a_{21}}{u_{11}}$, $\quad l_{31} = \dfrac{a_{31}}{u_{11}}$
- $u_{22} = a_{22} - l_{21}u_{12}$
- $u_{23} = a_{23} - l_{21}u_{13}$
- $l_{32} = \dfrac{a_{32} - l_{31}u_{12}}{u_{22}}$
- $u_{33} = a_{33} - l_{31}u_{13} - l_{32}u_{23}$

### Example
- Solve using LU Decomposition
    - $x + y + z = 6$
    - $2x + 3y + z = 11$
    - $x + 2y + 3z = 14$
- $AX = B$
- $A = \begin{bmatrix} 1 & 1 & 1 \\ 2 & 3 & 1 \\ 1 & 2 & 3 \end{bmatrix}$, $\quad X = \begin{bmatrix} x \\ y \\ z \end{bmatrix}$, $\quad B = \begin{bmatrix} 6 \\ 11 \\ 14 \end{bmatrix}$
- $A = LU$
- For Row 2: $R_2 \to R_2 - 2R_1$
- For Row 3: $R_3 \to R_3 - R_1$
- This generates: $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 1 & 2 & 8 \end{array}\right]$
- Then $R_3 \to R_3 - R_2$
    - $\left[\begin{array}{ccc|c} 1 & 1 & 1 & 6 \\ 0 & 1 & -1 & -1 \\ 0 & 0 & 3 & 9 \end{array}\right]$
- $U = \begin{bmatrix} 1 & 1 & 1 \\ 0 & 1 & -1 \\ 0 & 0 & 3 \end{bmatrix}$
- Similarly, $L = \begin{bmatrix} 1 & 0 & 0 \\ 2 & 1 & 0 \\ 1 & 1 & 1 \end{bmatrix}$
- Hence,$A = \underbrace{\begin{bmatrix} 1 & 0 & 0 \\ 2 & 1 & 0 \\ 1 & 1 & 1 \end{bmatrix}}_{L}\underbrace{\begin{bmatrix} 1 & 1 & 1 \\ 0 & 1 & -1 \\ 0 & 0 & 3 \end{bmatrix}}_{U}$
- $LU = \begin{bmatrix} 1 & 0 & 0 \\ 2 & 1 & 0 \\ 1 & 1 & 1 \end{bmatrix}\begin{bmatrix} 1 & 1 & 1 \\ 0 & 1 & -1 \\ 0 & 0 & 3 \end{bmatrix} = \begin{bmatrix} 1 & 1 & 1 \\ 2 & 3 & 1 \\ 1 & 2 & 3 \end{bmatrix} = A$
- Now solve $LY = B$
    - $\begin{bmatrix} 1 & 0 & 0 \\ 2 & 1 & 0 \\ 1 & 1 & 1 \end{bmatrix}\begin{bmatrix} y_1 \\ y_2 \\ y_3 \end{bmatrix} = \begin{bmatrix} 6 \\ 11 \\ 14 \end{bmatrix}$
    - $y_1 = 6$
    - $2y_1 + y_2 = 11$
    - $y_1 + y_2 + y_3 = 14$
- So, $y_2 = -1$, $y_3 = 9$.
- $Y = \begin{bmatrix} 6 \\ -1 \\ 9 \end{bmatrix}$
- Now solve $UX = Y$
    - $\begin{bmatrix} 1 & 1 & 1 \\ 0 & 1 & -1 \\ 0 & 0 & 3 \end{bmatrix}\begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 6 \\ -1 \\ 9 \end{bmatrix}$
    - $x + y + z = 6$
    - $y - z = -1$
    - $3z = 9$
- So, $z = 3$, $y = 2$, $x = 1$.

### Advantages of LU Decomposition
- Useful for solving multiple systems with the same coefficient matrix.
- Separates factorization from solving the system.
- Can be used to calculate determinants and matrix inverses.
- Uses forward and back substitution after factorization.

### Limitations of LU Decomposition
- Factorization can fail without pivoting, if a required pivot is zero.
- Small pivots can cause numerical instability.
- Pivoting may require a permutation matrix, giving $PA = LU$ rather than a simple $A = LU$.
- Factorization requires order of $n^3$ arithmetic operations for a dense $n \times n$ matrix.

### Exercises - H.W
1. Solve using L.U. Decomposition.
    - $2x + y = 5$
    - $4x + 3y = 11$
2. Why is LU Decomposition particularly useful when several systems have the same coefficient matrix but different right hand side vectors?

---
