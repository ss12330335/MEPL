#ifndef __ACDF_H__
#define __ACDF_H__

#include "header.h"
#include "enumeration.h"

using namespace std;

extern map<int, string> findAtomsByIndex;
extern map<string, int> findAtomsByName;
extern int atomNum;

class PropTerm;
class PropDNF;
class KLTerm;
class KLDNF;

class PropTerm {
public:
	vector<AtomType> literal;
	int len;

	PropTerm() {};
	PropTerm(int _len);
	~PropTerm();
	bool isSatisfiable() const;
	bool canEntail(const PropTerm& pt) const;
	PropTerm conjunction(const PropTerm& pt);
	PropTerm minimal();
	vector<PropTerm> negation();
	set<string> getTotalLiterals();

	void print() const;
	void show(ofstream& os) const;
};

class PropDNF {
public:
	list<PropTerm> dnf;

	PropDNF() {};
	PropDNF(const PropDNF& pd);
	~PropDNF();
	bool isSatisfiable() const;
	bool canEntail(const PropDNF& pd) const;
	bool isEqual(const PropDNF& pd) const;
	bool isEmpty();
	PropDNF conjunction(const PropDNF& pd);
	PropDNF disjunction(const PropDNF& pd);
	PropDNF minimal();
	PropDNF negation();
	PropDNF revision(const PropDNF& pd);
	PropDNF update(const PropDNF& pd);
	
	int diff(const PropTerm& lpt, const PropTerm& rpt, PropTerm& apt);
	void print() const;
	void show(ofstream& os) const;
};

class KLTerm {
public:
	PropDNF PPart;
	map<string, KLDNF> KPart;
	map<string, list<KLDNF>> LPart;

	KLTerm() {};
	KLTerm(const KLTerm& klt);
	~KLTerm();
	bool isSatisfiable(const PropDNF& constraint);
	bool isSatisfiable(KLTerm& klt, const PropDNF& constraint);
	bool negEntail(KLTerm& klt, const PropDNF& constraint);
	bool strongEntail(KLTerm& klt, const PropDNF& constraint);
	bool strongEquivlent(KLTerm& klt, const PropDNF& constraint);
	bool isEmpty();
	KLTerm minimal(const PropDNF& constraint);
	KLTerm conjunction(KLTerm& klt);
	vector<KLTerm> negation(const PropDNF& constraint);
	KLTerm revision(KLTerm& klt, const PropDNF& constraint);
	KLTerm update(KLTerm& klt, const PropDNF& constraint);

	void print() const;
	void show(ofstream& os) const;
};

class KLDNF {
public:
	list<KLTerm> dnf;

	KLDNF() {};
	KLDNF(const KLTerm& klt);
	KLDNF(const KLDNF& kld);
	~KLDNF();
	bool isSatisfiable(const PropDNF& constraint);
	bool isSatisfiable(KLDNF& kld, const PropDNF& constraint);
	bool negEntail(KLDNF& kld, const PropDNF& constraint);
	bool strongEntail(KLDNF& kld, const PropDNF& constraint);
	bool strongEquivlent(KLDNF& kld, const PropDNF& constraint);
	KLDNF conjunction(KLDNF& kld);
	KLDNF disjunction(KLDNF& kld);
	KLDNF minimal(const PropDNF& constraint);
	KLDNF negation(const PropDNF& constraint);
	KLDNF revision(KLDNF& kld, const PropDNF& constraint);
	KLDNF update(KLDNF& kld, const PropDNF& constraint);

	void print() const;
	void show(ofstream& os) const;
};

#endif