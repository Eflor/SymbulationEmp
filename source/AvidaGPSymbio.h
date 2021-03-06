#ifndef AVIDA_GP_SYMBIO_H
#define AVIDA_GP_SYMBIO_H

#include "../../Empirical/source/hardware/AvidaGP.h"
#include "../../Empirical/source/config/ArgManager.h"
#include "../../Empirical/source/Evolve/World.h"
#include <iostream>
using std::endl; using std::cout;

/*
* Class represents a single symbiont that inherits from AvidaCPU_base class 
*/
class Symbiont : public emp::AvidaCPU_Base<Symbiont> {
 public:
  using base_t = AvidaCPU_Base<Symbiont>;
  using typename base_t::genome_t;
  using typename base_t::inst_lib_t;

  Symbiont(const genome_t & in_genome) : AvidaCPU_Base(in_genome) { ; }
  Symbiont(emp::Ptr<const inst_lib_t> inst_lib) : AvidaCPU_Base(Genome(inst_lib)) { ; }
  Symbiont(const inst_lib_t & inst_lib) : AvidaCPU_Base(Genome(&inst_lib)) { ; }

  Symbiont() = default;
  Symbiont(const Symbiont &) = default;
  Symbiont(Symbiont &&) = default;

  virtual ~Symbiont() { ; }


};

#endif

