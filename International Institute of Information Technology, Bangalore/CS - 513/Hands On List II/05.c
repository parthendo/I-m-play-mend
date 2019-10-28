#include<stdio.h>
#include<unistd.h>
int main()
{
	long max_arguments,max_process,clock_ticks,max_open,page_size,total_pages_pmemory,curr_avail_pages;
	max_arguments=sysconf(_SC_ARG_MAX);
	max_process=sysconf(_SC_CHILD_MAX);
	clock_ticks=sysconf(_SC_CLK_TCK);
	max_open=sysconf(_SC_OPEN_MAX);
	page_size=sysconf(_SC_PAGE_SIZE);
	total_pages_pmemory=sysconf(_SC_PHYS_PAGES);
	curr_avail_pages=sysconf(_SC_AVPHYS_PAGES);
	printf("Arguments Limit=%ld\n",max_arguments);
	printf("Number of Simultaneous Process per user id=%ld\n",max_process);
	printf("Number of clock ticks per sec%ld\n",clock_ticks);
	printf("Maximum number of open files=%ld\n",max_open);
	printf("Size of a page=%ld\n",page_size);
	printf("Total number of pages in physical memory=%ld\n",total_pages_pmemory);
	printf("Number of currently available pages=%ld\n",curr_avail_pages);
	return 0;
}
