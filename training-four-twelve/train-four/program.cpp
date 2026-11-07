#include <iostream>
using namespace std;

class Time {
  public:
    Time(int h = 0, int m = 0, int s = 0) {
      setTime(h,m,s);
    }

    void setTime(int h, int m, int s) {
      hour    = (h >= 0 && h <= 24) ? h : 0;
      minute  = (m >= 0 && m <= 60) ? m : 0;
      second = (s >= 0 && s <= 60) ? s : 0;
    }

    void printTime() {
      cout << (hour   < 10 ? "0" : "") << hour   << ":"
        << (minute < 10 ? "0" : "") << minute << ":"
        << (second < 10 ? "0" : "") << second << endl;
    }

    void tick() {
      second++;                    
      if (second == 60) {         
        second = 0;
        minute++;
        if (minute == 60) {      
          minute = 0;
          hour++;
          if (hour == 24) {    
            hour = 0;
          }
        }
      }
      printTime();            
    }

  private:
    int hour;
    int minute;
    int second;
};

int main() {
  Time timee(23, 59, 59);

  timee.tick();
  timee.tick();
  timee.tick();
  timee.tick();
  timee.tick();

  return 0;
}
