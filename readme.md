
# String Parser in C

String Parser in C Standart Libs.



## API Functions

#### Timer Initalize
```c
int8_t parser(char* input,const char* header,const char* start,const char* end,char* output );
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `input` | `char*` | Input Array |
| `header ` | `char*` | Header of Array|
| `start  ` | `char*` | Parsing Starter |
| `end  ` | `char*` | Parsing Finisher |
| `output  ` | `char*` | Output Array |

#### Example Code
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;

    char demand[] = "[ DEMAND ]";
    char name[]   = "NAME=Demand_00$";
    char message[]= "MSG=%00000000000000000000#\\x06$";
    //Local Variable
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
```

## Download Code

Clone Project

```bash
  git clone https://github.com/seff34/String-Parser
```


  
