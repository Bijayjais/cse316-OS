#include <stdio.h>

struct process{
	int p[50];
	float at[50];
	float bt[50];
	float ct[50];
	float tat[50];
	float wt[50];
}o, a, b, c;

int i, j, n, pos;
float min, temp, temp1, temp2, total;	

void user_input(){
	printf("Enter the number of processes you wish to enter: ");
	scanf("%d", &n);
	printf("Enter arrival time and burst time for the processes: ");
	for(i = 0; i < n; i++){
		a.p[i] = i+1;
		printf("p%d:\n", i+1);
		printf("Arrival time : ");
		scanf("%f", &a.at[i]);
		printf("Burst time : ");
		scanf("%f", &a.bt[i]);
	}
}
 
void result(struct process p){
	float avg = 0;
	total = 0;	
	printf("\n\tP.No.\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++){
		printf("\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", p.p[i], p.at[i], p.bt[i], p.ct[i], p.tat[i], p.wt[i]);
		total += p.tat[i]; 
	}
	avg = total/n;
	printf("\n\tThe average turnaround time is : %.2f secs\n\n", avg);
}

void mnm(float arr[]){
	min = arr[0];
	while(i < n){
		if(arr[i] < min){
			min = arr[i];
		i++;
		}
	}
}

void sort(float arr[], float arr1[], int arr2[]){
	for(i = 1; i < n; i++){
		temp = arr[i];
		temp1 = arr1[i];
		temp2 = arr2[i];
		j = i-1;
		while((temp < arr[j]) && (arr[j] >= 0)){
			arr[j+1] = arr[j];
			arr1[j+1] = arr1[j];
			arr2[j+1] = arr2[j];
			j--;
		}
		arr[j+1] = temp;
		arr1[j+1] = temp1;
		arr2[j+1] = temp2;
	}
}

void fcfs(){
	b = a;
	sort(b.at, b.bt, b.p);
	total = b.at[0];
	for(i = 0; i < n; i++){
		total += b.bt[i];
		b.ct[i] = total;
		b.tat[i] = b.ct[i] - b.at[i];
		b.wt[i] = b.tat[i] - b.bt[i];
	}
	printf("\n\tAfter applying First Come First Serve.\n");
	result(b);	
}

void sjf(){
	c = a;
	mnm(c.at);
	sort(c.bt, c.at, c.p);
	for(i = 0; i < n; i++){
		if(c.at[i] == min){
			pos = i;
			temp = c.p[pos];
			temp1 = c.at[pos];
			temp2 = c.bt[pos];
			for(j = pos; j > 0; j--){
				c.p[j] = c.p[j-1];
				c.at[j] = c.at[j-1];
				c.bt[j] = c.bt[j-1];
			}
			c.p[0] = temp;
			c.at[0] = temp1;
			c.bt[0] = temp2;
		}
	}
	total = c.at[0];
	for(i = 0; i < n; i++){
		total += c.bt[i];
		c.ct[i] = total;
		c.tat[i] = c.ct[i] - c.at[i];
		c.wt[i] = c.tat[i] - c.bt[i];
	}
	printf("\n\tAfter applying Shortest Job First.\n");
	result(c);
}

void sjfi(){
	b = a;
	sort(b.bt, b.at, b.p);
	for(i = 0; i < n; i++){
		if(b.at[i] >= 1.00){
			pos = i;
			temp = b.p[pos];
			temp1 = b.at[pos];
			temp2 = b.bt[pos];
			for(j = pos; j > 0; j--){
				b.p[j] = b.p[j-1];
				b.at[j] = b.at[j-1];
				b.bt[j] = b.bt[j-1];
			}
			b.p[0] = temp;
			b.at[0] = temp1;
			b.bt[0] = temp2;
		}
	}
	printf("\n\tAfter applying Shortest Job First with idle time = 1.\n");
	total = b.at[0];
	for(i = 0; i < n; i++){
		total += b.bt[i];
		b.ct[i] = total;
		b.tat[i] = b.ct[i] - b.at[i];
		b.wt[i] = b.tat[i] - b.bt[i];
	}
	result(b);
}									
		
int main(){
	user_input();
	fcfs();	
	sjf();
	sjfi();
	return 0;
}

