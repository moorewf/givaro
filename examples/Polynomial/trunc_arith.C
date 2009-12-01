// Copyright(c)'1994-2009 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software. 
// see the COPYRIGHT file for more details.

#include <iostream>
#include <givaro/givrandom.h>
#include <givaro/givtimer.h>
#include <givaro/givgfq.h>
#include <givaro/givpoly1.h>
#include <givaro/givtruncdomain.h>


long long count = 0;

bool TestAdd(const TruncDom< GFqDom<int> >& DP, const TruncDom< GFqDom<int> >::Element& P, const TruncDom< GFqDom<int> >::Element& Q, size_t d1, size_t d2) 
{
    ++count;
    TruncDom< GFqDom<int> >::Element R, T, V;
    DP.add ( R, P, Q, d1, d2); // R = P*Q;
//     DP.write( DP.write(
//         std::cout << "[(" , P ) << ") + (", Q) << ")]_" << d1 << '^' << d2 ;
//     DP.write(std::cout << " = " , R) << std::endl;
    
    DP.add (T, P, Q);
    V=T;
    DP.truncin(V,d1,d2);

    if( DP.areNEqual( V, R) ) {
        std::cerr << "ERROR ADD:" << count << std::endl;
        DP.write(std::cout << "  R: " , R) << std::endl;
        DP.write(std::cout << "  T: " , T) << std::endl;
        DP.write(std::cout << "  V: " , V) << std::endl;
        Degree dP; DP.degree(dP,P);
        Degree dQ; DP.degree(dQ,Q);
        Degree vP; DP.val(vP,P);
        Degree vQ; DP.val(vQ,Q);
        std::cerr << "vR: " << vP << ", dR: " << dP << ", vP: " << vQ << ", dP: " << dQ << ", v: " << d1 << ", d: " << d2 << std::endl;
        return false;
    }
    return true;
}

bool TestSub(const TruncDom< GFqDom<int> >& DP, const TruncDom< GFqDom<int> >::Element& P, const TruncDom< GFqDom<int> >::Element& Q, size_t d1, size_t d2) 
{
    ++count;
    TruncDom< GFqDom<int> >::Element R, T, V;
    DP.sub ( R, P, Q, d1, d2); // R = P*Q;
//     DP.write( DP.write(
//         std::cout << "[(" , P ) << ") + (", Q) << ")]_" << d1 << '^' << d2 ;
//     DP.write(std::cout << " = " , R) << std::endl;
  
    DP.sub (T, P, Q);
    V=T;
    DP.truncin(V,d1,d2);

    if( DP.areNEqual( V, R) ) {
        std::cerr << "ERROR SUB:" << count << std::endl;
        DP.write(std::cout << "  R: " , R) << std::endl;
        DP.write(std::cout << "  T: " , T) << std::endl;
        DP.write(std::cout << "  V: " , V) << std::endl;
        Degree dP; DP.degree(dP,P);
        Degree dQ; DP.degree(dQ,Q);
        Degree vP; DP.val(vP,P);
        Degree vQ; DP.val(vQ,Q);
        std::cerr << "vR: " << vP << ", dR: " << dP << ", vP: " << vQ << ", dP: " << dQ << ", v: " << d1 << ", d: " << d2 << std::endl;
        return false;
    }
    return true;
}

