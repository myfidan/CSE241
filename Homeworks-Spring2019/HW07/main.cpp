#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<vector>

#include"EducationSystem.h"
#include"University.h"
#include"Employee.h"
#include"CommunistEducation.h"
#include"LiberalEducation.h"
#include"CapitalistEducation.h"
#include"Temp_University.h"
#include"ComUni.h"
#include"LibUni.h"
#include"CapUni.h"
#include"Lecturer.h"
#include"ComLec.h"
#include"LibLec.h"
#include"BrokerLecturer.h"
#include"WorkerLecturer.h"
#include"ResearchAssistant.h"
#include"ComResAssist.h"
#include"LibResAssist.h"
#include"BrokerResAssist.h"
#include"WorkerResAssist.h"
#include"Secretary.h"
#include"ComSec.h"
#include"LibSec.h"
#include"BrokerSecretary.h"
#include"WorkerSecretary.h"
#include"Officer.h"
#include"ComOff.h"
#include"LibOff.h"
#include"BrokerOfficer.h"
#include"WorkerOfficer.h"

using namespace std;
const int personel_number=30;

int main(){
	srand(time(NULL));
	EducationSystem* Education;
	EducationSystem* Education_lib=new LiberalEducation;
	EducationSystem* Education_cap=new CapitalistEducation;
	EducationSystem* Education_com=new CommunistEducation;
	LiberalEducation lb;
	Employee** emp=new Employee*[personel_number];
	University *uni;
	
	University* Cap_uni=Education_cap->foundUni(Capuni);//found uni func call now university point a cap uni
	
	
	Personnel person[30];
	ifstream read;
	read.open("personnellist.txt");
	string take_emp;
	int counter=0;
	int r;
	
	while(read>>take_emp){
		
		person[counter].name=take_emp;
		read>>take_emp;
		person[counter].surname=take_emp;
		read>>take_emp;
		person[counter].wb=take_emp;
		counter++;
	}
	string enter;
	Action x;
	int random_action;
	do{
		cout<<"***Enter L,Com,Cap or exit***"<<endl;
		cin>>enter;	
		if(enter=="L"){
			Education=new LiberalEducation;
			University* lib_uni=Education_lib->foundUni(Libuni);//found uni func call now university point a lib uni
			lib_uni=new LibUni;
		
			lib_uni->set_cont(0);
			counter=rand()%30;
			r=rand()%4;
		
			if(r==0){
				lib_uni->start(Liblec);
				emp[counter]=Education->giveJob(person[counter].name,person[counter].surname,Liblec);//Give this personel Liblec job in Lib university
				
				emp[counter]->set_happiness(0);
				for(int i=0; i<14; i++){
					random_action=rand()%11;
					if(random_action==0){
						x=slackness;
						lib_uni->contribute(-2);
					}
					else if(random_action==1){
						x=solution;
						lib_uni->contribute(-2);
					}
					else if(random_action==2){
						x=seminar;
						lib_uni->contribute(0);
					}
					else if(random_action==3){
						x=academicPaper;
						lib_uni->contribute(5);
					}
					else if(random_action==4){
						x=lesson;
						lib_uni->contribute(+5);
					}
					else if(random_action==5){
						x=HomeworkTime;
						lib_uni->contribute(+1);
					}
					else if(random_action==6){
						x=document;
					}
					else if(random_action==7){
						x=project;
					}
					else if(random_action==8){
						x=administration;
					}
					else if(random_action==9){
						x=incident;
					}
					else if(random_action==10){
						x=homeworkTimeout;
					}
					emp[counter]->work(x);
					if(random_action<6)
					cout<<" "<<lib_uni->get_cont()<<".I contribute "<<lib_uni->get_cont()<<" to university";
					cout<<endl;
				}
			}
			if(r==1){
				lib_uni->start(Libassist);//start function call
				emp[counter]=Education->giveJob(person[counter].name,person[counter].surname,Libassist);//Give this personel Libassit job in Lib university
			
				emp[counter]->set_happiness(0);
				for(int i=0; i<14; i++){
					random_action=rand()%11;
					if(random_action==0){
						x=slackness;
						lib_uni->contribute(-2);
					}
					else if(random_action==1){
						x=solution;
						lib_uni->contribute(-2);
					}
					else if(random_action==2){
						x=seminar;
						lib_uni->contribute(0);
					}
					else if(random_action==3){
						x=academicPaper;
						lib_uni->contribute(+5);
					}
					else if(random_action==4){
						x=project;
						lib_uni->contribute(+4);
					}
					else if(random_action==5){
						x=homeworkTimeout;
						lib_uni->contribute(+2);
					}
					else if(random_action==6){
						x=administration;	
					}
					else if(random_action==7){
						x=incident;
					}
					else if(random_action==8){
						x=document;
					}
					else if(random_action==9){
						x=HomeworkTime;
					}
					else if(random_action==10){
						x=lesson;
					}
					emp[counter]->work(x);
					if(random_action<6)
					cout<<" "<<lib_uni->get_cont()<<".I contribute "<<lib_uni->get_cont()<<" to university";
					cout<<endl;
				}
			}
			if(r==2){
				lib_uni->start(Liboff);//start func call
				emp[counter]=Education->giveJob(person[counter].name,person[counter].surname,Liboff);//Give this personel Liboff job in Lib university
			
				emp[counter]->set_happiness(0);
				for(int i=0; i<14; i++){
					random_action=rand()%11;
					if(random_action==0){
						x=slackness;
						lib_uni->contribute(-2);
					}
					else if(random_action==1){
						x=solution;
						lib_uni->contribute(-2);
					}
					else if(random_action==2){
						x=administration;
						lib_uni->contribute(+2);
					}
					else if(random_action==3){
						x=document;
						lib_uni->contribute(+3);
					}
					else if(random_action==4){
						x=lesson;	
					}
					else if(random_action==5){
						x=academicPaper;
					}
					else if(random_action==6){
						x=homeworkTimeout;	
					}
					else if(random_action==7){
						x=HomeworkTime;
					}
					else if(random_action==8){
						x=incident;
					}
					else if(random_action==9){
						x=project;
					}
					else if(random_action==10){
						x=seminar;
					}
					emp[counter]->work(x);
					if(random_action<4)
					cout<<" "<<lib_uni->get_cont()<<".I contribute "<<lib_uni->get_cont()<<" to university";
					cout<<endl;
				}
				
			}
			if(r==3){
				lib_uni->start(Libsec);//start func call
				emp[counter]=Education->giveJob(person[counter].name,person[counter].surname,Libsec);//Give this personel Libsec job in Lib university
				
				emp[counter]->set_happiness(0);
				for(int i=0; i<14; i++){
					random_action=rand()%11;
					if(random_action==0){
						x=slackness;
						lib_uni->contribute(-2);
					}
					else if(random_action==1){
						x=solution;
						lib_uni->contribute(-2);
					}
					else if(random_action==2){
						x=administration;
						lib_uni->contribute(+2);
					}
					else if(random_action==3){
						x=incident;
						lib_uni->contribute(-1);
					}
					else if(random_action==4){
						x=document;
					}
					else if(random_action==5){
						x=lesson;
					}
					else if(random_action==6){
						x=project;
					}
					else if(random_action==7){
						x=seminar;
					}
					else if(random_action==8){
						x=academicPaper;
					}
					else if(random_action==9){
						x=HomeworkTime;
					}
					else if(random_action==10){
						x=homeworkTimeout;
					}
					
					emp[counter]->work(x);
					if(random_action<4)
					cout<<" "<<lib_uni->get_cont()<<".I contribute "<<lib_uni->get_cont()<<" to university";
					cout<<endl;
				}
			}
			cout<<"After all My Happiness is "<<emp[counter]->get_happiness()<<".My money is "<<lib_uni->get_cont()<<".I contribute "<<lib_uni->get_cont()<<" to university."<<endl;
		}
		else if(enter=="Com"){
			Education=new CommunistEducation;
			University* com_uni=Education_com->foundUni(Comuni);//found uni func call now university point a com uni
			com_uni=new ComUni;
			com_uni->set_cont(0);
			double sec_money,lec_money,off_money,res_money;
			//take random 4 emp from list
			vector<int> take_emp;
			int check=0;
			while(true){
				check=0;
				r=rand()%30;
				for(int i=0; i<take_emp.size(); i++){
					if(r==take_emp[i]){
						check=1;	
					}
				}
				if(check==0){
					take_emp.push_back(r);
				}
				if(take_emp.size()==4)break;
			}
			emp[take_emp[0]]=Education->giveJob(person[take_emp[0]].name,person[take_emp[0]].surname,Comlec);//Give this personel Libsec job in Lib university
			emp[take_emp[1]]=Education->giveJob(person[take_emp[1]].name,person[take_emp[1]].surname,Comassist);//Give this personel Libsec job in Lib university
			emp[take_emp[2]]=Education->giveJob(person[take_emp[2]].name,person[take_emp[2]].surname,Comoff);//Give this personel Libsec job in Lib university
			emp[take_emp[3]]=Education->giveJob(person[take_emp[3]].name,person[take_emp[3]].surname,Comsec);//Give this personel Libsec job in Lib university
			
			emp[take_emp[0]]->set_happiness(0);
			emp[take_emp[1]]->set_happiness(0);
			emp[take_emp[2]]->set_happiness(0);
			emp[take_emp[3]]->set_happiness(0);
		
			int emp1=0,emp2=0,emp3=0,emp4=0;
			while(emp1!=3 || emp2!=3 || emp3!=3 || emp4!=3){
				r=rand()%4;
				if(r==0){
					if(emp1<3){
						random_action=rand()%11;
						if(random_action==0){
							x=slackness;
							com_uni->contribute(-2);
						}
						else if(random_action==1){
							x=solution;
							com_uni->contribute(-2);
						}
						else if(random_action==2){
							x=seminar;
							com_uni->contribute(0);
						}
						else if(random_action==3){
							x=academicPaper;
							com_uni->contribute(5);
						}
						else if(random_action==4){
							x=lesson;
							com_uni->contribute(+5);
						}
						else if(random_action==5){
							x=HomeworkTime;
							com_uni->contribute(+1);
						}
						else if(random_action==6){
							x=document;
						}
						else if(random_action==7){
							x=project;
						}
						else if(random_action==8){
							x=administration;
						}
						else if(random_action==9){
							x=incident;
						}
						else if(random_action==10){
							x=homeworkTimeout;
						}
					
							emp[take_emp[0]]->work(x);
							if(random_action<6){
								cout<<com_uni->get_cont()<<",Contribution of uni is "<<com_uni->get_cont();
								emp1++;	
							}
							cout<<endl;
						}
				}
				else if(r==1){
					if(emp2<3){
						random_action=rand()%11;
						if(random_action==0){
							x=slackness;
							com_uni->contribute(-2);
						}
						else if(random_action==1){
							x=solution;
							com_uni->contribute(-2);
						}
						else if(random_action==2){
							x=seminar;
							com_uni->contribute(0);
						}
						else if(random_action==3){
							x=academicPaper;
							com_uni->contribute(+5);
						}
						else if(random_action==4){
							x=project;
							com_uni->contribute(+4);
						}
						else if(random_action==5){
							x=homeworkTimeout;
							com_uni->contribute(+2);
						}
						else if(random_action==6){
							x=administration;	
						}
						else if(random_action==7){
							x=incident;
						}
						else if(random_action==8){
							x=document;
						}
						else if(random_action==9){
							x=HomeworkTime;
						}
						else if(random_action==10){
							x=lesson;
						}
					
							emp[take_emp[1]]->work(x);
							if(random_action<6){
								cout<<",Contribution of uni is "<<com_uni->get_cont();
								emp2++;		
							}
							cout<<endl;
						}
				}
				else if(r==2){
					if(emp3<3){
						random_action=rand()%11;
						if(random_action==0){
							x=slackness;
							com_uni->contribute(-2);
						}
						else if(random_action==1){
							x=solution;
							com_uni->contribute(-2);
						}
						else if(random_action==2){
							x=administration;
							com_uni->contribute(+2);
						}
						else if(random_action==3){
							x=document;
							com_uni->contribute(+3);
						}
						else if(random_action==4){
							x=lesson;	
						}
						else if(random_action==5){
							x=academicPaper;
						}
						else if(random_action==6){
							x=homeworkTimeout;	
						}
						else if(random_action==7){
							x=HomeworkTime;
						}
						else if(random_action==8){
							x=incident;
						}
						else if(random_action==9){
							x=project;
						}
						else if(random_action==10){
							x=seminar;
						}
					
							emp[take_emp[2]]->work(x);
							if(random_action<4){
								cout<<",Contribution of uni is "<<com_uni->get_cont();
								emp3++;	
							}
							cout<<endl;
						}
					}
				else if(r==3){
					if(emp4<3){
						random_action=rand()%11;
						if(random_action==0){
							x=slackness;
							com_uni->contribute(-2);
						}
						else if(random_action==1){
							x=solution;
							com_uni->contribute(-2);
						}
						else if(random_action==2){
							x=administration;
							com_uni->contribute(+2);
						}
						else if(random_action==3){
							x=incident;
							com_uni->contribute(-1);
						}
						else if(random_action==4){
							x=document;
						}
						else if(random_action==5){
							x=lesson;
						}
						else if(random_action==6){
							x=project;
						}
						else if(random_action==7){
							x=seminar;
						}
						else if(random_action==8){
							x=academicPaper;
						}
						else if(random_action==9){
							x=HomeworkTime;
						}
						else if(random_action==10){
							x=homeworkTimeout;
						}
						
							emp[take_emp[3]]->work(x);
							if(random_action<4){
							cout<<",Contribution of uni is "<<com_uni->get_cont();
							emp4++;	
							}
							cout<<endl;
						}
				}
				
			}
			cout<<emp[take_emp[0]]->get_name()<<" "<<emp[take_emp[0]]->get_surname()<<" has "<<com_uni->get_cont()/4.0<<" Money"<<endl;
			cout<<emp[take_emp[1]]->get_name()<<" "<<emp[take_emp[1]]->get_surname()<<" has "<<com_uni->get_cont()/4.0<<" Money"<<endl;
			cout<<emp[take_emp[2]]->get_name()<<" "<<emp[take_emp[2]]->get_surname()<<" has "<<com_uni->get_cont()/4.0<<" Money"<<endl;
			cout<<emp[take_emp[3]]->get_name()<<" "<<emp[take_emp[3]]->get_surname()<<" has "<<com_uni->get_cont()/4.0<<" Money"<<endl;
			
		}
		else if(enter=="Cap"){
		
			
		}
		else if(enter=="exit"){
			
		}
		else{
			cout<<"Wrong input"<<endl;
		}
	}while(enter!="exit");
	read.close();
	return 0;

}








