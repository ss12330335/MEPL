#include "header.h"
#include "planner.h"

using namespace std;

// global variable andfor compile
string domainName;
vector<string> atoms;
map<string, vector<string> > objects;
vector<string> agents;
map<int, string> findAtomsByIndex;
map<string, int> findAtomsByName;
map<string, int> findSensingActionByName;
map<string, int> findOnticActionByName;
vector<SensingAction> sActions;
vector<OnticAction> oActions;
KLDNF init;
KLDNF posGoal;
KLDNF goal;
PropDNF constraint;

// search data
int atomNum, solNum, expNum, solDepth;
double preTime, searchTime;

char epddlFilePath[500] = "../input/test.epddl";

int main(int argc, char** argv) {
	Planner planner(epddlFilePath);
	planner.exec();

	return 0;
}