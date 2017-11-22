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

