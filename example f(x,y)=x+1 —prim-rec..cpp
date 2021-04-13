// This program shows that f(x,y)=x+1 is primitive-recursive

#include <iostream>
#include <vector>
#include <assert.h>




template <class f, class g1>
struct S1 {
    static unsigned compute (std::vector <unsigned> x) {
        std::vector <unsigned> g;
        g.push_back (g1::compute(x));
        //g.push_back (g2::compute(x));
        return f::compute(g);
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
        assert (x.size() == n);
        return x[k-1];
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


typedef S1 < N, U<2,1> > f;

int main() {
    std::vector <unsigned> xy { 5, 17 };
    std::cout << "f(" << xy[0] << "," << xy[1] << ") = " << f::compute(xy) << "\n";
    return 0;
}
