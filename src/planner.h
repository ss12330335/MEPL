#ifndef __PLANNER_H__
#define __PLANNER_H__

#include "heuristicHelper.h"

extern map<int, string> findAtomsByIndex;
extern map<string, int> findAtomsByName;
extern map<string, int> findSensingActionByName;
extern map<string, int> findOnticActionByName;
extern vector<SensingAction> sActions;
extern vector<OnticAction> oActions;
extern KLDNF init;
extern KLDNF posGoal;
extern KLDNF goal;
extern PropDNF constraint;

class Planner {
public:
	Parse parser;
	HeuristicHelper heuristicHelper;
	// result information
	float preProcessTime;
	float searchTime;
	float heuristicTime;
	float pIteTime;
	int resDepth;
	int resNodeNum;
	int exploredNodeNum;
	int goalPos;

	// search information
	vector<LAONode> allNodes;
	map<int, vector<LAOEdge> > allEdges;
	map<int, int> solEdge;
	set<int> exploredNode;

	Planner(const char *domain);
	~Planner();
	void exec();
	bool isSolved(int index);
	int insertNode(KLDNF& kb);
	bool hasExplored(KLDNF& kb);
	bool isInSolGraph(const int index);
	void labelGraph();
	void policyIteration();
	void extractSolution();
	void updateStateCost();
	void updatePolicy(int index=0);
	int getToExploredNode();
	void exploreNode(int index);
	bool checkSolChange(const map<int, int>& ori);
	void print(int index, int ident=0, int depth=0);
	void show(ofstream& ros, int index=0, int indent=0);
	vector<char> checkEpisAlongSol(int index);
	map<int, double> getStateCost();
};

#endif