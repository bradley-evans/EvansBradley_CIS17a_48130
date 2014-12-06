/* 
 * File:   Noun.h
 * Author: Bradley Evans
 *
 * Created on November 23, 2014, 5:52 PM
 */

#ifndef NOUN_H
#define	NOUN_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

/** \brief Enumerated class which stores the nouns
 * considered valid within the game.
 * 
 * An enumerated class which stores the valid nouns
 * that can be called upon in commands when playing
 * the game. Adding a new noun requires an update to
 * two lists: one in EnumNoun and one in the map
 * found in Noun::parseNoun().
 */
enum class EnumNoun {
        name,
        base,
        attack,
        suspect,      
        debug,
        invalid
    };
/** \brief Parses out the noun given by the user
 * and converts it to a form usable by the game.
 * 
 * Contains functions which accept the noun parsed
 * out by the ParseCmd class. Stores the noun taken
 * by the parser for later use in a command tree.
 */
class Noun {
private:
    string nounstr;             ///< The noun found by the parser.
    EnumNoun noun;              ///< The noun stored as an enumerated value.
public:
    Noun(string);               ///< Noun constructor.
    void parseNoun();           ///< Noun parser, converts nounstr into an enumerated value.
    EnumNoun getNounEnum();     ///< Returns the noun's enumerated value.
    virtual ~Noun();            ///< Noun destructor.
};

#endif	/* NOUN_H */

