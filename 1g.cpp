#include<bits/stdc++.h>

using namespace std;

struct Z {
    static unsigned compute (std::vector <unsigned> x) {
    	/*
    	for (auto x1 : x) {
			cout << x1 << " ";
    	}
    	cout <<"\n";
    	*/
        assert (x.size() == 1);
        return 0;
    }
};

struct N {
    static unsigned compute (std::vector <unsigned> x) {
        assert (x.size() == 1);
        return x[0] + 1;
    }
};

template <unsigned n, unsigned k>
struct U {
    static unsigned compute (std::vector <unsigned> x) {
/*
    	cout << n << " " << k << "x: ";
    	for (auto x1 : x)
		{
			cout << x1 << " ";
		}
		cout <<"\n";
*/
        assert (x.size() == n);
        return x[k-1];
    }
};

template <class f, class g1>
struct S1 {
    static unsigned compute (std::vector <unsigned> x) {
        std::vector <unsigned> g;
        g.push_back (g1::compute(x));
        //g.push_back (g2::compute(x));
        return f::compute(g);
    }
};

template <class f, class g>
struct R {
    static unsigned compute (std::vector <unsigned> x) {
    	/*
    	for ( auto x1 :x ) {
			cout << x1 << " ";
    	}
    	cout <<"\n";
*/
		assert (x.size() >= 1);
		if (x.back() == 0 ){
			x.pop_back();
        	return f::compute(x);
		} else {
            x.back()--;
            x.push_back(R<f,g>::compute(x));
            return g::compute(x);
		}
    }
};
template <class f, class g1, class g2>
struct S2 {
    static unsigned compute (std::vector <unsigned> x) {
        std::vector <unsigned> g;
        g.push_back (g1::compute(x));
        g.push_back (g2::compute(x));
        return f::compute(g);
    }
};
template <class f, class g1, class g2, class g3, class g4>
struct S4 {
    static unsigned compute (std::vector <unsigned> x) {
        std::vector <unsigned> g;
        g.push_back (g1::compute(x));
        g.push_back (g2::compute(x));
        g.push_back (g3::compute(x));
        g.push_back (g4::compute(x));
        return f::compute(g);
    }
};
template <class f, class g1, class g2, class g3>
struct S3 {
    static unsigned compute (std::vector <unsigned> x) {
        std::vector <unsigned> g;
        g.push_back (g1::compute(x));
        g.push_back (g2::compute(x));
        g.push_back (g3::compute(x));
        return f::compute(g);
    }
};


typedef S2<R<Z,U<3,2>>, U<1, 1>, U<1, 1>> sub1;
typedef R<U<1,1>, S1<N, U<3,3>> > sum;

typedef R<Z, S2<sum,U<3,1> , U<3,3>> > mul;

typedef S1 <Z, U<3,1> > ZZ;
typedef R<N, ZZ> ff;
typedef S2< ff,U<1,1>,U<1,1> >eq0;


typedef R<Z,U<3,2>> f3;
typedef S2<f3, U<1, 1>, U<1, 1>> f2;
typedef R<U<1,1> , S1<f2 , U<3,3>>> sub;

typedef S1<eq0, sub> le;//le(x,y)=eq0(sub(x,y))

typedef S2<mul,le, S2<le,U<2,2>,U<2,1>>>eq;//eq(x,y)=mul(le(x,y),le(y,x))

typedef R<U<3,3>, U<5,2>>f1;
typedef S4<f1,U<3,1>,U<3,2>,U<3,3>,U<3,1>>iff;

typedef R<Z, S3<iff, S2<eq, S2<sub, S1<N,U<3,2>>, U<3,3>> , U<3,1> >,  S1<N,U<3,2>>, U<3,3> >>  dm;


typedef S2<dm,U<2,2>,U<2,1>>divmax;//divmax(0,y)=Z(y)
typedef S2<sub, U<2,1>, divmax> mod;

//typedef S2<sum, U<3,1>, S2<eq, S1<N,U<3,1>>, S2<divmax, S1<N,U<3,1>>, U<3,2>>> > h;
//typedef S3 < U<2,1>, U<2,2>,  >d;

int main()
{
	std::vector <unsigned> xy {15, 7};
    std::cout << "f(" << xy[0]<< ", " <<xy[1]  << ") = " << mod::compute(xy) << "\n";
    return 0;



	return 0;
}





