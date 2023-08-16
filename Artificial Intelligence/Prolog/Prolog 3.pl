% Define parent relationships
parent(john, mary).
parent(john, tom).
parent(mary, ann).
parent(mary, bob).
parent(tom, liz).

% Define grandparent relationships
grandparent(X, Y) :-
  parent(X, Z),
  parent(Z, Y).

% Query some relationships
?- parent(john, mary).    % true
?- parent(john, bob).     % true
?- grandparent(john, ann). % true
?- grandparent(john, liz). % true
