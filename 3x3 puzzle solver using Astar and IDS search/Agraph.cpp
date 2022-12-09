//   Agraph search algorithm for 8-puzzle
//   BSCS-3C
//=================================
//   Luke Vincent Samson
//   John Paul Del Rosario
//   Francis Mendaros
//=================================
// Note : if compiling error try palitan ang "#include <bits-stdc++.h>" to "#include <bits/stdc++.h>"

#include <bits-stdc++.h>
#include <ctime>
#include <cstdlib>

using namespace std;


//set global variables
float runtime;
int nodesopened;
int goal[3][3] = {{1,2,3},{8,0,4},{7,6,5}};

//structure with column and row properties for use of the heuristic function
struct position{
    int column;
    int row;
};

//class container state with properties that represent a node
class state{

    public:
    int depth = 0;
    int statearr[3][3];
    int spacecolumn;
    int spacerow;
    string lastmovemade;
    state * parent = NULL;
    state(void);
    state(int t1,int t2,int t3,int m1,int m2,int m3,int b1,int b2,int b3);
    int heuristic(void);
    void findspace(void);
    position findposition(int value,state node);
    
};

//definition of heuristic() function in an instance of state, returns manhattan distance
int state::heuristic(void){
int mh = 0;
for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (statearr[i][j] != goal[i][j]){
                if (goal[i][j] == 0){
                    continue;
                }
                else{ 
                    mh = mh + abs((findposition(goal[i][j],*this)).column - j) + abs(findposition(goal[i][j],*this).row - i);
                  
                }
            }
        }    
    }
    return mh;
}

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

/*definition of findposition() function in an instance of state, returns a struct of 
position containing the location of the passed value in puzzle */

position state::findposition(int value,state node){
    position valuepos;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (node.statearr[i][j] == value){
                valuepos.column = j;
                valuepos.row = i;
                return valuepos;
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
state temp;
state solution;
state current;
list<state> closed;
list<state> open;

//UTILITY FUNCTIONS

//definition of printcredits()

void printcredits(){
cout << "=============================\nAgraph Search for 8-puzzle by\n=============================" << endl;
cout << "Luke Vincent Samson\nJohn Paul Del Rosario\nFrancis Mendaros" << endl;
cout << "=============================" << endl;
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

//definition of isequal(), returns true if states passed are equal
bool isequal(state node, state node2){
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (node.statearr[i][j] != node2.statearr[i][j]){
                return false;
            }
        }    
    }

    return true;
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

cout << endl;

cout << "State Found!" << endl;
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
            cout << "[" << solution.statearr[i][j] << "]";
        }
    cout << endl;
}

cout << "Solution Path : ";

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

//expand function for Agraph()
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
            current.parent = &closed.back();
            current.lastmovemade = "right";
            open.push_back(current);
            current = initial;
            
            //move down
            swap(current.statearr[0][0],current.statearr[1][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "down";
            open.push_back(current);
            current = initial;
            break;

        case 1:

            //move left
            swap(current.statearr[0][1],current.statearr[0][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "left";
            open.push_back(current);
            current = initial;
        
            //move right
            swap(current.statearr[0][1],current.statearr[0][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "right";
            open.push_back(current);
            current = initial;
            
            //move down
            swap(current.statearr[0][1],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "down";
            open.push_back(current);
            current = initial;
            break;

            case 2:

            //move left
            swap(current.statearr[0][2],current.statearr[0][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "left";
            open.push_back(current);
            current = initial;
        
            
            //move down
            swap(current.statearr[0][2],current.statearr[1][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "down";
            open.push_back(current);
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
            current.parent = &closed.back();
            current.lastmovemade = "right";
            open.push_back(current);
            current = initial;

            //move up
            swap(current.statearr[1][0],current.statearr[0][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "up";
            open.push_back(current);
            current = initial;
            
            //move down
            swap(current.statearr[1][0],current.statearr[2][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "down";
            open.push_back(current);
            current = initial;
            break;

        case 1:

            //move left
            swap(current.statearr[1][1],current.statearr[1][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "left";
            open.push_back(current);
            current = initial;
        
            //move right
            swap(current.statearr[1][1],current.statearr[1][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "right";
            open.push_back(current);
            current = initial;
            
            //move up
            swap(current.statearr[1][1],current.statearr[0][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "up";
            open.push_back(current);
            current = initial;

            //move down
            swap(current.statearr[1][1],current.statearr[2][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "down";
            open.push_back(current);
            current = initial;
            break;

            case 2:

            //move up
            swap(current.statearr[1][2],current.statearr[0][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "up";
            open.push_back(current);
            current = initial;


            //move left
            swap(current.statearr[1][2],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "left";
            open.push_back(current);
            current = initial;
        
            
            //move down
            swap(current.statearr[1][2],current.statearr[2][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "down";
            open.push_back(current);
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
            current.parent = &closed.back();
            current.lastmovemade = "right";
            open.push_back(current);
            current = initial;

            //move up
            swap(current.statearr[2][0],current.statearr[1][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "up";
            open.push_back(current);
            current = initial;
            
            break;

        case 1:

            //move left
            swap(current.statearr[2][1],current.statearr[2][0]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "left";
            open.push_back(current);
            current = initial;
        
            //move right
            swap(current.statearr[2][1],current.statearr[2][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "right";
            open.push_back(current);
            current = initial;
            
            //move up
            swap(current.statearr[2][1],current.statearr[1][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "up";
            open.push_back(current);
            current = initial;

            break;

            case 2:

            //move up
            swap(current.statearr[2][2],current.statearr[1][2]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "up";
            open.push_back(current);
            current = initial;


            //move left
            swap(current.statearr[2][2],current.statearr[2][1]);
            current.depth = current.depth + 1;
            current.parent = &closed.back();
            current.lastmovemade = "left";
            open.push_back(current);
            current = initial;
            break;
        
        
        default:
            break;
        }
    
    }
   
}

//definition of notinclosed(), returns true if node passed is not in closed list
list<state>::iterator closedpointer; //global variable pointing to an element in the closed list
bool notinclosed(state node){

for (auto it = closed.begin(); it != closed.end(); it++){

if (isequal(node, *it)){

    closedpointer = it;
    return false;
}

}

return true;
}


//definition of calculatef(), returns the sum of a state cost(depth) and its heuristic value
int calculatef(state node){
    int f = node.depth + node.heuristic();
    return f;
}

//definition of lowestf(), iterates over the open list and popping the state with the least f value
state lowestf(){
    state node;
    auto nodeit = open.begin();
    for(auto it = open.begin();it != open.end(); it++){
        if (calculatef(*it) < calculatef(temp))
        {
            nodeit = it;
        }
    }

 node = *nodeit;
 open.erase(nodeit);
 return node;
}

//Agraph() function
state Agraph(state initial){
temp = initial;

while (!open.empty()){

if(goaltest(temp)){
    nodesopened++;
    solution = temp;
    return solution;
}


else {

if (notinclosed(temp)){
    nodesopened++;
    closed.push_back(temp);
    expand(temp);
    temp = lowestf();
}

else{
    if (calculatef(temp) < calculatef(*closedpointer)){
    nodesopened++;
    closed.push_back(temp);
    expand(temp);
    temp = lowestf();
    }

    else{
    temp = lowestf();
    }
}

}


}

}



//main function
int main() {

printcredits();
setinitialstate();

clock_t timer;
open.push_back(start);

timer = clock();
Agraph(open.front());
timer = clock() - timer;

runtime = (float)timer/CLOCKS_PER_SEC;

printsol(start);


    
}



