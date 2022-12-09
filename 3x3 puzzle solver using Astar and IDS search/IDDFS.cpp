//   IDDFS search algorithm for 8-puzzle
//   BSCS-3C
//=================================
//   Luke Vincent Samson
//   John Paul Del Rosario
//   Francis Mendaros
//=================================
// Note : if compiling error try palitan ang "#include <bits-stdc++.h>" to "#include <bits/stdc++.h>"
#include <bits-stdc++.h>
#include <ctime>

using namespace std;

//set global variables
float runtime;
int nodesopened;
int maxlimit;
int pathcost;
int goal[3][3] = {{1,2,3},{8,0,4},{7,6,5}};

//class container state with properties that represent a node
class state{

    public:
    bool failed = false;
    int depth = 0;
    int statearr[3][3];
    int spacecolumn;
    int spacerow;
    string lastmovemade;
    state * parent;
    state(void);
    state(int t1,int t2,int t3,int m1,int m2,int m3,int b1,int b2,int b3);
    void findspace(void);
       
};

/* definition of findspace() function in an instance of state, 
sets the spacerow and spacecolumn property of an instance of state */
void state::findspace(void){ 
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (statearr[i][j] == 0){
                spacerow = i;
                spacecolumn = j;
            }
        }    
    }
}

//constructor for state
state::state(void)
{
       
}

//constructor for state that takes 9 integers and sets them in an array
state::state(int t1,int t2,int t3,int m1,int m2,int m3,int b1,int b2,int b3){
        this->statearr[0][0] = t1;
        this->statearr[0][1] = t2;
        this->statearr[0][2] = t3;
        this->statearr[1][0] = m1;
        this->statearr[1][1] = m2;
        this->statearr[1][2] = m3;
        this->statearr[2][0] = b1;
        this->statearr[2][1] = b2;
        this->statearr[2][2] = b3;
        findspace();
}

//global variables of datatype state
state start;
state solution;
state current;
state temp;
list<state> fringe;
list<state> states;


//UTILITY FUNCTIONS

//definition of printcredits()
void printcredits(){
cout << "=============================\nIDDFS Search for 8-puzzle by\n=============================" << endl;
cout << "Luke Vincent Samson\nJohn Paul Del Rosario\nFrancis Mendaros" << endl;
cout << "============================" << endl;
}

//definition of printsol(), prints the solution state
void printsol(state start){
cout << "======================================================" << endl;
cout << "Initial State" << endl;

for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
            cout << "[" << start.statearr[i][j] << "]";
        }
    cout << endl;
}



cout << "\nState Found!" << endl;
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
            cout << "[" << solution.statearr[i][j] << "]";
        }
    cout << endl;
}

cout << "\nSolution Path : ";

state path = solution;
list<string> movesmade;

while (path.depth >= 0){
    movesmade.push_front(path.lastmovemade);
      if (path.parent == NULL){
        break;
    }
    path = *path.parent;
    path.depth--;
}

for (auto it = movesmade.begin(); it != movesmade.end();it++)
{
    cout << *it << " ";
}

cout << endl << "Path Cost : " << solution.depth;

cout << endl << "Nodes Expanded : " << nodesopened << endl;

cout <<  "Runtime : " << runtime << endl;

}

//definition of setinitialstate(), sets the start state
void setinitialstate(){
    int startvalues[9];
    cout << "Enter Top Left Value in Puzzle (0 for space): ";
    cin >> startvalues[0];
    cout << "Enter Top Middle Value in Puzzle (0 for space): ";
    cin >> startvalues[1];
    cout << "Enter Top Right Value in Puzzle (0 for space): ";
    cin >> startvalues[2];
    cout << "Enter Middle Left Value in Puzzle (0 for space): ";
    cin >> startvalues[3];
    cout << "Enter Center Value in Puzzle (0 for space): ";
    cin >> startvalues[4];
    cout << "Enter Middle Right Value in Puzzle (0 for space): ";
    cin >> startvalues[5];
    cout << "Enter Bottom Left Value in Puzzle (0 for space): ";
    cin >> startvalues[6];
    cout << "Enter Bottom Middle Value in Puzzle (0 for space): ";
    cin >> startvalues[7];
    cout << "Enter Bottom Right Value in Puzzle (0 for space): ";
    cin >> startvalues[8];
    cout << "Enter Maxlimit for IDDFS: ";
    cin >> maxlimit;

    state initial((startvalues[0]),(startvalues[1]),(startvalues[2]),(startvalues[3]),(startvalues[4]),(startvalues[5]),(startvalues[6]),(startvalues[7]),(startvalues[8]));
    start = initial;
}

//definition of goaltest(), returns true if the state passed is equal to the goal state
bool goaltest(state node){
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (node.statearr[i][j] != goal[i][j]){
                return false;
            }
        }    
    }

    return true;
}


