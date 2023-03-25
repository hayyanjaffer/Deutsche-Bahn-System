//
//  main.cpp
//  praktikum2cpp
//
//  Created by Hayyan Jaffer on 06.11.22.
//
/***********************************************************************
Matr.-Nr: 3133115
Nachname/Surname:Jaffer
Vorname/Given name:Hayyan
Uni-Email:hayyan.jaffer@stud.uni-due.de
Studiengang/Course of studis: Bsc Computer Engineering(Software)
***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// We will create a doubly linked lists for the first time
struct station {
   string name;// string for the name of station
   int travel_time;
   station* next;// assigning pointers
 station* prev;
};

struct Train{
    string name;
    int time_to_travel;
    bool outgoing;
    station* next_station;
};

//got from StackOverflow
int generateRandomNumber(int greater_number, int smaller_number){
    
    int randomNumber =rand()%
    (greater_number - smaller_number) + greater_number;
    return randomNumber;
}


station *generate_metro_line(int line_numbers, int metro_numbers){
    station* Station = NULL;
    
    station* head = Station;
    
    for(int i=1; i<=metro_numbers;i++){
        station* last = head;
        
        station* nextStation = new station; //Making the next station
        nextStation->name = "Line " + to_string(line_numbers) + "Station " + to_string(i); //Storing the string in the next node
        if(i == metro_numbers){
            nextStation->travel_time = 0; //Generating a random number and storing it as time taken.
        }
        else {
            nextStation->travel_time = generateRandomNumber(5,1); //Generating a random number and storing it as time taken.
        }
        
        nextStation->next = NULL;
        nextStation->prev = head;
        
        head = nextStation;
    }
        
        
    return Station;
}

void output_line(station* node)
{
    station* last;
    while (node != NULL) {
        cout << " " << node->name << " time left: " << node->travel_time<<endl;
        last = node;
        node = node->next;
    }
}

void init(Train &train, string name, station *current_station) {
    train.name = name;
    train.time_to_travel = 0;
    train.next_station = current_station;
    train.outgoing = true;
}

void output(Train &current_train) {
    if(current_train.time_to_travel < 0 ) {
        cout << current_train.name << ":" << current_train.time_to_travel << " minute(s) to " << current_train.next_station->name<< endl;
    }
    else {
        cout << current_train.name << ": stopps at" << current_train.next_station->name << endl;
    }
}

void output_all_trains(int simulation_time, Train trains[], int array_length) {
    cout << "time simulation: " << simulation_time << " min " << endl;
    for(int counter =0;counter<array_length;counter++) {
        output(trains[counter]);
    }
}

int main() {
    station *stations[] = {NULL, NULL};
    Train trains[2];
    int simulation_time=0;
    int station_line_1,station_line_2;
    int timeLeft1, timeLeft2;
    cout << "Enter the numbers of lines for station 1 ";
    cin >> station_line_1;
    cout << "Enter the number of lines for station 2 ";
    cin >> station_line_2;
    stations[0] = generate_metro_line(1,station_line_1);
    stations[1] = generate_metro_line(2,station_line_2);
     
    output_line(stations[0]);
    output_line(stations[1]);
    init(trains[0],"Train 1", stations[0]);
    init(trains[1],"Train 2", stations[1]);
    cout << "e end " << endl<<"l line output" << endl<< "t train output" <<endl<< "1 simulate 1 minute" << endl;
    char choice;
      cin >> choice;
    do {
        switch(choice) {
        case 'l':
          output_line(stations[0]);
          output_line(stations[1]);
        break;
        case 't':
          output_all_trains(simulation_time,trains,2);
        break;
        case '1':
          ++simulation_time;
          trains[0].time_to_travel = trains[0].next_station->travel_time;
          trains[1].time_to_travel = trains[1].next_station->travel_time;
            
        
                
        break;
    }
    cin >> choice;
    }while(choice != 'e');
      
    return 0;
}


