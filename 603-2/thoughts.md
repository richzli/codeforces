# ROUND 603

A - 0:14

B - 0:22, failed system test

C - 1:15

D - 1:51

E - N/A

F - N/A

## THOUGHTS

Goddamnit, Python. Y'all's too slow.

The first four were all easy problems, but I spent so much time wrangling inefficiencies out of my code. It got so bad that in D, I had to **rewrite my code in Java** to get it under the time limit. In total, I think I wasted around 700+ points (including the extra time taken to make it more efficient). Maybe I should just switch to Java. At the same time, though, I'll be learning C next semester, which will probably be better. Or maybe learn C++/C#?

On closer inspection, I don't think codeforces gives extra time for different languages. Yikes. Python bad.

A was harder than I thought.

I think for B, I trolled a little bit and didn't think of the case 0000 -> 0001, 0001 -> 0002 instead of 0000 -> 0002. That could have been solved by using a set or something. Actually,

```python
codes = <input>
codesset = set(codes)
print(10-len(codesset))
```

probably would have worked, with some modifications to get the new PINs. I'm sort of dumb.

C was messy.

I was pleasantly surprised that I was still able to rememeber how to use union-find for D. I haven't touched that in some time.

E looked very segment-tree-like to me. I didn't have enough time to solve it, though, or even take a closer look (I just read the problem description once), but that was just my initial reaction.

Overall: annoyed that I didn't get B right, satisfied that I got D right, annoyed that Python sucks.