bool TestMul(const TruncDom< GFqDom<int> >& DP, const TruncDom< GFqDom<int> >::Element& P, const TruncDom< GFqDom<int> >::Element& Q, size_t d1, size_t d2) 
{
    ++count;
    TruncDom< GFqDom<int> >::Element R, T, V;
    DP.mul ( R, P, Q, d1, d2); // R = P*Q;
//     DP.write( DP.write(
//         std::cout << "[(" , P ) << ") + (", Q) << ")]_" << d1 << '^' << d2 ;
//     DP.write(std::cout << " = " , R) << std::endl;
   
    DP.mul (T, P, Q);
    V=T;
    DP.truncin(V,d1,d2);

    if( DP.areNEqual( V, R) ) {
        std::cerr << "ERROR MUL:" << count << std::endl;
        DP.write(std::cout << "  R: " , R) << std::endl;
        DP.write(std::cout << "  T: " , T) << std::endl;
        DP.write(std::cout << "  V: " , V) << std::endl;
        Degree dP; DP.degree(dP,P);
        Degree dQ; DP.degree(dQ,Q);
        Degree vP; DP.val(vP,P);
        Degree vQ; DP.val(vQ,Q);
        std::cerr << "vR: " << vP << ", dR: " << dP << ", vP: " << vQ << ", dP: " << dQ << ", v: " << d1 << ", d: " << d2 << std::endl;
        return false;
    }
    return true;
}

bool TestAxpy(const TruncDom< GFqDom<int> >& DP, const TruncDom< GFqDom<int> >::Element& P, const TruncDom< GFqDom<int> >::Element& Q, const TruncDom< GFqDom<int> >::Element& G, size_t d1, size_t d2) 
{
    ++count;
    TruncDom< GFqDom<int> >::Element R, T, V;
    DP.axpy ( R, P, Q, G, d1, d2); // R = P*Q;
//     DP.write( DP.write(
//         std::cout << "[(" , P ) << ") + (", Q) << ")]_" << d1 << '^' << d2 ;
//     DP.write(std::cout << " = " , R) << std::endl;
    
    DP.axpy (T, P, Q, G);
    V=T;
    DP.truncin(V,d1,d2);

    if( DP.areNEqual( V, R) ) {
        std::cerr << "ERROR Axpy:" << std::endl;
        DP.write(std::cout << "  P: " , P) << std::endl;
        DP.write(std::cout << "  Q: " , Q) << std::endl;
        DP.write(std::cout << "  G: " , G) << std::endl;
        DP.write(std::cout << "  R: " , R) << std::endl;
        DP.write(std::cout << "  T: " , T) << std::endl;
        DP.write(std::cout << "  V: " , V) << std::endl;
        Degree dP; DP.degree(dP,P);
        Degree dQ; DP.degree(dQ,Q);
        Degree dG; DP.degree(dG,G);
        Degree vP; DP.val(vP,P);
        Degree vQ; DP.val(vQ,Q);
        Degree vG; DP.val(vG,G);
        std::cerr << "vP: " << vP << ", dP: " << dP << ", vQ: " << vQ << ", dQ: " << dQ << ", vG: " << vG << ", dG: " << dG << ", v: " << d1 << ", d: " << d2 << std::endl;
        return false;
    }
    return true;
}

bool TestAxmy(const TruncDom< GFqDom<int> >& DP, const TruncDom< GFqDom<int> >::Element& P, const TruncDom< GFqDom<int> >::Element& Q, const TruncDom< GFqDom<int> >::Element& G, size_t d1, size_t d2) 
{
    ++count;
    TruncDom< GFqDom<int> >::Element R, T, V;
    DP.axmy ( R, P, Q, G, d1, d2); // R = P*Q;
//     DP.write( DP.write(
//         std::cout << "[(" , P ) << ") + (", Q) << ")]_" << d1 << '^' << d2 ;
//     DP.write(std::cout << " = " , R) << std::endl;
    
    DP.axmy (T, P, Q, G);
    V=T;
    DP.truncin(V,d1,d2);

    if( DP.areNEqual( V, R) ) {
        std::cerr << "ERROR Axmy:" << std::endl;
        DP.write(std::cout << "  R: " , R) << std::endl;
        DP.write(std::cout << "  T: " , T) << std::endl;
        DP.write(std::cout << "  V: " , V) << std::endl;
        Degree dP; DP.degree(dP,P);
        Degree dQ; DP.degree(dQ,Q);
        Degree vP; DP.val(vP,P);
        Degree vQ; DP.val(vQ,Q);
        std::cerr << "vR: " << vP << ", dR: " << dP << ", vP: " << vQ << ", dP: " << dQ << ", v: " << d1 << ", d: " << d2 << std::endl;
        return false;
    }
    return true;
}

