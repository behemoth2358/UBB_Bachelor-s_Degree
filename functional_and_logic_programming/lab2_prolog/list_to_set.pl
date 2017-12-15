/*
Transform a list in a set, in the order of the last occurrences of elements. 
Eg.: [1,2,3,1,2] is transformed in [3,1,2].
*/

count_occurences([], _, Result) :-
	Result is 0.

count_occurences([H|T], X, Result) :-
	H =:= X,
	count_occurences(T, X, AuxResult),
	Result is AuxResult + 1.

count_occurences([H|T], X, Result) :-
	H =\= X,
	count_occurences(T, X, Result).

list_to_set([], Result) :-
	Result = [].

list_to_set([H|T], Result) :-
	list_to_set(T, AuxResult),
	count_occurences(AuxResult, H, Occurrences),
	add_in_set(AuxResult, H, Occurrences, Result).

add_in_set(Set, Elem, Occurrences, ResultSet) :-
	Occurrences =:= 0,
	ResultSet = [Elem|Set].

add_in_set(Set, _, Occurrences, ResultSet) :-
	Occurrences =\= 0,
	ResultSet = Set.

	