// =================================================================== //
// Givaro : Prime numbers
//              Factor sets :
//              Pollard's rho method for factorization
//              Elliptic curves factorization by Lenstra
// Needs Container structures : stl ones for instance
// Time-stamp: <29 Jun 04 16:11:22 Jean-Guillaume.Dumas@imag.fr> 
// =================================================================== //
#ifndef _GIVARO_FACTORISATION_H_
#define _GIVARO_FACTORISATION_H_

#include <iostream>
#include "givaro/givtimer.h"
#include "givaro/givinteger.h"
#include "givaro/givintprime.h"
#include "givaro/givrandom.h"

// #define BOUNDARY_factor TABMAX2

#define factor_first_primes(tmp,n) (tmp = iszero(mod(tmp,n,23))?23:( iszero(mod(tmp,n,19))?19:( iszero(mod(tmp,n,17))?17:  (iszero(mod(tmp,n,2))?2:( iszero(mod(tmp,n,3))?3:( iszero(mod(tmp,n,5))?5:( iszero(mod(tmp,n,7))?7: ( iszero(mod(tmp,n,11))?11:13 ))))))))

#define factor_second_primes(tmp,n) (tmp = iszero(mod(tmp,n,31))?31:( iszero(mod(tmp,n,29))?29: ( iszero(mod(tmp,n,37))?37: ( iszero(mod(tmp,n,41))?41:( iszero(mod(tmp,n,43))?43:  ( iszero(mod(tmp,n,71))?71:( iszero(mod(tmp,n,67))?67:( iszero(mod(tmp,n,61))?61:( iszero(mod(tmp,n,59))?59: ( iszero(mod(tmp,n,53))?53:( iszero(mod(tmp,n,47))?47: ( iszero(mod(tmp,n,97))?97: ( iszero(mod(tmp,n,89))?89:( iszero(mod(tmp,n,83))?83:( iszero(mod(tmp,n,79))?79:73)))))))))))))))


// =================================================================== //
// Set or Container of divisors, factors.
// =================================================================== //

template<class RandIter = GivRandom>
class IntFactorDom : public IntPrimeDom {
private:
    // 2*3*5*7*11*13*17*19*23
    const int PROD_first_primes;
    // 29*31*37*41*43*47*53*59*61*67*71*73*79*83*89*97
    const Rep PROD_second_primes;
protected:
    RandIter _g;

public:
    typedef RandIter random_generator;

    IntFactorDom(RandIter& g = *(new RandIter())) :  IntPrimeDom(),PROD_first_primes(223092870), PROD_second_primes("10334565887047481278774629361"), _g(g) {
#ifdef __GMP_PLUSPLUS__
	    seeding( _g.seed() );
#endif
    }

        //  loops defaulted to 0 forces Pollard's factorization to 
        //  be complete
    Rep& factor(Rep& r, const Rep& n, unsigned long loops = 0) const {
        if (isone(gcd(r,n,PROD_first_primes)))
            if (isone(gcd(r,n,PROD_second_primes))) {
#ifdef GIVARO_LENSTRA
                return Lenstra((RandIter&)_g, r, n);
#else
                return Pollard((RandIter&)_g, r, n, loops);
#endif
            } else
                return factor_second_primes(r,n);
        else 
            return factor_first_primes(r,n);
    }

        //  Factors are checked for primality
    Rep& primefactor(Rep& r, const Rep& n, unsigned long loops = 0) const {
	if (factor(r, n, loops) != 1) {
	   if (! isprime(r,5) ) {
		Rep nn = r; factor(r,nn, loops);
	   }
	   while (! isprime(r,5) ) {
		Rep nn = r;
        	if (isone(gcd(r,nn,PROD_first_primes))) {
            	   if (isone(gcd(r,nn,PROD_second_primes))) {
                	Pollard((RandIter&)_g, r, nn, loops);
            	   } else {
                	factor_second_primes(r,nn);
		   }
		} else {
            	   factor_first_primes(r,nn);
		}
	    	if (r == nn) {
			Lenstra((RandIter&)_g, r, nn) ;
			break; // In case Lenstra fails also
		}
           }
	}
	return r;
    }


        /// Factors with primes
        //  loops defaulted to 0 forces factorization to be complete
        //  otherwise returns if factorization is complete or not
        //  Factors are checked for primality
    template< template<class> class Container> bool set
        ( Container<Rep>& setint, Container<unsigned long>& setpwd,  const Rep& a, unsigned long loops = 0) const ;

        ///
    template< template<class> class Container> void set( Container<Rep>&,  const Rep&) const ;
        ///
    template< template<class> class Container> void Erathostene(Container<Rep>&, const Rep&) const ;
        /// returns a small factor
    Rep& Erathostene(Rep&,  const Rep& p ) const ;

        // Pollard with a bound on the number of loops
        // Bound 0 is without bound
    Rep& Pollard(RandIter&, Rep&, const Rep& n, unsigned long threshold = 0) const ;
        // returns a factor by Lenstra's elliptic curves method
    Rep& Lenstra(RandIter&, Rep&, const Rep& n, const Rep& B1 = 10000000, const unsigned long curves = 30) const ;
        ///
    template< template<class> class Container, template<class> class Cont2> Container<Rep>& divisors(Container<Rep>& L, const Cont2<Rep>& Lf, const Cont2<unsigned long>& Le)  const;
    template< template<class> class Container> Container<Rep>& divisors(Container<Rep>&, const Rep& ) const ;
    
    std::ostream& write(std::ostream& o, const Rep& n) const;
    template<class Array> std::ostream& write(std::ostream& o, Array&, const Rep& n) const;


private:
// Those are parameters for Pollard's algorithms
// Pollard_fctin : must be somewhat a "random" function in Z/nZ
// Pollard_cst can be a slight alternative for the Pfct x^2+1
#ifndef Pollard_cst
#define Pollard_cst 1
#endif
    
    Rep& Pollard_fctin(Rep & x, const Rep& n) const {
        mulin(x,x);
        addin(x,Pollard_cst);
        return modin(x,n);
    }

};

#include "givaro/givintfactor.inl"

#endif