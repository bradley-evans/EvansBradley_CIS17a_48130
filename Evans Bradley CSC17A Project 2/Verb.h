/* 
 * File:   Verb.h
 * Author: Bradley Evans
 *
 * Created on November 23, 2014, 5:53 PM
 */

#ifndef VERB_H
#define	VERB_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

/** \brief Enumerated class which stores the verbs
 * considered valid within the game.
 * 
 * An enumerated class which stores the valid verbs
 * that can be called upon in commands when playing
 * the game. Adding to this list requires modification
 * to two lists: adding the verb to EnumVerb and adding
 * strings to the map found in Verb::parseVerb().
 */
enum class EnumVerb {
    ask,
    look,
    quit,
    save,
    load,
    show,
    hit,
    invalid
};
/** \brief Parses out the verb given by the user and converts it into an enumerated value.
 *  */
class Verb {
private:
    string verbstr;             ///< The verb found by the parser.
    EnumVerb verb;              ///< The verb stored as an enumerated value.
public:
    Verb(string);               ///< Verb constructor.
    void parseVerb();           ///< Converts verbstr into an enumerated value.
    EnumVerb getVerbEnum();     ///< Returns the enumerated value of the verb.
    virtual ~Verb();            ///< Verb destructor.
};

#endif	/* VERB_H */

