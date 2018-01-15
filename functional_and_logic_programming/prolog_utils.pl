/* returns the number of occurrences of a given element in list */
list_cnt_occurrences([], _, 0).

list_cnt_occurrences([H | T], Elem, Result):-
	list_cnt_occurrences(T, Elem, AuxResult),
	list_cnt_occurrences_compute_res(H, Elem, AuxResult, Result).

list_cnt_occurrences_compute_res(H, Elem, AuxResult, Result):-
	H =:= Elem,
	Result is AuxResult + 1.

list_cnt_occurrences_compute_res(H, Elem, AuxResult, Result):-
	H =\= Elem,
	Result is AuxResult.


/* returns a set obtained from a given list */
list_to_set([], []).

list_to_set([H | T], Result):-
	list_to_set(T, AuxResult),
	list_cnt_occurrences(AuxResult, H, Cnt),
	list_to_set_compute_res(H, Cnt, AuxResult, Result). 

list_to_set_compute_res(H, Cnt, AuxResult, Result):-
	Cnt =:= 0,
	Result = [H | AuxResult].

list_to_set_compute_res(_, Cnt, AuxResult, Result):-
	Cnt =\= 0,
	Result = AuxResult.

/* removes all occurrences of a given element from a given list */
/* Version 1 */
list_remove([], _, []).

list_remove([H | T], Elem, Result):-
	list_remove(T, Elem, AuxResult),
	list_remove_check_and_add(H, Elem, AuxResult, Result).

list_remove_check_and_add(H, Elem, AuxResult, Result):-
	H =:= Elem,
	Result = AuxResult.

list_remove_check_and_add(H, Elem, AuxResult, Result):-
	H =\= Elem,
	Result = [H | AuxResult].


/* Version 2 */
list_rm([], _, []).

list_rm([H | T], Value, [H | R]):-
	H =\= Value,
	list_rm(T, Value, R).

list_rm([H | T], Value, R):-
	H =:= Value,
	list_rm(T, Value, R).

/* computes the greatest common divisor between 2 given numbers */
gcd(0, _, Result):-
	Result is nil.

gcd(A, 0, Result):-
	Result is A.

gcd(A, B, Result):-
	B =\= 0,
	M is mod(A, B),
	gcd(B, M, AuxResult),
	Result is AuxResult.

/* computes the lowest common multiple between 2 given numbers */
lcm(A, B, Result):-
	Prod is A * B,
	gcd(A, B, Gcd),
	Result is Prod / Gcd.

/* computes the lowest common multiple between all elements from a given list */

list_lcm([H], Result) :-
	Result is H.

list_lcm([H | T], Result):-
	list_lcm(T, AuxResult),
	lcm(H, AuxResult, Result).

/* computes the greatest common divisor between all elements from a given list */

list_gcd([H], Result) :-
	Result is H.

list_gcd([H | T], Result):-
	list_gcd(T, AuxResult),
	gcd(H, AuxResult, Result).

/* returns the max element between 2 given values */

max(A, B, Result):- A >= B, Result is A.
max(A, B, Result):- A < B, Result is B.

/* returns the min element between 2 given values */

min(A, B, Result):- A >= B, Result is B.
min(A, B, Result):- A < B, Result is A.

/* returns the max element from a given list */

list_max([H], H).

list_max([H | T], Result):-
	list_max(T, AuxResult),
	max(H, AuxResult, Result).

/* returns the min element from a given list */

list_min([H], H).

list_min([H | T], Result):-
	list_min(T, AuxResult),
	min(H, AuxResult, Result).

/* removes the first k occurrences of a given element from a given list */

list_k_rm([], _, _, []).

list_k_rm([H | T], _, 0, [H | T]).

list_k_rm([H | T], Elem, K, R):-
	K > 0,
	Elem =:= H,
	KK is K - 1,
	list_k_rm(T, Elem, KK, R).

list_k_rm([H | T], Elem, K, [H | R]):-
	K > 0,
	Elem =\= H,
	list_k_rm(T, Elem, K, R).

