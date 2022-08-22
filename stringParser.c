#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief String Parser 
 * @param  [in]  input   Input Array
 * @param  [in]  header  Header of parse line
 * @param  [in]  start   Start Character
 * @param  [in]  end     Finish Character
 * @param  [out] output  Output Array
 * @return [int8_t]      Function Execute Result
 * @retval [0]           Success
 * @retval [1]           Fail
 */
int8_t parser(char* input,const char* header,const char* start,const char* end,char* output )
{
    if(strstr(input,header))
    {
        strcpy(output,strtok(input,start));
        strcpy(output,strtok(NULL,end));
        return EXIT_SUCCESS;
    }
    printf("Undefined Data\n");
    return EXIT_FAILURE; 
}

int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;

    char demand[] = "[ DEMAND ]";
    char name[]   = "NAME=Demand_00$";
    char message[]= "MSG=%00000000000000000000#\\x06$";
    //Static or Local Variable
    //char result[50] = { 0 };

    //Dynamic Variable
    char* result = (char*)calloc(50,sizeof(char));
    
    parser(demand,"[ DEMAND ]"," "," ",result);
    printf("Result : %s\n",result);

    parser(name,"NAME=","=","$",result);
    printf("Result : %s\n",result);

    parser(message,"MSG=","=","$",result);
    printf("Result : %s\n",result);

    free(result);

    return EXIT_SUCCESS;
}


