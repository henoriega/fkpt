/*==============================================================================
 NAME: main.c				[code for redshift space correlation function - GSM]
 Alejandro Aviles (avilescervantes@gmail.com), ...
 *  (other people who collaborated: Mario A. Rodriguez-Meza ...)
 ================================================================================ 
 Use: ./gsm -help
 References:  arXiv:1306.1804, arXiv: 1609.02908, arXiv:1909.05261
 ==============================================================================*/

#define global

#include "globaldefs.h"
#include "cmdline_defs.h"
#include "protodefs.h"
#include "models.h"

int main(int argc, string argv[])
{
    gd.cpuinit = second();
    InitParam(argv, defv);
    StartRun(argv[0], HEAD1, HEAD2, HEAD3);
    MainLoop();
    EndRun();
    return 0;
}



void MainLoop(void)
{
    global_variables();
    compute_kfunctions();
    compute_rsdmultipoles();
    write();
    free_variables();	
}
