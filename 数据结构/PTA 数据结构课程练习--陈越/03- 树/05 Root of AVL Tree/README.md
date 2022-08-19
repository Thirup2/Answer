# Root of AVL Tree
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
<div align=center><img src="https://images.ptausercontent.com/d265ae37-4348-4585-b39f-0b2e2e0a24f5.jpg"></div>
<div align=center><img src="https://images.ptausercontent.com/4a9f6fbd-e21e-4493-834d-7782e13bee4e.jpg"></div>
<div align=center><img src="https://images.ptausercontent.com/7dc0e66f-c458-4c92-bb8e-55b7bf6391ce.jpg"></div>
<div align=center><img src="https://images.ptausercontent.com/b17a9687-6be8-4256-873d-6a747154a58d.jpg"></div>

Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

### Output Specification:
For each test case, print the root of the resulting AVL tree in one line.

### Sample Input 1:
```
5
88 70 61 96 120
```
### Sample Output 1:
```
70
```
### Sample Input 2:
```
7
88 70 61 96 120 90 65
```
### Sample Output 2:
```
88
```