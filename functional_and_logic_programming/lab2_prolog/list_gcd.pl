/*
Define a predicate to determine the greatest common divisor of all numbers in a list.
*/

gcd(X, 0, Result) :-
	X =\= 0,
	Result is X.

gcd(X, Y, Result) :- 
	Y =\= 0,
	Z is mod(X, Y),
	gcd(Y, Z, Result).

list_gcd([], _) :-
	true.

list_gcd([H|[]], Result) :-
	Result is H.

list_gcd([H|T], Result) :-
	list_gcd(T, Aux),
	gcd(H, Aux, Result).
	
