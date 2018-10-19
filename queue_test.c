#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int *queue_elem(int data)
{
    int *elem = (int *)malloc(sizeof(int));
    *elem = data;
    return elem;
}
int main(void)
{
        char *input=(char *)malloc(10);
        int queue_data=0,option=0;
        int q_size = 0;
        int elem_cnt = 0;
        int *top_elem = NULL;

        printf("\n Please enter the size of the QUEUE to be created :");
        scanf("%d",&q_size);
        if (!create_queue(q_size)) {
            printf("\n Queue creation of size %d Failed",q_size);
            return 0;
        }
        do {
            printf("\n Enter QUEUE operation to be performed");
            printf("\n 1. Enqueue");
            printf("\n 2. Dqueue");
            printf("\n 3. top_element");
            printf("\n 4. Print queue all elem");
            printf("\n E. Exit");
            scanf("%s",input);
            if (strcmp(input,"E")) {
                option = atoi(input);
                switch(option) {
                    case 1:
         	       memset(input,0,10);
                       printf("\nEnter data to insert into queue(press E to exit)");
                       scanf("%s",input);
                       queue_data = atoi(input);
                       if (!enqueue((void *)queue_elem(queue_data))) {
                           printf("\n Failed to enequeue %d",queue_data);
                       } 
			elem_cnt++;
                       break;
                    case 2: /* dequeue*/
                       dequeue();
  			break;
                    case 3: /* topelem*/
        		top_elem = (int *)queue_frontelem();
 			if (top_elem) {
 			    printf("\n The front element is %d",*top_elem);
			}
			break;
                    case 4: /* print_q */
        		printf("\n Printing the QUEUE \n");
  			print_queue();
			break;
                    default:
                         printf("\n Invalid input, retry....");
                         break;
                }
            }
        }while (strcmp(input,"E") && (elem_cnt < q_size) );

        return 0;
}
