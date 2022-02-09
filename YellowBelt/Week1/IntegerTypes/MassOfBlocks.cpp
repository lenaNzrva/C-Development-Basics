#include <iostream>

using namespace std;

int main()
{
    uint32_t N;
    uint16_t R, W, H, D;

    cin >> N >> R;
    
    int result = 0;
    for (uint32_t i=0; i<N; ++i)
    {
        cin >> W >> H >> D;
        result += (W*H*D*R);
    }

    cout << result;

    return 0;
}