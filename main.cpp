#include <iostream>
#include <cstring>
#include <list>
#include <stack>
#include <cstdlib>

enum e_Direction{e_UP=0, e_DOWN=1, e_LEFT=2, e_RIGHT=3};
const int SIZE_DATASTATE = 9;
const int MAX_G = 4;




struct State{
	int DataState[SIZE_DATASTATE];
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
bool CheckStateOfCorrect(const State &state);
void ExitFail(const char *msg);
State* CreateState(void);

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

	WriteLog("main", "Get data SRC");
	for(int i = 0; i < SIZE_DATASTATE; i++){
		cin >> SourceState.DataState[i];
	}//for

	WriteLog("main", "Get data DST");
	for(int i = 0; i < SIZE_DATASTATE; i++){
		cin >> DestinationState.DataState[i];
	}//for

	WriteLog("main", "Show data SRC");
	PrintDataState(SourceState);

	WriteLog("main", "Show data DST");
	PrintDataState(DestinationState);

	if((!CheckStateOfCorrect(SourceState)) && (!CheckStateOfCorrect(DestinationState)))
        ExitFail("Uncorrect state!");


    cout << "Calculate SRC\n";
    CalculteAllGenerations(SourceState);
    cout << "Show SRC generates:\n";
    for(int i = 0; i < MAX_G; i++){

        PrintDataState(*SourceState.Generations[i]);
    }//for

	return 0;
}//end main()



void CalculteAllGenerations(State &ParentState){
    if(&ParentState == &NullState)
        return;
	WriteLog("Calculate", "Start process");
	for(int i = 0; i < MAX_G; i++){
        ParentState.Generations[i] = CreateState();
        if(i == e_UP){
            ParentState.Generations[i].DataState
        }else if(i == e_DOWN){


        }else if(i == e_LEFT){


        }else if(i == e_RIGHT){


        }else{
            ExitFail("No recogn i");
        }// if else if
	}//for

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
			TargetLog << ": " << msg2;
	}//if
	TargetLog << endl;
	TargetLog.flush();
}// end WriteLog()


void PrintDataState(const State &state){
    if(&state == &NullState)
        return;
	for(int i = 0; i < SIZE_DATASTATE; i++){
		cout << state.DataState[i];
		if(i + 1 != SIZE_DATASTATE){
				cout  << '-';
		}
	}// for
	cout << endl;
}// end PrintDataState()



bool CheckStateOfCorrect(const State &state){
    static int tmp;
    // find duplicates && find no correct value
    for(int i = 0; i < SIZE_DATASTATE; i++){
        tmp = state.DataState[i];
        if(tmp < 0 || tmp > (SIZE_DATASTATE - 1)){
            return false;
        }// if
        for(int j = 0; j < SIZE_DATASTATE; j++){
            if(j == i)
                continue;
            if(state.DataState[j] == tmp)
                return false;
        }//for
    }//for
    return true;
}// end CheckStateOfCorrect()

void ExitFail(const char *msg){
    cerr << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%\nError!\n" << msg << endl;
    exit(EXIT_FAILURE);

}// end ExitFail()


State* CreateState(void){
    State* tmp = new State;
    if(tmp == 0){
        WriteLog("CreateState", "Can't create new State");
        return &NullState;
    }
    for(int i = 0; i < MAX_G; i++){
        tmp->Generations[i] = &NullState;
    }//for
    return tmp;
};
