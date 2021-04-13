#include<bits/stdc++.h>

using namespace std;

struct N {
    static unsigned compute (std::vector <unsigned> x) {
        assert (x.size() == 1);
        return x[0] + 1;
    }
};

template <unsigned n, unsigned k>
struct U {
    static unsigned compute (std::vector <unsigned> x) {
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

/*
	f(a,b) | b == 0 = a
		   | otherwise = f(a,b-1) + 1
*/
typedef R<U<1,1>, S1<N, U<3,3>> > sum;
int main()
{

	/*
	std::vector <unsigned> xy {5, 10};
    std::cout << "f(" << xy[0] << "," << xy[1] << ") = " << sum::compute(xy) << "\n";
    */
    std::cout << sum::compute({5,10}) << "\n";
    std::cout << sum::compute({5,0}) << "\n";
    std::cout << sum::compute({0,5}) << "\n";
    std::cout << sum::compute({0,0}) << "\n";
    std::cout << sum::compute({10,10}) << "\n";
    return 0;



	return 0;
}
