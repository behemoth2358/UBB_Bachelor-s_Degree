% Are given n points in a plan (represented using its coordinates). 
% Write a predicate to determine all subsets of collinear points.

subs([], []).

subs([_ | T], Res):-
	subs(T, Res),
	collinear(Res).

subs([H | T], [H | Res]):-
	subs(T, Res),
	collinear([H | Res]).

triangle_area([X1, Y1], [X2, Y2], [X3, Y3], Res):-
	Res is X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2).

collinear([]).

collinear([_]).

collinear([_, _]).

collinear([H1, H2, H3 | T]):-
	triangle_area(H1, H2, H3, Area),
	Area =:= 0,
	collinear([H2, H3 | T]).

