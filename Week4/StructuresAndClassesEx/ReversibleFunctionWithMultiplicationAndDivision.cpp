#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

struct FunctionPart
{
    char operand; 
    double value;
};

class Function
{
public:
    void AddPart(char operand, double value)
    {
        v = {operand, value};
        V.push_back(v);
    }

    double Apply(double value) const
    {
        for (const FunctionPart& part : V)
        {
            if (part.operand == '+') {value += part.value;}
            else if (part.operand == '-'){value -= part.value;}
            else if (part.operand == '*'){value *= part.value;}
            else{value /= part.value;}
        }
        return value;
    }
    void Invert()
    {
        reverse(V.begin(), V.end());
        for (FunctionPart& part : V)
        {
            if (part.operand == '+') {part.operand = '-';}
            else if (part.operand == '-') {part.operand = '+';}
            else if (part.operand == '*') {part.operand = '/';}
            else {part.operand = '*';}
        }
    }
private:   
    FunctionPart v;
    vector<FunctionPart> V;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}