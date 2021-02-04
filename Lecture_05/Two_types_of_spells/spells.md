# Solution

Assume that we have **n** fire spells and **m** lightning spells. The maximum damage is obtained if we double the m spells with maximum damage.
We keep the set S of largest by power spells and the set T to store all the other ones. The maximum damage is reached if we oduble all the spells in S and this it's possible only if it contains at least one fire spells (we need the first lightning spell to start the chain of doubling) otherwhise we need to double m-1 spells from s and the max damage spell from T.

At each change simply readjust the two sets in order to keep the properties wanted intact. We also need to keep track of the number of fire spells and how many of them are in S.

## Time complexity

O(nlogn) where n is the total number of changes

## Space complexity

O(n) to store the two sets.