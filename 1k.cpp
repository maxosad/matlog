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

typedef R<U<1,1>, S1<N, U<3,3>> > sum;
typedef R<Z, S2<sum,U<3,1> , U<3,3>> > mul;


typedef S1<N,Z> uno;
typedef R<uno,S2 <mul, U<3,1>, U<3,3>>  > st;




int main()
{
	std::vector <unsigned> xy {2,3};
    std::cout << "f(" << xy[0]<< ", " <<xy[1]  << ") = " << st::compute(xy) << "\n";
    return 0;



	return 0;
}
