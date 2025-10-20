# Pairings

The goal is to generate pairs of numbers, each time doubling in size, until we cannot form any more pairs.

A pair is defined as two parts, each part containing an equal number of elements

The remaining, left-out elements will be left untouched

1 3 5 7 9 splits into 1 3 and 5 7, as well as 9 which will be ignored

The size of the pairs starts at

Elements = 1
Size of pair = elements \* 2

The next step
Elements = 2
Size of pair = elements \* 2 = 4

Elements = 4
Size of pair = elements \* 2 = 8

So it starts at 1, then doubles to 2, then doubles to 4, etc.

The important thing is to form as many pairs as possible

Two ways:

We can calculate beforehand, how many pairs we can form. This can be done by:

Check our number of elements, then divide by our pair size. If we have 9 elements, and our element size is 1, pair size is 2, then
9 / 2 = 4.5, but they're always ints, so concatenate to 4

That means that, for 9 elements, we can make 4 pairs

Do we need to keep track of the remainder or how many elements have been paired?

Another way we can calculate is by doing it on the fly. So, we create as many pairs as we can, until we cannot create any more

So, for 9 elements, we try to create 1 pair, that works. We have 7 elements left. Let's create another pair. 5. 3, then we have only 1 element left. We cannot create a pair with this number of elements, as elements < pair size

This method requires a lookahead. We need to see if we index out.

Because there is one more problem. It would be impractical to create a new vector for each pair, as it would require an array of vectors, or a vector of vectors.

An easier method would be to use indexing, because the positions of all the elements are already known

With the first method, we can calculate the indexes of all the pairs beforehand.

A formula can be used. We start from index 0. The first pair will always be at index 0. The formula is pair_size \* pair_number.
The first pair will be pair 0. For 4 pairs, they will have pair numbers 0-3.

Assume we have pair size of 2. For the fourth pair, pair_number = 3, the fourth pair will start at 2 \* 3 = 6

Another challenging point is swapping pairs larger than one digit. We need to know the pair size we are swapping.

For example, with 8 6 4 2 7 5 3 1 0, we can reach the second level, where we have pairs that are size 4

After swapping, we get 6 8 2 4 5 7 1 3 0. Using the formula pair size \* pair_number, the first pair is 0, and the second pair is 4 \* 1 = index 4

[6 8, 2 4], [5 7, 1 3]. Ignoring the 0 at the end. We can see that elements is 2 now, and pair size is 4.
0 1 2 3 4 5 6 7

We always swap according to the last number in the element. What is the index of that last number?

Pair size = 4
Elements = 2

Each element in each pair has a size of 2.

We know that the start index of the first pair is 0, and the start index of the next pair is 4

We know that the first and last from the first pair is 1 and 3. How do we get there?

[16 15] [14 13] [12 11] [10 9] [8 7] [6 5] [4 3] [2 1]

[[15 16][13 14]], [[11 12][9 10]], [[7 8][5 6]], [[3 4][1 2]]

Index of last elements in first pair is 1 and 3, when pair size = 4 and elements = 2

[ [ [13 14][15 16] ][ [9 10][11 12] ] ], [ [ [5 6][7 8]][[1 2][3 4] ] ]

Index of last elements in first pair is 3 and 7, when pair size = 8 and elements = 4

Could we try elements _ pair_number + elements - 1 = (4 _ 0) + (4) - 1 = 3 for last element in first half of first pair, and
elements _ pair_number + elements _ 2 - 1 = (4 _ 0) + (4 _ 2) - 1 = 7

Next pair:
elements _ pair_number + elements - 1 = (4 _ 1) + 4 - 1 = 7 wait that's not right
