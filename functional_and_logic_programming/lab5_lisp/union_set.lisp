;;;; Write a function to return the union of two sets

(defun is_in_list (collection elem)
	(cond
		((null collection) 0)
		((equal (car collection) elem) 1)
		(T (is_in_list (cdr collection) elem))
	)
)

(defun union_set (first_set second_set)
	(cond
		((null second_set) first_set)
		((equal (is_in_list first_set (car second_set)) 0) (cons (car second_set) (union_set first_set (cdr second_set))))
		(T (union_set first_set (cdr second_set)))
	)
)