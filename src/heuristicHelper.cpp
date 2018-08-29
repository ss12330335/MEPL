#include "heuristicHelper.h"

const double minHeuristicValue = 1.0f;
const double mMaxHeuristicValue = (double)INT_MAX;

double HeuristicHelper::getHeuristicValue(const KLDNF& kld) {
	//return minHeuristicValue;
	double ans = minHeuristicValue;
	ans += dist(kld, posGoal);
	//cout << ans << endl;
	return ans;
}

double HeuristicHelper::dist(const KLDNF& lkld, const KLDNF& rkld) {
	double ans = mMaxHeuristicValue;
	if(lkld.dnf.empty() && rkld.dnf.empty()) return 0.0f;
	if(lkld.dnf.empty()) {
		for(list<KLTerm>::const_iterator ite2 = rkld.dnf.begin();
			ite2 != rkld.dnf.end();ite2++) {
			KLTerm klt;
			ans = min(ans, dist(klt, *ite2));
		}
		return (abs(ans-mMaxHeuristicValue) < 0.00001f ? 0 : ans);
	}
	if(rkld.dnf.empty()) return 0.0f;
	for(list<KLTerm>::const_iterator ite1 = lkld.dnf.begin();
		ite1 != lkld.dnf.end();ite1++) {
		for(list<KLTerm>::const_iterator ite2 = rkld.dnf.begin();
			ite2 != rkld.dnf.end();ite2++) {
			ans = min(ans, dist(*ite1, *ite2));
		}
	}
	return ((abs(ans-mMaxHeuristicValue) < 0.00001f) ? 0 : ans);
}

double HeuristicHelper::dist(const KLTerm& lklt, const KLTerm& rklt) {
	double pans = 0.0f, kans = 0.0f, lans = 0.0f, klen = 0.0f, kc = 0.0f;
	pans = dist(lklt.PPart, rklt.PPart);
	for(map<string, KLDNF>::const_iterator ite2 = rklt.KPart.begin();
		ite2 != rklt.KPart.end();ite2++) {
		if(lklt.KPart.find(ite2->first) == lklt.KPart.end()) {
			KLDNF kld;
			kans += dist(kld, ite2->second);
		}
		else {
			kans += dist(lklt.KPart.find(ite2->first)->second, ite2->second);
			klen += (lklt.KPart.find(ite2->first))->second.dnf.size();
			kc++;
		}
	}
	if(abs(kc-0.0f) > 0.00001f) kans += (klen/kc);
	for(map<string, list<KLDNF> >::const_iterator ite2 = rklt.LPart.begin();
		ite2 != rklt.LPart.end();ite2++) {
		if(lklt.LPart.find(ite2->first) == lklt.LPart.end()) {
			double tlans = (double)INT_MAX;
			KLDNF kld;
			for(list<KLDNF>::const_iterator ite3 = ite2->second.begin();
				ite3 != ite2->second.end();ite3++) {
				tlans = min(tlans, dist(kld, *ite3));
			}
			lans += tlans;
		}
		else {
			double tlans = (double)INT_MAX;
			for(list<KLDNF>::const_iterator ite3 = ite2->second.begin();
				ite3 != ite2->second.end();ite3++) {
				for(list<KLDNF>::const_iterator ite1 = lklt.LPart.find(ite2->first)->second.begin();
					ite1 != lklt.LPart.find(ite2->first)->second.end();ite1++) {
					tlans = min(tlans, dist(*ite1, *ite3));
				}
			}
			lans += tlans;
		}
	}
	return pans + kans + ((abs(lans-mMaxHeuristicValue) < 0.00001f) ? 0 : lans);
}

double HeuristicHelper::dist(const PropDNF& lpd, const PropDNF& rpd) {
	double ans = (double)INT_MAX;
	for(list<PropTerm>::const_iterator ite2 = rpd.dnf.begin();
		ite2 != rpd.dnf.end();ite2++) {
		double tans = 0.0f;
		for(size_t i = 0;i < (ite2->literal).size();i++) {
			if(ite2->literal[i] == TRUE ||
				ite2->literal[i] == FALSE) {
				bool isConsisitent = true;
				for(list<PropTerm>::const_iterator ite1 = lpd.dnf.begin();
					ite1 != lpd.dnf.end();ite1++) {
					if(!ite1->isSatisfiable()) continue;
					isConsisitent &= (ite1->literal[i] == ite2->literal[i]);
					if(!isConsisitent) break;
				}
				tans += ((isConsisitent) ? 0.0f : 1.0f);
			}
		}
		ans = min(ans, tans);
	}
	return ((abs(ans-mMaxHeuristicValue) < 0.00001f) ? 0 : ans);
}
