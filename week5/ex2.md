## Exercise 2

> Part 1.

Three times loop running in the background:
Before the first `pstree` command `a.out` forks and creates its copy.  \
After that it 2 processes make copies of themself.\
Before the third `pstree` all four process create its copies. \
In the end we have 8 processes.

> Part 2.

Like in first part algorithm is the same. \
So in the end we have `8*2*2=32` processes. 
