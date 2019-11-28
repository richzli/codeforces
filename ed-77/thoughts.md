# ROUND ED 77

A - 0:06

B - 0:11

C - 0:39

D - N/A

E - N/A

F - N/A

## THOUGHTS

Holy moly, so much ad hoc.

D is actually more difficult than I thought. I tried a few solutions but they all failed before I realized that mine didn't work for various reasons. However, the solution goes something like this (I think?):

1. Treat each trap as a line segment. If two traps intersect, then merge the two traps into one large trap with r = max(r1, r2). That trap will take 2\*(l-r) to traverse.
2. Sort the traps from greatest difficulty to lowest difficulty. Start with time taken tt = n+1.
3. For each trap, update the min skill needed (which is equal to the trap danger) and add the traversal time to the total time needed. Before it goes over the max time, stop.
4. Choose all soldiers such that their skill is greater or equal to the min skill, and output.

There's probably still some problems with that, actually, now that I think about it. Whatever.

E is more manageable, I just couldn't think of an efficient way to code it.

1. Bribe the strongest guy. (If he's your friend, total cost = 0) Remove that guy from the list.
2. Have that guy be in one half of the bracket, and your friend in the other half. The strongest guy can take out n//2-1 people stronger than your friend. (If there are less than n//2-1 people stronger than your friend, then only the one bribe is needed.) The strongest guy should take out the people with the biggest bribes.
3. Repeat.

The constraints were n < 2^18, so I think a naive solution wouldn't have worked? I didn't try though; by that time I had spent so much time on D I don't think I would have had the brainpower to do it.
