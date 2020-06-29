#ifndef AVIDA_GP_SYMBIO_H
#define AVIDA_GP_SYMBIO_H

#include "SymWorld.h"
//#include "../SymOrg.h"
#include "../../Empirical/source/hardware/AvidaGP.h"
#include "../../Empirical/source/config/ArgManager.h"
#include "../../Empirical/source/Evolve/World.h"
#include <iostream>
using std::endl; using std::cout;

class Symbiont {
private:  
  double interaction_val;
  double points;
  std::set<int> res_types;


public:

  double burst_timer = 0;
  Symbiont(double _intval=0.0, double _points = 0.0, std::set<int> _set = std::set<int>())
    : interaction_val(_intval), points(_points), res_types(_set) {}
  Symbiont(const Symbiont &) = default;
  Symbiont(Symbiont &&) = default;

    Symbiont & operator=(const Symbiont &) = default;
  Symbiont & operator=(Symbiont &&) = default;

  double GetIntVal() const {return interaction_val;}
  double GetPoints() {return points;}
  //  std::set<int> GetResTypes() const {return res_types;}
  double GetBurstTimer() {return burst_timer;}

  void SetIntVal(double _in) { interaction_val = _in;}
  void SetPoints(double _in) { points = _in;}
  void AddPoints(double _in) { points += _in;}
  //void SetResTypes(std::set<int> _in) {res_types = _in;}
  void IncBurstTimer(emp::Random &random) {burst_timer += random.GetRandNormal(1.0, 0.5);}

  //TODO: change everything to camel case
  void mutate(emp::Random &random, double mut_rate){
    interaction_val += random.GetRandNormal(0.0, mut_rate);
    if(interaction_val < -1) interaction_val = -1;
    else if (interaction_val > 1) interaction_val = 1;
  }

};

#endif