/**
 * Implementation of CThread's cwait function, including supporting functions.
 *
 * @author Marlize Ramos
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"

#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Sample of support function. It uses cwait prefix to avoid naming conflicts.
 */
void cwait_hello_world();


// ======================================================================================
//                                         CWAIT
// ======================================================================================

/**
 * Request access to a resource managed by a semaphore variable. May block the thread
 * until the resource is available.
 *
 * @param sem   Pointer to semaphore variable that manages the requested resource.
 * @return 0 if successful, -1 otherwise.
 */
int cwait(csem_t *sem) {

    sem -> count--;
    if (sem->count <= 0)
    {
        insereNaFilaDoSemaforo(sem);

    }

    //else
        return CTHREAD_SUCCESS;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void cwait_hello_world()
{
    printf("Hello world!\n");
}
