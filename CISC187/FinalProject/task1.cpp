#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct Player{
    string first_name;
    string last_name;
    string team;
};

int main(){
vector<Player> basketball_players = {
    {"Jill", "Huang", "Gators"},
      {"Janko", "Barton", "Sharks"},
      {"Wanda","Vakulskas", "Sharks"},
      {"Jill", "Moloney", "Gators"},
      {"Luuk", "Watkins", "Gators"}
};

vector<Player> football_players = {
    {"Hanzla", "Radosti", "32ers"},
    {"Tina", "Watkins", "Barleycorns"},
    {"Alex", "Patel", "32ers"},
    {"Jill", "Huang", "Barleycorns"},
    {"Wanda", "Vakulskas", "Barleycorns"}
};

unordered_set<string> basketball_names;

for (const Player& p : basketball_players){
    string full_name = p.first_name + " " + p.last_name;
    basketball_names.insert(full_name);

}

vector<Player> common_players;
for (const Player& p : football_players){
    string full_name = p.first_name + " " + p.last_name;
    if(basketball_names.find(full_name) != basketball_names.end()){
        common_players.push_back(p);
    }
}

cout<<"The following players play both sports: "<<endl;
for(const Player&p : common_players){
    cout<<p.first_name + " " + p.last_name<<endl;
}

}


