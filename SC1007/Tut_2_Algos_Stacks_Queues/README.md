# Tutorial 2: Analysis of Algorithms and Stacks and Queues

## Q1: 
Worst case: θ(mn), where m is the length of the first list, and n is the length of the second.

This worst case will happen when the first linked list is a subset of the second linked list, and the first linked list is filled with the last integer of the second linked list.

To illustrate, eg.

- List1: [1, 1, 1, 1, 1, 1]
- List2: [3, 2, 4, 2, 5, 6, 1]

## Q2a
For this question, we'll assess the loops one by one. Removing the inner loop, we have
```c
void Q2a (int N) {
  int j;
  for (j =1; j <= N;j *=3)
    printf (" SC1007 \n");
  }
```

As N increases in size, as j increases exponentially, the number of times that "SC1007" gets printed grows in a logarithmic manner. Θ(logN)

Now we insert the inner loop
```c
void Q2a (int N) {
  int j, k;
  for (j =1; j <= N;j *=3)
    for (k =1; k <= N; k *=2)
      printf (" SC1007 \n");
  }
```

As N increases in size, both j and k increase exponentially, hence the number of times that "SC1007" gets printed grows in a logarithmic^2 manner. Θ((logN)^2)

## Q2b
```c
void Q2b (int N) {
  int i;
  if(N >0) {
    for (i =0; i < N;i ++)
      printf (" SC1007 \n");
    Q2b (N -1);
    Q2b (N -1);
  }
}
```

For this question, we analyse as N grows:
- N = 0: W0 = 0
- N = 1: W1 = 1
- N = 2: W2 = 2 + W1 + W1 = 2 + 1 + 1 = 4
- N = 3: W3 = 3 + W2 + W2 = 3 + 4 + 4 = 11
- N = 4: W4 = 4 + W3 + W3 = 26

Every function call involves a for loop (Θ(N)) as well as 2 recursion calls (Θ(2^N))

Hence, The time complexity is Θ(N * 2^N)
