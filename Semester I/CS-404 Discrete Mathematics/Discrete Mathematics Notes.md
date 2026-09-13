# Discrete Mathematics

Taught by [Prof. Sonajharia Minz](https://www.jnu.ac.in/content/sonaminz)

### References
- [Discrete Mathematical Structures with Applications to Computer Science](Materials/Discrete%20Mathematical%20Structure%20with%20Applications%20to%20Computer%20Science%20(TREMBLAY).pdf)

---

# Sets

## Introduction

- **Set:** A well-defined collection of distinct objects, called *elements* or *members*.
- **Universal Set ($U$):** The "background" set containing all objects under consideration in a given context. Every other set discussed in that context is treated as a subset of $U$ (this is what lets us define complements: $A^c = U - A$).
- **Principle (Axiom) of Specification:** Given a set $A$ and a property/predicate $P(x)$, there exists a set consisting of exactly those elements of $A$ that satisfy $P(x)$:
$$\{x \in A : P(x)\}$$
This is the principle that justifies **set-builder notation** — e.g. the relation defined later in this document, $R = \{(a,b) : a = b-3,\ a\in A,\ b \in B\}$, is a direct application of this principle.
- **Power Set:** The set of *all* subsets of a set $A$, denoted $2^A$. If $A = \{1, 2, 3\}$:
$$2^A = \{\phi,\ \{1\},\ \{2\},\ \{3\},\ \{1,2\},\ \{1,3\},\ \{2,3\},\ \{1,2,3\}\}$$

## Cartesian Product

For sets $A$ and $B$, the **Cartesian product** $A \times B$ is the set of all ordered pairs $(a,b)$ with $a \in A$ and $b \in B$.

**Example:** Let $A = \{1,2,3\}$ and $B = \{4,5,6\}$. Then
$$A \times B = \{(1,4),(1,5),(1,6),(2,4),(2,5),(2,6),(3,4),(3,5),(3,6)\}$$
which has $|A|\cdot|B| = 9$ elements.

## Characteristic Vector of a Relation

- **Characteristic vector (indicator function):** For a finite universal set $U = \{u_1, \dots, u_n\}$ and a subset $S \subseteq U$, the characteristic vector of $S$ is the $n$-tuple $(x_1,\dots,x_n)$ where $x_i = 1$ if $u_i \in S$, and $x_i = 0$ otherwise.

A relation $R \subseteq A \times B$ is just a *subset* of the universal set $A \times B$, so we can describe it with a characteristic vector.

**Example (continued):** Define
$$R = \{(a,b) : a = b - 3,\ a \in A,\ b \in B\}$$
Checking each pair: $1 = 4-3$, $2 = 5-3$, $3 = 6-3$. So
$$R = \{(1,4),\ (2,5),\ (3,6)\}$$
Listing $A\times B$ in the order $(1,4),(1,5),(1,6),(2,4),(2,5),(2,6),(3,4),(3,5),(3,6)$, the characteristic vector of $R$ is:
$$R = \{1,0,0,\ 0,1,0,\ 0,0,1\}$$
Reshaped into a $3\times 3$ matrix (rows = values of $a$, columns = values of $b$):
$$M_R = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1\end{pmatrix}$$
This is exactly the **matrix representation of a relation**.

---

# Relations

## Definition of a Relation

A **relation** $R$ from set $A$ to set $B$ is any subset of the Cartesian product:
$$R \subseteq A \times B$$
(When $A = B$, we simply say "$R$ is a relation *on* $A$".)

## Properties of Relations

For a relation $R$ on a set $A$:

| Property | Definition |
|---|---|
| **Reflexive** | $\forall a \in A,\ (a,a) \in R$ |
| **Symmetric** | $(a,b) \in R \implies (b,a) \in R$ |
| **Anti-symmetric** | $(a,b) \in R \ \wedge\ (b,a) \in R \implies a = b$ |
| **Asymmetric** | $(a,b) \in R \implies (b,a) \notin R$ |
| **Transitive** | $(a,b) \in R\ \wedge\ (b,c) \in R \implies (a,c) \in R$ |

## Representing Relations

- **Matrix representation:** An $m \times n$ 0/1 matrix $M_{m\times n}$, exactly as constructed in the [characteristic vector](#characteristic-vector-of-a-relation) section.
- **Graph representation:** $G(V,E)$, with $V = A$ and an edge $a \to b$ whenever $(a,b) \in R$.
  - Reflexive relations show up as a **self-loop** at every vertex.
  - Symmetric relations can be drawn as an **undirected** graph, since every edge that exists, exists in both directions anyway.
  - Relations in general (including asymmetric ones) need a **directed** graph, since direction actually carries information.

## Composition of Relations

Let $R_1 \subseteq A \times B$ and $R_2 \subseteq B \times C$. Their **composition** $R_1 \circ R_2 \subseteq A \times C$ is defined by:
$$(a,b) \in R_1 \ \wedge\ (b,c) \in R_2 \implies (a,c) \in R_1 \circ R_2$$
If we call this composed relation $R_3 = R_1 \circ R_2$, then $R_3 \subseteq A \times C$, so its elements are **ordered pairs**:
$$(a,c) \in R_3$$

## Compatibility Relations

A relation is called a **compatibility relation** if it is **reflexive and symmetric** (transitivity is *not* required). This is a weaker notion than an equivalence relation — every equivalence relation is a compatibility relation, but not vice versa.

## Equivalence Relations and Equivalence Classes

A relation that is reflexive, symmetric, **and** transitive is an **equivalence relation**.

Given an equivalence relation $R$ on a set $A$, and $x \in A$, the **equivalence class** of $x$ is:
$$[x] = \{y \in A : x\,R\,y\}$$
For example, if $A = \{x,y,z,a,t,\dots\}$ and $x\,R\,y$, $y\,R\,x$, etc. hold, we might have:
$$[x] = \{x,y,z,\dots\}, \qquad [a] = \{a,\dots\}, \qquad [t] = \{t,\dots\}$$
and so on. The collection of all distinct equivalence classes,
$$\delta = \{[x],\ [a],\ [t],\ \dots\}$$
**is** a partition of $A$ (the individual classes $[x],[a],[t],\dots$ are called the **blocks** of the partition).

## Partitions and Coverings

- **Covering** of a set $A$: a collection of subsets $A_1, A_2, \dots, A_n$ such that their union is all of $A$:
$$\bigcup_{i=1}^{n} A_i = A$$
(the subsets are allowed to overlap).

- **Partition** of a set $A$: a collection of **non-empty**, **pairwise disjoint** subsets $A_1, \dots, A_n$ whose union is $A$:
$$A_i \cap A_j = \phi \ \text{ for all } i \ne j, \qquad \text{and} \qquad \bigcup_{i=1}^n A_i = A$$

## The Fundamental Theorem

**Theorem:** Given a set $A$ and an equivalence relation $R$ on $A$, the collection of equivalence classes
$$\delta = \{[x]_R : x \in A\}$$
is a partition of $A$ into disjoint, non-empty subsets.

**Converse:** If $P$ is a partition of $A$ into non-empty, disjoint subsets, then $P$ is precisely the set of equivalence classes of an equivalence relation $E$ defined on $A$ by:
$$a\, E\, b \iff a \text{ and } b \text{ belong to the same block of } P$$

## Congruence Modulo $n$

Integer modulo arithmetic underlies enumeration/indexing schemes in computer science; using a **prime** modulus specifically is common in hashing, OS memory allocation, etc. (fewer collisions).

**Definition:** For a fixed positive integer $n$ (the modulus) and integers $a,b$:
$$a\ R_n\ b \iff a - b = k n \ \text{ for some } k \in \Z$$
This is read "$a$ is congruent to $b$ modulo $n$" and is written $a \equiv b \pmod n$. It is an equivalence relation on $\Z$ (reflexive, symmetric, transitive). The related operation $b = a \bmod n$ returns the canonical remainder of $a$, i.e. the representative of $a$'s class in $\{0,1,\dots,n-1\}$.

**Example ($n = 5$):** this relation splits the integers into 5 equivalence (residue) classes:
$$[0] = \{0,5,10,\dots\},\quad [1]=\{1,6,11,\dots\},\quad [2]=\{2,7,12,\dots\},\quad [3]=\{3,8,13,\dots\},\quad [4]=\{4,9,14,\dots\}$$

*(If the domain is taken to be all of $\Z$ rather than just $\N$, each class also extends in the negative direction, e.g. $[0] = \{\dots,-10,-5,0,5,10,\dots\}$ — the non-negative-only listing above matches CS contexts like array indexing.)*

**General pattern:** for modulus $n$, each residue class $[r]$ (for $r = 0,1,\dots,n-1$) consists of exactly:
$$[r] = \{\, q\cdot n + r : q \in \Z \,\}$$

## Partial Order Relations (Posets)

A relation that is reflexive, anti-symmetric, and transitive is a **partial order**, and a set equipped with one is a **partially ordered set (poset)**.

**Example:** Let $A = \{2,3,6,12,24,36\}$ with the "divides" relation. This is a valid partial order (divisibility is reflexive, anti-symmetric, and transitive).

**Example:** The power set $2^P$ of any set $P$, ordered by set inclusion, is a poset:
$$(2^P,\ \subseteq)$$

## Hasse Diagrams

A **Hasse diagram** draws only the *covering* relations of a poset (i.e., direct "immediate successor" edges — redundant edges implied by transitivity are omitted), with "greater" elements placed higher.

**Example:** For $A = \{2,3,6,12,24,36\}$ under "divides":

```
         24    36
           \  /
            12
            |
            6
           / \
          2   3
```

## Lattices

A poset in which every pair of elements has both a unique **least upper bound** (join) and a unique **greatest lower bound** (meet) is called a **lattice**. The power set of any set, ordered by $\subseteq$, is always a lattice (join = union, meet = intersection).

**Example:** Let $P = \{1,2\}$. The poset $(2^P, \subseteq)$ forms the following lattice:

```
        {1,2}
        /   \
     {1}     {2}
        \   /
          ∅
```

---

# Propositional Logic

## Boolean Algebra and Propositions

**Boolean algebra:** the structure $(B, \neg, \vee, \wedge, \rightarrow, \leftrightarrow)$ where $B = \{0,1\}$.

A **proposition (statement)** is a declarative sentence that is either true or false (never both, never neither). Examples:

- $P$: "It is not raining today." — $P$ is a Boolean statement (true, say).
- $Q$: "JNU is in London." — $Q$ *is* a Boolean statement, and it's **false** (JNU is in Delhi).
- $R$, $S$: "Amit is in class" and "[Amit] is hungry." If both are true, then $R \wedge S$ is true.
- $T$: "Did Arnav come on time?" — **not** a Boolean statement (it's a question, not a declarative sentence).
- $U$: "Khushi may be the class rep." — **not** treated as a Boolean statement here, since "may be" expresses uncertainty rather than asserting a definite claim.

A **program** can be thought of as a set of propositions.

## Well-Formed Formulas (WFF)

A formula is a **WFF** if it is built using these rules:

1. Every propositional **constant** ($T,F$ or $1,0$) and every propositional **variable** ($P,Q,R,A,B,\dots$) is a WFF (these are the *atomic* WFFs).
2. If $A$ is a WFF, then $\neg A$ is a WFF.
3. If $A$ and $B$ are WFFs, then $A \vee B$ and $A \wedge B$ are WFFs.
4. If $A$ and $B$ are WFFs, then $A \rightarrow B$ and $A \leftrightarrow B$ are WFFs.

**Example:** Is $\neg P \vee Q$ a WFF?
- $P$ and $Q$ are WFFs by rule 1.
- $\neg P$ is a WFF by rule 2.
- $\neg P \vee Q$ is a WFF by rule 3.

## Truth Tables and Logical Equivalence

A **truth table** lists the truth value of a formula under every possible assignment of truth values to its variables. Two formulas are **(logically) equivalent** if they have identical truth tables — i.e., the same truth value under every assignment. We write $A \equiv B$ or $A \Leftrightarrow B$.

**Example 1:**
$$P \rightarrow R \ \equiv\ \neg P \vee R$$

**Example 2:**
$$P \leftrightarrow R \ \equiv\ (P \rightarrow R) \wedge (R \rightarrow P) \ \equiv\ (\neg P \vee R) \wedge (\neg R \vee P)$$

## Normal Forms, Tautology, Contradiction, Satisfiability

- **Disjunctive Normal Form (DNF):** a formula written as a *disjunction of conjunctions* (an "OR of ANDs").
- **Conjunctive Normal Form (CNF):** a formula written as a *conjunction of disjunctions* (an "AND of ORs").
- **Tautology:** a formula that is **True** under every truth assignment of its variables.
- **Contradiction:** a formula that is **False** under every truth assignment of its variables.
- **Satisfiable formula:** a formula that is True for **at least one** truth assignment (i.e., at least one row of its truth table is True).

## Laws of Logical Equivalence

| Law | $\vee$ form | $\wedge$ form |
|---|---|---|
| Idempotent | $P \vee P \Leftrightarrow P$ | $P \wedge P \Leftrightarrow P$ |
| Associative | $(P\vee Q)\vee R \Leftrightarrow P\vee(Q\vee R)$ | $(P\wedge Q)\wedge R \Leftrightarrow P\wedge(Q\wedge R)$ |
| Commutative | $P\vee Q \Leftrightarrow Q\vee P$ | $P\wedge Q \Leftrightarrow Q\wedge P$ |
| Distributive | $P\vee(Q\wedge R) \Leftrightarrow (P\vee Q)\wedge(P\vee R)$ | $P\wedge(Q\vee R) \Leftrightarrow (P\wedge Q)\vee(P\wedge R)$ |
| Identity | $P \vee F \Leftrightarrow P$ | $P \wedge T \Leftrightarrow P$ |
| Domination | $P \vee T \Leftrightarrow T$ | $P \wedge F \Leftrightarrow F$ |
| Complement | $P \vee \neg P \Leftrightarrow T$ | $P \wedge \neg P \Leftrightarrow F$ |
| Absorption | $P \vee (P \wedge Q) \Leftrightarrow P$ | $P \wedge (P \vee Q) \Leftrightarrow P$ |
| De Morgan's | $\neg(P\vee Q) \Leftrightarrow \neg P \wedge \neg Q$ | $\neg(P\wedge Q) \Leftrightarrow \neg P \vee \neg Q$ |
| Double Negation | $\neg(\neg P) \Leftrightarrow P$ | |
| Implication elimination | $P \rightarrow Q \Leftrightarrow \neg P \vee Q$ | |
| Contrapositive | $P \rightarrow Q \Leftrightarrow \neg Q \rightarrow \neg P$ | |

## Proving the Distributive Law by Truth Table

**Claim:**
$$R' \vee (P' \wedge Q') \ =\ (R' \vee P') \wedge (R' \vee Q')$$
(this is exactly the Distributive Law, with variables renamed $P\to R',\ Q\to P',\ R\to Q'$).

Let $X' = P' \wedge Q'$, $\ Y' = R' \vee P'$, $\ Z' = R' \vee Q'$, and finally $A' = R' \vee X'$, $\ B' = Y' \wedge Z'$. We must show $A' = B'$ for every combination of truth values.

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

Since the $A'$ and $B'$ columns agree on **every** row, $A' = B'$ is a tautology — the distributive law holds.

## Minterms and Maxterms

For a set of variables, a **minterm** is a *conjunction* containing every variable (each either plain or negated); a **maxterm** is a *disjunction* containing every variable (each either plain or negated).

- **Maxterms** (2 variables, e.g. $P,Q$): $P\vee Q,\ \ \neg P\vee Q,\ \ P\vee\neg Q,\ \ \neg P\vee\neg Q$.
 A maxterm is **False** for exactly **one** of the 4 possible assignments (when every literal in it is false) and **True** for the other 3 — i.e. it's "true unless all [its literals are] false."

- **Minterms** (2 variables): $P\wedge Q,\ \ \neg P\wedge Q,\ \ P\wedge\neg Q,\ \ \neg P\wedge\neg Q$.
 A minterm is **True** for exactly **one** of the 4 possible assignments (when every literal in it is true) and **False** for the other 3 — i.e. it's "false unless all [its literals are] true."

Minterms and maxterms are the building blocks of the two canonical normal forms: a **canonical DNF** is a disjunction ("OR") of minterms, and a **canonical CNF** is a conjunction ("AND") of maxterms.