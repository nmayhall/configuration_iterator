#ifndef COMBINATORIALINDEX_H
#define COMBINATORIALINDEX_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"
#include <algorithm>
//#include <sstream>
//#include <string>
//#include <map>

using namespace std;

class CombinatorialIndex 
{
    /*!
      This implementation of CombinatorialIndex uses a vector<int> as the primary
      object for describing a configuration. 

      @todo{ 
      Reimplement this class using bit operations
      }
     */
    
    private:
        int _n_orbs;  
        int _n_elec;  
        vector<int> _scr; ///< scratch vector
        vector<int> _config; ///< vector of orbital indices describing the config
        vector<int> _vir; ///< vector of orbital indices vacant in config
        void increment_comb(std::vector<int>& list, const int& Mstart, const int& Mend);
        void decrement_comb(std::vector<int>& list, const int& Mstart, const int& Mend);
        long int calc_nchk(const int&, const int&) const;    // n choose k 
        size_t _max;

    public:
        /// Default constructor
        CombinatorialIndex();
        CombinatorialIndex(const int&, const int&); //!< (NOrb,NElec)
        
        
        void print(); //!< Formatted print

        //  transformations
        //void operator++(){};
        void incr(); //!< Increment the combinatorial index by one, updating the configuration string
        void decr(); //!< Decrement the combinatorial index by one, updating the configuration string
        void set_config(const vector<int>&); //!< set the index to specified config

        //  computing data
        long int calc_linear_index(); //!< Calculate the linear index
        
        //  accessing data
        int occ(const int&i) const; ///< Get i'th occupied orbital in config
        int vir(const int&a) const; ///< Get a'th unnoccupied orbital in config 
        size_t max(); ///< Get length of index range

        /// Get vector of configuration
        vector<int> config() const {return _config;}; 


        int calc_single_excitation_sign(const int& n, const int& a); ///< Get sign obtained after creating single excitation (electron -> a) one string search

        int calc_single_excitation_sign2(const int& i, const int& a); ///< Get sign obtained after creating single excitation (i -> a) two string searches
        void apply_single_excitation(const int& i, const int& a); ///< Obtain new configuration after applying single substitution (i->a) 
        void single_excitation(const int& i, const int& a, size_t& ind, int& sign); 
};

#endif  

