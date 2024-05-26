//End Semester Project
//WELLNESSRECORDS: A C++ PROJECT FOR CENTRALIZING MEDICAL INFORMATION
//BEFORE USING CONFIRM WHETHER THE GRAPHICS IN INSTALLED
#include <iostream>
#include <cstdlib>		//used for random no 
#include <ctime>		//used for random no with respect to time
#include <string.h>		//used for strings
#include <unistd.h> 	//used for sleep ftn in human verification
#include <algorithm> 	//used for sorting in human verification
#include <graphics.h>   //used for ECG
#include <math.h>		//used for mathematics in ecg
using namespace std;

//structures
struct doctors_data 	//for doctors
{ 						//taking following this for a doctor
	string name;int pmc_no;long long int cnic;string gender;
	int age;string type;int doc_num;string pass;
};

struct patients_data 	//for patients
{						//taking following this for a patient
	string name;int patients_no;long long int cnic;string gender;
	int age;string type;int doc_num;string pass; 
};

struct doc_request_data //doctors request
{						//taking following this for doctors request
	string name;int pmc_no;long long int cnic;string gender;
	int age;string type;int req_num;string pass;string result;int doc_num;
};

struct pat_request_data //patients request
{						//taking following this for patients request
	string name;long long int cnic;string gender;
	int age;string type;int req_num;string pass;string result;
	int doc_num;int pat_num;
};

struct patients_notes 	//for patients notes toward doctor
{						//data required for notes
	string note;string name;int doc_num;
};

//function prototype
int human_verification(); 	//will be used for human verification
void toLower(string& str);	//will be used to convert to lower alphabets
void printECGLine(int age, int heartRate, int bloodPressure); //ECG Function	

