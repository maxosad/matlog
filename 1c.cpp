#include<bits/stdc++.h>

using namespace std;

struct Z {
    static unsigned compute (std::vector <unsigned> x) {
    	for (auto x1 : x) {
			cout << x1 << " ";
    	}
    	cout <<"\n";
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

template <class f, class g1, class g2>
struct S2 {
    static unsigned compute (std::vector <unsigned> x) {
        std::vector <unsigned> g;
        g.push_back (g1::compute(x));
        g.push_back (g2::compute(x));
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
//S<f, U<1, 1>, U<1, 1>>
//typedef R<Z,U<3,2>> ff;
typedef S1<R<Z,U<3,2>>, U<1, 1>, U<1, 1>> sub1;

int main()
{
	std::vector <unsigned> xy {0};
    std::cout << "f(" << xy[0] << ") = " << sub1::compute(xy) << "\n";
    return 0;



	return 0;
}