//expand function for IDDFS()
void expand(state initial){ 
    initial.findspace();
    current = initial;
    

    if (current.spacerow == 0)
    {
        
        switch (current.spacecolumn)
        {
        case 0:
            //move right
            swap(current.statearr[0][0],current.statearr[0][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "right";
            fringe.push_back(current);
            current = initial;
            
            //move down
            swap(current.statearr[0][0],current.statearr[1][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "down";
            fringe.push_back(current);
            current = initial;
            break;

        case 1:

            //move left
            swap(current.statearr[0][1],current.statearr[0][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "left";
            fringe.push_back(current);
            current = initial;
        
            //move right
            swap(current.statearr[0][1],current.statearr[0][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "right";
            fringe.push_back(current);
            current = initial;
            
            //move down
            swap(current.statearr[0][1],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "down";
            fringe.push_back(current);
            current = initial;
            break;

            case 2:

            //move left
            swap(current.statearr[0][2],current.statearr[0][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "left";
            fringe.push_back(current);
            current = initial;
        
            
            //move down
            swap(current.statearr[0][2],current.statearr[1][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "down";
            fringe.push_back(current);
            current = initial;
            break;
        
        
        default:
            break;
        }
      

    }


  else if (current.spacerow == 1)
    {
        
        switch (current.spacecolumn)
        {
        case 0:
            //move right
            swap(current.statearr[1][0],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "right";
            fringe.push_back(current);
            current = initial;

            //move up
            swap(current.statearr[1][0],current.statearr[0][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "up";
            fringe.push_back(current);
            current = initial;
            
            //move down
            swap(current.statearr[1][0],current.statearr[2][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "down";
            fringe.push_back(current);
            current = initial;
            break;

        case 1:

            //move left
            swap(current.statearr[1][1],current.statearr[1][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "left";
            fringe.push_back(current);
            current = initial;
        
            //move right
            swap(current.statearr[1][1],current.statearr[1][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "right";
            fringe.push_back(current);
            current = initial;
            
            //move up
            swap(current.statearr[1][1],current.statearr[0][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "up";
            fringe.push_back(current);
            current = initial;

            //move down
            swap(current.statearr[1][1],current.statearr[2][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "down";
            fringe.push_back(current);
            current = initial;
            break;

            case 2:

            //move up
            swap(current.statearr[1][2],current.statearr[0][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "up";
            fringe.push_back(current);
            current = initial;


            //move left
            swap(current.statearr[1][2],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "left";
            fringe.push_back(current);
            current = initial;
        
            
            //move down
            swap(current.statearr[1][2],current.statearr[2][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "down";
            fringe.push_back(current);
            current = initial;
            break;
        
        
        default:
            break;
        }
      

    }


    else if (current.spacerow == 2)
    {
        
        switch (current.spacecolumn)
        {
        case 0:
            //move right
            swap(current.statearr[2][0],current.statearr[2][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "right";
            fringe.push_back(current);
            current = initial;

            //move up
            swap(current.statearr[2][0],current.statearr[1][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "up";
            fringe.push_back(current);
            current = initial;
            
            break;

        case 1:

            //move left
            swap(current.statearr[2][1],current.statearr[2][0]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "left";
            fringe.push_back(current);
            current = initial;
        
            //move right
            swap(current.statearr[2][1],current.statearr[2][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "right";
            fringe.push_back(current);
            current = initial;
            
            //move up
            swap(current.statearr[2][1],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "up";
            fringe.push_back(current);
            current = initial;

            break;

            case 2:

            //move up
            swap(current.statearr[2][2],current.statearr[1][2]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "up";
            fringe.push_back(current);
            current = initial;


            //move left
            swap(current.statearr[2][2],current.statearr[2][1]);
            current.depth = current.depth + 1;
            current.parent = &states.front();
            current.lastmovemade = "left";
            fringe.push_back(current);
            current = initial;
            break;
        
        
        default:
            break;
        }
    
    }
   
}

//definition for reset(), resets the fringe back to its first state
void reset(state node){
    fringe.clear();
    states.clear();
    fringe.push_back(node);
}

/*Depth Limited Search function, called by the IDDFS(), returns true if solution is found
returns false if limit set by an iteration of IDDFS() is reached*/
bool DLS(int limit){

while(!fringe.empty()){

state node = fringe.back();
fringe.pop_back(); 


if (goaltest(node)){ 
nodesopened++;
solution = node;
return true;
}
    
else 
{
    nodesopened++;
    states.push_front(node);
    if (node.depth < limit) {
    expand(node);
    }
}

}

return false;
}




/*Iterative Deepening Search function, Calls DLS(), while iterating from depth 0
to the maxlimit, returns solution state when found, else sets the solution failed flag to true*/
state IDDFS(state node, int maxlimit){

for (int i = 0; i < maxlimit; i++)
{

if(DLS(i)){
    return solution;
}
reset(node);
}

cout << "Max limit reached or failure" << endl;

solution.failed = true;
return solution;

}


//Main Code
int main() {

clock_t timer;

printcredits();
setinitialstate();
fringe.push_back(start);
timer = clock();
IDDFS(start, maxlimit);
timer = clock() - timer;
runtime = (float)timer/CLOCKS_PER_SEC;
if (solution.failed){
cout << "\n\nFailed" << endl;
}
else{
printsol(start);
}
    
}



