#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <set>

using namespace std;
enum class Lang {
    DE, FR, IT  
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    const uint8_t N = regions.size();
    if (N == 0){return 0;}
    else if(N == 1){return 1;}
    else
    {
        map<tuple<string, string, map<Lang, string>, int64_t>, int> result;
        set<int> MaxResult;

        for (int i=0; i<N-1; ++i)
        {
            auto lhs = make_tuple(regions[i].std_name, 
            regions[i].parent_std_name, regions[i].names, regions[i].population);

            if (result.count(lhs) == 0)
            {
                for (int j=i+1; j<N; ++j)
                {
                    auto rhs = make_tuple(regions[j].std_name, 
                    regions[j].parent_std_name, regions[j].names, regions[j].population);
                    
                    if (rhs == lhs)
                    {
                        result[rhs] += 1;
                        MaxResult.insert(result[rhs]);
                    }
                }
            }   
        }
        if (MaxResult.size()==0){return 1;}
        else{return *MaxResult.rbegin()+1;}
    }
}

int main()
{
    return 0;
}