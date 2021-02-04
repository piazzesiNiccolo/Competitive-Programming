# Solution 

We store the position of the frogs in a BST. When a mosquito lands on position b, to know which frog eats it we simply do a **predecessor(b)** query on the tree.

This base solution needs to be adjusted to account for three main issues:

- *Overlapping segments* 

    Each frog can cover  the segment(p, p+tongue). To enforce that the leftmost frog has the priority on the landing mosquito we preprocess the segments to force no overlap.
    
    If two frogs share a common segment the rightmost frog gets moved and is assigned the segment (r+1, r+1+tongue) where r is the maximum distance reached by the tongue of the left frog.

- *Dynamic segments*
    
    When a frog eats it's tongue grows which means that it now can cover a longer segment.This new segment might fully contain other segments (found with a successor query). 
    
    In this case we simply delete the contained segments from the tree(this frog can never eat). 
    
    If the new segment partially overlaps with another we reuse the solution used for the first issue.

- *Uneaten mosquitoes* 

    A mosquito may be uneaten when it first lands. We store uneaten mosquitoes in another BST. 
    
    When a frog eats we check on this tree if the frog can eat other mosquitoes. This can be found with a successor query.

## Time complexity

Assume that we have n frogs and m mosquitoes.

Each predecessor query on the frog tree can be answered in O(log n) time.

Forcing no overlap in the starting segments takes O(n).

Changing dynamic segments has an overall complexity of O((n+m)log n) time because the initial segments are not overlapping and remove n segments at most.

Searching for uneaten mosquitoes takes O( m log m) time overall because we can search for a maximum of m mosquitoes.

## Space complexity

O(n) to store the two trees.
