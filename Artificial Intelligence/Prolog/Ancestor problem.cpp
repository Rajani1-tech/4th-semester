#include <SWI-Prolog.h>
#include <stdio.h>

void query_solution(const char* person)
{
    term_t query, solution;

    // Initialize Prolog engine
    PL_initialise(0, NULL);

    // Create a query
    query = PL_new_term_ref();
    char query_string[256];
    sprintf(query_string, "ancestor(%s, X)", person);
    PL_chars_to_term(query_string, query);

    // Create a term to hold the solution
    solution = PL_new_term_ref();

    // Query the Prolog program
    int success = PL_query(query, solution);

    // Process the solutions
    if (success)
    {
        term_t ancestor = PL_new_term_ref();
        char *name;
        int count = 0;
        
        printf("Ancestors of %s:\n", person);
        
        // Iterate over the solutions
        while (PL_next_solution(success))
        {
            count++;
            PL_get_arg(2, solution, ancestor);
            PL_get_chars(ancestor, &name, CVT_ALL);
            printf("%d. %s\n", count, name);
        }
        
        if (count == 0)
        {
            printf("No ancestors found.\n");
        }
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
    const char* person = "john";
    query_solution(person);
    return 0;
}

