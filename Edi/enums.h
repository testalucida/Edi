#ifndef ENUMS_H
#define ENUMS_H

/**
 * MainTile contains two EdiTab objects.
 * By using whichTabs::LEFT or whichTabs::RIGHT
 * you may specify one of them.
 */
enum whichTabs {
    LEFT = 0,
    RIGHT = 1
};

/**
 * Each EdiTabTile contains max. 2 EdiGrp objects.
 * This enum is needed by the getEdiGrp() method.
 */
enum whichGrp {
    TOP = 0,
    BOTTOM = 1
} ;

#endif