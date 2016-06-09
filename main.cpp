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
} nullState;

std::list<State>StorageOfStates;
std::stack<e_Direction>WayFromStartToFinish;

void CalculteAllGenerations(State &ParentState);

bool CheckCollisionOfState(const State &one, const State &two);



int main(int argc, char **argv){
	
	memset(nullState.DataState, -1, SZ);
	for(int i = 0; i < MAX_G; i++)
		nullState.Generations[i] = 0;



	return 0;
}//end main()



void CalculteAllGenerations(State &ParentState){
	
	
	
	
}// end ClalculteAllGenerations()

bool CheckCollisionOfState(const State &one, const State &two){
	
	
	
	return false;
}// end CheckCollisionOfState()
