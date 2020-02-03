#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>


#include"Lecturer.h"
#include"ResearchAssistant.h"
#include"Secretary.h"
#include"Officer.h"

using namespace Fidan_class;//MY namespace
using namespace std;

const int max_action=50;

enum employe_action{
	slackness=1,solution=2
};
enum Academic_action{
	seminar,academicPaper
};
enum Admin_action{
	administration
};
//Action that lecturers can
enum Lecturer_action{
	lesson,HomeworkTime
};
//Actions that Assistants can
enum Assistant_action{
	project,HomeworkTimeout
};
//Actions that Secretary can
enum Secretary_action{
	incident	
};
//Actions that Officer can
enum Officer_action{
	document	
};

void TakeRandomEmp(int*);

int main()
{	
	srand(time(NULL));
	
	vector<Lecturer> lecturer;
	vector<ResearchAssistant> assistant;
	vector<Secretary> secretary;
	vector<Officer> officer;
	read_file personels[25];
	int person_id=1;
	string read_string;
	int tut[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	ifstream read;
	read.open("personnellist.txt");
	int t=0;
	int contribution=0;
	//read file
	while(read>>read_string){
		personels[t].id=person_id++;
		personels[t].alan=read_string;
		read>>read_string;
		personels[t].name=read_string;
		read>>read_string;
		personels[t].surname=read_string;
		t++;
	}
	
	//take random 10 employe id from 1-25
	TakeRandomEmp(tut);
	for(int i=0; i<10; i++){
		for(int j=0; j<25; j++){
			if(tut[i]==personels[j].id){
				if(personels[j].alan=="Lecturer"){
					Lecturer temp;
					temp.set_id(personels[j].id);
					temp.set_name(personels[j].name);
					temp.set_surname(personels[j].surname);
					temp.set_happiness(0);//set starter happiness 0
					lecturer.push_back(temp);
				}
				else if(personels[j].alan=="Officer"){
					Officer temp;
					temp.set_id(personels[j].id);
					temp.set_name(personels[j].name);
					temp.set_surname(personels[j].surname);
					temp.set_happiness(0);//set starter happiness 0
					officer.push_back(temp);
				}
				else if(personels[j].alan=="Secretary"){
					Secretary temp;
					temp.set_id(personels[j].id);
					temp.set_name(personels[j].name);
					temp.set_surname(personels[j].surname);
					temp.set_happiness(0);//set starter happiness 0
					secretary.push_back(temp);
				}
				else if(personels[j].alan=="ResearchAssistant"){
					ResearchAssistant temp;
					temp.set_id(personels[j].id);
					temp.set_name(personels[j].name);
					temp.set_surname(personels[j].surname);
					temp.set_happiness(0);//set starter happiness 0
					assistant.push_back(temp);
					
				}
			}
		}
	}
	
	cout<<lecturer.size()<<" "<<assistant.size()<<" "<<officer.size()<<" "<<secretary.size()<<endl;
	int number=0;
	while(number!=max_action){
		int random=rand()%4+1;//take a random lecturer officer secreter or assistant from our 10 random employes
		if(random==1 && lecturer.size()>0){//lecturer
			int random_lect=rand()%lecturer.size()+1;
			for(int j=0; j<=lecturer.size()+1; j++){
				if(random_lect==j){
					int random_action=rand()%3+1;//take a random action 3 possiblities employe action-academic action or lecturer action
					if(random_action==1){
						employe_action Action;
						int action_rand=rand()%2+1;//there are 2 random action in employe so this rand take one of them randomly
						if(action_rand==1){
							Action=slackness;
						}
						else if(action_rand==2){
							Action=solution;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case slackness:
								lecturer[random_lect-1].drinkTea(contribution);
								cout<<lecturer[random_lect-1].get_name()<<" have slackness.Therefore,"<<lecturer[random_lect-1].get_name()<<" drinks tea."<<"Happiness of "<<lecturer[random_lect-1].get_name()<<" is "<<lecturer[random_lect-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;
								number++;
								break;
							case solution:
								lecturer[random_lect-1].submitPetition(contribution);
								cout<<lecturer[random_lect-1].get_name()<<" have solution.Therefore,"<<lecturer[random_lect-1].get_name()<<" submit peririon."<<"Happiness of "<<lecturer[random_lect-1].get_name()<<" is "<<lecturer[random_lect-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
					
					else if(random_action==2){
						Academic_action Action;
						int action_rand=rand()%2+1;//there are 2 random aciton in academic_action so this rand func take one of them randomly
						if(action_rand==1){
							Action=seminar;
						}
						else if(action_rand==2){
							Action=academicPaper;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case seminar:
								lecturer[random_lect-1].seeSuccessfulStudent(contribution);
								cout<<lecturer[random_lect-1].get_name()<<" have seminar.Therefore,"<<lecturer[random_lect-1].get_name()<<" see successful student."<<"Happiness of "<<lecturer[random_lect-1].get_name()<<" is "<<lecturer[random_lect-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;	
								break;
							case academicPaper:
								lecturer[random_lect-1].makePublish(contribution);
								cout<<lecturer[random_lect-1].get_name()<<" have academic paper.Therefore,"<<lecturer[random_lect-1].get_name()<<" make publish."<<"Happiness of "<<lecturer[random_lect-1].get_name()<<" is "<<lecturer[random_lect-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;	
								break;	
						}
					}
					else if(random_action==3){
						Lecturer_action Action;
						int action_rand=rand()%2+1;//there are 2 action in lecturer class so this rand take one of them randomly
						if(action_rand==1){
							Action=lesson;
						}
						else if(action_rand==2){
							Action=HomeworkTime;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case lesson:
								lecturer[random_lect-1].giveLesson(contribution);
								cout<<lecturer[random_lect-1].get_name()<<" have lesson.Therefore,"<<lecturer[random_lect-1].get_name()<<" give lesson."<<"Happiness of "<<lecturer[random_lect-1].get_name()<<" is "<<lecturer[random_lect-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
							case HomeworkTime:	
								lecturer[random_lect-1].giveHW(contribution);
								cout<<lecturer[random_lect-1].get_name()<<" have HomeworkTime.Therefore,"<<lecturer[random_lect-1].get_name()<<" give homework."<<"Happiness of "<<lecturer[random_lect-1].get_name()<<" is "<<lecturer[random_lect-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;	
								number++;
								break;
						}
						
					}
				}
			}
		}
		else if(random==2 && assistant.size()>0){//assistant
			int random_assistant=rand()%assistant.size()+1;
			for(int j=0; j<=assistant.size()+1; j++){
				if(random_assistant==j){
					int random_action=rand()%3+1;//take a random action 3 possiblities employe actions-academic actions or assistant actions
					if(random_action==1){
						employe_action Action;
						int action_rand=rand()%2+1;
						if(action_rand==1){
							Action=slackness;
						}
						else if(action_rand==2){
							Action=solution;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case slackness:
								assistant[random_assistant-1].drinkTea(contribution);
								cout<<assistant[random_assistant-1].get_name()<<" have slackness.Therefore,"<<assistant[random_assistant-1].get_name()<<" drinks tea."<<"Happiness of "<<assistant[random_assistant-1].get_name()<<" is "<<assistant[random_assistant-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;
								number++;
								break;
							case solution:
								assistant[random_assistant-1].submitPetition(contribution);
								cout<<assistant[random_assistant-1].get_name()<<" have solution.Therefore,"<<assistant[random_assistant-1].get_name()<<" submit peririon."<<"Happiness of "<<assistant[random_assistant-1].get_name()<<" is "<<assistant[random_assistant-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
					else if(random_action==2){
						Academic_action Action;
						int action_rand=rand()%2+1;
						if(action_rand==1){
							Action=seminar;
						}
						else if(action_rand==2){
							Action=academicPaper;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case seminar:
								assistant[random_assistant-1].seeSuccessfulStudent(contribution);
								cout<<assistant[random_assistant-1].get_name()<<" have seminar.Therefore,"<<assistant[random_assistant-1].get_name()<<" see successful student."<<"Happiness of "<<assistant[random_assistant-1].get_name()<<" is "<<assistant[random_assistant-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;	
								break;
							case academicPaper:
								assistant[random_assistant-1].makePublish(contribution);
								cout<<assistant[random_assistant-1].get_name()<<" have academic paper.Therefore,"<<assistant[random_assistant-1].get_name()<<" make publish."<<"Happiness of "<<assistant[random_assistant-1].get_name()<<" is "<<assistant[random_assistant-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;	
								break;	
						}
					}
					else if(random_action==3){
						Assistant_action Action;
						int action_rand=rand()%2+1;
						if(action_rand==1){
							Action=project;
						}
						else if(action_rand==2){
							Action=HomeworkTimeout;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case project:
								assistant[random_assistant-1].research(contribution);
								cout<<assistant[random_assistant-1].get_name()<<" have project.Therefore,"<<assistant[random_assistant-1].get_name()<<" research."<<"Happiness of "<<assistant[random_assistant-1].get_name()<<" is "<<assistant[random_assistant-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;	
								break;
							case HomeworkTimeout:
								assistant[random_assistant-1].readHW(contribution);
								cout<<assistant[random_assistant-1].get_name()<<" have homeworkTimeout.Therefore,"<<assistant[random_assistant-1].get_name()<<" read HW."<<"Happiness of "<<assistant[random_assistant-1].get_name()<<" is "<<assistant[random_assistant-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;	
								break;	
						}
					}
				}
			}
		}
		else if(random==3 && secretary.size()>0){//secretary
			int random_secretary=rand()%secretary.size()+1;
			for(int j=0; j<=secretary.size()+1; j++){
				if(random_secretary==j){
					int random_action=rand()%3+1;//take a random action 3 possiblities employe action-Admin action or secretary actions
					if(random_action==1){
						employe_action Action;
						int action_rand=rand()%2+1;
						if(action_rand==1){
							Action=slackness;
						}
						else if(action_rand==2){
							Action=solution;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case slackness:
								secretary[random_secretary-1].drinkTea(contribution);
								cout<<secretary[random_secretary-1].get_name()<<" have slackness.Therefore,"<<secretary[random_secretary-1].get_name()<<" drinks tea."<<"Happiness of "<<secretary[random_secretary-1].get_name()<<" is "<<secretary[random_secretary-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;
								number++;
								break;
							case solution:
								secretary[random_secretary-1].submitPetition(contribution);
								cout<<secretary[random_secretary-1].get_name()<<" have solution.Therefore,"<<secretary[random_secretary-1].get_name()<<" submit peririon."<<"Happiness of "<<secretary[random_secretary-1].get_name()<<" is "<<secretary[random_secretary-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
					else if(random_action==2){
						Admin_action Action;
						Action=administration;
						//acording to the action switch call this actions function
						switch(Action){
							case administration:
								secretary[random_secretary-1].manageProcess(contribution);
								cout<<secretary[random_secretary-1].get_name()<<" have administration.Therefore,"<<secretary[random_secretary-1].get_name()<<" manage process."<<"Happiness of "<<secretary[random_secretary-1].get_name()<<" is "<<secretary[random_secretary-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
					else if(random_action==3){
						Secretary_action Action;
						Action=incident;
						//acording to the action switch call this actions function
						switch(Action){
							case incident:
								secretary[random_secretary-1].receivePetition(contribution);
								cout<<secretary[random_secretary-1].get_name()<<" have incident.Therefore,"<<secretary[random_secretary-1].get_name()<<" receive Petition."<<"Happiness of "<<secretary[random_secretary-1].get_name()<<" is "<<secretary[random_secretary-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
				}
			}
		}
		else if(random==4 && officer.size()>0){//officer
			int random_officer=rand()%officer.size()+1;
			for(int j=0; j<=officer.size()+1; j++){
				if(random_officer==j){
					int random_action=rand()%3+1;//take a random action 3 possiblities employe actions-admin actions or officer actions
					if(random_action==1){
						employe_action Action;
						int action_rand=rand()%2+1;//there are 2 action in employe class so this rand take one of the actions
						if(action_rand==1){
							Action=slackness;
						}
						else if(action_rand==2){
							Action=solution;
						}
						//acording to the action switch call this actions function
						switch(Action){
							case slackness:
								officer[random_officer-1].drinkTea(contribution);
								cout<<officer[random_officer-1].get_name()<<" have slackness.Therefore,"<<officer[random_officer-1].get_name()<<" drinks tea."<<"Happiness of "<<officer[random_officer-1].get_name()<<" is "<<officer[random_officer-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;
								number++;
								break;
							case solution:
								officer[random_officer-1].submitPetition(contribution);
								cout<<officer[random_officer-1].get_name()<<" have solution.Therefore,"<<officer[random_officer-1].get_name()<<" submit peririon."<<"Happiness of "<<officer[random_officer-1].get_name()<<" is "<<officer[random_officer-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
					else if(random_action==2){
						Admin_action Action;
						Action=administration;
						//acording to the action switch call this actions function
						switch(Action){
							case administration:
								officer[random_officer-1].manageProcess(contribution);
								cout<<officer[random_officer-1].get_name()<<" have administration.Therefore,"<<officer[random_officer-1].get_name()<<" manage process."<<"Happiness of "<<officer[random_officer-1].get_name()<<" is "<<officer[random_officer-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
					else if(random_action==3){
						Officer_action Action;
						Action=document;
						//acording to the action switch call this actions function
						switch(Action){
							case document:
								officer[random_officer-1].makeDoc(contribution);
								cout<<officer[random_officer-1].get_name()<<" have document.Therefore,"<<officer[random_officer-1].get_name()<<" make doc."<<"Happiness of "<<officer[random_officer-1].get_name()<<" is "<<officer[random_officer-1].get_happiness()<<",contribution of uni is "<<contribution<<endl;		
								number++;
								break;
						}
					}
				}
			}
		}
	}
	
	return 0;
}

//because of the this function program take 10 random employe from the personnellist.txt
void TakeRandomEmp(int* tut){
	for(int i=0; i<10; i++){
		int check=1;
		while(check==1){
			check=0;	
		
			int x=rand()%25+1;
			for(int j=0; j<i+1; j++){
				if(tut[j]==x){
					check=1;
				}
			}
			if(check==0){
				tut[i]=x;
			}
		}
	}
}
