#ifndef AVIDA_GP_HOST_H
#define AVIDA_GP_HOST_H

//#include "SymWorld.h"
#include "AvidaGPSymbio.h"
#include "../../Empirical/source/hardware/AvidaGP.h"
#include "../../Empirical/source/config/ArgManager.h"
#include "../../Empirical/source/Evolve/World.h"
#include <iostream>
using std::endl; using std::cout;


class Host : public emp::AvidaCPU_Base<Host>{
 private:
  emp::vector<Symbiont> syms;

  /*
  void AddSymbionts(Symbiont _in, int sym_limit) {
    if(syms.size() < sym_limit){
      syms.push_back(_in);
    }
  }  
  
  bool HasSym() {
    return syms.size() != 0;
  }
  */

public:
  using base_t = AvidaCPU_Base<Host>;
  using typename base_t::genome_t;
  using typename base_t::inst_lib_t;
  
  Host(const genome_t & in_genome) : AvidaCPU_Base(in_genome) { ; }
  Host(emp::Ptr<const inst_lib_t> inst_lib) : AvidaCPU_Base(Genome(inst_lib)) { ; }
  Host(const inst_lib_t & inst_lib) : AvidaCPU_Base(Genome(&inst_lib)) { ; }

  Host() = default;
  Host(const Host &) = default;
  Host(Host &&) = default;

  virtual ~Host() { ; }

  
};

#endif

