#include <sys/wait.h>
#include <minix/type.h>
#include <sys/types.h>
#include <lib.h>

#include <minix/callnr.h>
#include <minix/config.h>
#include <minix/type.h>
#include <minix/const.h>
#include <minix/com.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char const *argv[]){
	struct pm_mem_info pmi;
	int i, j, h, largest_bytes, total_bytes, nholes, avg, stddev, median;
	int sizes[_NR_HOLES];
	printf("No Holes\tAvg Size\tStdDev Size\tMedian Size\n\n");
	while(1){
		largest_bytes = 0;
		total_bytes = 0;
		nholes = 0;
		for (i = 0; i < _NR_HOLES; ++i){
			sizes[i] = 0;
		}
		/*do stuff */
		if(getsysinfo(PM_PROC_NR, SI_MEM_ALLOC, &pmi) != 0) {
			printf("Obtaining memory hole list failed.\n");
			return;
		}
		for(h = 0; h < _NR_HOLES; h++) {
			if(pmi.pmi_holes[h].h_base && pmi.pmi_holes[h].h_len) {
				int bytes;
				nholes++;
				/*Multiplica por 4096. why not '*' ? idk man*/
				bytes = (pmi.pmi_holes[h].h_len << CLICK_SHIFT);
				for(j = i-1; j >= 0 && (sizes[j] == 0 || sizes[j] > bytes); j--){
					sizes[j+1] = sizes[j];
					sizes[j] = 0;
				}
				sizes[j+1] = bytes;
				if(bytes > largest_bytes) largest_bytes = bytes;
				total_bytes += bytes;
				avg += bytes;
			}
		}
		avg /= nholes;
		median = sizes[nholes/2];
		for (i = 0; i < nholes; ++i){
			stddev += (sizes[i] - avg)*(sizes[i] - avg);
		}
		stddev = sqrt(stddev/nholes);
		printf("%7d\t%7d kB\t%7d kB\t%7d kB\n", nholes, avg/1024, stddev/1024, median/1024);
		sleep(1);
	}
	return 0;
}
