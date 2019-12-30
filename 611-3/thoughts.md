# ROUND 611

I thought this thing started at 9:35, not 9:05, so I lost 30 minutes.

I spent way too much time on C. "Why is this not working?? n<2*10^5 and my solution is O(n)??" Turns out list::remove(int) is also O(n), so my solution was secretly O(n^2). Lost around 25 minutes debugging that. Things to note: use list::erase(iterator) instead.

D looked do-able? You would fill people in around the trees; if two tree-blobs intersect, join the blobs and store the left-most and right-most trees? Not sure how time-efficient/memory-efficient that would be, and what would implementation even look like? I'll take a look at the official solution later.

EDIT: My C got hacked :(, if that `else` on line 58 didn't exist it would have been a correct solution...