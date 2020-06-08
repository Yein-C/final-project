#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	ifstream fc;
	string cpu;
	double cpu_tem;
	
	cout<<"CPU thermometer start"<<endl;

	system("cat /sys/class/thermal/thermal_zone0/temp > cpu.txt");
	
	fc.open("cpu.txt");
	getline(fc, cpu);
	cpu_tem=stod(cpu);
	cpu_tem/=1000;
	if(cpu_tem>=70){
		cout<<"cpu: 70'c (96%)."<<endl;
		cout<<"SHUTDOWN after 3s"<<endl;
		system("sleep(3)");
		system("sudo shutdown -h now");
	}
	else if(cpu_tem>=65){
		cout<<"cpu: 65'c (89%). WARNING"<<endl;
		cout<<"SHUTDOWN after 1m"<<endl;
		system("sudo shutdown -h 1");
		cout<<"If you want to stop!!"<<endl<<endl;
		cout<<"  sudo shutdown -c  "<<endl;
	}
	else if(cpu_tem>=60){
		cout<<"cpu: 60'c (82%)."<<endl;
		cout<<"Maybe turned off while in use"<<endl;
	}
	else if(cpu_tem>=55){
		cout<<"cpu: 55'c"<<endl;
		cout<<"Why don't you turn off the RASPBERRY PI and take a break?"<<endl;
	}
	else if(cpu_tem>=40){
		cout<<"55'c~40'c  testing"<<endl;
	}
	
	if(cpu_tem<=0){
		cout<<"0'c. SHUTDOWN after 1m"<<endl;
		system("sudo shutdown -h 1");
	}
	
	return 0;
}
