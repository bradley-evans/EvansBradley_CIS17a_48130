#include "verbs.h"
using namespace std;

Verb parseVerb(const string &verb)
{
    auto n = knownVerbs.find(verb);
    if ( n == knownVerbs.end() ) {
        return Verb::invalid;
    }
}

/*
 * Send the verb off to be paired with nouns.
 */

int verbProc (Noun noun, Verb verb) {
    switch (verb) {
        case Verb::ask:     ask(noun);
        case Verb::look:    look(noun);
    }
    return 0;
}
#endif	/* VERBS_H */


