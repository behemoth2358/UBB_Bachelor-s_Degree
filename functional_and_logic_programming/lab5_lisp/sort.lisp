;;;;Write a function to sort a linear list with keeping the double values

(defun delete_first_occurrence (collection elem)
	(cond
		((null collection) nil)
		((equal (car collection) elem) (cdr collection))
		(T (cons (car collection) (delete_first_occurrence (cdr collection) elem)))
	)
)

(defun get_min_number (collection)
	(cond
		((null collection) nil)
		((equal (length collection) 1) (car collection))
		(T (min (car collection) (get_min_number (cdr collection))))
	)
)

(defun sort_collection (collection)
	(setq min_nr (get_min_number collection))
	(cond 
		((null min_nr) nil)
		(T (cons min_nr (sort_collection (delete_first_occurrence collection min_nr))))
	)
)