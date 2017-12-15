;;;;Write a function to return the product of all numerical atoms in a list, at any level.

(defun product (collection)
	(cond
		((null collection) 1)
		((numberp (car collection)) (* (car collection) (product (cdr collection))))
		((listp (car collection)) (* (product (car collection)) (product (cdr  collection))))
		(T (product (cdr collection)))
	)
)