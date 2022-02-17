#include <iostream>
#include <cstddef>
using namespace std;

int main()
{
    uint32_t N;
    uint16_t R;
    uint16_t W, H, D;
    uint64_t TypeChanger = 1;

    cin >> N >> R;
    
    uint64_t result = 0;
    for (uint32_t i=0; i<N; ++i)
    {
        cin >> W >> H >> D;

        result += TypeChanger*W*H*D*R;
    }

    cout << result;

    return 0;
}