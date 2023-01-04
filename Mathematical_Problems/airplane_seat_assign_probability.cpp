// https://leetcode.com/problems/airplane-seat-assignment-probability/description/

double nthPersonGetsNthSeat(int n)
{
    if (n == 1)
        return 1.0;
    return 0.5;
}


Explanation:
	Lets take, n=100
	when last person e.i 100th person comes he will have only two choices, either sit on 1st seat  or 100th  seat.  Why?
	
    Lets Prove this By contradiction,
    suppose person 100th chooses seat number x ,    2<= x<=99
    that means seat x is free and since 100th person is last to come that means x person has already been arrived
    but if the seat x was free then person number x was supposed to sit on seat x only according to problem statement.
    So this contradict the choice of Person 100th sitting on any seat between 2 to 99
    therefore 100th person can only sit on either 1st or 100th seat.

    Now probability of position 100th being free for 100th person is half(1/2).
    why?
    Since It is clear that position 2 to 99 has been already filled. Hence we can suppose that out of those previous 99 persons ,
    one is sitting either on seat number 100 or 1. 
    Let's suppose this person is y.
    so choice between seat 1 or seat 100 is equally likely for y. 
    Hence probability of y choosing seat 1 or 100 is 1/2 and Hence probability of 100th person sitting on 100th seat is also 1/2.
    and this will hold true for every n>=2.

