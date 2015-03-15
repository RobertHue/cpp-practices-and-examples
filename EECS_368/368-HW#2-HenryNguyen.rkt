#lang racket

;;; ==============================
;;; Name: Henry C. Nguyen
;;; Assignment: EECS 368 Program 2
;;; Professor: Frank Brown
;;; Date: 02-26-2015
;;; ==============================

(require racket/trace)

;;; Necessary for eval function argument
(define-namespace-anchor a)
(define ev (namespace-anchor->namespace a))

;;; Define y as free variable for part (B)
(define y 43)
;;; Expressions for part (B)
(define num '(λ (x) 47))
(define numc '(λ (x) 2+3i))
(define xbound '(λ (x) x))
(define yfree '(λ (x) y))
(define x+ '(λ (x) (+ x 3 x 5 x)))
(define x+nil '(λ (x) (+)))
(define x- '(λ (x) (- x 3 x 5 x)))
(define x1- '(λ (x) (- x)))
(define x* '(λ (x) (* x 3 x 5 x)))
(define x*nil '(λ (x) (*)))
(define x/ '(λ (x) (/ x 3 x 5 x)))
(define x1/ '(λ (x) (/ x)))
(define xexp '(λ (x) (exp x)))
(define xlog '(λ (x) (log x)))
(define xexplog '(λ (x) (exp (log x))))
(define xlogexp '(λ (x) (log (exp x))))
(define xexpt '(λ (x) (expt x 3)))
(define xexpt2 '(λ (x) (expt 2 x)))
(define xexpt3 '(λ (x) (expt x x)))
(define xexpi '(λ (x) (exp(* +i x))))
(define xexpii '(λ (x) (exp(*(expt -1 1/2)x))))
(define xcos '(λ (x) (+(cos x)(*(expt -1 1/2)(sin x)))))
(define xsin '(λ (x) (log(sin x))))
(define xtan '(λ (x) (tan x)))
(define xasin '(λ (x) (asin(- x 1/2))))
(define xacos '(λ (x) (acos(- x 1/2))))
(define xatan '(λ (x) (atan x)))
(define xabs '(λ (x) (abs(- x 2))))
(define archimedes '(λ (lat) (sin lat)))
(define mercator '(λ (lat) (log(+(tan lat)(/(cos lat))))))                

;;; List of part (B) expressions named qfs
(define qfs (list num numc xbound yfree x+ x+nil x- x1- x* x*nil x/ x1/ 
                  xexp xlog xexplog xlogexp xexpt xexpt2 xexpt3 xexpi xexpii xcos 
                  xsin xtan xasin xacos xatan xabs archimedes mercator))

;;; Derivative function based on formula for differentiation
;;; (f(x+dx) - f(x) / dx)
(define dx 0.000000000001) ; As dx gets smaller, the more accurate our approximation
(define (deriv f)
  (λ (x) (/ (- (f (+ x dx)) (f x)) dx)))

;;; Simplification function that eliminates 0 from sums and 0 and 1 from products
(define (simp_zero exp)
 (cond ((number? exp) exp)
       ((symbol? exp) exp)
       ((list?   exp)
        (if (>= (length exp) 3)
        (let ((op  (list-ref exp 0))
              (arg1 (simp_zero (list-ref exp 1)))
              (arg2 (simp_zero (list-ref exp 2))))
          (case op
            
            ;;; ======================================
            ;;; Necessary Simplifications for part (C)
            ;;; ======================================
            ((+)
             (cond ((and (number? arg1) (number? arg2)) (+ arg1 arg2))
                   ((and (number? arg2) (= 0 arg2)) arg1)
                   ((and (number? arg1) (= 0 arg1)) arg2)
                   (else `(,op ,arg1 ,arg2))))

            ((*)
             (cond ((and (number? arg1) (number? arg2)) (* arg1 arg2))
                   ((and (number? arg2) (= 1 arg2)) arg1)
                   ((and (number? arg1) (= 1 arg1)) arg2)
                   ((and (number? arg1) (= 0 arg1)) 0)
                   ((and (number? arg2) (= 0 arg2)) 0)
                   (else `(,op ,arg1 ,arg2))))
            
            ;;; =============================
            ;;; Additional Simplification(s)
            ;;; =============================
            ((-)
             (cond ((and (number? arg1) (number? arg2) (- arg1 arg2)))
                   ((and (number? arg2) (= 0 arg2)) arg1)
                   ((and (number? arg1) (= 0 arg1)) (- 0 arg2))    
                   (else `(,op ,arg1 ,arg2))))
    
            ((/)
             (cond ((and (number? arg1) (= 0 arg1)) 0)
                   (else `(,op ,arg1 ,arg2))))
            
            (else exp))) exp))(else exp)))

;;; Symbolic Differentiation Function for part (A)
(define (symderivat v z)
  (cond ((number? z) 0)
        ((symbol? z) (if (eq? z v) 1 0))
  (else (case (car z)
          
        ;;; Derivative for Addition
        ((+) (cons '+ (map (λ (y)(symderivat v y))(cdr z))))
          
        ;;; Derivative for Subtraction
        ((-) (cons '- (map (λ (y)(symderivat v y))(cdr z))))

        ;;; Derivative for Multiplication
        ((*) (if (= (length(cdr z)) 0)
                 0
                 (list '+ (cons '* (cons (symderivat v (cadr z)) 
                                         (if (= (length(cddr z)) 0)
                                         '(1)
                                         (cddr z)))) (cons '* (list (cadr z) (symderivat v (cons '* (cddr z))))))))
        ;;; Derivative for Division  
        ((/) (symderivat v (list '* (cadr z) (list 'expt  (cons '*  (cddr z )) -1) ) ) )
          
        ;;; Derivative for Exponential
        ((expt) (cond
                   ((and (number? (cadr z))(number? (caddr z))) 0)
                   ((number? (cadr z)) (list '* (symderivat v (caddr z)) z (list 'log (cadr z))))
                   (else(list '* z (list '+ (list '* (symderivat v (cadr z))(list '/ (caddr z) (cadr z))) (list '* (symderivat v (caddr z))(list 'log (cadr z))))))))
          
        ;;; Derivative for Euler's Number
        ((exp) (list '* (list 'exp (cadr z)) (car(map (λ (y)(symderivat v y))(cdr z)))))
          
        ;;; Derivative for Log
        ((log) (list '* (list '/ (cadr z)) (car(map (λ (y)(symderivat v y))(cdr z)))))
          
        ;;; Derivative for Sine
        ((sin) (list '* (cons 'cos (cdr z)) (car(map (λ (y)(symderivat v y))(cdr z)))))
          
        ;;; Derivative for Cosine
        ((cos) (list '* (list '- (cons 'sin (cdr z))) (car(map (λ (y)(symderivat v y))(cdr z)))))
          
        ;;; Derivative for Tangent
        ((tan) (list '* (list '/ (cons '* (list (cons 'cos(cdr z)) (cons 'cos(cdr z)) ))) (car (map (λ (y)(symderivat v y))(cdr z)))))
          
        ;;; Derivative for Arcsine
        ((asin)(list '* (list '/ (list 'sqrt (list '- 1 (list 'expt (cadr z) 2))) (car(map (λ (y)(symderivat v y))(cdr z))))))
          
        ;;; Derivative for Arccosine
        ((acos)(list '* (list '/ (list '- (list 'sqrt (list '- 1 (list 'expt (cadr z) 2)))) (car(map (λ (y)(symderivat v y))(cdr z))))))
          
        ;;; Derivative for Arctangent
        ((atan)(list '*  (list '/ (list '+ (cons 'expt (list (cadr z) 2)) 1))(car(map (λ (y)(symderivat v y))(cdr z)))))
          
        ;;; Derivative for Absolute Value
        ((abs)(list '* (list '/ (cadr z) (cons 'sqrt (list(cons 'expt (list (cadr z) 2))))) (car(map (λ (y)(symderivat v y))(cdr z)))))
          
        ))))


;;; symderiv Function for part (A)
;;; Calls symderivat, sticks on lambda, and calls simp_zero on expressions
(define (symderiv qf)
  (list 'λ 
        (cadr qf) 
        (simp_zero (symderivat (car(cadr qf)) (caddr qf))))
  
)


;;; Mapping function to fulfill part (B)
(define (deriv-map b) (map (λ (qf) 
                             (list ((deriv (eval qf ev)) 1) 
                                   ((eval (symderiv qf) ev) 1) 
                                   (symderiv qf))) 
                           b))

;;; Calls mapping function on qfs
(deriv-map qfs)