bool TestMaxpy(const TruncDom< GFqDom<int> >& DP, const TruncDom< GFqDom<int> >::Element& P, const TruncDom< GFqDom<int> >::Element& Q, const TruncDom< GFqDom<int> >::Element& G, size_t d1, size_t d2) 
{
    ++count;
    TruncDom< GFqDom<int> >::Element R, T, V;
    DP.maxpy ( R, P, Q, G, d1, d2); // R = P*Q;
//     DP.write( DP.write(
//         std::cout << "[(" , P ) << ") + (", Q) << ")]_" << d1 << '^' << d2 ;
//     DP.write(std::cout << " = " , R) << std::endl;
    
    DP.maxpy (T, P, Q, G);
    V=T;
    DP.truncin(V,d1,d2);

    if( DP.areNEqual( V, R) ) {
        std::cerr << "ERROR Maxpy:" << std::endl;
        DP.write(std::cout << "  R: " , R) << std::endl;
        DP.write(std::cout << "  T: " , T) << std::endl;
        DP.write(std::cout << "  V: " , V) << std::endl;
        Degree dP; DP.degree(dP,P);
        Degree dQ; DP.degree(dQ,Q);
        Degree vP; DP.val(vP,P);
        Degree vQ; DP.val(vQ,Q);
        std::cerr << "vR: " << vP << ", dR: " << dP << ", vP: " << vQ << ", dP: " << dQ << ", v: " << d1 << ", d: " << d2 << std::endl;
        return false;
    }
    return true;
}


