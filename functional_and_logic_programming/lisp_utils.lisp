
;;; returns true if the node is in the tree
(defun tree_find_node(tree node)
	(cond
		((null tree) nil)
		((equal (car tree) node) T)
        (T (or (tree_find_node (cadr tree) node) (tree_find_node (caddr tree) node)))
	)
)

;;; returns the path from the root to a given node
(defun tree_path(root node)
	(cond
        ((equal (car root) node) (list node))
		((not (null (tree_find_node (cadr root) node))) 
			(cons 
				(list (car root)) 
				(tree_path (cadr root) node)
			)
		)
		((not (null (tree_find_node (caddr root) node))) 
			(cons 
				(list (car root)) 
				(tree_path (caddr root) node)
			)
		)
		(nil)
	)
)

;;;tree inorder traversal
(defun tree_inorder (tree)
	(cond
		((null tree) nil)
		(T (append 
				(tree_inorder (cadr tree)) 
				(list (car tree))
				(tree_inorder (caddr tree))
			)
		)
	)
)

;;;tree postorder traversal
(defun tree_postorder (tree)
	(cond
		((null tree) nil)
		(T (append 
				(tree_postorder (cadr tree)) 
				(tree_postorder (caddr tree)) 
				(list (car tree))
			)
		)
	)
)