#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;


// Предварительное объявление шаблонных функций
template <typename ForSqr> ForSqr Sqr(ForSqr x);
template <typename ForVec> vector<ForVec> Sqr(vector<ForVec> V); 
template <typename FirstP, typename SecondP> pair<FirstP,SecondP> Sqr(pair<FirstP, SecondP> P);
template <typename KeyM, typename ValueM> map<KeyM, ValueM> Sqr(map<KeyM, ValueM> M);


// Объявляем шаблонные функции
template <typename ForSqr>
ForSqr Sqr(ForSqr x){return x*x;}

template <typename ForVec>
vector<ForVec> Sqr(vector<ForVec> V) 
{
    for (auto &v : V){v = Sqr(v);}
    return V;
}

template <typename FirstP, typename SecondP>
pair<FirstP,SecondP> Sqr(pair<FirstP, SecondP> P){return {Sqr(P.first), Sqr(P.second)};}

template <typename KeyM, typename ValueM>
map<KeyM, ValueM> Sqr(map<KeyM, ValueM> M)
{
    for (auto &m: M){M[m.first] = Sqr(m.second);}
    return M;
}


int main()
{
    cout << "Int: " << Sqr(5) << endl;
    cout << "Double: " << Sqr(34.1) << endl;
    // // Пример вызова функции
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