//main function
int main()
{
	
	//CREATING A MINI DATABASE WITHIN THE PROGRAM WITH 5 DOCTORS AND 2 PATIENTS WITH EACH DOCTOR
	//5 doctors data is already in
	int doc_size=5; 					//creating a Variable to store the size of doctors, afters wards this size could be changed
	doctors_data *doctor[doc_size]; 	//creating a dynamic array as normal array doesn't allow user to change its size
	int num1=5453;						//a variable created to give a num to every doctor
	doctor[0] = new doctors_data(); 	//a new structure created as it is a dynamic array
	doctor[0]->name = "Waleed Usman";	//using "->" instead of "." as the dynamic array doesn't accepts "."
	doctor[0]->pmc_no = 4502;
	doctor[0]->cnic = 3320387021319;doctor[0]->gender="male";doctor[0]->age = 18;
	doctor[0]->type = "oncologist";doctor[0]->doc_num = num1++;doctor[0]->pass = "waleed181";
	
	doctor[1] = new doctors_data();doctor[1]->name = "basil wahab  ";doctor[1]->pmc_no = 4503;
	doctor[1]->cnic = 33760789900001;doctor[1]->gender="male";doctor[1]->age = 19;
	doctor[1]->type = "cardiologist";doctor[1]->doc_num = num1++;doctor[1]->pass = "basil181";
	
	doctor[2] = new doctors_data();doctor[2]->name = "muntaha ajmal";doctor[2]->pmc_no = 4504;
	doctor[2]->cnic = 33203123456789;doctor[2]->gender="female";doctor[2]->age = 18;
	doctor[2]->type = "ophthalmologist";doctor[2]->doc_num = num1++;doctor[2]->pass = "kashi181";
	
	doctor[3] = new doctors_data();doctor[3]->name = "minahil malik";doctor[3]->pmc_no = 4506;
	doctor[3]->cnic = 33205547654891;doctor[3]->gender="female";doctor[3]->age = 17;
	doctor[3]->type = "psychiatrist";doctor[3]->doc_num = num1++;doctor[3]->pass = "minahil181";
	
	doctor[4] = new doctors_data();doctor[4]->name = "ikramah khizar";doctor[4]->pmc_no = 4507;
	doctor[4]->cnic = 33207546754891;doctor[4]->gender="male";doctor[4]->age = 18;
	doctor[4]->type = "dermatologist";doctor[4]->doc_num = num1++;doctor[4]->pass = "ikramah181";
	
	int pat_size=10;					//creating a Variable to store the size of patients, afters wards this size could be changed
	patients_data *patient[pat_size];	//creating a dynamic array as normal array doesn't allow user to change its size
	int num2=1001;						//a variable created to give a num to every patient
	
	//patients of doctor no 1
	patient[0]=new patients_data;		//a new structure created as it is a dynamic array
	patient[0]->name="faizan akmal";patient[0]->patients_no=num2++;
	patient[0]->cnic =9345672015389;patient[0]->gender="male";patient[0]->age=18;
	patient[0]->type="oncologist";patient[0]->doc_num=5453;patient[0]->pass="181faizan";
	
	patient[1]=new patients_data;patient[1]->name="nabiha zaman";patient[1]->patients_no=num2++;
	patient[1]->cnic =1634853719012;patient[1]->gender="female";patient[1]->age=19;
	patient[1]->type="oncologist";patient[1]->doc_num=5453;patient[1]->pass="181nabiha";
	
	//patients of doctor no 2
	patient[2]=new patients_data;patient[2]->name="aafiyah najma";patient[2]->patients_no=num2++;
	patient[2]->cnic =7246090934124;patient[2]->gender="female";patient[2]->age=18;
	patient[2]->type="cardiologist";patient[2]->doc_num=5454;patient[2]->pass="181aafiyah";
	
	patient[3]=new patients_data;patient[3]->name="saad hamid";patient[3]->patients_no=num2++;
	patient[3]->cnic =3528913802341;patient[3]->gender="male";patient[3]->age=20;
	patient[3]->type="cardiologist";patient[3]->doc_num=5454;patient[3]->pass="181saad";
	//patients of doctor 3
	patient[4]=new patients_data;patient[4]->name="hassan ali";patient[4]->patients_no=num2++;
	patient[4]->cnic =4102582147693;patient[4]->gender="male";patient[4]->age=17;
	patient[4]->type="ophthalmologist";patient[4]->doc_num=5455;patient[4]->pass="181hassan";
	
	patient[5]=new patients_data;patient[5]->name="asma aziz";patient[5]->patients_no=num2++;
	patient[5]->cnic =5176820193036;patient[5]->gender="female";patient[5]->age=18;
	patient[5]->type="ophthalmologist";patient[5]->doc_num=5455;patient[5]->pass="181asma";
	
	//patients of doctor 4 
	patient[6]=new patients_data;patient[6]->name="saima hassan";patient[6]->patients_no=num2++;
	patient[6]->cnic =2873441874162;patient[6]->gender="female";patient[6]->age=16;
	patient[6]->type="psychiatrist";patient[6]->doc_num=5456;patient[6]->pass="181saima";
	
	patient[7]=new patients_data;patient[7]->name="anam zainab";patient[7]->patients_no=num2++;
	patient[7]->cnic = 8490770301251;patient[7]->gender="female";patient[7]->age=19;
	patient[7]->type="psychiatrist";patient[7]->doc_num=5456;patient[7]->pass="181aima";
	
	//patients of doctor 5
	patient[8]=new patients_data;patient[8]->name="usman farooq";patient[8]->patients_no=num2++;
	patient[8]->cnic =9518614279658;patient[8]->gender="male";patient[8]->age=21;
	patient[8]->type="dermatologist";patient[8]->doc_num=5457;patient[8]->pass="181usman";
	
	patient[9]=new patients_data;patient[9]->name="fatima naheed";patient[9]->patients_no=num2++;
	patient[9]->cnic =6802403287013;patient[9]->gender="female";patient[9]->age=22;
	patient[9]->type="dermatologist";patient[9]->doc_num=5457;patient[9]->pass="181fatima";
	
	//doc requests
	int doc_req_size=0;   						//creating a Variable to store the size of Doctors requests,afters wards this size could be changed			
	doc_request_data *request[doc_req_size];	//creating a dynamic array as normal array doesn't allow user to change its size
	int num3=1356;								//a variable created to give a request num to every doctors request	
	//pat requests
	int pat_req_size=0;							//creating a Variable to store the size of Patients requests,afters wards this size could be changed	
	pat_request_data *pat_request[pat_req_size];//creating a dynamic array as normal array doesn't allow user to change its size
	int num4=6851;								//a variable created to give a request num to every patient request	
	//notes by patients
	int notes_size=0;							//creating a Variable to store the size of Patients notes,afters wards this size could be change
	patients_notes *note[notes_size];			//creating a dynamic array as normal array doesn't allow user to change its size
	
	//start
	char aga;
	do
	{
		system("cls");							//pre-defined function used to clear previous screen
		//displaying the menu to the user
		int menu;
		cout<<"1. Login as a Doctor\n";					//only 1 option left
		cout<<"2. New Doctor\n";						//done
		cout<<"3. Login as a Patient\n";
		cout<<"4. New Patient\n";						//done
		cout<<"5. Login as Hospital Management\n";		//done
		cout<<"6. Exit the program\n"; 					//done
		do//do while loop if the user enters any wrong number other than available in the menu
		{
			cout<<"\nEnter the operation (1-6) : ";
			cin>>menu;
			if(menu>6 || menu<1)//condition to check user enters the proper reply
			{
				cout<<"\nWrong Selection ! Select again\n";
			}
		}
		while(menu>6 || menu<1);//condition to check user enters the proper reply
		
		
		
		//loging in
		if(menu==1) //login as doctor
		{
			system("cls");
			cout<<"\n<><><><><><><><><>   LOGING IN AS A DOCTOR   <><><><><><><><><> \n\n";
			int count=0; //here count is used as flag and it is initially zero 
			do
			{
			    int pass1;
			    cout<<"Enter your Doctors Number : ";
			    cin>>pass1;
			    for(int i=0;i<doc_size;i++)
			    {
			        if(pass1 == doctor[i]->doc_num)
			        {
			            count++;
			            string pass2;
			            cout<<"Enter your password : ";
			            cin>>pass2;
			            int pass3=human_verification();
			            if(pass3==1)
			            {
			            	if(pass2 == doctor[i]->pass)
				            {
				            	
				                cout<<"\n~~~ Login Successful ~~~\n";
				                char again56;
								do
								{
									system("cls");
									cout<<"\n<><><><><><><><><><><><><><> LOGGED IN AS DOCTER <><><><><><><><><><><><><><>\n\n";
									int option;
									
									int num_of_pat=0;
									for(int j=0;j<pat_size;j++)
									{
										if(patient[j]->doc_num==doctor[i]->doc_num)
										{
											num_of_pat++;
										}
									}
									
									cout<<"\nDOCTOR NAME : \t\t"<<doctor[i]->name<<endl;
									cout<<"DOCTOR TYPE : \t\t"<<doctor[i]->type<<endl;
									cout<<"DOCTOR NUMBER : \t"<<doctor[i]->doc_num<<endl;
									cout<<"PMC NUMBER : \t\t"<<doctor[i]->pmc_no<<endl;
									cout<<"NO OF PATIENTS : \t"<<num_of_pat<<endl;
									cout<<"\n\n\nMENU:\n1. Check Patient\n2. Check Patients list\n3. Check patients Notes\n4. Check Patients request\n5. Add a patient\n6. Logout\n\n";
									do
									{
										cout<<"Enter operation (1-6) : ";
										cin>>option;	
									}
									while(option>6 || option<1);
									
									
									switch(option)
									{
										case 1: // check patient
											{
												system("cls");
												cout<<"\n<><><><><><><><><>   CHECKING PATIENTS    <><><><><><><><><> \n\n\n";
												
												int flag2=0;
												for(int j=0;j<pat_size;j++)
												{
													if(patient[j]->doc_num==doctor[i]->doc_num)
													{
														flag2=1;
														break;
													}
													else
													{
														flag2==0;
													}
												}
												if(flag2==1)
												{
													int count1=1;
													cout<<"\nYou have following patients : \n\n";
													cout<<"\tNAME\t\t\tPAT NO\n"<<endl;
													for(int j=0;j<pat_size;j++)
													{
														if(patient[j]->doc_num==doctor[i]->doc_num)
														{
															cout<<count1++<<".\t"<<patient[j]->name<<"\t\t"<<patient[j]->patients_no<<endl;
														}
													}		
												}
												else
												{
													cout<<"\n~~~ YOU CURRNTLY HAVE NO PATIENT ~~~\n";
												}
												
												int patnum;
												do
												{
													cout<<"\nEnter Patient number : ";
													cin>>patnum;
												}
												while(patnum<999 || patnum>9999);
												int flag=0;
												for(int j=0;j<pat_size;j++)
												{
													if(doctor[i]->doc_num==patient[j]->doc_num)
													{
														if(patnum==patient[j]->patients_no)
														{
															flag=2;
															break;
														}
														else
														flag=1;	
													}
													else
													flag=0;
												}
												if(flag==0)
												{
													cout<<"\n\n~~~ PATIENT NOT FOUND ~~~\n";
												}
												if(flag==1)
												{
													cout<<"\n\n~~~ PATIENT NOT FOUND ~~~\n";
												}
												if(flag==2)
												{
													for(int j=0;j<pat_size;j++)
													{
														if(doctor[i]->doc_num==patient[j]->doc_num)
														{
															if(patnum==patient[j]->patients_no)
															{
																char again9;
																do
																{
																	system("cls");
																	cout<<"\n<><><><><><><><><>   CHECKING PATIENT    <><><><><><><><><> \n\n\n";
																	cout<<"\nPATIENT NAME : \t\t"<<patient[i]->name<<endl;
																	cout<<"PATIENT NUMBER : \t"<<patient[i]->patients_no<<endl;
																	cout<<"PATIENT CNIC : \t\t"<<patient[i]->cnic<<endl;
																	cout<<"PATIENT AGE : \t\t"<<patient[i]->age<<endl;
																	
																	int opt69;
																	cout<<"\n\nMENU:\n1. ECG\n2. SPO2\n3. Logiut";
																	do
																	{
																		cout<<"\nEnter what you want : ";
																		cin>>opt69;
																		if(opt69 !=1 && opt69!=2 && opt69!=3)
																		{
																			cout<<"\n~~~ Enter 1 , 2 or 3! ENTER AGAIN! ~~~\n";
																		}
																	}
																	while(opt69 !=1 && opt69!=2 && opt69!=3);
																	if(opt69==1)
																	{
																		system("cls");
																		cout<<"\n<><><><><><><><><>   ECG FUNCTION    <><><><><><><><><> \n\n\n";
																		// call the ECG line function with initial parameters
																		int age=patient[j]->age;
																		int heartrate,bloodpressure;
																		cout<<"\nEnter the Heart Rate of "<<patient[j]->name<<" : ";
																		cin>>heartrate;
																		cout<<"Enter the blood pressure of "<<patient[j]->name<<" : ";
																		cin>>bloodpressure;
																		// display ECG line
																		cout << "Press any key to close the window..." << endl;
																		
																		printECGLine(age, heartrate, bloodpressure); //age , heartrate , blood pressure
																		getch(); // wait for user to press a key
																		closegraph();
																	}
																	
																	if(opt69==2)
																	{
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																		//
																	}
																	
																	if(opt69==3)
																	{
																		break;
																	}
																	cout<<"\n\nDo you want to check menu again ? (y\n) : ";
																	cin>>again9;
																}
																while(again9!='n');
																	
																
																
																break;
															}
														}
													}
												}
													
												break;
											}
										case 2: //check patient list
											{
												system("cls");
												cout<<"\n<><><><><><><><><><> Patients List <><><><><><><><><><>\n\n";
												
												int flag=0;
												for(int j=0;j<pat_size;j++)
												{
													if(patient[j]->doc_num==doctor[i]->doc_num)
													{
														flag=1;
														break;
													}
													else
													{
														flag==0;
													}
												}
												if(flag==1)
												{
													int count=1;
													cout<<"\nYou have following patients : \n";
													cout<<"\tNAME\t\t\tPAT NO\t\tCNIC\tGENDER\tAGE\tTYPE\t\tPASS\n"<<endl;
													for(int j=0;j<pat_size;j++)
													{
														if(patient[j]->doc_num==doctor[i]->doc_num)
														{
															cout<<count++<<".\t"<<patient[j]->name<<"\t\t"<<patient[j]->patients_no<<"\t"<<patient[j]->cnic<<"\t"
															<<patient[j]->gender<<"\t"<<patient[j]->age<<"\t"<<patient[j]->type<<"\t"
															<<patient[j]->pass<<endl;
														}
													}		
												}
												else
												{
													cout<<"\n~~~ YOU CURRNTLY HAVE NO PATIENT ~~~\n";
												}
												break;
											}
										case 3: //check patient notes
											{
												system("cls");
												cout<<"\n<><><><><><><><><><> Patients Notes <><><><><><><><><><>\n\n";
												if(notes_size!=0)
												{
													cout<<"Following are the notes : \n";
													for(int j=0;j<notes_size;j++)
													{
														if(note[j]->doc_num==doctor[i]->doc_num)
														{
															cout<<j+1<<".\t"<<note[j]->name<<endl<<"\t'"<<note[j]->note<<"'";
														}	
													}	
												}
												else
												cout<<"~~~ Currently No Note available ~~~";
												break;
											}
										case 4: //check patient request
											{
												system("cls");
												cout<<"\n<><><><><><><><><>   CHECKING PATIENTS REQUESTS   <><><><><><><><><> \n\n";
												if(pat_req_size!=0)
												{
													int flag=0;
													cout<<"\n\tPATIENT NAME\t\tCNIC\t\tGENDER\t\tAGE\tREQUEST NUMBER\tPASSWORD\tRESULT"<<endl<<endl;
													for(int j=0;j<pat_req_size;j++)
													{
														if(pat_request[j]->doc_num==doctor[i]->doc_num)
														{
															flag++;
														}
													}
													if(flag!=0)
													{
														int count=1;
														for(int j=0;j<pat_req_size;j++)
														{
															if(pat_request[j]->doc_num==doctor[i]->doc_num)
															{
																cout<<count++<<".\t"<<pat_request[j]->name<<"\t\t"<<pat_request[j]->cnic<<"\t"<<pat_request[j]->gender<<
																"\t\t"<<pat_request[j]->age<<"\t"<<pat_request[j]->req_num<<"\t\t"<<pat_request[j]->pass<<"\t"<<
																pat_request[j]->result<<endl;
															}
														}
														
														int reqnum;
														cout<<"\nWhich request do you want to check (write request number) : ";
														cin>>reqnum;
														int flag=0;
														for(int j=0;j<pat_req_size;j++)
														{
															if(reqnum==pat_request[j]->req_num)
															{
																flag=1;
																break;
															}
															else
															flag=0;
														}
														if(flag==1)
														{
															int option;
															cout<<"\nSelect :\n1. Accept\n2. Reject\n";
															do
															{
																cout<<"\nEnter option ( 1-2 ) : ";
																cin>>option;
																if(option>2 || option <1)
																{
																	cout<<"~~~Wrong select ! Please select again ~~~\n";
																}
															}
															while(option>2 || option <1);
															
								
															if(option==1)
															{
																for(int j=0;j<pat_req_size;j++)
																{
																	if(reqnum==pat_request[j]->req_num )
																	{
																		if(pat_request[j]->result=="pending")
																		{
																			cout<<"\n~~~ ACCEPTED ~~~\n";
																			pat_request[i]->result="accepted";
																			pat_size = pat_size + 1;
																			patient[pat_size-1] = new patients_data();
																			patient[pat_size-1]->name=pat_request[j]->name;
																			patient[pat_size-1]->cnic=pat_request[j]->cnic;
																			patient[pat_size-1]->gender=pat_request[j]->gender;
																			patient[pat_size-1]->age=pat_request[j]->age;
																			patient[pat_size-1]->type=pat_request[j]->type;
																			pat_request[j]->pat_num=num2++;
																			patient[pat_size-1]->patients_no=pat_request[j]->pat_num;
																			patient[pat_size-1]->doc_num=doctor[i]->doc_num;
																			patient[pat_size-1]->pass=pat_request[j]->pass;
																			break;
																		}
																		else
																		{
																			cout<<"\n~~~ Sorry this Request is not pending ~~~\n";
																		}			
																	}		
																}	
															}
															if(option==2)
															{
																for(int j=0;j<pat_req_size;j++)
																{
																	if(reqnum==pat_request[j]->req_num )
																	{
																		if(pat_request[j]->result=="pending")
																		{
																			cout<<"\n~~~ REJECTED ~~~\n";
																			pat_request[j]->result="rejected";
																			break;
																		}
																		else
																		{
																			cout<<"\n~~~ Sorry this Request is not pending ~~~\n";
																		}			
																	}		
																}
															}		
														}
														else
														{
															cout<<"\n~~~! REQUEST DOESN'T EXISTS !~~~\n";
														}	
													}
													else
													{
														cout<<"\n~~~ NO REQUEST FOUND ~~~\n";	
													}
													if(flag==0)
													{
														cout<<"\n~~~ CURRENTLY NO REQUEST AVAILABLE ~~~\n";
													}
												
														
												}
												else
												{
													cout<<"\n~~~ CURRENTLY NO REQUEST AVAILABLE ~~~\n";
												}
												break;
											}
										case 5: //add a patient
											{
												system("cls");
												cout<<"\n<><><><><><><><><>   ADDING A PATIENT   <><><><><><><><><> \n\n";
												pat_size = pat_size + 1;
												patient[pat_size-1] = new patients_data();
												string name;
												cout<<"\nEnter Patients Name : ";
												cin.ignore();
												getline(cin,name);
												toLower(name);
												patient[pat_size-1]->name=name;
												do
												{
													cout<<"\nEnter CNIC no : ";
													cin>>patient[pat_size-1]->cnic;
													if(patient[pat_size-1]->cnic>9999999999999 || patient[pat_size-1]->cnic<999999999999)
													{
														cout<<"Please enter 13 digits in this format (xxxxxxxxxxxxx)";
													}
												}
												while(patient[pat_size-1]->cnic>9999999999999 || patient[pat_size-1]->cnic<999999999999);
												
												int opt1;	
												cout<<"\nSelect Gender :\n1. Male \n2. Female ";
												do
												{
													cout<<"\nSelect gender (1 or 2) : ";
													cin>>opt1;
													if(opt1>2 || opt1<1)
													{
														cout<<"\nThe choise is wrong , please type 1 or 2\n";
													}
												}
												while(opt1>2 || opt1<1);
												
												if(opt1==1)
												{
													patient[pat_size-1]->gender="male";	
												}
												if(opt1==2)
												{
													patient[pat_size-1]->gender="female";	
												}
												
												cout<<"\nEnter age : ";
												cin>>patient[pat_size-1]->age;
														
												patient[pat_size-1]->type=doctor[i]->type;
												patient[pat_size-1]->doc_num=doctor[i]->doc_num;
												patient[pat_size-1]->patients_no=num2++;
												int b3=0;
												do
												{
													string b1,b2;
													cout<<"\n\nEnter password : ";
													cin>>b1;
													cout<<"Enter password again : ";
													cin>>b2;
													if(b1==b2)
													{
														patient[pat_size-1]->pass=b1;
														cout<<"\n~~~Password Added !~~~ \n";
														b3=1;
													}
													else
													{
														cout<<"\nPassword doesn't match! please rewrite\n";
														b3=0;
													}
												}
												while(b3==0);
							
												cout<<"\n~~~NEW PATIENT ADDED!~~~";																
												break;
											}
										default: //logout
											{
												cout<<"\n~~~ Good bye, Have a nice day ~~~";
											}
									}
									cout<<"\n\nDo you want to check menu again (y/n) ? : ";
									cin>>again56;
								}
								while(again56!='n');
				                break;
				            }
				            else
				            {
				                cout<<"~~~ Incorrect password ~~~\n";
				                break;
				            }
						}   
			        }
			    }
			    if(count == 0)
			    {
			        cout<<"~~~ Doctor Number doesn't exist ~~~\n";
			    }
			}
			while(count == 0);
		}
		
		if(menu==2) //new doctor
		{
			system("cls");
			int cmd;
			cout<<"\n<><><><><><><><><>   NEW DOCTOR   <><><><><><><><><> \n\n";
			cout<<"\nSelct\n\n1. Sign up as new\n2. Check your Request\n";
			do
			{
				cout<<"\nENTER COMMAND (1 or 2) : ";
				cin>>cmd;
				if(cmd>2 || cmd<1)
				{
					cout<<"You Entered a wrong command , Please enter again\n";
				}
			}
			while(cmd>2 || cmd<1);
			if(cmd==1)
			{
				system("cls");
				cout<<"\n<><><><><><><><><>   SIGNING UP AS A NEW DOCTOR   <><><><><><><><><> \n\n";
				doc_req_size = doc_req_size + 1;
				request[doc_req_size-1] = new doc_request_data();
				request[doc_req_size-1]->result="pending";
				
				string name;
				cout<<"\nEnter Doctor Name : ";
				cin.ignore();
				getline(cin,name);
				toLower(name);
				request[doc_req_size-1]->name=name;
				int rep=1;
					do
					{
					    rep = 0;
					    do
					    {
					        cout<<"\nEnter PMC no (xxxx): ";
					        cin>>request[doc_req_size-1]->pmc_no;
					        if(request[doc_req_size-1]->pmc_no>9999 || request[doc_req_size-1]->pmc_no<999)
					        {
					        	cout<<"Enter 4 digits PMC number\n";
							}
					    }
					    while(request[doc_req_size-1]->pmc_no>9999 || request[doc_req_size-1]->pmc_no<999);
					
					    //if the pmc number already existing
					    for(int i=0;i<doc_size;i++)
					    {
			                if(request[doc_req_size-1]->pmc_no==doctor[i]->pmc_no)
			                {
			                    rep=1;
			                    break;
			                }
					    }
					    
					    if(rep==1)
					    {
					    	cout<<"\nThe PMC number Already exists\n";
						}
					}
					while(rep==1);
										
					do
					{
						cout<<"\nEnter CNIC no : ";
						cin>>request[doc_req_size-1]->cnic;
						if(request[doc_req_size-1]->cnic>9999999999999 || request[doc_req_size-1]->cnic<999999999999)
						{
							cout<<"Please enter 13 digits in this format (xxxxxxxxxxxxx)";
						}
					}
					while(request[doc_req_size-1]->cnic>9999999999999 || request[doc_req_size-1]->cnic<999999999999);
					
					int opt2;	
					cout<<"\nSelect Gender :\n1. Male \n2. Female ";
					do
					{
						cout<<"\nSelect gender (1 or 2) : ";
						cin>>opt2;
						if(opt2>2 || opt2<1)
						{
							cout<<"\nThe choice is wrong , please type 1 or 2\n";
						}
					}
					while(opt2>2 || opt2<1);
					
					if(opt2==1)
					{
						request[doc_req_size-1]->gender="Male";	
					}
					if(opt2==2)
					{
						request[doc_req_size-1]->gender="Female";	
					}
					
					cout<<"\nEnter age : ";
					cin>>request[doc_req_size-1]->age;
					
					int b;
					cout<<"\nSelect type : \n1. Oncologist\n2. Cardiologist\n3. Ophthalmologist\n4. Psychiatrist\n5. Dermatologist";
					do
					{
						cout<<"\nSelect type (1-5): ";
						cin>>b;
						if(b>5 || b<1)
						cout<<"Wrong selection ! please select again\n";
					}
					while(b>5 || b<1);
					if(b==1)
					{
						request[doc_req_size-1]->type="oncologist";
					}
					if(b==2)
					{
						request[doc_req_size-1]->type="cardiologist";
					}
					if(b==3)
					{
						request[doc_req_size-1]->type="ophthalmologist";
					}
					if(b==4)
					{
						request[doc_req_size-1]->type="psychiatrist";
					}
					if(b==5)
					{
						request[doc_req_size-1]->type="dermatologist";
					}					
					 
					
					
					cout<<"\nRequest number : "<<num3;
					request[doc_req_size-1]->req_num=num3++;
					
					int b3=0;
					do
					{
						string b1,b2;
						cout<<"\n\nEnter password : ";
						cin>>b1;
						cout<<"Enter password again : ";
						cin>>b2;
						if(b1==b2)
						{
							request[doc_req_size-1]->pass=b1;
							cout<<"\n~~~Password Added !~~~ \n";
							b3=1;
						}
						else
						{
							cout<<"\nPassword doesn't match! please rewrite\n";
							b3=0;
						}
					}
					while(b3==0);

					cout<<"\n~~~Request sent ! Please wait!~~~\n";	
			}
			if(cmd==2)
			{
				system("cls");
				cout<<"\n<><><><><><><><><>   CHECKING REQUEST   <><><><><><><><><> \n\n";
				int reqnum;
				string pass;
				cout<<"\nEnter Request number : ";
				cin>>reqnum;
				cout<<"\nEnter Password : ";
				cin>>pass;
				int num=human_verification();
				if(num==1)
				{
					if(doc_req_size!=0)
					{
						for(int i=0;i<doc_req_size;i++)
						{
							if(reqnum==request[i]->req_num)
							{
								if(request[i]->result=="pending")
								{
									cout<<"\n~~~ Your request is still pending ~~~\n";
								}
								if(request[i]->result=="accepted")
								{
									cout<<"\n~~~ Your request is accepted ~~~\n";
									cout<<"YOUR DOCTOR NUMBER IS "<<request[i]->doc_num;
								}
								if(request[i]->result=="rejected")
								{
									cout<<"\n~~~ Your request is rejected ~~~\n";
								}
							}
						}
					}
					else
					{
						cout<<"\n~~~ No requests are there ~~~\n";
					}
				}
				else
				{
					cout<<"\n~~~ Verifcation failed ~~~\n";
				}
			}
			
			
		}
		if(menu==3) //login as patient
		{
			
		}
		if(menu==4) //new patient
		{
			system("cls");
			cout<<"\n<><><><><><><><><>   NEW PATIENT   <><><><><><><><><> \n\n";
			cout<<"\nMENU:\n1. Signup as a new patient\n2. check your request\n";
			int opt;
			do
			{
				cout<<"\nEnter your Command (1 or 2) : ";
				cin>>opt;
				if(opt>2 || opt<1)
				{
					cout<<"\n~~~ WRONG SELECTION! SELECT AGAIN ~~~\n";
				}
			}
			while(opt>2 || opt<1);
			if(opt==1) //signup as new patient
			{
				system("cls");
				cout<<"\n<><><><><><><><><>   SIGNING UP AS NEW PATIENT   <><><><><><><><><> \n\n";
				
				pat_req_size = pat_req_size + 1;
				pat_request[pat_req_size-1] = new pat_request_data();
				pat_request[pat_req_size-1]->result="pending";
				
				string name;
				cout<<"\nEnter Your Name : ";
				cin.ignore();
				getline(cin,name);
				toLower(name);
				pat_request[pat_req_size-1]->name=name;						
				do
				{
					cout<<"\nEnter CNIC no : ";
					cin>>pat_request[pat_req_size-1]->cnic;
					if(pat_request[pat_req_size-1]->cnic>9999999999999 || pat_request[pat_req_size-1]->cnic<999999999999)
					{
						cout<<"\nPlease enter 13 digits in this format (xxxxxxxxxxxxx)\n";
					}
				}
				while(pat_request[pat_req_size-1]->cnic>9999999999999 || pat_request[pat_req_size-1]->cnic<999999999999);
					
				int opt2;	
				cout<<"\nSelect Gender :\n1. Male \n2. Female ";
				do
				{
					cout<<"\nSelect gender (1 or 2) : ";
					cin>>opt2;
					if(opt2>2 || opt2<1)
					{
						cout<<"\nThe choice is wrong , please type 1 or 2\n";
					}
				}
				while(opt2>2 || opt2<1);
				
				if(opt2==1)
				{
					pat_request[pat_req_size-1]->gender="Male";	
				}
				if(opt2==2)
				{
					pat_request[pat_req_size-1]->gender="Female";	
				}
					
				cout<<"\nEnter age : ";
				cin>>pat_request[pat_req_size-1]->age;
					
				int b;
				cout<<"\nSelect type of doctor you want : \n1. Oncologist\n2. Cardiologist\n3. Ophthalmologist\n4. Psychiatrist\n5. Dermatologist";
				do
				{
					cout<<"\nSelect type (1-5): ";
					cin>>b;
					if(b>5 || b<1)
					cout<<"Wrong selection ! please select again\n";
				}
				while(b>5 || b<1);
				if(b==1)
				{
					pat_request[pat_req_size-1]->type="oncologist";
				}
				if(b==2)
				{
					pat_request[pat_req_size-1]->type="cardiologist";
				}
				if(b==3)
				{
					pat_request[pat_req_size-1]->type="ophthalmologist";
				}
				if(b==4)
				{
					pat_request[pat_req_size-1]->type="psychiatrist";
				}
				if(b==5)
				{
					pat_request[pat_req_size-1]->type="dermatologist";
				}	
				
				
				
				cout<<"\nSelect the doctor of your choise : \n";
				int size=0;
				for(int i=0;i<doc_size;i++)
				{
					if(doctor[i]->type==pat_request[pat_req_size-1]->type)
					{
						size++;
					}
				}
				
				string name1[size];
				int my=0;
				for(int i=0;i<doc_size;i++)
				{
					if(doctor[i]->type==pat_request[pat_req_size-1]->type)
					{
						cout<<my+1<<".\t"<<doctor[i]->name<<endl;
						name1[my]=doctor[i]->name;
						my++;
					}
				}
				int sel;
				do
				{
					cout<<"\nSELECT : ";
					cin>>sel;
					if(sel>my || sel<1)
					{
						cout<<"\n~~~ WRONG SELECTION! SELECT AGAIN ~~~\n";
					}
				}
				while(sel>my || sel<1);
				
				for(int i=0;i<doc_size;i++)
				{
					if(name1[sel-1]==doctor[i]->name)
					{
						pat_request[pat_req_size-1]->doc_num=doctor[i]->doc_num;
					}
				}
				
					
				cout<<"\nRequest number : "<<num4;
				pat_request[pat_req_size-1]->req_num=num4++;
					
					int b3=0;
					do
					{
						string b1,b2;
						cout<<"\n\nEnter password : ";
						cin>>b1;
						cout<<"Enter password again : ";
						cin>>b2;
						if(b1==b2)
						{
							pat_request[pat_req_size-1]->pass=b1;
							cout<<"\n~~~Password Added !~~~ \n";
							b3=1;
						}
						else
						{
							cout<<"\nPassword doesn't match! please rewrite\n";
							b3=0;
						}
					}
					while(b3==0);
					
					cout<<"\n~~~ REQUEST SENT! WAIT UNTILL DOCTOR ACCEPSTS YOUR REQUEST ~~~\n";
				
				
			}
			if(opt==2) //check request
			{
				system("cls");
				cout<<"\n<><><><><><><><><>   CHECKING REQUEST   <><><><><><><><><> \n\n";
				int reqnum;
				string pass;
				cout<<"\nEnter Request number : ";
				cin>>reqnum;
				cout<<"\nEnter Password : ";
				cin>>pass;
				int num=human_verification();
				
				int flag;
				if(num==1)
				{
					if(pat_req_size!=0)
					{
						for(int i=0;i<pat_req_size;i++)
						{
							if(reqnum==pat_request[i]->req_num)
							{
								if(pass==pat_request[i]->pass)
								{
									if(pat_request[i]->result=="pending")
									{
										cout<<"\n<><><><><><><><> Your request is still pending <><><><><><><><>\n";
									}
									if(pat_request[i]->result=="accepted")
									{
										cout<<"\n<><><><><><><><> Your request is accepted <><><><><><><><>\n";
										cout<<"\n\nYOUR PATIENT NUMBER IS "<<pat_request[i]->pat_num;
									}
									if(pat_request[i]->result=="rejected")
									{
										cout<<"\n<><><><><><><><> Your request is rejected <><><><><><><><>\n";
									}
									flag=0;
									break;
								}
								else
								{
									flag=2;
								}
									
							}
							else
							{
								flag=1;
							}
							
						}
					}
					else
					{
						cout<<"\n~~~ No requests are there ~~~\n";
					}	
				}
				else
				{
					cout<<"\n~~~ Verifcation failed ~~~\n";
				}
				
				if(flag==1)
				{
					cout<<"\n~~~ Request doesnn't Exixts! ~~~\n";
				}
				if(flag==2)
				{
					cout<<"\n~~~ WRONG PASSWORD! ~~~\n";
				}
				
			}
		}
		
		if(menu==5)//loggingin as hospital management
		{
			system("cls");
			cout<<"\n<><><><><><><><><>   LOGGING IN AS HOSPITAL MANAGEMENT   <><><><><><><><><> \n\n";
			string login;
			string password;
			cout<<"\nEnter Username : ";
			cin>>login;
			cout<<"\nEnter Password : ";
			cin>>password;
			int me=human_verification();
			if(me==1 && login=="groupno1" && password=="admin")
			{
				char again;
				do
				{
					system("cls");
					cout<<"\n<><><><><><><><><>   LOGGED IN AS HOSPITAL MANAGEMENT   <><><><><><><><><> \n\n";
					int opt;
					cout<<"\n1. Check all doctors list ";
					cout<<"\n2. Check all patients ";
					cout<<"\n3. Check doctors request";
					cout<<"\n4. Add a doctor";
					cout<<"\n5. Logout\n";
					do
					{
						cout<<"\nEnter your operation (1-5) : ";
						cin>>opt;
						if(opt>5 || opt<1)
						{
							cout<<"Wrong selection ! Please select again\n";
						}
					}
					while(opt>5 || opt<1);
					
					
					if(opt==1)
					{
						system("cls");
						cout<<"\n<><><><><><><><><><>    DISPLAYING ALL DOCTORS LIST    <><><><><><><><><><> \n\n";
						cout<<"\nDOCTOR NAME\t\tPMC NO\tCNIC\t\tGENDER\tAGE\tTYPE\t\tDOCTOR NUMBER\tPASSWORD"<<endl<<endl;
						for(int i=0;i<doc_size;i++)
						{
							cout<<i+1<<". "<<doctor[i]->name<<"\t"<<doctor[i]->pmc_no<<"\t"<<doctor[i]->cnic<<
							"\t"<<doctor[i]->gender<<"\t"<<doctor[i]->age<<"\t"<<doctor[i]->type<<"\t\t"<<
							doctor[i]->doc_num<<"\t"<<doctor[i]->pass<<endl;
						}
					}
					
					if(opt==2)
					{
						system("cls");
						cout<<"\n<><><><><><><><><><>    DISPLAYING ALL PATIENTS LIST    <><><><><><><><><><> \n\n";
						cout<<"\nPATIENTS NAME\t\tPAT NO\tCNIC\t\tGENDER\tAGE\tTYPE\t\tDOCTOR NUMBER\tPASSWORD"<<endl<<endl;
						for(int i=0;i<pat_size;i++)
						{
							cout<<i+1<<". "<<patient[i]->name<<"\t\t"<<patient[i]->patients_no<<"\t"<<patient[i]->cnic<<
							"\t"<<patient[i]->gender<<"\t"<<patient[i]->age<<"\t"<<patient[i]->type<<"\t\t"<<
							patient[i]->doc_num<<"\t"<<patient[i]->pass<<endl;
						}
					}
					
					if(opt==3)
					{
						system("cls");
						cout<<"\n<><><><><><><><><><>    DISPLAYING ALL REQUESTS     <><><><><><><><><><> \n\n";
						if(doc_req_size!=0)
						{
							cout<<"\nDOCTOR NAME\t\tPMC NO\tCNIC\t\tGENDER\tAGE\tTYPE\t\tREQUEST NUMBER\tPASSWORD\tRESULT"<<endl<<endl;
							for(int i=0;i<doc_req_size;i++)
							{
								cout<<i+1<<". "<<request[i]->name<<"\t\t"<<request[i]->pmc_no<<"\t"<<request[i]->cnic<<
								"\t"<<request[i]->gender<<"\t"<<request[i]->age<<"\t"<<request[i]->type<<"\t\t"<<
								request[i]->req_num<<"\t"<<request[i]->pass<<"\t\t"<<request[i]->result<<endl;
							}
							
							
							
							
							int reqnum;
							cout<<"\nWhich request do you want to check (write request number) : ";
							cin>>reqnum;
							int flag=0;
							for(int i=0;i<doc_req_size;i++)
							{
								if(reqnum==request[i]->req_num)
								{
									flag=1;
									break;
								}
								else
								flag=0;
							}
							if(flag==1)
							{
								int option;
								cout<<"\nSelect :\n1. Accept\n2. Reject\n";
								do
								{
									cout<<"\nEnter option ( 1-2 ) : ";
									cin>>option;
									if(option>2 || option <1)
									{
										cout<<"~~~Wrong select ! Please select again ~~~\n";
									}
								}
								while(option>2 || option <1);
								
	
								if(option==1)
								{
									for(int i=0;i<doc_req_size;i++)
									{
										if(reqnum==request[i]->req_num )
										{
											if(request[i]->result=="pending")
											{
												cout<<"\n~~~ ACCEPTED ~~~\n";
												request[i]->result="accepted";
												doc_size = doc_size + 1;
												doctor[doc_size-1] = new doctors_data();
												doctor[doc_size-1]->name=request[i]->name;
												doctor[doc_size-1]->pmc_no=request[i]->pmc_no;
												doctor[doc_size-1]->cnic=request[i]->cnic;
												doctor[doc_size-1]->gender=request[i]->gender;
												doctor[doc_size-1]->age=request[i]->age;
												doctor[doc_size-1]->type=request[i]->type;
												request[i]->doc_num=num1;
												doctor[doc_size-1]->doc_num=num1++;
												doctor[doc_size-1]->pass=request[i]->pass;
												break;
											}
											else
											{
												cout<<"\n~~~ Sorry this Request is not pending ~~~\n";
											}			
										}		
									}	
								}
								if(option==2)
								{
									for(int i=0;i<doc_req_size;i++)
									{
										if(reqnum==request[i]->req_num )
										{
											if(request[i]->result=="pending")
											{
												cout<<"\n~~~ REJECTED ~~~\n";
												request[i]->result="rejected";
												break;
											}
											else
											{
												cout<<"\n~~~ Sorry this Request is not pending ~~~\n";
											}			
										}		
									}
								}		
							}
							else
							{
								cout<<"\n~~~! REQUEST DOESN'T EXISTS !~~~\n";
							}
							
							
						}
						else
						cout<<"\n~~~ NO REQUEST FOUND ~~~\n";
							
					}
					if(opt==4)
					{
						system("cls");
						cout<<"\n<><><><><><><><><>   ADDING A DOCTOR   <><><><><><><><><> \n\n";
						// increasing the doc_size of the array
						doc_size = doc_size + 1;
						doctor[doc_size-1] = new doctors_data();
						
						string name;
						cout<<"\nEnter Doctor Name : ";
						cin.ignore();
						getline(cin,name);
						toLower(name);
						doctor[doc_size-1]->name=name;
						
						int rep=1;
						do
						{
						    rep = 0;
						    do
						    {
						        cout<<"\nEnter PMC no (xxxx): ";
						        cin>>doctor[doc_size-1]->pmc_no;
						        if(doctor[doc_size-1]->pmc_no>9999 || doctor[doc_size-1]->pmc_no<999)
						        {
						        	cout<<"Enter 4 digits PMC number\n";
								}
						    }
						    while(doctor[doc_size-1]->pmc_no>9999 || doctor[doc_size-1]->pmc_no<999);
						
						    //if the pmc number already existing
						    for(int i=0;i<doc_size;i++)
						    {
						        for(int j=i+1;j<doc_size;j++)
						        {
						            if(i!=j)
						            {
						                if(doctor[j-1]->pmc_no==doctor[doc_size-1]->pmc_no)
						                {
						                    rep=1;
						                    break;
						                }
						            }
						        }
						        if (rep == 1) break;
						    }
						    
						    if(rep==1)
						    {
						    	cout<<"\nThe PMC number Already exists\n";
							}
						}
						while(rep==1);
							
						
						do
						{
							cout<<"\nEnter CNIC no : ";
							cin>>doctor[doc_size-1]->cnic;
							if(doctor[doc_size-1]->cnic>9999999999999 || doctor[doc_size-1]->cnic<999999999999)
							{
								cout<<"Please enter 13 digits in this format (xxxxxxxxxxxxx)";
							}
						}
						while(doctor[doc_size-1]->cnic>9999999999999 || doctor[doc_size-1]->cnic<999999999999);
						
						int opt1;	
						cout<<"\nSelect Gender :\n1. Male \n2. Female ";
						do
						{
							cout<<"\nSelect gender (1 or 2) : ";
							cin>>opt1;
							if(opt1>2 || opt1<1)
							{
								cout<<"\nThe choise is wrong , please type 1 or 2\n";
							}
						}
						while(opt1>2 || opt1<1);
						
						if(opt1==1)
						{
							doctor[doc_size-1]->gender="Male";	
						}
						if(opt1==2)
						{
							doctor[doc_size-1]->gender="Female";	
						}
						
						cout<<"\nEnter age : ";
						cin>>doctor[doc_size-1]->age;
						
						int a;
						cout<<"\nSelect type : \n1. Oncologist\n2. Cardiologist\n3. Ophthalmologist\n4. Psychiatrist\n5. Dermatologist";
						do
						{
							cout<<"\nSelect type (1-5): ";
							cin>>a;
						}
						while(a>5 || a<1);
						if(a==1)
						{
							doctor[doc_size-1]->type="oncologist";
						}
						if(a==2)
						{
							doctor[doc_size-1]->type="cardiologist";
						}
						if(a==3)
						{
							doctor[doc_size-1]->type="ophthalmologist";
						}
						if(a==4)
						{
							doctor[doc_size-1]->type="psychiatrist";
						}
						if(a==5)
						{
							doctor[doc_size-1]->type="dermatologist";
						}					
						 
						
						
						cout<<"\nDoctor number : "<<num1;
						doctor[doc_size-1]->doc_num=num1++;
						
						int b3=0;
						do
						{
							string b1,b2;
							cout<<"\n\nEnter password : ";
							cin>>b1;
							cout<<"Enter password again : ";
							cin>>b2;
							if(b1==b2)
							{
								doctor[doc_size-1]->pass=b1;
								cout<<"\n~~~Password Added !~~~ \n";
								b3=1;
							}
							else
							{
								cout<<"\nPassword doesn't match! please rewrite\n";
								b3=0;
							}
						}
						while(b3==0);
	
						cout<<"\n~~~NEW DOCTOR ADDED!~~~";	
							
					}
					if(opt==5)
					{
						system("cls");
						cout<<"\n\n~~~Account Logged out~~~\n";
						break;
					}
					cout<<"\n\nDo you want to check menu again (y/n) : ";
					cin>>again;
		
				}
				while(again!='n');
			}
			else
			{
				cout<<"\n~~~ Access Denied ~~~\n";
			}				
		}
		
		if(menu==6)
		{
			break;
		}
		cout<<"\nDo you want to login again (y/n) : ";
		cin>>aga;
		cout<<endl;
	}
	while(aga!='n');
	
	cout<<"\n\n\n~~~ GOOD BYE , HAVE A NICE DAY ~~~\n";
}


