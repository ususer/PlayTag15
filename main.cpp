#include <iostream>
#include <cstring>
#include <list>
#include <stack>

enum e_Direction{e_UP=0, e_DOWN=1, e_LEFT=2, e_RIGHT=3};
const int SIZE_DATASTATE = 9;
const int MAX_G = 4;




struct State{
	char DataState[SIZE_DATASTATE];
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
void PrintDataState(const State &state);
bool CheckCollisionOfState(const State &one, const State &two);

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main(int argc, char **argv){
	
	Debug.Set(true);

	
	WriteLog("Clear data", "NULL");
	memset(NullState.DataState, -1, SIZE_DATASTATE);
	for(int i = 0; i < MAX_G; i++)
		NullState.Generations[i] = 0;

	WriteLog("Get data", "SRC");
	for(int i = 0; i < SIZE_DATASTATE; i++){
		cin >> SourceState.DataState[i];
	}//for
		
	WriteLog("Get data", "DST");
	for(int i = 0; i < SIZE_DATASTATE; i++){
		cin >> DestinationState.DataState[i];
	}//for

	WriteLog("Show data", "Null");
	PrintDataState(NullState);
	WriteLog("Show data", "SRC");
	PrintDataState(SourceState);
	WriteLog("Show data", "DST");
	PrintDataState(DestinationState);

	

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
			TargetLog << " \t " << msg2;
	}//if
	TargetLog << endl;
	TargetLog.flush();
	
}// end WriteLog()


void PrintDataState(const State &state){
	
	for(int i = 0; i < SIZE_DATASTATE; i++){
		cout << state.DataState[i];
		if(i + 1 != SIZE_DATASTATE){
				cout  << '-';
		}		
	}// for
	cout << endl;
	
	
}// end void PrintDataState();
