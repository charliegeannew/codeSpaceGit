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

	if(my_rank!=0){
			// MPI_Barrier(MPI_COMM_WORLD);
		MPI_Request request;
		sprintf(greeting,"Greetings from process %d of %d!",my_rank,comm_sz);
		// MPI_Send(greeting,strlen(greeting),MPI_CHAR,0,0,MPI_COMM_WORLD);
		// MPI_IRecv(greeting,strlen(greeting),MPI_CHAR,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			// cout<<"444"<<endl;
		// cout<<"in "<<my_rank<<" function the greating is "<<greeting<<endl;
		MPI_Isend(greeting,strlen(greeting),MPI_CHAR,0,0,MPI_COMM_WORLD,&request);
		// cout<<"in "<<my_rank<<" function the greating is "<<greeting<<endl;
			// cout<<"555"<<endl;
		// MPI_Irecv(greeting,max_string,MPI_CHAR,0,0,MPI_COMM_WORLD,&request);
			// cout<<"666"<<endl;
		// cout<<"in "<<my_rank<<" function the greating is "<<greeting<<endl;
		MPI_Wait(&request,MPI_STATUS_IGNORE);
	}
	else{
		MPI_Request request;
		// cout<<"Greetings from process "<<my_rank<<" of "<<comm_sz<<"!"<<endl;
		// sprintf(greeting,"Greetings from process %d of %d!",my_rank*5+5,comm_sz*5);
		for(int i=1;i<comm_sz;i++){
			// MPI_Recv(greeting,max_string,MPI_CHAR,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			// cout<<"111"<<endl;
			int j=0;
			while(j<1000){
				j++;
			}
			MPI_Irecv(greeting,max_string,MPI_CHAR,i,0,MPI_COMM_WORLD,&request);
			cout<<"in "<<my_rank<<" function the greating is "<<greeting<<endl;
			// cout<<"222"<<endl;
			// MPI_Isend(greeting,strlen(greeting),MPI_CHAR,i,0,MPI_COMM_WORLD,&request);
			// cout<<"333"<<endl;
			// MPI_Send(greeting,max_string,MPI_CHAR,i,0,MPI_COMM_WORLD);
			// MPI_Barrier(MPI_COMM_WORLD);
			MPI_Wait(&request,MPI_STATUS_IGNORE);
			// cout<<"in "<<my_rank<<" function the greating is "<<greeting<<endl;
		}
	}
	
	MPI_Finalize ();
	return 0;
}
