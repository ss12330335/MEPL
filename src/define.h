#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "header.h"
#include "ACDF.h"

using namespace std;

// structure
struct SensingAction {
	string name;

	KLDNF preCon;
	KLDNF posRes;
	KLDNF negRes;
};

struct ConditionalEffect {
	KLDNF condition;
	KLDNF effect;
};

struct OnticAction {
	string name;

	KLDNF preCon;
	vector<ConditionalEffect> eff;
};

/* the node used in LAO* */
struct LAONode {  
	KLDNF kb;
	double heuValue;
	bool isSolved;
	bool isDeadend;

	LAONode(KLDNF _kb, double hv, bool iss, bool isd) : 
		kb(_kb), heuValue(hv), isSolved(iss), isDeadend(isd) {}
};

/* the edge used in LAO* */
struct LAOEdge {
    EdgeType et;
    int actionIndex;
    vector<int> childNode;

    LAOEdge() {};
    LAOEdge(EdgeType _et, int _actionIndex, vector<int> _childNode) : et(_et),
        actionIndex(_actionIndex), childNode(_childNode) {};

    bool operator == (const LAOEdge& r) const {
        return et==r.et && actionIndex==r.actionIndex;
    }
};

const int onticCost = 1;
const int episCost = 1;
const double errorBound = 0.00001f;
const double maxHeuristicValue = (double)INT_MAX;

#endif