#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_INPUTS 10

typedef struct {
    int state;
    char input;
    int nextState;
} NFATransition;

typedef struct {
    int numStates;
    int numInputs;
    int startState;
    int finalStates[MAX_STATES];
    NFATransition transitions[MAX_STATES][MAX_INPUTS];
} NFA;

typedef struct {
    int numStates;
    int numInputs;
    int startState;
    int finalStates[MAX_STATES];
    int transitions[MAX_STATES][MAX_INPUTS];
} DFA;

void epsilonClosure(int state, bool visited[], int epsilonClosureSet[], int* epsilonClosureSetSize, NFA nfa) {
    visited[state] = true;
    epsilonClosureSet[(*epsilonClosureSetSize)++] = state;

    for (int i = 0; i < nfa.numInputs; i++) {
        NFATransition transition = nfa.transitions[state][i];
        if (transition.input == '$' && !visited[transition.nextState]) {
            epsilonClosure(transition.nextState, visited, epsilonClosureSet, epsilonClosureSetSize, nfa);
        }
    }
}

void move(int states[], int statesSize, char input, int moveSet[], int* moveSetSize, NFA nfa) {
    for (int i = 0; i < statesSize; i++) {
        int state = states[i];
        for (int j = 0; j < nfa.numInputs; j++) {
            NFATransition transition = nfa.transitions[state][j];
            if (transition.input == input) {
                moveSet[(*moveSetSize)++] = transition.nextState;
            }
        }
    }
}

void convertToDFA(NFA nfa, DFA* dfa) {
    int dfaStates[MAX_STATES][MAX_INPUTS] = {0};
    int dfaStatesSize = 0;

    bool visited[MAX_STATES] = {false};

    int startStateClosureSet[MAX_STATES];
    int startStateClosureSetSize = 0;
    epsilonClosure(nfa.startState, visited, startStateClosureSet, &startStateClosureSetSize, nfa);

    dfaStates[dfaStatesSize][0] = nfa.startState;
    dfa->numStates = 1;
    dfa->startState = 0;
    if (startStateClosureSetSize > 0) {
        for (int i = 0; i < startStateClosureSetSize; i++) {
            int state = startStateClosureSet[i];
            for (int j = 0; j < nfa.numStates; j++) {
                if (state == nfa.finalStates[j]) {
                    dfa->finalStates[dfa->numInputs++] = dfaStatesSize;
                    break;
                }
            }
        }
    }

    while (dfaStatesSize < dfa->numStates) {
        int currentStateClosureSet[MAX_STATES];
        int currentStateClosureSetSize = 0;

        for (int i = 0; i < nfa.numInputs; i++) {
            char input = 'a' + i;

            int moveSet[MAX_STATES];
            int moveSetSize = 0;

            move(dfaStates[dfaStatesSize], dfa->numInputs, input, moveSet, &moveSetSize, nfa);

            for (int j = 0; j < moveSetSize; j++) {
                int state = moveSet[j];
                epsilonClosure(state, visited, currentStateClosureSet, &currentStateClosureSetSize, nfa);
            }

            if (currentStateClosureSetSize > 0) {
                bool newStateExists = false;
                int newStateIndex = -1;

                for (int j = 0; j < dfaStatesSize; j++) {
                    bool statesEqual = true;

                    for (int k = 0; k < currentStateClosureSetSize; k++) {
                        if (dfaStates[j][k] != currentStateClosureSet[k]) {
                            statesEqual = false;
                            break;
                        }
                    }

                    if (statesEqual) {
                        newStateExists = true;
                        newStateIndex = j;
                        break;
                    }
                }

                if (!newStateExists) {
                    newStateIndex = dfa->numStates++;
                    for (int j = 0; j < currentStateClosureSetSize; j++) {
                        dfaStates[newStateIndex][j] = currentStateClosureSet[j];
                    }

                    for (int j = 0; j < currentStateClosureSetSize; j++) {
                        int state = currentStateClosureSet[j];
                        for (int k = 0; k < nfa.numStates; k++) {
                            if (state == nfa.finalStates[k]) {
                                dfa->finalStates[dfa->numInputs++] = newStateIndex;
                                break;
                            }
                        }
                    }
                }

                dfaStates[dfaStatesSize][i] = newStateIndex;
            }
        }

        dfaStatesSize++;
    }

    for (int i = 0; i < dfa->numStates; i++) {
        for (int j = 0; j < dfa->numInputs; j++) {
            dfa->transitions[i][j] = dfaStates[i][j];
        }
    }
}

int main() {
    NFA nfa;
    nfa.numStates = 3;
    nfa.numInputs = 2;
    nfa.startState = 0;

    // Initialize final states
    nfa.finalStates[0] = 2;

    // Initialize transitions
    nfa.transitions[0][0].state = 0;
    nfa.transitions[0][0].input = 'a';
    nfa.transitions[0][0].nextState = 0;

    nfa.transitions[0][1].state = 0;
    nfa.transitions[0][1].input = 'b';
    nfa.transitions[0][1].nextState = 1;

    nfa.transitions[1][0].state = 1;
    nfa.transitions[1][0].input = 'a';
    nfa.transitions[1][0].nextState = 1;

    nfa.transitions[1][1].state = 1;
    nfa.transitions[1][1].input = 'b';
    nfa.transitions[1][1].nextState = 2;

    nfa.transitions[2][0].state = 2;
    nfa.transitions[2][0].input = 'a';
    nfa.transitions[2][0].nextState = 2;

    nfa.transitions[2][1].state = 2;
    nfa.transitions[2][1].input = 'b';
    nfa.transitions[2][1].nextState = 2;

    DFA dfa;
    convertToDFA(nfa, &dfa);

    // Print DFA transitions
    printf("DFA Transitions:\n");
    for (int i = 0; i < dfa.numStates; i++) {
        for (int j = 0; j < dfa.numInputs; j++) {
            printf("(%d, %c) -> %d

