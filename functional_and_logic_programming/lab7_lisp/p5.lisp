(defun solve(x)
	(cond
		((and (numberp x) (equal (mod x 2) 0)) x)
		((and (numberp x) (equal (mod x 2) 1)) (* -1 x))
		((atom x) x)
		(T (apply '+ (mapcar 'solve x)))
	)
)