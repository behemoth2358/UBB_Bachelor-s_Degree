/*
Define a predicate to determine the greatest common divisor of all numbers in a list.
*/

gcd(0, _, _) :- 
	true.

gcd(X, 0, Result) :-
	Result is X.

gcd(X, Y, Result) :- 
	Z is mod(X, Y),
	gcd(Y, Z, Result).

list_gcd([], _) :-
	true.

list_gcd([H|[]], Result) :-
	Result is H.

list_gcd([H|T], Result) :-
	list_gcd(T, Aux),
	gcd(H, Aux, Result).
	