int main(int argc, char ** argv) {

 {
    long seed = (argc>1?atoi(argv[1]):BaseTimer::seed());
    std::cerr << "seed: " << seed << std::endl;

    GFqDom<int> Z101( 101, 1 );  // integers modulo 101

    // Polynomials over Z101, with X as indeterminate
    TruncDom< GFqDom<int> > DP101( Z101, Indeter("X") );
    TruncDom< GFqDom<int> >::Element P, Q, R, monomial;
    GFqDom<int>::Element tmp;

    DP101.assign( P, Z101.init(tmp,5) ); // P is degree 0 polynomial : 5 modulo 101
    DP101.write( std::cout << "P: " , P )<< std::endl;
    DP101.init( monomial, Degree(1), 33UL) ; // -33 X
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    Degree deg,val;
    DP101.degree(deg,monomial);
    DP101.val(val,monomial);
    DP101.write( std::cout << "[m]_" << val << '^' << deg << ": " , monomial )<< std::endl;
    DP101.addin( P, monomial ); // P += monomial
    DP101.write( std::cout << "P: " , P )<< std::endl;
    DP101.init( monomial, Degree(2), 12UL) ; // 12 X^2
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( P, monomial ); // P is now 5-33*X+12*X^2
    DP101.write( std::cout << "P: " , P )<< std::endl;

//     // DP101.read( std::cin, P); // would read P as a succession of integers :
//                                 // deg leadcoeff (lead-1)coeff ... unitcoeff
    Q = P;
    DP101.write( std::cout << "P: " , P )<< std::endl;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    

    DP101.init( Q, Degree(0), 6UL ); 
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.init( monomial, Degree(4), 3UL);
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.init( monomial, Degree(1), 75UL);
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.init( monomial, Degree(3), 45UL);
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.subin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    // Q is now 3*X^4+75*X-45*X^3+6

    DP101.mulin( Q, Degree(15) ) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.mulin( monomial, Degree(32));
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.subin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;

    DP101.divin( Q, Degree(5) ) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.divin( monomial, Degree(12));
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.subin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;

    DP101.divin( monomial, Degree(10));
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.subin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;

    DP101.divin( monomial, Degree(10));
    DP101.write( std::cout << "m: " , monomial )<< std::endl;
    DP101.addin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.subin( Q, monomial) ;
    DP101.write( std::cout << "Q: " , Q )<< std::endl;
    DP101.setval(Q);
    DP101.write( std::cout << "Q: " , Q )<< std::endl;

    DP101.mulin( P, Degree(15) ) ;

    DP101.mul ( R, P, Q); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "(" , P ) << ") * (", Q) << ")";
    DP101.write(std::cout << " = " , R) << std::endl;

    DP101.mul ( R, P, Q, Degree(28), Degree(30)); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "[(" , P ) << ") * (", Q) << ")]_28^30";
    DP101.write(std::cout << " = " , R) << std::endl;
    DP101.mul ( R, P, Q, Degree(0), Degree(30)); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "[(" , P ) << ") * (", Q) << ")]_0^30";
    DP101.write(std::cout << " = " , R) << std::endl;
    DP101.mul ( R, P, Q, Degree(28), Degree(100)); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "[(" , P ) << ") * (", Q) << ")]_28^100";
    DP101.write(std::cout << " = " , R) << std::endl;
    DP101.mul ( R, P, Q, Degree(4), Degree(10)); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "[(" , P ) << ") * (", Q) << ")]_4^10";
    DP101.write(std::cout << " = " , R) << std::endl;
    DP101.mul ( R, P, Q, Degree(75), Degree(100)); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "[(" , P ) << ") * (", Q) << ")]_75^100";
    DP101.write(std::cout << " = " , R) << std::endl;
    DP101.setval(R);
    DP101.write( std::cout << "R: " , R )<< std::endl;

    DP101.mulin( Q, Degree(3) ) ;

    DP101.add ( R, P, Q); // R = P*Q;
    DP101.write( DP101.write(
        std::cout << "(" , P ) << ") + (", Q) << ")";
    DP101.write(std::cout << " = " , R) << std::endl;
    



    bool success;

    success = TestAdd(DP101, P, Q, 28, 30);
    success &= TestAdd(DP101, P, Q, 0, 30);
    success &= TestAdd(DP101, P, Q, 28, 100);
    success &= TestAdd(DP101, P, Q, 4, 10);
    success &= TestAdd(DP101, P, Q, 75, 100);
    success &= TestAdd(DP101, P, Q, 12, 18);
    success &= TestAdd(DP101, P, Q, 13, 18);
    success &= TestAdd(DP101, P, Q, 14, 18);
    success &= TestAdd(DP101, P, Q, 15, 18);
    success &= TestAdd(DP101, P, Q, 16, 18);
    success &= TestAdd(DP101, P, Q, 17, 18);
    success &= TestAdd(DP101, P, Q, 18, 18);
    success &= TestAdd(DP101, P, Q, 12, 17);
    success &= TestAdd(DP101, P, Q, 13, 17);
    success &= TestAdd(DP101, P, Q, 14, 17);
    success &= TestAdd(DP101, P, Q, 15, 17);
    success &= TestAdd(DP101, P, Q, 16, 17);
    success &= TestAdd(DP101, P, Q, 17, 17);
    success &= TestAdd(DP101, P, Q, 12, 16);
    success &= TestAdd(DP101, P, Q, 13, 16);
    success &= TestAdd(DP101, P, Q, 14, 16);
    success &= TestAdd(DP101, P, Q, 15, 16);
    success &= TestAdd(DP101, P, Q, 16, 16);
    success &= TestAdd(DP101, P, Q, 12, 15);
    success &= TestAdd(DP101, P, Q, 13, 15);
    success &= TestAdd(DP101, P, Q, 14, 15);
    success &= TestAdd(DP101, P, Q, 15, 15);
    success &= TestAdd(DP101, P, Q, 12, 14);
    success &= TestAdd(DP101, P, Q, 13, 14);
    success &= TestAdd(DP101, P, Q, 14, 14);
    success &= TestAdd(DP101, P, Q, 12, 13);
    success &= TestAdd(DP101, P, Q, 13, 13);
    success &= TestAdd(DP101, P, Q, 12, 12);

    success &= TestAdd(DP101, Q, P, 12, 18);
    success &= TestAdd(DP101, Q, P, 13, 18);
    success &= TestAdd(DP101, Q, P, 14, 18);
    success &= TestAdd(DP101, Q, P, 15, 18);
    success &= TestAdd(DP101, Q, P, 16, 18);
    success &= TestAdd(DP101, Q, P, 17, 18);
    success &= TestAdd(DP101, Q, P, 18, 18);
    success &= TestAdd(DP101, Q, P, 12, 17);
    success &= TestAdd(DP101, Q, P, 13, 17);
    success &= TestAdd(DP101, Q, P, 14, 17);
    success &= TestAdd(DP101, Q, P, 15, 17);
    success &= TestAdd(DP101, Q, P, 16, 17);
    success &= TestAdd(DP101, Q, P, 17, 17);
    success &= TestAdd(DP101, Q, P, 12, 16);
    success &= TestAdd(DP101, Q, P, 13, 16);
    success &= TestAdd(DP101, Q, P, 14, 16);
    success &= TestAdd(DP101, Q, P, 15, 16);
    success &= TestAdd(DP101, Q, P, 16, 16);
    success &= TestAdd(DP101, Q, P, 12, 15);
    success &= TestAdd(DP101, Q, P, 13, 15);
    success &= TestAdd(DP101, Q, P, 14, 15);
    success &= TestAdd(DP101, Q, P, 15, 15);
    success &= TestAdd(DP101, Q, P, 12, 14);
    success &= TestAdd(DP101, Q, P, 13, 14);
    success &= TestAdd(DP101, Q, P, 14, 14);
    success &= TestAdd(DP101, Q, P, 12, 13);
    success &= TestAdd(DP101, Q, P, 13, 13);
    success &= TestAdd(DP101, Q, P, 12, 12);


    GivRandom generator(seed);
    
    for(size_t i=0; i<2000; ++i) {
        long deg1 = generator() % 75;
        long deg2 = generator() % 85;
        long deg3 = generator() % 155;
        long v1 = generator() % 195;
        long v2 = v1 + (generator() % 5);
        DP101.random(generator, P, Degree(deg1) );
        DP101.random(generator, Q, Degree(deg2) );
        DP101.random(generator, R, Degree(deg3) );
        Degree dP; DP101.degree(dP,P);
        Degree dQ; DP101.degree(dQ,Q);
        Degree dR; DP101.degree(dR,R);
        Degree vP; DP101.val(vP,P);
        Degree vQ; DP101.val(vQ,Q);
        Degree vR; DP101.val(vR,R);
        success &= TestAdd(DP101, P, Q, v1, v2 );
        success &= TestSub(DP101, P, Q, v1, v2 );
        success &= TestMul(DP101, P, Q, v1, v2 );
        success &= TestAxpy(DP101, P, Q, R, v1, v2 );
        success &= TestAxmy(DP101, P, Q, R, v1, v2 );
        success &= TestMaxpy(DP101, P, Q, R, v1, v2 );
    }

    if (! success) {
        std::cerr << "Error: " << seed << std::endl;
    } else {
        std::cerr << "Success:" << count << std::endl;
    }

    success &= TestAxpy(DP101, P, Q, monomial, 11, 11);



//     DP101.gcd ( R, P, Q); // 

//     DP101.write( DP101.write( DP101.write(
//          std::cout << "gcd(", P ) << ",", Q) << ") = ", R) << std::endl;

//     DP101.lcm ( R, P, Q); //
//     DP101.write( DP101.write( DP101.write(
//          std::cout << "lcm(", P ) << ",", Q) << ") = ", R) << std::endl;
//     DP101.lcm ( R, Q, P); // 
//     DP101.write( DP101.write( DP101.write(
//          std::cout << "lcm(", Q ) << ",", P) << ") = ", R) << std::endl;

 }   
 return 0;
}