# Discrete Mathematics

- Sets
- Universal Set
- Characteristic Vector
- Principle of Specification

---

- $A = \{1, 2, 3\}$, $B = \{4, 5, 6\}$
- $A \times B = {(1, 4), (1, 5), ... (3, 6)}$
- $R = \{(a, b): a = b - 3, a \in A, b \in B\}$
- $R = \{1, 0, 0, 0, 1, 0, 0, 0, 1\}$

---

- $R' \vee (P' \wedge Q') = (R' \vee P') \wedge (R' \vee Q')$
- Let $(P' \wedge Q') = X'$, $(R' \vee P') = Y'$, and $(R' \vee Q') = Z'$
- Let $R' \vee X' = A'$ and $Y' \wedge Z' = B'$
- Prove, $A' = B'$

| $R'$ | $P'$ | $Q'$ | $X'$ | $Y'$ | $Z'$ | $A'$ | $B'$ |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| 0    | 0    | 1    | 0    | 0    | 1    | 0    | 0    |
| 0    | 1    | 0    | 0    | 1    | 0    | 0    | 0    |
| 0    | 1    | 1    | 1    | 1    | 1    | 1    | 1    |
| 1    | 0    | 0    | 0    | 1    | 1    | 1    | 1    |
| 1    | 0    | 1    | 0    | 1    | 1    | 1    | 1    |
| 1    | 1    | 0    | 0    | 1    | 1    | 1    | 1    |
| 1    | 1    | 1    | 1    | 1    | 1    | 1    | 1    |

---

- Relation is a subset of the Cartesian Product: $R \subseteq A \times B$
- Reflexive Relation: $(a, a) \in R$
- Symmetric Relation: $(a, b) \in R \implies (b, a) \in R$
- Anti-Symmetric Relation: $(a, b) \in R, (b, a) \in R, \iff a = b$
- Asymmetric Relation: $(a, b) \in R \implies (b, a) \notin R$
- Transitive Relation: $(a, b) \in R, (b, c) \in R \implies (a, c) \in R$

---

- Matrix $M_{m \times n}$ representation of a relation.
- Graph $G (V, E)$ representation of a relation.
- Directional graphs for asymmetric relations.
- Un-directional graphs for symmetric relations.
- Graphs with self-loops for reflexive relations.

---

- Composition of Relations
    - $R_1 \subseteq A \times B$ and $R_2 \subseteq B \times C$
    - $(a, b) \in R_1 \wedge (b, c) \in R_2 \implies (a, c) \in R_1 \circ R_2$
    - $R_1 \circ R_2 = R_3$, $(a, b, c) \in R_3$
- Compatible Relations - reflexive and symmetric

---

- Set $A = \{1, 2, 3\}$
- Power Set of A: $\{\phi, \{1\}, \{2\}, \{3\}, \{1, 2\},...  \{1, 2, 3\}\}$
- Covering of a Set: $\bigcup_{i = 1}A_i = A$ 
- Partition of a Set: $\bigcap_{i = 1}A_i = \phi$
    - "Blocks": subsets of partition
- Equivalence classes:
    - Let $A = \{x, y, z, a, t, ...\}$ have a equivalence relation $R$ such that,
    - $[x] = \{x, y, z, ...\}$, where $x R y$ or $y R x$, etc
    - $[a] = \{a, ...\}$
    - $[t] = \{t, ...\}$ and so on.
    - $\delta = \{[x], [a], [t], ...\}$ are set of partitions on set $A$.
- Theorem: Given $A$ and equivalence relation $R$ on $A$. Let $\delta = \{[x]_R | x \in A\}$ is a partition of A into disjoint non-empty subsets.
- Conversely, if $P$ is a partition of A into non-empty disjoint subsets, then, $P$ is a set of equivalence classes for the equivalence relation $E$ defined on $A$ by $a E b$.

---

- Integer Modulo: Basis for enumeration in computer science.
- Prime Modulo: Used in hashing, OS, memory allocation, etc.
- $a R_n b \iff (a - b) = k n$
- $b = a \mod n$
- If $n = 5$:
    - $[0] = \{0, 5, 10, ...\}$
    - $[1] = \{1, 6, 11, ...\}$
    - $[2] = \{2, 7, 12, ...\}$
    - $[3] = \{3, 8, 13, ...\}$
    - $[4] = \{4, 9, 14, ...\}$
- $[z] \to w.y + z$
- $[z - 1] \to w.y + (z - 1)$ ...
- $[1] \to w.y + 1$
- $[0] \to w.y + 0$

---

- Let $A = \{2, 3, 6, 12, 24, 36\}$, relation be "divides relation"
- Hasse Diagram for divides relation:
    - $24$ $36$
    - $\searrow$ $\swarrow$
    - $12$
    - $\downarrow$
    - $6$
    - $\swarrow$ $\searrow$
    - $2$ $3$ 
