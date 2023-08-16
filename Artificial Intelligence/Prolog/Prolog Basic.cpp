#include <SWI-Prolog.h>
#include <stdio.h>

void query_solution(void)
{
    term_t query, solution;

    // Initialize Prolog engine
    PL_initialise(0, NULL);

    // Create a query
    query = PL_new_term_ref();
    PL_chars_to_term("father(john, X)", query);

    // Create a term to hold the solution
    solution = PL_new_term_ref();

    // Query the Prolog program
    int success = PL_query(query, solution);

    // Process the solution
    if (success)
    {
        term_t variable = PL_new_term_ref();
        char *name;
        PL_get_name_arity(solution, &name, NULL);
        PL_get_arg(1, solution, variable);
        PL_get_chars(variable, &name, CVT_ALL);
        printf("Father: %s\n", name);
    }
    else
    {
        printf("Query failed.\n");
    }

    // Cleanup
    PL_cleanup(0);
}

int main()
{
    query_solution();
    return 0;
}

