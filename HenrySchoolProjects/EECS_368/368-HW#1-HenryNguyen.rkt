#lang racket

;;; ==============================
;;; Name: Henry C. Nguyen
;;; Assignment: EECS 368 Program 1
;;; Professor: Frank Brown
;;; Date: 02-01-2015
;;; ==============================

;;; Enable debug tracing
(require racket/trace)

;;; 1. Enumerates values from l to h
;;; decrementing and incrementing
(define (enumerate-interval l h)
  (cond ((= l h) (cons l null))
        ((> l h) (cons l (enumerate-interval (- l 1) h)))
        (else (cons l (enumerate-interval (+ l 1) h)))))

;;; 2. Like permutation except that 
;;; it has an extra argument to build up 
;;; the list of partial permutations
(define (iperm l a)
  (if (null? l) (list a)
      (append-map (lambda (x) (iperm (remove x l) (cons x a))) l)))

;;; 3. Predicate check to diagonal
;;; bishop moves in chess
(define (diag? col a)
  (if (null? a) #f
  (ormap (lambda (x y) (= (abs (- x col)) (abs (- y (+ (length a) 1))))) 
         a (enumerate-interval (length a) 1))))

;;; 4. Implement iqueens by modifying
;;; iperm program to only return "good"
;;; partial permutatons using diagonal?
(define (iqueens l a)
  (if (null? l) (list a)
      (append-map (lambda (x) (if (diag? x a) '() (iqueens (remove x l) (cons x a)))) l)))

;;; 5. Write a program called q whose
;;; inputs are a number n, and solves
;;; n-queens problem and returns all
;;; good permutations for nXn board
(define (q n)
  (iqueens (enumerate-interval 1 n) '()))

;;; 6. Write a program called test so 
;;; that (test n) will call q on every
;;; number i from 0 to n and return a
;;; list of lists, etc.
(define (test n) 
  (map (lambda(x) (cons x (cons (length (q x)) '()))) (enumerate-interval 0 n)))


;;;=======================================
;;; Tests to show that the program works 
;;; for homework assignment              
;;;=======================================

;;;Test for enumerate-interval
'(Test for enumerate-interval)
(enumerate-interval 1 10)
(enumerate-interval 10 1)
(enumerate-interval 5 5)
'()

;;;Test for iperm using homework example
'(Test for iperm)
(iperm '(1 2) '())
'()

;;;Test for diag? using homework examples
'(Test for diag?)
(diag? 1 '())
(diag? 2 '(1))
(diag? 3 '(1))
(diag? 2 '(3 1))
(diag? 4 '(3 1))
(diag? 5 '(3 1))
(diag? 2 '(5 3 1))
(diag? 4 '(2 5 3 1))
(diag? 6 '(4 2 5 3 1))
'()

;;;Test for iqueens using homework example
'(Test for iqueens)
(iqueens '(1 2 3 4) '())
'()

;;;Test for q
'(Test for q)
(q 4)
'()

;;;Test for test
'(Test for test)
(test 11)



