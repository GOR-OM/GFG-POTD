<h2><a href="https://www.geeksforgeeks.org/problems/arrays-game0327/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Array's Game</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array A of N integers. Two players play a game with the array in turns. The game aims to make the array equal. Players add 1 to any number of the array to increase it by 1(except the maximum number). The player who adds last i.e. the player after whose turn the array becomes equal is declared the winner. If no moves can be made, the game is a draw.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=2
A[]={1,2}
<strong>Output:</strong>
First
<strong>Explanation:</strong>
The first player adds 1 to the first 
number making it 2. The array 
becomes equal, so he is the winner.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=3
A[]={2,2,2}
<strong>Output:</strong>
Draw
<strong>Explanation:</strong>
No moves can be made as all the elements are
already maximum and numbers cannot be
added to the maximum numbers.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function arrayGame() which takes an integer N and an integer array A as input parameters and returns a string denoting the result of the game. ("Draw" if the game is a draw, "First" if the first player and "Second" otherwise).</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N)<br>
<strong>Expected Auxillary Space:&nbsp;</strong>O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=10<sup>6</sup><br>
1&lt;=A[i]&lt;=10<sup>9</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Game Theory</code>&nbsp;<code>Algorithms</code>&nbsp;