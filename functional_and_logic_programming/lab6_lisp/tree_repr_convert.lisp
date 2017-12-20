(defun convert_tree_repr (tree)
	(cond
		((null tree) nil)
		((equal (length (cdr tree)) 2) 
			(append
				(append 
					(list (car tree) 2) 
					(convert_tree_repr (cadr tree))
				)
				(convert_tree_repr (caddr tree))
			)
		)
		((equal (length (cdr tree)) 1)
			(append
				(list (car tree) 1)
				(convert_tree_repr (cadr tree))
			)
		)
		(T (list (car tree) 0))
	)
)