- Partially Ordered Set - Poset.
- Power set of $P \to 2^P$ is a Poset. $P (2^P, \le)$
- Lattice of $P$: Let $P = \{1, 2, 3\}$
    - $\{1, 2\}$
    - $\swarrow$ $\searrow$
    - $\{1\}$ $\{2\}$
    - $\searrow$ $\swarrow$
    - $\phi$ 

---

- Boolean Algebra, $B = \{0 1\}, (B, \neg, \vee, \wedge, \rightarrow, \leftrightarrow)$.
- Statements:
    - $P$: It is not raining today. $P$ is true.
    - $Q$: JNU is in London. $Q$ is false.
    - $R$, $S$: Amit is in class and is hungry. $R$ is true and $S$ is true. $R \wedge S$ is true.
    - $T$: Did Arnav come on time? $T$ is NOT a Boolean statement.
    - $U$: Khushi maybe the class rep. $U$ is NOT a Boolean statement.
- Propositional Logic, Formulae, Compound Propositions.
- A program is a set of propositions.

---

- Well-formed Formula (WFF)
    1. Every propositional variable ($T$, $F$, $0$, $1$, $A$, $B$, etc) is a WFF.
    2. If $A$ is a WFF, then $\neg A$ is a WFF.
    3. $\vee, \wedge$: If $A$, $B$ are WFF, then $A \vee B$, $A \wedge B$ are WFF.
    4. $\rightarrow, \leftrightarrow$: If $A$, $B$ are WFF, then $A \rightarrow B$, $A \leftrightarrow B$ are WFF.
- Consider $\neg P \vee Q$:
    - $P$ and $Q$ are WFF by definition 1.
    - $\neg P$ is a WFF by definition 2.
    - $\neg P \vee Q$ are WFF by definition 3.

---

- Truth table: interpretation of all truth values assignments for the propositions in a formula.
- Consider $P \rightarrow R$:
    - $P \rightarrow R$ is equivalent to $\neg P \vee R$.
    - Equivalent means they have the exact same truth values.
- Consider $P \leftrightarrow R$:
    - $P \leftrightarrow R$ is equivalent to $P \rightarrow Q \wedge Q \rightarrow P$.
    - $P \rightarrow Q \wedge Q \rightarrow P$ is equivalent to $(\neg P \vee Q) \wedge (\neg Q \vee P)$.
- $\vee$ is disjunction and $\wedge$ is conjunction.
- **Disjunctive Normal Form:** When a formula is written in the form of disjunctions of conjunctions.
- **Conjunctive Normal Form:** When a formula is written in the form of conjunctions of disjunctions.
- **Tautology:** The truth vale of formula is True for all values of the propositions involved.
- **Contradiction:** The truth value of formula is False for all truth value of the propositions involved.
- **Satisfiable (Solvable) Problem**: If in the WFF, at least 1 True.

---

| **Equivalent Formulas** | | |
| :--- | :--- | :--- |
| $P \vee P \Leftrightarrow P$ | $P \wedge P \Leftrightarrow P$ | (Idempotent laws) |
| $(P \vee Q) \vee R \Leftrightarrow P \vee (Q \vee R)$ | $(P \wedge Q) \wedge R \Leftrightarrow P \wedge (Q \wedge R)$ | (Associative laws) |
| $P \vee Q \Leftrightarrow Q \vee P$ | $P \wedge Q \Leftrightarrow Q \wedge P$ | (Commutative laws) |
| $P \vee (Q \wedge R) \Leftrightarrow (P \vee Q) \wedge (P \vee R)$ | $P \wedge (Q \vee R) \Leftrightarrow (P \wedge Q) \vee (P \wedge R)$ | (Distributive laws) |
| $P \vee F \Leftrightarrow P$ | $P \wedge T \Leftrightarrow P$ | |
| $P \vee T \Leftrightarrow T$ | $P \wedge F \Leftrightarrow F$ | |
| $P \vee \neg P \Leftrightarrow T$ | $P \wedge \neg P \Leftrightarrow F$ | |
| $P \vee (P \wedge Q) \Leftrightarrow P$ | $P \wedge (P \vee Q) \Leftrightarrow P$ | (Absorption laws) |
| $\neg(P \vee Q) \Leftrightarrow \neg P \wedge \neg Q$ | $\neg(P \wedge Q) \Leftrightarrow \neg P \vee \neg Q$ | (De Morgan's laws) |

---

- **Max Terms:** Will be true unless all are false.
    - $P \vee Q$, $\neg P \vee Q$, $P \vee \neg Q$, $\neg P \vee \neg Q$ (only one of four is false).
- **Min Terms:** Will be false unless all are true.
    - $P \wedge Q$, $\wedge P \wedge Q$, $P \wedge \neg Q$, $\neg P \wedge \neg Q$ (only one of four is true).
- Min terms and max terms are also called **factors**.