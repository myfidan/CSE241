#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>

#include"Employee.h"
#include "YOK.h"
#include"University.h"
#include"Officer.h"
#include"ResearchAssistant.h"
#include"Secretary.h"
#include"Lecturer.h"
#include"Complex.h"

using namespace My_Fidan;//my namespace
using namespace std;

const int personel_number=30;
const int employee_num=10;
void TakeRandomEmp(int*,int*,int*);//my function for take random 10 employe from the list


int main(){
	srand(time(NULL));
	Employee** emp=new Employee*[personel_number];//pointer array of abstract class employee
	YOK<int> yok_int;
	YOK<double> yok_double;
	YOK<Complex> yok_complex;
	University<int> uni_int;
	University<double> uni_double;
	University<Complex> uni_complex;
	 	
	UniType research=research_uni;
	UniType linguistic=linguistic_uni;
	UniType technical=technical_uni;
	
	uni_double=yok_double.foundUni(research);//found a research uni
	uni_int=yok_int.foundUni(linguistic);//found a linguistic uni
	uni_complex=yok_complex.foundUni(technical);//found a technical uni
	
	uni_double.set_cont(0);
	uni_int.set_cont(0);
	Complex temp;
	temp.set_real_int(0);
	temp.set_real_double(0);
	temp.set_imag_int(0);
	temp.set_imag_double(0);
	
	uni_complex.set_cont(temp);
	
	read_file personels[personel_number];
	read_file random_personel[personel_number];
	string read_string;
	ifstream read;
	read.open("personnellist.txt");
	int first_uni[10]={0};
	int second_uni[10]={0};
	int third_uni[10]={0};
	
	int t=0;
	int person_id=1;
	//read file
	while(read>>read_string){
		personels[t].id=person_id++;
		personels[t].name=read_string;
		read>>read_string;
		personels[t].surname=read_string;
		t++;
	}
	TakeRandomEmp(first_uni,second_uni,third_uni);//random 30 ogrenciyi 3 universiteye dagýtýr
	
	for(int i=0; i<10; i++){
		for(int j=0; j<30; j++){
			if(personels[j].id==first_uni[i]){
				random_personel[i].id=personels[j].id;
				random_personel[i].name=personels[j].name;
				random_personel[i].surname=personels[j].surname;
			}
		}
	}
	for(int i=0; i<10; i++){
		for(int j=0; j<30; j++){
			if(personels[j].id==second_uni[i]){
				random_personel[i+10].id=personels[j].id;
				random_personel[i+10].name=personels[j].name;
				random_personel[i+10].surname=personels[j].surname;
			}
		}
	}
	for(int i=0; i<10; i++){
		for(int j=0; j<30; j++){
			if(personels[j].id==third_uni[i]){
				random_personel[i+20].id=personels[j].id;
				random_personel[i+20].name=personels[j].name;
				random_personel[i+20].surname=personels[j].surname;
			}
		}
	}
	vector<int> lecturers_index;
	vector<int> secretary_index;
	vector<int> officer_index;
	vector<int> assistant_index;
	//first uni 
	for(int i=0; i<10; i++){
			
		int random_field=rand()%4+1;
		if(random_field==1){
			lecturers_index.push_back(i);
			emp[i]=yok_double.giveJob(random_personel[i].name,random_personel[i].surname,lecturer);//YOK give job function give emp[i] Lecturer job
			cout<<uni_double.get_name()<<" requests Lecturer"<<endl;
			cout<<"YOK give job to "<<random_personel[i].name<<" "<<random_personel[i].surname<<" as Lecturer"<<endl;
		}
		else if(random_field==2){
			officer_index.push_back(i);
			emp[i]=yok_double.giveJob(random_personel[i].name,random_personel[i].surname,officer);//YOK give job function give emp[i] Officer job
			cout<<uni_double.get_name()<<" requests Officer"<<endl;
			cout<<"YOK give job to "<<random_personel[i].name<<" "<<random_personel[i].surname<<" as Officer"<<endl;

		}
		else if(random_field==3){
			secretary_index.push_back(i);
			emp[i]=yok_double.giveJob(random_personel[i].name,random_personel[i].surname,secretary);//YOK give job function give emp[i] Secretary job
			cout<<uni_double.get_name()<<" requests Secretary"<<endl;
			cout<<"YOK give job to "<<random_personel[i].name<<" "<<random_personel[i].surname<<" as Secretary"<<endl;

		}
		else if(random_field==4){
			assistant_index.push_back(i);
			emp[i]=yok_double.giveJob(random_personel[i].name,random_personel[i].surname,researchassistant);//YOK give job function give emp[i] Assistant job
			cout<<uni_double.get_name()<<" requests Research Assistant"<<endl;
			cout<<"YOK give job to "<<random_personel[i].name<<" "<<random_personel[i].surname<<" as Research Assistant"<<endl;
		
		}	
	}
	cout<<endl;
	int rand_lect_action;
	int rand_person;
	string yaz;
	for(int i=0; i<50; i++){
		Action x;
		rand_person=rand()%9;
		for(int j=0; j<lecturers_index.size(); j++){//lecturers actions
			if(lecturers_index[j]==rand_person){
				rand_lect_action=rand()%6+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_double.contribute(-2);//University contribute function called and set contribute acording to actions
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_double.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=seminar;
					uni_double.contribute(0);
				}
				else if(rand_lect_action==4){
					x=academicPaper;
					uni_double.contribute(5);
				}
				else if(rand_lect_action==5){
					x=lesson;
					uni_double.contribute(5);
				}
				else if(rand_lect_action==6){
					x=HomeworkTime;
					uni_double.contribute(1);
				}
				emp[rand_person]->work(x);//here emp point a lecturer so work function called lecturers work function
				yaz="contribution of uni is "+to_string(uni_double.contribute(0));
				cout<<yaz<<endl;
			}
		}
		for(int j=0; j<officer_index.size(); j++){//officer actions
			if(officer_index[j]==rand_person){
				rand_lect_action=rand()%4+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_double.contribute(-2);//University contribute function called and return a string whick containts contribute value
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_double.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=administration;
					uni_double.contribute(2);
				}
				else if(rand_lect_action==4){
					x=document;
					uni_double.contribute(3);
				}
				emp[rand_person]->work(x);//here emp is point a officer so this call officer work function
				yaz="contribution of uni is "+to_string(uni_double.contribute(0));
				cout<<yaz<<endl;
			}
		}
		for(int j=0; j<secretary_index.size(); j++){//secretary actions
			if(secretary_index[j]==rand_person){
				rand_lect_action=rand()%4+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_double.contribute(-2);
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_double.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=administration;
					uni_double.contribute(2);
				}
				else if(rand_lect_action==4){
					x=incident;
					uni_double.contribute(-1);
				}
				emp[rand_person]->work(x);//here emp point a secretary so its called secretary work function
				yaz="contribution of uni is "+to_string(uni_double.contribute(0));
				cout<<yaz<<endl;
			}
			
		}
		for(int j=0; j<assistant_index.size(); j++){//assistants actions
			if(assistant_index[j]==rand_person){
				rand_lect_action=rand()%6+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_double.contribute(-2);
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_double.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=seminar;
					uni_double.contribute(0);
				}
				else if(rand_lect_action==4){
					x=academicPaper;
					uni_double.contribute(5);
				}
				else if(rand_lect_action==5){
					x=project;
					uni_double.contribute(4);
				}
				else if(rand_lect_action==6){
					x=HomeworkTimeout;
					uni_double.contribute(2);
				}
				emp[rand_person]->work(x);//here emp point a assistant so its called assistant work function
				yaz="contribution of uni is "+to_string(uni_double.contribute(0));
				cout<<yaz<<endl;
			}
			}
		}
		cout<<endl<<"***************************"<<endl;
		//second uni
		lecturers_index.clear();
		officer_index.clear();
		secretary_index.clear();
		assistant_index.clear();
		for(int i=0; i<10; i++){
			
		int random_field=rand()%4+1;
		if(random_field==1){
			lecturers_index.push_back(i+10);
			emp[i+10]=yok_int.giveJob(random_personel[i+10].name,random_personel[i+10].surname,lecturer);//for university<int> get job function called
			cout<<uni_int.get_name()<<" requests Lecturer"<<endl;
			cout<<"YOK give job to "<<random_personel[i+10].name<<" "<<random_personel[i+10].surname<<" as Lecturer"<<endl;
		}
		else if(random_field==2){
			officer_index.push_back(i+10);
			emp[i+10]=yok_int.giveJob(random_personel[i+10].name,random_personel[i+10].surname,officer);//for university<int> get job function called
			cout<<uni_int.get_name()<<" requests Officer"<<endl;
			cout<<"YOK give job to "<<random_personel[i+10].name<<" "<<random_personel[i+10].surname<<" as Officer"<<endl;

		}
		else if(random_field==3){
			secretary_index.push_back(i+10);
			emp[i+10]=yok_int.giveJob(random_personel[i+10].name,random_personel[i+10].surname,secretary);//for university<int> get job function called
			cout<<uni_int.get_name()<<" requests Secretary"<<endl;
			cout<<"YOK give job to "<<random_personel[i+10].name<<" "<<random_personel[i+10].surname<<" as Secretary"<<endl;

		}
		else if(random_field==4){
			assistant_index.push_back(i+10);
			emp[i+10]=yok_int.giveJob(random_personel[i+10].name,random_personel[i+10].surname,researchassistant);//for university<int> get job function called
			cout<<uni_int.get_name()<<" requests Research Assistant"<<endl;
			cout<<"YOK give job to "<<random_personel[i+10].name<<" "<<random_personel[i+10].surname<<" as Research Assistant"<<endl;
		
		}	
	}
	cout<<endl;
	for(int i=0; i<50; i++){
		Action x;
		rand_person=rand()%10+10;
		for(int j=0; j<lecturers_index.size(); j++){//lecturers actions
			if(lecturers_index[j]==rand_person){
				rand_lect_action=rand()%6+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=seminar;
					uni_int.contribute(0);
				}
				else if(rand_lect_action==4){
					x=academicPaper;
					uni_int.contribute(5);
				}
				else if(rand_lect_action==5){
					x=lesson;
					uni_int.contribute(5);
				}
				else if(rand_lect_action==6){
					x=HomeworkTime;
					uni_int.contribute(1);
				}
				emp[rand_person]->work(x);
				yaz="contribution of uni is "+to_string(uni_int.contribute(0));
				cout<<yaz<<endl;
			}
		}
		for(int j=0; j<officer_index.size(); j++){//officer actions
			if(officer_index[j]==rand_person){
				rand_lect_action=rand()%4+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=administration;
					uni_int.contribute(2);
				}
				else if(rand_lect_action==4){
					x=document;
					uni_int.contribute(3);
				}
				emp[rand_person]->work(x);
				yaz="contribution of uni is "+to_string(uni_int.contribute(0));
				cout<<yaz<<endl;
			}
		}
		for(int j=0; j<secretary_index.size(); j++){//secretary actions
			if(secretary_index[j]==rand_person){
				rand_lect_action=rand()%4+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=administration;
					uni_int.contribute(2);
				}
				else if(rand_lect_action==4){
					x=incident;
					uni_int.contribute(-1);
				}
				emp[rand_person]->work(x);
				yaz="contribution of uni is "+to_string(uni_int.contribute(0));
				cout<<yaz<<endl;
			}
			
		}
		for(int j=0; j<assistant_index.size(); j++){//assistants actions
			if(assistant_index[j]==rand_person){
				rand_lect_action=rand()%6+1;
				if(rand_lect_action==1){
					x=slackness;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==2){
					x=solution;
					uni_int.contribute(-2);
				}
				else if(rand_lect_action==3){
					x=seminar;
					uni_int.contribute(0);
				}
				else if(rand_lect_action==4){
					x=academicPaper;
					uni_int.contribute(5);
				}
				else if(rand_lect_action==5){
					x=project;
					uni_int.contribute(4);
				}
				else if(rand_lect_action==6){
					x=HomeworkTimeout;
					uni_int.contribute(2);
				}
				emp[rand_person]->work(x);
				yaz="contribution of uni is "+to_string(uni_int.contribute(0));
				cout<<yaz<<endl;
			}
			}
		}
		cout<<endl<<"***************************"<<endl;
		//third uni
		lecturers_index.clear();
		officer_index.clear();
		secretary_index.clear();
		assistant_index.clear();
		for(int i=0; i<10; i++){
			
		int random_field=rand()%4+1;
		if(random_field==1){
			lecturers_index.push_back(i+20);
			emp[i+20]=yok_complex.giveJob(random_personel[i+20].name,random_personel[i+20].surname,lecturer);//for university<complex> found uni function called
			cout<<uni_complex.get_name()<<" requests Lecturer"<<endl;
			cout<<"YOK give job to "<<random_personel[i+20].name<<" "<<random_personel[i+20].surname<<" as Lecturer"<<endl;
		}
		else if(random_field==2){
			officer_index.push_back(i+20);
			emp[i+20]=yok_complex.giveJob(random_personel[i+20].name,random_personel[i+20].surname,officer);//for university<complex> found uni function called
			cout<<uni_complex.get_name()<<" requests Officer"<<endl;
			cout<<"YOK give job to "<<random_personel[i+20].name<<" "<<random_personel[i+20].surname<<" as Officer"<<endl;

		}
		else if(random_field==3){
			secretary_index.push_back(i+20);
			emp[i+20]=yok_complex.giveJob(random_personel[i+20].name,random_personel[i+20].surname,secretary);//for university<complex> found uni function called
			cout<<uni_complex.get_name()<<" requests Secretary"<<endl;
			cout<<"YOK give job to "<<random_personel[i+20].name<<" "<<random_personel[i+20].surname<<" as Secretary"<<endl;

		}
		else if(random_field==4){
			assistant_index.push_back(i+20);
			emp[i+20]=yok_complex.giveJob(random_personel[i+20].name,random_personel[i+20].surname,researchassistant);//for university<complex> found uni function called
			cout<<uni_complex.get_name()<<" requests Research Assistant"<<endl;
			cout<<"YOK give job to "<<random_personel[i+20].name<<" "<<random_personel[i+20].surname<<" as Research Assistant"<<endl;
		
		}	
	}
	cout<<endl;
	Complex tut;
	for(int i=0; i<50; i++){
		Action x;
		rand_person=rand()%10+20;
		for(int j=0; j<lecturers_index.size(); j++){
			if(lecturers_index[j]==rand_person){//lecturers action
				rand_lect_action=rand()%6+1;
				if(rand_lect_action==1){
					x=slackness;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);//University contribute function called and return a string whick containts contribute value
				}
				else if(rand_lect_action==2){
					x=solution;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==3){
					x=seminar;
					tut.set_real_int(0);
					tut.set_real_double(0);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==4){
					x=academicPaper;
					tut.set_real_int(5);
					tut.set_real_double(5);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==5){
					x=lesson;
					tut.set_real_int(5);
					tut.set_real_double(5);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==6){
					x=HomeworkTime;
					tut.set_real_int(1);
					tut.set_real_double(1);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				emp[rand_person]->work(x);//here emp point a lecturer so work function called lecturers work function
				tut=uni_complex.get_cont();
				cout<<"contribution of uni is "<<tut<<endl;
			}
		}
		for(int j=0; j<officer_index.size(); j++){//officer actions
			if(officer_index[j]==rand_person){
				rand_lect_action=rand()%4+1;
				if(rand_lect_action==1){
					x=slackness;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);//University contribute function called and return a string whick containts contribute value
				}
				else if(rand_lect_action==2){
					x=solution;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==3){
					x=administration;
					tut.set_real_int(2);
					tut.set_real_double(2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==4){
					x=document;
					tut.set_real_int(3);
					tut.set_real_double(3);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				emp[rand_person]->work(x);//here emp is point a officer so this call officer work function
				tut=uni_complex.get_cont();
				cout<<"contribution of uni is "<<tut<<endl;
			}
		}
		for(int j=0; j<secretary_index.size(); j++){//secretary actions
			if(secretary_index[j]==rand_person){
				rand_lect_action=rand()%4+1;
				if(rand_lect_action==1){
					x=slackness;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==2){
					x=solution;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==3){
					x=administration;
					tut.set_real_int(2);
					tut.set_real_double(2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==4){
					x=incident;
					tut.set_real_int(-1);
					tut.set_real_double(-1);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				emp[rand_person]->work(x);//here emp point a secretary so its called secretary work function
				tut=uni_complex.get_cont();
				cout<<"contribution of uni is "<<tut<<endl;
			}
			
		}
		for(int j=0; j<assistant_index.size(); j++){//assistants actions
			if(assistant_index[j]==rand_person){
				rand_lect_action=rand()%6+1;
				if(rand_lect_action==1){
					x=slackness;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==2){
					x=solution;
					tut.set_real_int(-2);
					tut.set_real_double(-2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==3){
					x=seminar;
					tut.set_real_int(0);
					tut.set_real_double(0);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==4){
					x=academicPaper;
					tut.set_real_int(5);
					tut.set_real_double(5);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==5){
					x=project;
					tut.set_real_int(4);
					tut.set_real_double(4);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				else if(rand_lect_action==6){
					x=HomeworkTimeout;
					tut.set_real_int(2);
					tut.set_real_double(2);
					tut.set_imag_int(0);
					tut.set_imag_double(0);
					uni_complex.contribute(tut);
				}
				emp[rand_person]->work(x);//here emp point a assistant so its called assistant work function
				tut=uni_complex.get_cont();
				cout<<"contribution of uni is "<<tut<<endl;
			}
			}
		}
		delete [] emp;//after program finish delete emp for memory managament
		return 0;
	}
	


void TakeRandomEmp(int* first_uni,int* second_uni,int* third_uni){
	for(int i=0; i<10; i++){
		int check=1;
		while(check==1){
			check=0;	
		
			int x=rand()%30+1;
			for(int j=0; j<i+1; j++){
				if(first_uni[j]==x){
					check=1;
				}
			}
			if(check==0){
				first_uni[i]=x;
			}
		}
	}
	
	for(int i=0; i<10; i++){
		int check=1;
		int check_2=1;
		while(check==1){
			check=0;	
		
			int x=rand()%30+1;
			for(int j=0; j<i+1; j++){
				for(int k=0; k<10; k++){
					if(first_uni[k]==x){
						check_2=0;
					}
				}
				if(second_uni[j]==x || check_2==0){
					check=1;
					check_2=1;
				}
			}
			if(check==0){
				second_uni[i]=x;
			}
		}
	}
	
	for(int i=0; i<10; i++){
		int check=1;
		int check_2=1;
		int check_3=1;
		while(check==1){
			check=0;	
		
			int x=rand()%30+1;
			for(int j=0; j<i+1; j++){
				for(int k=0; k<10; k++){
					if(first_uni[k]==x){
						check_2=0;
					}
				}
				for(int k=0; k<10; k++){
					if(second_uni[k]==x){
						check_3=0;
					}
				}
				if(third_uni[j]==x || check_2==0 || check_3==0){
					check=1;
					check_2=1;
					check_3=1;
				}
			}
			if(check==0){
				third_uni[i]=x;
			}
		}
	}
}
