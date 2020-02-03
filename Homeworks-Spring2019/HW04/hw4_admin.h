#ifndef HW4_ADMIN_H
#define HW4_ADMIN_H

#include<vector>
#include<string>
#include "hw4_lecturer.h"
#include "hw4_classroom.h"

namespace Fidan_class{
	
	
	class Administrator{
		public:
			inline Administrator(){//constructer
				pid=1;
				password=1;
			}//Big three
			inline Administrator(const Administrator& other_admin){//copy constructer
				pid=other_admin.pid;
				password=other_admin.password;
			}
			inline Administrator& operator=(const Administrator& other_admin){//assignment operator overloading
				if(this==&other_admin){
					return *this;
				}
				else{
					pid=other_admin.pid;
					password=other_admin.password;
					return *this;
				}
			}
			inline ~Administrator(){//dectructer
				
			}
			void arrangeClassroom(std::vector<Lecturer>&,Course&,int);
			void arrangeTimeTable(Course&);	
		private:
			int pid,password;
	};
	
}
#endif
