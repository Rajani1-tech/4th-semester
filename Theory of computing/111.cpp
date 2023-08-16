

#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_INPUTS 10

typedef struct {
    int state;
    char output;
} MooreState;

typedef struct {
    int state;
    char input;
    int nextState;
    char output;
} MooreTransition;

typedef struct {
    int state;
    char input;
    int nextState;
    char output;
} MealyTransition;

typedef struct {
    int numStates;
    int numInputs;
    MooreState states[MAX_STATES];
    MooreTransition transitions[MAX_STATES][MAX_INPUTS];
} MooreMachine;

typedef struct {
    int numStates;
    int numInputs;
    MealyTransition transitions[MAX_STATES][MAX_INPUTS];
} MealyMachine;

MealyMachine convertToMealy(MooreMachine mooreMachine) {
    MealyMachine mealyMachine;
    mealyMachine.numStates = mooreMachine.numStates;
    mealyMachine.numInputs = mooreMachine.numInputs;

    for (int i = 0; i < mooreMachine.numStates; i++) {
        for (int j = 0; j < mooreMachine.numInputs; j++) {
            MealyTransition transition;
            transition.state = i;
            transition.input = mooreMachine.transitions[i][j].input;
            transition.nextState = mooreMachine.transitions[i][j].nextState;
            transition.output = mooreMachine.transitions[i][j].output;
            mealyMachine.transitions[i][j] = transition;
        }
    }

    return mealyMachine;
}

int main() {
    MooreMachine mooreMachine;
    mooreMachine.numStates = 3;
    mooreMachine.numInputs = 2;

    // Initialize states
    mooreMachine.states[0].state = 0;
    mooreMachine.states[0].output = 'A';
    mooreMachine.states[1].state = 1;
    mooreMachine.states[1].output = 'B';
    mooreMachine.states[2].state = 2;
    mooreMachine.states[2].output = 'C';

    // Initialize transitions
    mooreMachine.transitions[0][0].state = 0;
    mooreMachine.transitions[0][0].input = '0';
    mooreMachine.transitions[0][0].nextState = 1;
    mooreMachine.transitions[0][0].output = 'X';

    mooreMachine.transitions[0][1].state = 0;
    mooreMachine.transitions[0][1].input = '1';
    mooreMachine.transitions[0][1].nextState = 2;
    mooreMachine.transitions[0][1].output = 'Y';

    mooreMachine.transitions[1][0].state = 1;
    mooreMachine.transitions[1][0].input = '0';
    mooreMachine.transitions[1][0].nextState = 2;
    mooreMachine.transitions[1][0].output = 'Z';

    mooreMachine.transitions[1][1].state = 1;
    mooreMachine.transitions[1][1].input = '1';
    mooreMachine.transitions[1][1].nextState = 0;
    mooreMachine.transitions[1][1].output = 'X';

    mooreMachine.transitions[2][0].state = 2;
    mooreMachine.transitions[2][0].input = '0';
    mooreMachine.transitions[2][0].nextState = 0;
    mooreMachine.transitions[2][0].output = 'Y';

    mooreMachine.transitions[2][1].state = 2;
    mooreMachine.transitions[2][1].input = '1';
    mooreMachine.transitions[2][1].nextState = 1;
    mooreMachine.transitions[2][1].output = 'Z';

    MealyMachine mealyMachine = convertToMealy(mooreMachine);

    // Print Mealy machine transitions
    printf("Mealy Machine Transitions:\n");
    for (int i = 0; i < mealyMachine.numStates; i++) {
        for (int j = 0; j < mealyMachine.numInputs; j++) {
            MealyTransition transition = mealyMachine.transitions[i][j];
            printf("(%d, %c) -> (%d, %c)\n", transition.state, transition.input,
                   transition.nextState, transition.output);
        }
    }

    return 0;
}

