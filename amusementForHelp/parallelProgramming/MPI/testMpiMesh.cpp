/*************************************************************************
*File Name: testMPI.cpp
*Author:Charliegean
*wht905@gmail.com
*Created Time: Tue Mar 16 09:47:18 2021
 ************************************************************************/
#include <iostream>
#include <string.h>
#include <mpi.h>
using namespace std;

const int max_string = 100;
// const int max_string = 2;

int main ()
{
	int comm_sz=0;
	int my_rank=0;
	char greeting[max_string];
	
	MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);

	switch(my_rank){
		case 0:break;
		case 1:break;
		case 2:break;
		case 3:break;
		default: cout<<"error"<<endl;
	}
	if(my_rank!=0){
		MPI_Request request;
		sprintf(greeting,"Greetings from process %d of %d!",my_rank,comm_sz);
		// MPI_Send(greeting,strlen(greeting),MPI_CHAR,0,0,MPI_COMM_WORLD);
		MPI_Isend(greeting,strlen(greeting),MPI_CHAR,0,0,MPI_COMM_WORLD,&request);
		MPI_Wait(&request,MPI_STATUS_IGNORE);
	}
	else{
		MPI_Request request;
		cout<<"Greetings from process "<<my_rank<<" of "<<comm_sz<<"!"<<endl;
		for(int i=1;i<comm_sz;i++){
			MPI_Recv(greeting,max_string,MPI_CHAR,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			// MPI_Wait(&request,MPI_STATUS_IGNORE);
			cout<<"in "<<my_rank<<" function the greating is "<<greeting<<endl;
		}
	}
	
	MPI_Finalize ();
	return 0;
}
