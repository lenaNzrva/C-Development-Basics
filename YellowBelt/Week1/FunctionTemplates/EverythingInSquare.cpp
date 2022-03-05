#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

// Предварительное объявление шаблонных функций
template <typename SqrPass> SqrPass Sqr(SqrPass x);
template <typename VectorElem> vector<VectorElem> operator* (vector<VectorElem> V, const vector<VectorElem>& V2);
template <typename PKey, typename PValue> pair<PKey, PValue> operator* (pair<PKey, PValue> P, const pair<PKey, PValue>& P2);
template <typename MapKey, typename MapVal> map<MapKey, MapVal> operator* (map<MapKey, MapVal> M, const map<MapKey, MapVal>& M2);


// Объявляем шаблонные функции
template <typename SqrPass>
SqrPass Sqr(SqrPass x){return x*x;}

template <typename VectorElem>
vector<VectorElem> operator* (vector<VectorElem> V, const vector<VectorElem>& V2)
{
    for (auto &v : V){v = v*v;}
    // for (int i=0; i<V.size(); ++i){V[i] = }
    return V;
}

template <typename PKey, typename PValue>
pair<PKey, PValue> operator* (pair<PKey, PValue> P, const pair<PKey, PValue>& P2){return {P.first*P.first, P.second*P.second};}

template <typename MapKey, typename MapVal>
map<MapKey, MapVal> operator* (map<MapKey, MapVal> M, const map<MapKey, MapVal>& M2)
{
    for (auto &m : M){M[m.first] = m.second*m.second;}
    return M; 
}


int main()
{
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
    cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}