#include <iostream>
#include <cstring>
#include <list>
#include <stack>

enum e_Direction{e_UP=0, e_DOWN=1, e_LEFT=2, e_RIGHT=3};
const int SZ = 9;
const int MAX_G = 4;




struct State{
	char DataState[SZ];
	State *Generations[MAX_G];
} NullState, SourceState, DestinationState;

struct ProgrammStatus{
	
	bool dbg;
	bool IsOn(void){return dbg;}
	void Switch(void){ dbg = (dbg?false:true);}
	void Set(bool mode){dbg = mode;}
	
	
}Debug;

std::ostream &TargetLog = std::cout;
std::list<State>StorageOfStates;
std::stack<e_Direction>WayFromStartToFinish;

void CalculteAllGenerations(State &ParentState);
void WriteLog(const char *msg, const char* msg2 = NULL);
bool CheckCollisionOfState(const State &one, const State &two);

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main(int argc, char **argv){
	
	memset(NullState.DataState, -1, SZ);
	for(int i = 0; i < MAX_G; i++)
		NullState.Generations[i] = 0;

	memset(SourceState.DataState, -1, SZ);
	for(int i = 0; i < MAX_G; i++)
		SourceState.Generations[i] = 0;
		
	memset(DestinationState.DataState, -1, SZ);
	for(int i = 0; i < MAX_G; i++)
		DestinationState.Generations[i] = 0;

	Debug.Set(true);
	
	WriteLog("Start programm!", "Test run.");
	WriteLog("Write log 1");
	WriteLog("Write log 2");
	Debug.Set(false);
	WriteLog("Write log 3");
	Debug.Set(true);
	WriteLog("Write log 4");
	
	return 0;
}//end main()



void CalculteAllGenerations(State &ParentState){
	
	
	
	
}// end ClalculteAllGenerations()

bool CheckCollisionOfState(const State &one, const State &two){
	
	bool result = false;
	
	for(int i = 0; i < MAX_G; i++){
		if(one.DataState[i] == two.DataState[i]){
			
			result = true;
			break;
		}//if
		
	}// for
	
	return result;
}// end CheckCollisionOfState()



void WriteLog(const char *msg, const char* msg2){
	
	if(!Debug.IsOn()){
		return;
	}//if
	
	TargetLog << msg;
	if(msg2){
			TargetLog << " : " << msg2;
	}//if
	TargetLog << endl;
	TargetLog.flush();
	
}// end WriteLog()
