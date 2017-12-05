;;;;Build a list which contains positions of a minimum numeric element from a given linear list.
(defun get_min_number (collection)
	(cond
		((null collection) nil)
		((equal (length collection) 1) (car collection))
		(T (min (car collection) (get_min_number (cdr collection))))
	)
)

(defun get_min_positions (collection)
	(setq min_nr (get_min_number collection))
	(get_min_nr_indexes collection min_nr 0)
)

(defun get_min_nr_indexes (collection min_nr cnt)
	(cond
		((null collection) nil)
		((equal min_nr (car collection)) (cons cnt (get_min_nr_indexes (cdr collection) min_nr (+ cnt 1))))
		(T (get_min_nr_indexes (cdr collection) min_nr (+ cnt 1)))
	)
)