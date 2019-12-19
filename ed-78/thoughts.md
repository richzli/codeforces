# ROUND ED-78

I need to improve putting my thoughts into code. Might look at official solutions later and code them up.

B was ad hoc math problem, which I'm not very good at (and failed at).

For C, you can sort of think of it as taking jars from the end, and keeping the number of blue/red even.

D, I found a n^2, but it looks like it's not efficient enough? I don't think a segment tree would have helped. Tried 

E is actually really easy, but I just can't code it. You just set some root node, and for each node after that set the number of empty points inside (for example, 4-6 would have an empty point 5 inside) each segment equal to the number of connections. You "latch on" connections from the right. So for example this would be a tree:

```
|--| 2 connections
  |--| 2 connections
    |-| 1 
 |------| 2 (connected to the leftmost empty spot in the first segment, must fully enclose the other branch)
       |---| 3
          |-| 1
         |---| 1
```

corresponding to
```
1 2
2 3
1 4
4 5
5 6
5 7
```

F is modular exponentiation (i think).