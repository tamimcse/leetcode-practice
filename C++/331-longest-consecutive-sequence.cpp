/*
https://leetcode.com/problems/longest-consecutive-sequence/

Very very intersing problem!!!

Problem isn't very clear. What does it mean by sequnce? Here, they mean longest range where each element of the range is a member of the array.

Sometimes, you may come across a problem where you need to check if you came through this path. This problem particularly arise in sequence building. In that, check if you can solve this using DFS/BFS. Usually you can. An example of such problem is longest-consecutive-sequence.

But, note that, when you really want to create a sequence, do you really need to start from the any node. For instance, in longest-consecutive-sequence problem, you are given an array. The first element of the array may not be the first element of the sequence. This is why, you may need to look both ways to create sequence. Solving this problem with DFS and BFS also involve havinhg visit array so that we don't visit an element if we visited before. But, all this problem can be simplified if we only start with elements that's the start of a sequence. In that case, we don't need to look bi-directionally. We only look unidirectionally. For instance, Approach #3

https://leetcode.com/problems/longest-consecutive-sequence/solution/


But, implememnt it using both DFS and better approch. DFS will get TLE though.
*/
