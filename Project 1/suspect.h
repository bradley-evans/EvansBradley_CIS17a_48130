/* 
 * File:   suspect.h
 * Author: Bradley Evans
 *
 * Created on October 28, 2014, 11:29 AM
 */

#ifndef SUSPECT_H
#define	SUSPECT_H

class Suspect {                      // Defines the suspect's statistics.     
    // The likelihood the suspect will take a certain action.
    int     minimize,       ///< give minimum amount of cooperation, delay tactic
            silence,        ///< ignore interrogation
            distort,        ///< misinformation, with some truth
            distract;       ///< distract
    // primary three responses
    int     comply,         ///< answer at all
            honest,         ///< be honest
            deception;      ///< be deceptive
    // other modifiers
    int     exhaustion,     ///< tired
            pain,           ///< result of torture
            hatred;         ///< hatred, willingness to do anything to deny information
}

#endif	/* SUSPECT_H */

