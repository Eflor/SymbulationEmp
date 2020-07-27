#ifndef AVIDA_GP_HOST_H
#define AVIDA_GP_HOST_H

#include "AvidaGPSymbio.h"
#include "../../Empirical/source/hardware/AvidaGP.h"
#include "../../Empirical/source/config/ArgManager.h"
#include "../../Empirical/source/Evolve/World.h"
#include <iostream>
#include <vector>
using std::endl; using std::cout;

/*
* Host class made to able to use AvidaGP's structs in its file. 
*/
class Host : public emp::AvidaCPU_Base<Host>{
 private:
  emp::vector<Symbiont> syms;

  /*
  bool HasSym() {
    return syms.size() != 0;
  }
  */

public:
  using base_t = AvidaCPU_Base<Host>;
  using typename base_t::genome_t;
  using typename base_t::inst_lib_t;
  
  //Constructors
  Host(const genome_t & in_genome) : AvidaCPU_Base(in_genome) { ; }
  Host(emp::Ptr<const inst_lib_t> inst_lib) : AvidaCPU_Base(Genome(inst_lib)) { ; }
  Host(const inst_lib_t & inst_lib) : AvidaCPU_Base(Genome(&inst_lib)) { ; }
  Host() = default;
  Host(const Host &) = default;
  Host(Host &&) = default;

  //Sets hosts' Symbionts
  void SetSymbio(emp::vector<Symbiont> sym_in ){
    for (Symbiont s : sym_in){
      syms.push_back(s);
    }
  }

  //returns hosts' symbionts
  emp::vector<Symbiont> GetSymbio(){
    return syms;
  }
  //Destructor 
  virtual ~Host() { ; }

  
};

#endif

