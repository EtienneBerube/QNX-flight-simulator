#include <iostream>
#include <pthread.h>
#include <sys/neutrino.h>
#include <unistd.h>
#include "Display.h"
#include "Radar.h"

using namespace std;
#define MY_PULSE_CODE 0x01

//Function initialization
void setupCommChannels();
void setupRadar();
void setupUserCLI();
void setupSimulation();
void setupDisplay();
void setupTimersAndThreads();
void startTimers();


//Global stuff
int radarChannelReceiveID;
int displayChannelReceiveID;
int historyChannelReceiveID;
int simulationChannelReceiveID;

AirplaneDB airplaneDB;

Radar radar;
timer_t radar_timer;
struct sigevent radar_event;
struct itimerspec radar_itime;

Display display(&airplaneDB);
timer_t display_timer;
struct sigevent display_event;
struct itimerspec display_itime;

timer_t history_timer;
struct sigevent history_event;
struct itimerspec history_itime;

timer_t simulation_timer;
struct sigevent simulation_event;
struct itimerspec simulation_itime;


void dummyFunction(void* arg){
	cout << "thread exec" << endl;
}

//TODO add other threads
pthread_t radar_thread;
pthread_t cli_thread;

string radar_file_url = "smtg";


//Startup routine
int main() {
	cout << "Hello World!!! NICE" << endl; // prints Hello World!!!
	char* cwd;
	char buff[PATH_MAX + 1];

	cwd = getcwd( buff, PATH_MAX + 1 );
	if( cwd != NULL ) {
	    printf( "My working directory is %s.\n", cwd );
	}
	return 0;
}

void setupCommChannels(){

}

void setupTimersAndThreads(){

	setupDisplay();
	setupRadar();

	//TODO add your shit here

	//When done, start
	startTimers();

}

void runDisplay(sigval value){
	display.displayCurrentState();
}

void setupDisplay(){

	SIGEV_THREAD_INIT( &display_event, &runDisplay, 0, NULL );

	timer_create(CLOCK_REALTIME, &display_event, &display_timer);

	display_itime.it_value.tv_sec = 5;
	display_itime.it_interval.tv_sec = 5;
}

void runRadar(sigval value){
	radar.executeRadar();
}

void setupRadar(){

	SIGEV_THREAD_INIT( &radar_event, &runRadar, 0, NULL );

	timer_create(CLOCK_REALTIME, &display_event, &display_timer);

	display_itime.it_value.tv_sec = 15;
	display_itime.it_interval.tv_sec = 15;
}



void startTimers(){
	timer_settime(radar_timer, 0, &radar_itime, NULL);
	timer_settime(display_timer, 0, &display_itime, NULL);
	timer_settime(simulation_timer, 0, &simulation_itime, NULL);
	timer_settime(history_timer, 0, &history_itime, NULL);
}

