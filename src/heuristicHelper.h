#ifndef __HEURISTIC_HELPER__
#define __HEURISTIC_HELPER__

#include "parse.h"

extern KLDNF posGoal;

class HeuristicHelper {
public:
	HeuristicHelper() {};
	double getHeuristicValue(const KLDNF& kld);
	double dist(const KLDNF& lkld, const KLDNF& rkld);
	double dist(const KLTerm& lklt, const KLTerm& rklt);
	double dist(const PropDNF& lpd, const PropDNF& rpd);
};

#endif