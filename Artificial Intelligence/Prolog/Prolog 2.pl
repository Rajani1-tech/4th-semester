% Solve Tower of Hanoi problem
solve_toh(NumDisks) :- move(NumDisks, left, center, right).
% Base case: Move 1 disk from Source to Destination
move(1, Source, _, Destination) :-
    write('Move top disk from '),
    write(Source),
    write(' to '),
    write(Destination),
    nl.
% Recursive case: Move N disks from Source to Destination using% Auxiliary peg
move(N, Source, Auxiliary, Destination) :-
    N > 1,
    M is N - 1,
    move(M, Source, Destination, Auxiliary),
    move(1, Source, _, Destination),
    move(M, Auxiliary, Source, Destination).
