#include "Caretaker.hpp"
#include "Memento.hpp"
#include "Originator.hpp"

#include <iostream>
#include <string>

/* #################################### Memento - Behavioural ####################################
* Notes:   The Memento pattern is used to capture the current state of an object and store it in a
*          separate object. This allows the object to be restored to its previous state at a later
*          time.
* Common Uses: - Undo feature (Ctrl + Z) on applications
*/

class Originator;   // Object the User interacts with
class Memento;      // State of one Originator Object
class Caretaker;    // History of States

int main(){

    Originator editor;
    Caretaker history(editor);

    // Initial State
    history.pushState();

    // First Change
    editor.m_title = "Title 1";
    editor.m_value = 1;
    history.pushState();

    // Second Change
    editor.m_title = "Title 2";
    editor.m_value = 2;
    history.pushState();

    // Display History
    history.printStates();

    // Undo
    history.popState();

    // Display History
    history.printStates();

    return 0;
}