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

Radar radar;
timer_t radar_timer;
struct sigevent radar_event;
struct itimerspec radar_itime;

Display Display;
timer_t display_timer;
struct sigevent display_event;
struct itimerspec display_itime;

timer_t history_timer;
struct sigevent history_event;
struct itimerspec history_itime;

timer_t simulation_timer;
struct sigevent simulation_event;
struct itimerspec simulation_itime;


void* dummyFunction(void* arg){
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
	int radarChannelReceiveID = ChannelCreate(_NTO_CHF_FIXED_PRIORITY);
	int displayChannelReceiveID = ChannelCreate(_NTO_CHF_FIXED_PRIORITY);
	int historyChannelReceiveID = ChannelCreate(_NTO_CHF_FIXED_PRIORITY);
	int simulationChannelReceiveID = ChannelCreate(_NTO_CHF_FIXED_PRIORITY);
}

void setupTimersAndThreads(){

	setupDisplay();
	setupRadar();


	//Setting up environment simulation
	simulation_event.sigev_notify = SIGEV_PULSE;
	simulation_event.sigev_coid = ConnectAttach(ND_LOCAL_NODE, 0, radarChannelReceiveID, _NTO_SIDE_CHANNEL, 0);
	simulation_event.sigev_priority = getprio(0);
	simulation_event.sigev_code = MY_PULSE_CODE;

	timer_create(CLOCK_REALTIME, &simulation_event, &simulation_timer);

	simulation_itime.it_value.tv_sec = 15;
	simulation_itime.it_interval.tv_sec = 15;

	//Setting up history
	history_event.sigev_notify = SIGEV_PULSE;
	history_event.sigev_coid = ConnectAttach(ND_LOCAL_NODE, 0, radarChannelReceiveID, _NTO_SIDE_CHANNEL, 0);
	history_event.sigev_priority = getprio(0);
	history_event.sigev_code = MY_PULSE_CODE;

	timer_create(CLOCK_REALTIME, &history_event, &history_timer);

	history_itime.it_value.tv_sec = 15;
	history_itime.it_interval.tv_sec = 15;

	//When done, start
	startTimers();

}

void setupDisplay(){
	pthread_attr attr;

	SIGEV_THREAD_INIT( &display_event, &Display::getThreadRunnable, &display, attr );

	timer_create(CLOCK_REALTIME, &display_event, &display_timer);

	display_itime.it_value.tv_sec = 5;
	display_itime.it_interval.tv_sec = 5;
}

void setupRadar(){
	pthread_attr attr;

	SIGEV_THREAD_INIT( &radar_event, &Radar::getThreadRunnable, &radar, attr );

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

