#include<bits/stdc++.h>

using namespace std;

class Time{
public:
	Time(int s = 0, int m = 0, int h = 0){
		if(h == 0 && m == 0 && s > 3600){
			hour = s / 3600;
			min = (s - (hour * 3600)) / 60;
			sec = s - (hour * 3600) - (min * 60); 
		}
		else if(h == 0 && m == 0 && s > 60){
			hour = h;
			min = s / 60;
			sec = s - (min * 60); 
		}
		else{
			hour = h;
			min = m;
			sec = s;
		}

	}

	friend ostream &operator<<(ostream &str, Time &val);
	friend istream &operator>>(istream &is, Time &val);

	Time operator-(const Time &rhs) const{
		int h = hour - rhs.hour, m = min - rhs.min, s = sec - rhs.sec;;
		if(s < 0){
			m -= 1;
			s = 60 + s;
		}
		if(m < 0){
			h -= 1;
			m = 60 + m;
		}
		return Time(s, m, h);
	}
private:
	int hour;
	int min;
	int sec;
};

ostream &operator<<(ostream &str, Time &val){
	if(val.hour > 0)
		str << val.hour << "h:" << val.min << "m:" << val.sec << "s";
	else if(val.min > 0)
		str << val.min << "m:" << val.sec << "s";
	else
		str << val.sec << "s";
	return str;
}

istream &operator>>(istream &is, Time &val){
	is >> val.hour >> val.min >> val.sec;
	return is;
}


int main(){
	Time t1(200);
	cout << t1 << endl;
	Time t2;
	cin >> t2;

	Time t3 = t2 - t1;
	cout << t3 << endl;
	return 0;
}