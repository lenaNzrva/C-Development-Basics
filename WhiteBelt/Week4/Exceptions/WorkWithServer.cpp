#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    // return "Lena";
    // throw system_error(error_code());
    // throw invalid_argument("Invalid argument");

}

class TimeServer {
public:
    string GetCurrentTime() {
        try
        {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;

        }catch (system_error& sys_err)
        {
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // �亠仆���� �亠舒仍亳亰舒�亳�� ��仆从�亳亳 AskTimeServer, �弍亠亟亳�亠��, ��仂 ��仂 从仂亟 �舒弍仂�舒亠� 从仂��亠从�仆仂
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}