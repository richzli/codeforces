#ROUND 601

A - 0:11
B - 1:40
C - N/A
D - N/A
E1 - N/A
E2 - N/A
F - N/A

##A WRITEUP
Fairly simple. You always want to press the largest button possible, so you first press 5 as many times as possible, then 2 as many times as possible, then 1 if needed. Notice that you only ever want to press buttons in one direction, so the sign of the difference between the two volumes can be ignored.

##B WRITEUP
First thing to notice is that each fridge must be connected with two chains from two other fridges. We can let the connections be a loop around all fridges, which would require n chains. If there are less than n chains, then we can't lock all the fridges securely, since then at least one fridge will have less than 2 chains connected.
And finally, since each fridge is chained exactly two times, the total cost will be 2*(sum of fridge weights).

##THOUGHTS
First codeforces contest, feeling a bit rusty. I solved A pretty easily, which was good, but I gave up on B without realizing how easy it was. The original version was just as easy; you just needed to chain the two smallest-weight fridges with any excess chains. I should have solved it way earlier in the contest.

C was a tricky one. I initially thought of an O(n^2) solution, and immediately started coding without thinking about optimizations. Of course it didn't work (10^5 is too large), so I tried working on a O(n) solution, but time ran out.
My thinking for the O(n) solution goes like this:
1. put triplets in a map corresponding to number
1. find the number with only one triplet and set that as the start (the first number will only be in a single triplet)
1. take the other two numbers in the first triplet and check for the triplet containing both of them
1. repeat
   1. we don't know which number in the two will be the next one, so just test each of them; only one of the numbers should have two matches
From the correct order of sets, we can derive a correct ordering. (The other correct ordering is simply the reverse.)

All in all, it wasn't terrible. I just know I could have done better.
