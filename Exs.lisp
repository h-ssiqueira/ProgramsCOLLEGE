;Escreva uma função ROTACIONA-D que é similar ao anterior - ROTACIONA-E – difere
;apenas por rotacionar o elemento da lista para a direita, ou seja, o último elemento foi
;rotacionado de uma posição para a direita

(defun ROTACIONA-D (alist)
(append (last alist) (reverse (rest (reverse alist))))
)


;Defina uma função COMPRIMENTO-CIRC que retorne o comprimento de um círculo. A
;função recebe o raio R como parâmetro

(defun COMPRIMENTO-CIRC (R)
(* 2 pi R))


;Defina uma função COMPARA que retorne T (TRUE) se qualquer um dos dois primeiros argumentos for menor que o terceiro e maior que o'quarto.

(defun COMPARA (a b c d)
(if (and (or (< a c) (< b c)) (or (> a d) (> b d))) t nil))

;Defina uma função FIBONACCI recursiva.

(defun FIBONACCI (n)
    (cond   
        ((or (= n 1) (= n 2)) 1)
        (t (+ (FIBONACCI (- n 1)) (FIBONACCI (- n 2))))
    )
)

;Utilizando a macro DOTIMES, defina uma função ELEVA que receba dois argumentos M e N e a função eleva M a N.

(defun ELEVA (M N)
	(setf s 1)
   		(dotimes (i n s)
       		(setq s (* s m))
 		)
)

;Defina uma função que adiciona um elemento (elem) em uma lista (list),
;caso o elemento não for encontrado na lista.

(defun ELEM_IF_NOT_LIST (elem list)
	(if (position elem list)
    	t
    	(append (list elem)list)
	)
)

