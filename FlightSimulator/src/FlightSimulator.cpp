#include <iostream>
#include <pthread.h>
#include <sys/neutrino.h>
#include <unistd.h>
#include "Display.h"
#include "Radar.h"
#include "History.h"
#include "Simulation.h"
#include "Operator.h"

using namespace std;
#define MY_PULSE_CODE 0x01

//Function initialization
void setupRadar();
void setupOperator();
void setupSimulation();
void setupDisplay();
void setupHistory();
void setupTimersAndThreads();
void startTimers();


//Global stuff
pthread_mutex_t synchronizer = PTHREAD_MUTEX_INITIALIZER;

AirplaneDB airplaneDB;
Operator anOperator;

Radar radar(&airplaneDB);
timer_t radar_timer;
struct sigevent radar_event;
struct itimerspec radar_itime;

Display display(&airplaneDB);
timer_t display_timer;
struct sigevent display_event;
struct itimerspec display_itime;

History history(&radar);
timer_t history_timer;
struct sigevent history_event;
struct itimerspec history_itime;

Simulation simulation(&airplaneDB);
timer_t simulation_timer;
struct sigevent simulation_event;
struct itimerspec simulation_itime;


//Startup routine
int main() {
	cout << "Flight Simulator Start Deano" << endl; // prints Hello World!!!
	char* cwd;
	char buff[PATH_MAX + 1];

	cwd = getcwd( buff, PATH_MAX + 1 );
	if( cwd != NULL ) {
	    printf( "My working directory is %s.\n", cwd );
	}

	cout << "Starting project" << endl;

	pthread_mutex_init(&synchronizer, NULL);

	setupTimersAndThreads();

	while(true);
}

void setupTimersAndThreads(){

	setupDisplay();
	setupRadar();
	setupHistory();
	setupSimulation();
	setupOperator();

	//TODO add your shit here

	//When done, start
	startTimers();

}

void runDisplay(sigval value){
	pthread_mutex_lock( &synchronizer);
	display.displayCurrentState();
	pthread_mutex_unlock( &synchronizer);
}

void setupDisplay(){

	SIGEV_THREAD_INIT( &display_event, &runDisplay, 0, NULL );

	timer_create(CLOCK_REALTIME, &display_event, &display_timer);

	display_itime.it_value.tv_sec = 5;
	display_itime.it_interval.tv_sec = 5;
}

void runRadar(sigval value){
	pthread_mutex_lock( &synchronizer);
	radar.executeRadar();
	pthread_mutex_unlock( &synchronizer);
}

void setupRadar(){

	SIGEV_THREAD_INIT( &radar_event, &runRadar, 0, NULL );

	timer_create(CLOCK_REALTIME, &radar_event, &radar_timer);

	radar_itime.it_value.tv_sec = 15;
	radar_itime.it_interval.tv_sec = 15;
}

void runHistory(sigval value){
	pthread_mutex_lock( &synchronizer);
	history.saveState();
	pthread_mutex_unlock( &synchronizer);
}

void setupHistory(){
	SIGEV_THREAD_INIT( &history_event, &runHistory, 0, NULL );

	timer_create(CLOCK_REALTIME, &history_event, &history_timer);

	history_itime.it_value.tv_sec = 60;
	history_itime.it_interval.tv_sec = 60;
}

void runSimulation(sigval value){
	pthread_mutex_lock( &synchronizer);
	simulation.run();
	pthread_mutex_unlock( &synchronizer);
}

void setupSimulation(){
	SIGEV_THREAD_INIT( &simulation_event, &runSimulation, 0, NULL );

	timer_create(CLOCK_REALTIME, &simulation_event, &simulation_timer);

	simulation_itime.it_value.tv_sec = 1;
	simulation_itime.it_interval.tv_sec = 1;
}

void* runOperator(void*  arg){
	anOperator.run(airplaneDB);
	return nullptr;
}

void setupOperator(){
	pthread_create( NULL, NULL, &runOperator, NULL );
}

void startTimers(){
	timer_settime(radar_timer, 0, &radar_itime, NULL);
	timer_settime(display_timer, 0, &display_itime, NULL);
	timer_settime(simulation_timer, 0, &simulation_itime, NULL);
	timer_settime(history_timer, 0, &history_itime, NULL);
}

