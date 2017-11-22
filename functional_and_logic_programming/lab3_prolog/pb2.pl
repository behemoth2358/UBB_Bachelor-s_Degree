/*
#Substitute all occurrences of an element of a list with all the elements of another list.
#Eg. subst([1,2,1,3,1,4],1,[10,11],X) produces X=[10,11,2,10,11,3,10,11,4].
*/



subst([], _, _, ResultList) :-
	ResultList = [].

subst([H | T], X, YList, ResultList) :-
	subst(T, X, YList, AuxResultList),	
	push_back_correct_item(H, X, YList, AuxResultList, AuxRes),
	ResultList = AuxRes.

push_back_correct_item(H, X, YList, List, Res) :-
	H =:= X,
	append(YList, List, Res).

push_back_correct_item(H, X, _, List, Res) :-
	H =\= X,
	Res = [ H | List ].


/*
# For a heterogeneous list, formed from integer numbers and list of numbers, replace in every sublist all
# occurrences of the first element from sublist it a new given list.
# Eg.: [1, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] si [11, 11] =>
# [1, [11, 11, 1, 11, 11], 3, 6, [11, 11, 10, 1, 3, 9], 5, [11 11 11 11 11 11], 7]
*/

subst2([], _, ResultList) :-
	ResultList = [].

subst2([H|T], YList, ResultList) :-
	subst2(T, YList, AuxResultList),
	handleElem(H, YList, AuxResultList, Res),
	ResultList = Res.

handleElem(H, _, List, Res) :-
	not(is_list(H)),
	Res = [H | List].

handleElem(H, YList, List, Res) :-
	is_list(H),
	subst_first_elem_occ(H, YList, ARes),
	Res = [ARes | List].

subst_first_elem_occ([H|T], YList, Res) :-
	subst([H|T], H, YList, Res).
