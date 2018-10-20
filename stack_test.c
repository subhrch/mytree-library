#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int *stack_elem(int data)
{
    int *elem = (int *)malloc(sizeof(int));
    *elem = data;
    return elem;
}
int main(void)
{
        char *input=(char *)malloc(10);
        int stack_data=0,option=0;
        int q_size = 0;
        int elem_cnt = 0;
        int *top_elem = NULL;
        void *temp = NULL;
        void **stack1 = NULL;

        printf("\n Please enter the size of the STACK to be created :");
        scanf("%d",&q_size);
        stack1 = create_stack(q_size);
        if (!stack1) {
            printf("\n Stack creation of size %d Failed",q_size);
            return 0;
        }
        do {
            printf("\n Enter STACK operation to be performed");
            printf("\n 1. PUSH");
            printf("\n 2. POP");
            printf("\n 3. top_element");
            printf("\n 4. Print stack all elem");
            printf("\n E. Exit");
            scanf("%s",input);
            if (strcmp(input,"E")) {
                option = atoi(input);
                switch(option) {
                    case 1:
         	       memset(input,0,10);
                       printf("\nEnter data to insert into stack(press E to exit)");
                       scanf("%s",input);
                       stack_data = atoi(input);
                       if (!push(stack1,(void *)stack_elem(stack_data))) {
                           printf("\n Failed to enequeue %d",stack_data);
                       } 
			elem_cnt++;
                       break;
                    case 2: /* dequeue*/
                        temp=pop(stack1);
                        elem_cnt--;
  			break;
                    case 3: /* topelem*/
        		top_elem = (int *)stack_topelement(stack1);
 			if (top_elem) {
 			    printf("\n The front element is %d",*top_elem);
			}
			break;
                    case 4: /* print_q */
        		printf("\n Printing the STACK \n");
  			print_stack(stack1);
			break;
                    default:
                         printf("\n Invalid input, retry....");
                         break;
                }
            }
        }while (strcmp(input,"E") && (elem_cnt < q_size) );

        return 0;
}