//function definition
int human_verification()
{
	cout<<"\n~~~ HUMAN VERIFICATION ~~~\n";
	cout<<"\nVERIFY YOU ARE A HUMAH";
	srand(time(0));
  	int num[4];
  	cout<<"\nGenerating number :\t\t\t";
  	for(int i=0;i<4;i++)
  	{
    	num[i]=(rand() % 9 + 1);
    	cout<<num[i];
    	sleep(1);
  	}

  	sort(num, num + 4);  

  	int pass = 0;  
  	int multiplier = 1;
  	for (int i = 3; i >= 0; i--) {
    	pass += num[i] * multiplier;
    	multiplier *= 10;
  	}
  	
  	int pass1;
  	cout<<"\nSort the Generated number :\t\t";
  	cin>>pass1;
  	if(pass1==pass)
  	{
  		cout<<"\n~~~Nice Job Verified~~~\n";
  		return 1;
	}
	else
	{
		cout<<"\n~~~ Verification Failed ~~~\n";
		return 0;
	}
  	
}

void toLower(string& str) 
{
    for (int i = 0; i < str.length(); i++) 
	{
        str[i] = std::tolower(str[i]);
    }
}
void printECGLine(int age, int heartRate, int bloodPressure) {
    // calculate ECG line using the passed parameters

    // initialize graphics window
    initwindow(800, 600, "ECG Line");
    
    // calculate formula parameters based on input values
    double hrFactor = 60.0 / heartRate;   // adjusts the frequency of the waveform
    double bpFactor = bloodPressure / 10.0;   // adjusts the amplitude of the waveform
    double ageFactor = (age - 20) / 50.0;   // adjusts the shape of the waveform
    
    // draw ECG line
    setcolor(RED);
    double t = 0;
    double dt = 0.001;
    int x = 0;
    int y = 0;
    double v = 0;
    
    // generate ECG waveform
    for (int i = 0; i < 8000; i++) {
        v = 0.25 * (sin(2 * M_PI * (1.0 / hrFactor) * t - M_PI / 2.0) +
                    0.5 * sin(2 * M_PI * (1.0 / (hrFactor / 2.0)) * t + M_PI / 4.0) +
                    0.25 * sin(2 * M_PI * (1.0 / (hrFactor / 4.0)) * t + M_PI / 2.0));
        
        if (t < 0.12) {
            v = (0.01 / 0.12) * t;
        } else if (t < 0.2) {
            v = (-0.1 / 0.08) * (t - 0.12) + 0.01;
        } else if (t < 0.33) {
            v = (0.04 / 0.13) * (t - 0.2) - 0.09;
        } else if (t < 0.4) {
            v = (-0.05 / 0.07) * (t - 0.33) - 0.05;
        } else if (t < 0.55) {
            v = (0.15 / 0.15) * (t - 0.4) - 0.1;
        } else if (t < 0.66) {
            v = (-0.2 / 0.11) * (t - 0.55) + 0.05;
        } else if (t < 0.8) {
            v = (0.1 / 0.14) * (t - 0.66) - 0.15;
        } else if (t < 1.0) {
            v = (-0.1 / 0.2) * (t - 0.8) - 0.05;
		} else {
		v = 0;
		}
	    // adjust the amplitude and shape of the waveform
	    v *= bpFactor * exp(-ageFactor * t);
	    
	    // convert to pixel coordinates and draw
		x = i;
		y = 300 - 100 * v;
		
		// adjust the amplitude of the waveform based on heart rate
		double hrAmplitude = 1;
		if (heartRate > 0) {
		    hrAmplitude = heartRate / 100.0;
		}
		y *= hrAmplitude;
		
		putpixel(x, y, RED);
		
		t += dt;
	}

	
}