/* returns a list with the positions of a given element in a given list */

list_find_idxes(Lst, Elem, Result):-
	lst_find_idxes(Lst, Elem, 0, Result).

lst_find_idxes([], _, _, []).

lst_find_idxes([H | T], Elem, Index, [Index | R]):-
	H =:= Elem,
	NextIndex is Index + 1,
	lst_find_idxes(T, Elem, NextIndex, R).

lst_find_idxes([H | T], Elem, Index, R):-
	H =\= Elem,
	NextIndex is Index + 1,
	lst_find_idxes(T, Elem, NextIndex, R).

/* Sorts desc. of a given list */

list_sort_desc([], []).

list_sort_desc([H | T], Result):-
	list_max([H | T], Max),
	list_k_rm([H | T], Max, 1, AuxList),
	list_sort_desc(AuxList, AuxResult),
	Result = [Max | AuxResult].

/* Sorts asc. of a given list */

list_sort_asc([], []).

list_sort_asc([H | T], Result):-
	list_min([H | T], Max),
	list_k_rm([H | T], Max, 1, AuxList),
	list_sort_asc(AuxList, AuxResult),
	Result = [Max | AuxResult].

/* Returns the sum of all elements from a list */

list_sum([], 0).

list_sum([H | T], R):-
	list_sum(T, AuxR),
	R is AuxR + H.

/* returns 1 or 0 if the given number is prime or not */

is_prime(Number, Result):-
	Number < 2,
	Result is 0.

is_prime(Number, Result):-
	Number >= 2,
	check_prime(2, Number, Result).

check_prime(It, Number, Result):-
	It =:= Number,
	Result is 1.

check_prime(It, Number, Result):-
	It < Number,
	M is mod(Number, It),
	M =:= 0,
	Result is 0.

check_prime(It, Number, Result):-
	It < Number,
	M is mod(Number, It),
	M =\= 0,
	NextIt is It + 1,
	check_prime(NextIt, Number, Result).

/* returns the number of occurrences at all levels of a given atom in a given heterogenous list */

hlist_cnt_occurrences([], _, 0).

hlist_cnt_occurrences([H | T], Elem, Result):-
	is_list(H),
	hlist_cnt_occurrences(H, Elem, AuxResult1),
	hlist_cnt_occurrences(T, Elem, AuxResult2),
	Result is AuxResult1 + AuxResult2.

hlist_cnt_occurrences([H | T], Elem, Result):-
	not(is_list(H)),
	H =:= Elem,
	hlist_cnt_occurrences(T, Elem, AuxResult),
	Result is AuxResult + 1.

hlist_cnt_occurrences([H | T], Elem, Result):-
	not(is_list(H)),
	H =\= Elem,
	hlist_cnt_occurrences(T, Elem, Result).
/* length of a normal list */

list_length([], 0).

list_length([_ | T], R):-
	list_length(T, AuxR),
	R is AuxR + 1.


/* list index delete */

list_index_delete([], _, _, []).

list_index_delete([H | T], Index, Count, [H | R]):-
	Count =\= Index,
	Cnt is Count + 1,
	list_index_delete(T, Index, Cnt, R).

list_index_delete([_ | T], Index, Count, T):-
	Count =:= Index.

/* combinations of k elements */

comb(_, 0, []).

comb([H | T], K, [H | R]):-
	K > 0,
	KK is K - 1,
	comb(T, KK, R).

comb([_ | T], K, R):-
	K > 0,
	comb(T, K, R).

/* all posibilities to insert an element in a list */

minsert([], E, [E]).

minsert([H | T], E, [E, H | T]).

minsert([H | T], E, [H | R]):-
	minsert(T, E, R).


/* permutations */
perm([], []).

perm([H | T], R):-
	perm(T, AuxR),
	minsert(AuxR, H, R).

/* arrangements of k elements */

arr(L, K, R):-
	comb(L, K, AuxR),
	perm(AuxR, R).






