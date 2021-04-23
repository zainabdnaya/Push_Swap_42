# push_swap
sort data on a stack, with a limited set of instructions, using the lowest possible number of actions

## Concept of this Project ##

 The idea is simple, You have two stacks called Stack A and Stack B. <br>
 Stack A is given a random list of unorganized numbers.  <br>
 You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest. <br> 
 There are only a few moves you’re allowed to used to manipulate the stacks that we’re going to call “Actions”.  <br>
 The main goal of this project is to organize Stack A in as few actions as possible. <br>

 ## MOVES ##

the moves are named:  sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb.<br>
I use Double linked list to implement these moves :<br>

## sa || sb :arrows_clockwise:  ##
    -swap 2 first element
<a href="https://ibb.co/wC6FY2V"><img src="https://i.ibb.co/828LXQq/Screen-Shot-2021-04-03-at-12-44-32-PM.png" alt="Screen-Shot-2021-04-03-at-12-44-32-PM" border="0"></a>
##  :arrow_heading_up: ra || rb :arrow_right_hook:	 ##
    -put the first element last,and all elemnt go UP by one 
<a href="https://ibb.co/9ggTtbY"><img src="https://i.ibb.co/YQQkZcj/Screen-Shot-2021-04-03-at-2-51-42-PM.png" alt="Screen-Shot-2021-04-03-at-2-51-42-PM" border="0"></a>

##  :arrow_heading_down: rra || rrb :arrows_counterclockwise: ##
    -put the last element First, so all elements go DOWN by ine element 
<a href="https://ibb.co/k6NrLj8"><img src="https://i.ibb.co/KzTQtdq/Screen-Shot-2021-04-03-at-5-26-13-PM.png" alt="Screen-Shot-2021-04-03-at-5-26-13-PM" border="0"></a>

## pa || pb :arrow_right: ##
    -take the first element at the top of a stack and put it at the top of other_stack.
<a href="https://ibb.co/Byf5G3C"><img src="https://i.ibb.co/qND3Cjr/Screen-Shot-2021-04-03-at-6-41-55-PM.png" alt="Screen-Shot-2021-04-03-at-6-41-55-PM" border="0"></a>
<a href="https://ibb.co/j4Kjp2F"><img src="https://i.ibb.co/kcnPdfF/Screen-Shot-2021-04-04-at-3-27-57-PM.png" alt="Screen-Shot-2021-04-04-at-3-27-57-PM" border="0"></a>

## Checker:
    -Thanks to the checker program, you will be able to check if the
    list of instructions you’ll generate with the program push_swap is
    actually sorting the stack properly.

## This is how much instriction the algorithm Do with 100 random number 
<a href="https://ibb.co/TTbfy6W"><img src="https://i.ibb.co/j5WNtmJ/Screen-Shot-2021-04-11-at-2-46-15-PM.png" alt="Screen-Shot-2021-04-11-at-2-46-15-PM" border="0"></a>

<a href="https://ibb.co/Rb0SvY5"><img src="https://i.ibb.co/jfM56bp/Screen-Shot-2021-04-11-at-2-33-56-PM.png" alt="Screen-Shot-2021-04-11-at-2-33-56-PM" border="0"></a>

## To Test
 Try to use : ./push_swap -h "this command will show what to do " 
