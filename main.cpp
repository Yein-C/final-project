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
		system("aplay /usr/share/sounds/alsa/Front_Center.wav");
		cout<<endl<<"cpu: 70'c(96%) or more."<<endl;
		cout<<"SHUTDOWN after 3s"<<endl<<endl;
		system("sleep(3)");
		system("sudo shutdown -h now");
	}
	else if(cpu_tem>=65){
		system("aplay /usr/share/sounds/alsa/Rear_Left.wav");
		cout<<endl<<"cpu:  70'c ~ 65'c(89%). WARNING"<<endl;
		cout<<"SHUTDOWN after 1m"<<endl<<endl;
		system("sudo shutdown -h 1");
		cout<<"If you want to stop!!"<<endl<<endl;
		cout<<"  sudo shutdown -c  "<<endl<<endl;
	}
	else if(cpu_tem>=60){
		system("ffplay ~/final-project/sound/Alarm_Clock.mp3");
		cout<<endl<<"cpu:  65'c ~ 60'c(82%)."<<endl;
		cout<<"Maybe turned off while in use"<<endl<<endl;
	}
	else if(cpu_tem>=55){
		system("aplay /usr/share/sounds/alsa/Front_Left.wav");
		cout<<endl<<"cpu:  60'c ~ 55'c"<<endl;
		cout<<"Why don't you turn off the RASPBERRY PI and take a break?"<<endl<<endl;
	}
	else if(cpu_tem>=40){
		system("aplay /usr/share/sounds/alsa/Side_Left.wav");
		cout<<endl<<"cpu:  55'c ~ 40'c"<<endl;
		cout<<"It's Okay."<<endl<<endl;;
	}

	
	if(cpu_tem<=0){
		system("aplay /usr/share/sounds/alsa/Noise.wav");
		cout<<endl<<"0'c. SHUTDOWN after 1m"<<endl<<endl;
		system("sudo shutdown -h 1");
	}
	
	cout<<" * cpu: "<<cpu_tem<<"'c"<<endl<<endl;
	
	system("mv ~/cpu.txt ~/final-project/");
	fc.close();

	return 0;
}
