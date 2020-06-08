#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	ifstream file;
	string cpu;
	double cpu_tem;

	system("cat /sys/class/thermal/thermal_zone0/temp > main.txt");
	
	file.open("main.txt");
	getline(file, cpu);
	cpu_tem=stod(cpu);
	cpu_tem/=1000;
	if(cpu_tem>80){
		cout<<"I'm okay"<<endl;
	}
	
	else if(cpu_tem>=40){
		cout<<"The cpu is too Hot, So I'm going to SHUTDOWN after 10sec"<<endl;
		system("sleep 10");
		system("sudo shutdown -h now");
	}
	cout<<cpu<<endl;
	cout<<cpu_tem<<" 'C"<<endl;
	
	
	
	return 0;
}
