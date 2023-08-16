% Base case: Factorial of 0 is 1
factorial(0, 1).
% Recursive case: Factorial of N is N multiplied by factorial of N-1
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, Result1),
    Result is N * Result1.
