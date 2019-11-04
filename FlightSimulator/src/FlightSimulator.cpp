#include <iostream>
#include <pthread.h>
#include <sys/neutrino.h>
#include <unistd.h>

using namespace std;

//Function initialization
void setupComponents();
void setupRadar();
void setupUserCLI();
void setupSimulation();

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

void setupComponents(){
	int chid =
	ChannelCreate(_NTO_CHF_FIXED_PRIORITY);

}

void setupRadar(){
	pthread_attr_t attr;
	pthread_attr_init( &attr );

	//TODO add run() function in radar
	pthread_create( &radar_thread, &attr, &dummyFunction, NULL);
	pthread_setschedprio( thread, 2 );
}

void setupUserCLI(){
	pthread_attr_t attr;
	pthread_attr_init( &attr );

	//TODO add run() function in CLI
	pthread_create( &cli_thread, &attr, &dummyFunction, NULL);
	pthread_setschedprio( thread, 2 );
}
