#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	int l,third=1,temp,heart,hold,hold_tek,heart_tek;
	int counter_1=2,counter_2=2,counter_3=0,counter_4=1;
	int decrease=2,increase=2,increase_2=1;

	
	cin>>l;
	if(l<0){
		cout<<"L<0 Error!"<<endl;
		return 0;
	}
	if(l>46){
		cout<<"L>46 ERROR BEACUSE PROGRAM PASS OVER INTIGER LIMIT";
		return 0;
	}
	for(int i=1; i<=l+1; i++){
		//This is the formula which find the i. fibonachi number with using golden ratio
		third=round(((1/sqrt(5))*pow((1+sqrt(5))/2,i)-(1/sqrt(5))*pow((1-sqrt(5))/2,i)));
		//I use round function in cmath library because sometimes golden ratio formula
		for(int j=1; j<=i; j++){
			if(i==1 && j==1){
				cout<<"1 ";
				third=1;
				heart=1;
			} 
			else if(i==2 && j==1){
				cout<<"1 ";
				third=1;
				heart=1;
			} 
			else if(i==2 && j==2) cout<<"1";
			else if(j==1) cout<<third<<" ";
			else{
				if(j<=(i+1)/2){
					if(counter_1%2==0){
						
						temp=round(((1/sqrt(5))*pow((1+sqrt(5))/2,i-decrease)-(1/sqrt(5))*pow((1-sqrt(5))/2,i-decrease)));
						if(temp==0) temp=1;
						cout<<third-temp<<" ";
						third=third-temp;
						
						if((j==(i+1)/2) && (i==(l+1)/2+2)){
						heart_tek=third;
						hold_tek=i;
						} 
						
						if(j==(i+1)/2 && i==(l+1)/2+1){
							heart=third;
							hold=i;
						} 
						
						
						decrease=decrease+2;
						counter_1++;
						counter_4=1;
					}
					else{
						
						temp=round(((1/sqrt(5))*pow((1+sqrt(5))/2,i-decrease)-(1/sqrt(5))*pow((1-sqrt(5))/2,i-decrease)));
						if(temp==0) temp=1;
						cout<<third+temp<<" ";
						third=third+temp;
						if((j==(i+1)/2) && (i==(l+1)/2+2)){
						heart_tek=third;
						hold_tek=i;
						} 
						if(j==(i+1)/2 && i==(l+1)/2+1){
							heart=third;
							hold=i;
						} 
						decrease=decrease+2;
						counter_1++;
						counter_4=2;
					}
					}
					
				else{
					
					if(i%2==0){
						if(counter_3==0){
							cout<<third<<" ";
							counter_3++;
						} 
						else{							
								if(counter_4==1){
									counter_2=2;	
								}
								else if(counter_4==2){
									counter_2=3;
								}
								counter_4=0;
								if(counter_2%2==0){
									temp=round(((1/sqrt(5))*pow((1+sqrt(5))/2,increase)-(1/sqrt(5))*pow((1-sqrt(5))/2,increase)));
									if(temp==0) temp=1;
									cout<<third+temp<<" ";
									third=third+temp;
									counter_2++;
									increase+=2;
								}
								else{
									temp=round(((1/sqrt(5))*pow((1+sqrt(5))/2,increase)-(1/sqrt(5))*pow((1-sqrt(5))/2,increase)));
									if(temp==0) temp=1;
									cout<<third-temp<<" ";
									third=third-temp;
									counter_2++;
									increase+=2;
								}
							}
					}
					else{
								if(counter_4==1){
									counter_2=2;	
								}
								else if(counter_4==2){
									counter_2=3;
								}
								counter_4=0;
								if(counter_2%2==0){
									temp=round(((1/sqrt(5))*pow((1+sqrt(5))/2,increase_2)-(1/sqrt(5))*pow((1-sqrt(5))/2,increase_2)));
									if(temp==0) temp=1;
									cout<<third+temp<<" ";
									third=third+temp;
									counter_2++;
									increase_2+=2;
								}
								else{
									temp=round(((1/sqrt(5))*pow((1+sqrt(5))/2,increase_2)-(1/sqrt(5))*pow((1-sqrt(5))/2,increase_2)));
									if(temp==0) temp=1;
									cout<<third-temp<<" ";
									third=third-temp;
									counter_2++;
									increase_2+=2;
								}
					}
				}	
			}
	}//initialize my counters again
	counter_1=2;
	counter_2=2;
	counter_3=0;
	//initialize my variables again 
	decrease=2; 
	increase=2;
	increase_2=1;
	cout<<endl;
	}
	//After the prints triangle,here prints biggest number and the heart numbers
	if(l==1){
		cout<<"Biggest Number:"<<third<<endl;
		cout<<"Heart Number: "<<heart<<" "<<heart<<endl;
	}
	else if(l==0){
		cout<<"Biggest Number:"<<third<<endl;
		cout<<"Heart Number: There is no heart number"<<endl;
	}
	else if(l==2){
		cout<<"Biggest Number:"<<third<<endl;
		cout<<"Heart Number: "<<heart<<" "<<endl;
	}
	else if(l%2==0){//
		if(hold_tek%2==0){
			cout<<"Biggest Number:"<<third<<endl;
			cout<<"Heart Number: "<<heart_tek<<" "<<heart_tek<<endl;
		}
		else{
			cout<<"Biggest Number:"<<third<<endl;
			cout<<"Heart Number: "<<heart_tek<<" "<<endl;
		}
		
	}
	else if(hold%2==0){
		cout<<"Biggest Number:"<<third<<endl;
		cout<<"Heart Number: "<<heart<<" "<<heart<<endl;
	}
	else if(l>-1){
		cout<<"Biggest Number:"<<third<<endl;
		cout<<"Heart Number: "<<heart<<endl;
	}	
	
	return 0;
}
