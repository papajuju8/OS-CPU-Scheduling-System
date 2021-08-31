///Julius Anthony A. Villa
///BSIT-2A
///PROJECT IN OPERATING SYSTEMS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define MAX 10

void FCFS_Scheduling();
void FCFSIO_Scheduling();
void SJF_Scheduling();
void SJFIO_Scheduling();
void SRTF_Scheduling();
void NPP_Scheduling();
void NPPIO_Scheduling();
void PP_Scheduling();
void RR_Scheduling();
void comparison();
void print_comparison();
void delay();

///main
int mainmenu, firstmenu, sndmenufirst, sndmenusecond;

///FCFS
int i=0, j=0, FCFS_num_proc, FCFS_arrival[10], FCFS_cpu_burst[10], FCFS_s[10], FCFS_e[10], FCFS_wait_time[50], FCFS_response_time[50], FCFS_ta_time[50];
float FCFS_ave_wt=0, FCFS_ave_rt=0, FCFS_ave_tat=0, FCFS_fin_ave_wt=0, FCFS_fin_ave_rt=0, FCFS_fin_ave_tat=0;

///SJF
int SJF_numproc; SJF_at[999], SJF_cpubt[999], SJF_s[999], SJF_e[999], SJF_wt[999], SJF_rt[999], SJF_tat[999];
float SJF_wt_ave=0, SJF_rt_ave=0, SJF_tat_ave=0, SJF_fin_wt_ave=0, SJF_fin_rt_ave=0, SJF_fin_tat_ave=0;

///SRTF
void SRTF_drawGanttChart();
void SRTF_calculateProcessSequence();
int SRTF_findAptProcessNumber(int);
int SRTF_numberOfProcesses, SRTF_totalCPUBurstTime, *SRTF_arrivalTime, *SRTF_CPUBurstTime, *SRTF_CPUBurstTimeCopy, *SRTF_processNumber, SRTF_minimumArrivalTime, *SRTF_processSequenceForEachSecond, *SRTF_waitingTime, SRTF_s[999], SRTF_completionTime[999], SRTF_e[999];
float SRTF_averageWaitingTime, SRTF_averageTurnAroundTime;
float SRTF_averageWaitingTime=0, SRTF_responseTime[999], SRTF_averageResponseTime, SRTF_preaverageWaitingTime[999], SRTF_preaverageResponseTime[999], SRTF_preaverageTurnAroundTime[999], SRTF_fin_averageWaitingTime, SRTF_fin_averageTurnAroundTime;
/*arrays used to draw Gantt Chart*/
int *SRTF_processNumberGantt, *SRTF_CPUBurstTimeGantt, SRTF_ganttSize;

///NPP
float NPP_wt = 0, NPP_rt = 0, NPP_tat = 0;

///PP
void PP_drawGanttChart();
void PP_calculateProcessSequence();
int PP_findAptProcessNumber(int);
int PP_numberOfProcesses=0, PP_totalCPUBurstTime, *PP_arrivalTime, *PP_CPUBurstTime, *PP_CPUBurstTimeCopy, *PP_processNumber, PP_minimumArrivalTime, *PP_processSequenceForEachSecond, *PP_waitingTime, *PP_priority;
int PP_s[999], PP_e[999], PP_completionTime[999];
float PP_averageWaitingTime=0, PP_averageTurnAroundTime=0;
float PP_preaverageWaitingTime[999], PP_preaverageTurnAroundTime[999];
float PP_fin_averageWaitingTime=0, PP_fin_averageTurnAroundTime=0;
/*arrays used to draw Gantt Chart*/
int *PP_processNumberGantt, *PP_CPUBurstTimeGantt, PP_ganttSize;

///RR
void RR_drawGanttChart();
void RR_calculateProcessSequence();
int RR_findAptProcessNumber(int,int,int);
int RR_numberOfProcesses, RR_totalCPUBurstTime, *RR_arrivalTime, *RR_CPUBurstTime, *RR_CPUBurstTimeCopy, *RR_processNumber, RR_minimumArrivalTime, *RR_processSequenceForEachSecond, *RR_waitingTime, RR_timeQuantum;
int RR_s[999], RR_e[999], RR_completionTime[999];
float RR_averageWaitingTime=0, RR_averageTurnAroundTime=0, RR_averageResponseTime=0, RR_fin_averageWaitingTime=0;
float RR_responseTime[999], RR_preaverageWaitingTime[999], RR_preaverageTurnAroundTime[999];
/*arrays used to draw Gantt Chart*/
int *RR_processNumberGantt, *RR_CPUBurstTimeGantt, RR_ganttSize;

///IO BURST ALGORITHMS
int proc_size, num,res;
char p[MAX][MAX];
int at[MAX], bt[MAX], io[MAX], bt2[MAX], s[MAX], e[MAX], prio[MAX], wt[MAX], rt[MAX], tat[MAX], tq;
int tempat[MAX], tempbt[MAX], tempbt2[MAX];
int sched[MAX];
int sched_count;
int time2, count, i, j, k, x, y, max_end, cpu_time[MAX];
char r_sched[MAX][MAX];
char temp_r_sched[MAX][MAX];
float r_rt[MAX], r_wt[MAX], r_tat[MAX];

///COMPARISON
float *first_RT_variable=0, *second_RT_variable=0, *first_WT_variable=0, *second_WT_variable=0, *first_TAT_variable=0, *second_TAT_variable=0;

int main()
{
    system("cls");
    printf("\n\n");
    printf("         O -----------------------------                              O                     \n");
    printf("                 O -------------------- \\                            /                     \n");
    printf("                                       \\ \\                          /                     \n");
    printf("                   +------------------------------------+    ------                         \n");
    printf("    O              |           CPU SCHEDULING           |---/ ------------ O                \n");
    printf("     \\             |------------------------------------|----/                             \n");
    printf("      -----------  |       VILLA, JULIUS ANTHONY A.     |    ---- O                         \n");
    printf("                   |                                    |--------                           \n");
    printf("                   |              BSIT - 2A             |------  \\                         \n");
    printf("                   +------------------------------------+      \\ -------- O                \n");
    printf("               O -------------/  O ---    /     \\   O   \\      ------- O                  \n");
    printf("                                         /       \\       --------- O                       \n");
    printf("                O ----------------\\     /        ---------- O                              \n");
    printf("                            O ----------                                                    \n");
    printf("          O -----------------------/                                                        \n\n\n");
    printf("                               Loading . . . ");
    delay(1);
    system("cls");

    do{
        printf("\n");
        printf("                            +-----------------------+       \n");
        printf("                       +----|      - M E N U -      |----+  \n");
        printf("                       |    +-----------------------+    |  \n");
        printf("                       |                                 |  \n");
        printf("   +--------------------------------------------------------------------------+\n");
        printf("   |                                                                          |\n");
        printf("   |             [1]          Create a table with Gantt Chart                 |\n");
        printf("   |             [2]          Compare Two Scheduling Algorithms               |\n");
        printf("   |             [3]          Exit the program                                |\n");
        printf("   |                                                                          |\n");
        printf("   |    +----------------------------------------------------------------+    |\n");
        printf("   +---||              ENTER THE NUMBER THAT YOU WANT TO RUN             ||---+\n");
        printf("        +----------------------------------------------------------------+     \n");
        printf("                                    CHOICE : ");
        scanf("%d",&mainmenu);

        switch(mainmenu){

            case 1:
                do{
                    system("cls");
                    printf("                            +-----------------------+       \n");
                    printf("                       +----|      - M E N U -      |----+  \n");
                    printf("                       |    +-----------------------+    |  \n");
                    printf("                       |                                 |  \n");
                    printf("   +--------------------------------------------------------------------------+\n");
                    printf("   |                                                                          |\n");
                    printf("   |             [1]          Create a table with Gantt Chart                 |\n");
                    printf("   |                                                                          |\n");
                    printf("   |    +----------------------------------------------------------------+    |\n");
                    printf("   +---||              ENTER THE NUMBER THAT YOU WANT TO RUN             ||---+\n");
                    printf("        +----------------------------------------------------------------+     \n");
                    printf("                                    CHOICE : 1 \n\n");
                    printf("                                    |        |                                 \n");
                    printf("   +--------------------------------------------------------------------------+\n");
                    printf("   |                                                                          |\n");
                    printf("   |           [1]           First Come, First Serve (FCFS)                   |\n");
                    printf("   |           [2]           First Come, First Serve w/ IO Burst (FCFS[IO])   |\n");
                    printf("   |           [3]           Shortest Job First (SJF)                         |\n");
                    printf("   |           [4]           Shortest Job First w/ IO Burst (SJF[IO])         |\n");
                    printf("   |           [5]           Shortest Remaining Time First (SRTF)             |\n");
                    printf("   |           [6]           Non-Preemptive Priority (NPP)                    |\n");
                    printf("   |           [7]           Non-Preemptive Priority w/ IO Burst (NPP[IO])    |\n");
                    printf("   |           [8]           Preemptive Priority (PP)                         |\n");
                    printf("   |           [9]           Round Robin (RR)                                 |\n");
                    printf("   |                                                                          |\n");
                    printf("   |           [0]           Return to Main Menu                              |\n");
                    printf("   |                                                                          |\n");
                    printf("   |    +----------------------------------------------------------------+    |\n");
                    printf("   +-||  ENTER THE NUMBER OF THE CPU SCHEDULING ALGORITHM YOU WANT TO USE  ||-+\n");
                    printf("        +----------------------------------------------------------------+     \n");
                    printf("                                    CHOICE : ");
                    scanf("%d",&firstmenu);
                    switch(firstmenu){
                        case 1:
                            system("cls");
                            FCFS_Scheduling();
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            FCFSIO_Scheduling();
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            SJF_Scheduling();
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            SJFIO_Scheduling();
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            SRTF_Scheduling();
                            system("pause");
                            break;
                        case 6:
                            system("cls");
                            NPP_Scheduling();
                            system("pause");
                            break;
                        case 7:
                            system("cls");
                            NPP_Scheduling();
                            system("pause");
                            break;
                        case 8:
                            system("cls");
                            PP_Scheduling();
                            system("pause");
                            break;
                        case 9:
                            system("cls");
                            RR_Scheduling();
                            system("pause");
                            break;
                        case 0:
                            main();
                            break;
                        default:
                            printf("Incorrect number. Please try again.");
                            break;
                        }
                    }while (firstmenu != 7);

                case 2:
                    system("cls");
                    printf("                            +-----------------------+       \n");
                    printf("                       +----|      - M E N U -      |----+  \n");
                    printf("                       |    +-----------------------+    |  \n");
                    printf("                       |                                 |  \n");
                    printf("   +--------------------------------------------------------------------------+\n");
                    printf("   |                                                                          |\n");
                    printf("   |             [2]        Compare Two Scheduling Algorithms                 |\n");
                    printf("   |                                                                          |\n");
                    printf("   |    +----------------------------------------------------------------+    |\n");
                    printf("   +---||              ENTER THE NUMBER THAT YOU WANT TO RUN             ||---+\n");
                    printf("        +----------------------------------------------------------------+     \n");
                    printf("                                    CHOICE : 2 \n\n");
                    printf("                                    |        |                                 \n");
                    printf("   +--------------------------------------------------------------------------+\n");
                    printf("   |                                                                          |\n");
                    printf("   |           [1]           First Come, First Serve (FCFS)                   |\n");
                    printf("   |           [2]           First Come, First Serve w/ IO Burst (FCFS[IO])   |\n");
                    printf("   |           [3]           Shortest Job First (SJF)                         |\n");
                    printf("   |           [4]           Shortest Job First w/ IO Burst (SJF[IO])         |\n");
                    printf("   |           [5]           Shortest Remaining Time First (SRTF)             |\n");
                    printf("   |           [6]           Non-Preemptive Priority (NPP)                    |\n");
                    printf("   |           [7]           Non-Preemptive Priority w/ IO Burst (NPP[IO])    |\n");
                    printf("   |           [8]           Preemptive Priority (PP)                         |\n");
                    printf("   |           [9]           Round Robin (RR)                                 |\n");
                    printf("   |                                                                          |\n");
                    printf("   |           [0]           Return to Main Menu                              |\n");
                    printf("   |                                                                          |\n");
                    printf("   |    +----------------------------------------------------------------+    |\n");
                    printf("   +---||  ENTER THE NUMBER OF CPU SCHEDULING ALGORITHM YOU WANT TO USE  ||---+\n");
                    printf("        +----------------------------------------------------------------+     \n");
                    printf("                            -  FIRST ALGORITHM : ");
                    scanf("%d", &sndmenufirst);
                    if(sndmenufirst > 6){
                        printf("Incorrect number. Please try again.\n\n");
                        system("pause");
                        system("cls");
                        fflush(stdin);
                        break;
                    }
                    printf("                            -  SECOND ALGORITHM : ");
                    scanf("%d", &sndmenusecond);
                    if(sndmenufirst && sndmenusecond < 7)
                    {
                        switch(sndmenufirst){
                            case 1:
                                system("cls");
                                fflush(stdin);
                                FCFS_Scheduling();
                                first_WT_variable = &FCFS_fin_ave_wt;
                                first_RT_variable = &FCFS_fin_ave_rt;
                                first_TAT_variable = &FCFS_fin_ave_tat;
                                printf("\n\n");
                                break;
                            case 2:
                                system("cls");
                                fflush(stdin);
                                FCFSIO_Scheduling();
                                first_WT_variable = &FCFSIO_fin_ave_wt;
                                first_RT_variable = &FCFSIO_fin_ave_rt;
                                first_TAT_variable = &FCFSIO_fin_ave_tat;
                                printf("\n\n");
                                break;
                            case 3:
                                system("cls");
                                fflush(stdin);
                                SJF_Scheduling();
                                first_WT_variable = &SJF_fin_wt_ave;
                                first_RT_variable = &SJF_fin_rt_ave;
                                first_TAT_variable = &SJF_fin_tat_ave;
                                printf("\n\n");
                                break;
                            case 4:
                                system("cls");
                                fflush(stdin);
                                SJFIO_Scheduling();
                                first_WT_variable = &SJFIO_fin_wt_ave;
                                first_RT_variable = &SJFIO_fin_rt_ave;
                                first_TAT_variable = &SJFIO_fin_tat_ave;
                                printf("\n\n");
                                break;
                            case 5:
                                system("cls");
                                fflush(stdin);
                                SRTF_Scheduling();
                                first_WT_variable = &SRTF_fin_averageWaitingTime;
                                first_RT_variable = &SRTF_fin_averageWaitingTime;
                                first_TAT_variable = &SRTF_fin_averageTurnAroundTime;
                                printf("\n\n");
                                break;
                            case 6:
                                system("cls");
                                fflush(stdin);
                                NPP_Scheduling();
                                first_WT_variable = &NPP_wt;
                                first_RT_variable = &NPP_rt;
                                first_TAT_variable = &NPP_tat;
                                printf("\n\n");
                                break;
                            case 7:
                                system("cls");
                                fflush(stdin);
                                NPPIO_Scheduling();
                                first_WT_variable = &NPPIO_wt;
                                first_RT_variable = &NPPIO_rt;
                                first_TAT_variable = &NPPIO_tat;
                                printf("\n\n");
                                break;
                            case 8:
                                system("cls");
                                fflush(stdin);
                                PP_Scheduling();
                                first_WT_variable = &PP_fin_averageWaitingTime;
                                first_RT_variable = &PP_fin_averageWaitingTime;
                                first_TAT_variable = &PP_fin_averageTurnAroundTime;
                                printf("\n\n");
                                break;
                            case 9:
                                system("cls");
                                fflush(stdin);
                                RR_Scheduling();
                                first_WT_variable = &RR_fin_averageWaitingTime;
                                first_RT_variable = &RR_averageResponseTime;
                                first_TAT_variable = &RR_averageTurnAroundTime;
                                printf("\n\n");
                                break;
                            case 0:
                                main();
                                break;
                            default:
                                printf("Incorrect number. Please try again.\n\n");
                                system("pause");
                                break;
                            }
                        switch(sndmenusecond){
                            case 1:
                                fflush(stdin);
                                FCFS_Scheduling();
                                second_WT_variable = &FCFS_fin_ave_wt;
                                second_RT_variable = &FCFS_fin_ave_rt;
                                second_TAT_variable = &FCFS_fin_ave_tat;
                                //fflush(stdin);
                                comparison();
                                print_comparison();
                                break;
                            case 2:
                                fflush(stdin);
                                SJF_Scheduling();
                                second_WT_variable = &SJF_fin_wt_ave;
                                second_RT_variable = &SJF_fin_rt_ave;
                                second_TAT_variable = &SJF_fin_tat_ave;
                                //fflush(stdin);
                                comparison();
                                print_comparison();
                                break;
                            case 3:
                                fflush(stdin);
                                SRTF_Scheduling();
                                second_WT_variable = &SRTF_fin_averageWaitingTime;
                                second_RT_variable = &SRTF_fin_averageWaitingTime;
                                second_TAT_variable = &SRTF_fin_averageTurnAroundTime;
                                //fflush(stdin);
                                comparison();
                                print_comparison();
                                break;
                            case 4:
                                fflush(stdin);
                                NPP_Scheduling();
                                second_WT_variable = &NPP_wt;
                                second_RT_variable = &NPP_rt;
                                second_TAT_variable = &NPP_tat;
                                //fflush(stdin);
                                comparison();
                                print_comparison();
                                break;
                            case 5:
                                fflush(stdin);
                                PP_Scheduling();
                                second_WT_variable = &PP_fin_averageWaitingTime;
                                second_RT_variable = &PP_fin_averageWaitingTime;
                                second_TAT_variable = &PP_fin_averageTurnAroundTime;
                                //fflush(stdin);
                                comparison();
                                print_comparison();
                                break;
                            case 6:
                                fflush(stdin);
                                RR_Scheduling();
                                second_WT_variable = &RR_fin_averageWaitingTime;
                                second_RT_variable = &RR_averageResponseTime;
                                second_TAT_variable = &RR_averageTurnAroundTime;
                                //fflush(stdin);
                                comparison();
                                print_comparison();
                                break;
                            case 0:
                                main();
                                break;
                            default:
                                printf("Incorrect number. Please try again.\n\n");
                                system("pause");
                                break;
                        }
                    }
                    else{
                        printf("Incorrect number. Please try again.\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    system("cls");
                    break;
                case 3:
                    exit(1);
                    break;
            }

        }while (mainmenu != 4);

    return 0;
}

///FIRST COME FIRST SERVE SCHEDULING
void FCFS_Scheduling()
{
    printf("OPERATING SYSTEMS: FIRST COME FIRST SERVE\n\n");
    printf("DIRECTION: ENTER WHAT IS ASKED.\n");
    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &FCFS_num_proc);
    printf("\nENTER THE ARRIVAL TIME OF THE FOLLOWING:\n");

    for(i=0; i<FCFS_num_proc; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d", &FCFS_arrival[i]);
    }

    printf("\nENTER THE CPU BURST TIME OF THE FOLLOWING:\n");
    for(j=0; j<FCFS_num_proc; j++)
    {
        printf("P%d: ", j+1);
        scanf("%d", &FCFS_cpu_burst[j]);
    }

    printf("\n");
    for(i=0; i<FCFS_num_proc; i++)
    {
        if(FCFS_arrival[i]<FCFS_e[i-1])
        {
            FCFS_s[i]=FCFS_e[i-1];
        }
        else
        {
            FCFS_s[i]=FCFS_arrival[i];
        }

        FCFS_e[i]=FCFS_s[i]+FCFS_cpu_burst[i];
    }

    for(i=0; i<FCFS_num_proc; i++)
    {
        FCFS_wait_time[i]=FCFS_s[i]-FCFS_arrival[i];
        FCFS_response_time[i]=FCFS_s[i]-FCFS_arrival[i];
        FCFS_ta_time[i]=FCFS_e[i]-FCFS_arrival[i];

        FCFS_ave_wt += FCFS_wait_time[i];
        FCFS_ave_rt += FCFS_response_time[i];
        FCFS_ave_tat += FCFS_ta_time[i];
    }

    printf("\tARRIVAL TIME\tCPU B.T.\tSTART TIME\tEND TIME\tWAITING TIME\tRESPONSE TIME\tTURNAROUND TIME\n");
    for(i=0; i<FCFS_num_proc; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, FCFS_arrival[i], FCFS_cpu_burst[i], FCFS_s[i], FCFS_e[i], FCFS_wait_time[i], FCFS_response_time[i], FCFS_ta_time[i]);
    }
    FCFS_fin_ave_wt = FCFS_ave_wt/FCFS_num_proc;
    FCFS_fin_ave_rt = FCFS_ave_rt/FCFS_num_proc;
    FCFS_fin_ave_tat = FCFS_ave_tat/FCFS_num_proc;
    printf("\t\t\t\t\t\t\t\t\tAVE: %.2f\tAVE: %.2f\tAVE: %.2f\n\n", FCFS_fin_ave_wt, FCFS_fin_ave_rt, FCFS_fin_ave_tat);

    printf("GANTT CHART\n");
    printf("  ");
    for(i=0; i<FCFS_num_proc; i++)   //start line
    {
        for(j=0; j<FCFS_cpu_burst[i]; j++)
        {
            printf("--");
        }
    }
    printf("\n|");

    for(i=0; i<FCFS_num_proc; i++)   //process
    {
        for(j=0; j<FCFS_cpu_burst[i]-1; j++)
        {
            printf(" ");
        }
        if(i+1==1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        }

        else if(i+1==2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        }

        else if(i+1==3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        }

        else if(i+1==4)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        }

        else if(i+1==5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        }
        else if(i+1==6)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        }
        else if(i+1==7)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        printf("P%d", i+1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        for(j=0; j<FCFS_cpu_burst[i]-1; j++)
        {
            printf(" ");
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("|");
    }
    printf("\n");
    printf("  ");
    for(i=0; i<FCFS_num_proc; i++)   //end line
    {
        for(j=0; j<FCFS_cpu_burst[i]; j++)
        {
            printf("--");
        }
    }

    printf("\n 0");
    for(i=0; i<FCFS_num_proc; i++)
    {
        for(j=0; j<FCFS_cpu_burst[i]; j++)
        {
            printf("  ");
        }
        if(FCFS_ta_time > 9)
        {
            printf("\b");
        }
        printf("%d", FCFS_e[i]);
    }

    printf("\n");
    for(i=0; i<FCFS_num_proc; i++)
    {
        for(j=0; j<FCFS_s[i]; j++)
        {
            printf(" ");
        }
        if(FCFS_ta_time > 9)
        {
            printf("\b");
        }
    }
}

///FIRST COME FIRST SERVE IO BURST
void FCFSIO_Scheduling()
{
    printf("\n\n\t\t***********************************\n\n");
    printf("\n\n\tFIRST COME FIRST SERVE with IO SCHEDULING ALGORITHM\n\n");

    int gant_count = 0, gant_time[MAX], smallest = 9;
    char gant_p[MAX][MAX];
    float aveWT = 0, aveRT = 0, aveTAT = 0;
    time2 = 0;
    count = 0;
    at[smallest] = 999;

    while(count < proc_size){
        smallest = 9;
        for(i=0; i < proc_size; i++){
            if((at[i] < at[smallest]) && bt2[i] > 0){
                smallest = i;
            }
        }

        if(bt[smallest] > 0){
            s[smallest] = time2;
            gant_time[gant_count] = time2;
            strcpy(gant_p[gant_count], p[smallest]);
            time2 += bt[smallest];
            at[smallest] = time2 + io[smallest];
            bt[smallest] = 0;
        } else if(bt[smallest] == 0){
            gant_time[gant_count] = time2;
            strcpy(gant_p[gant_count], p[smallest]);
            time2 += bt2[smallest];
            e[smallest] = time2;
            max_end = time2;
            bt2[smallest] = 0;
            count++;
            rt[smallest] = s[smallest] - tempat[smallest];
            tat[smallest] = e[smallest] - tempat[smallest];
            wt[smallest] = tat[smallest] - cpu_time[smallest];
        }
        gant_count++;
    }

    for(i = 0; i < proc_size; i++){
        aveWT += (float)wt[i]/(float)proc_size;
        aveRT += (float)rt[i]/(float)proc_size;
        aveTAT += (float)tat[i]/(float)proc_size;
    }

        printf("\n  PROCESS \t AT \t CPU,IO,CPU \t Start \t End \t RT \t WT \t TAT \n");
    for(i = 0; i < proc_size; i++){
        printf("\n  %s \t\t %d \t %d,%d,%d \t\t %d \t %d \t %d \t %d \t %d", p[i], tempat[i], tempbt[i], io[i], tempbt2[i], s[i], e[i], rt[i], wt[i], tat[i]);
    }
    printf("\n---------------------------------------------------------------------");
    printf("\n \t\t\t\t\t    AVERAGE :\t %.2f \t %.2f \t %.2f\n\n", aveRT, aveWT, aveTAT);

    r_rt[y] = aveRT;
    r_wt[y] = aveWT;
    r_tat[y++] = aveTAT;

    ///GANCHART
    printf("\n\n  LEGEND: \n");
    for(i = 0; i < proc_size; i++){
        printf("\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i+2) * 16);

        printf(" %s ", p[i]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n");

    }

        printf("\n\n\t\t\tGANTT CHART\n\n");

    printf("\n");
    for(i = 0; i < gant_count; i++){
        for(j = 0; j < proc_size; j++){
            if(strcmp(gant_p[i], p[j])==0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (j+2) * 16);
            }
        }
        printf("%d %s     ", gant_time[i], gant_p[i]);
    }
    printf("%d ", max_end);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

///SHORTEST JOB FIRST
void SJF_Scheduling()
{
int temp = 0, tempe = 0, tempt = 0, p[999], check[999];
    printf("SHORTEST JOB FIRST\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &SJF_numproc);
    for(int i=0; i<SJF_numproc; i++){
        printf("\nEnter the Arrival Time of P%d: ",i+1);
        scanf("%d", &SJF_at[i]);
        printf("Enter the CPU Burst of P%d: ", i+1);
        scanf("%d",& SJF_cpubt[i]);
        p[i]=i+1;
    }

    for(int i=0; i<SJF_numproc; i++){
        for(int j=i+1; j<SJF_numproc; j++){
            if(SJF_at[i] >= SJF_at[j]){
                tempe = SJF_at[i];
                SJF_at[i] = SJF_at[j];
                SJF_at[j] = tempe;
                tempt = SJF_cpubt[i];
                SJF_cpubt[i] = SJF_cpubt[j];
                SJF_cpubt[j] = tempt;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int temptemp = SJF_at[0];
    for(int i=0; i<SJF_numproc; i++){
        if(check[i])
            continue;
        for(int j=i+1; j<SJF_numproc; j++){
            if(SJF_at[j] <= temptemp && SJF_cpubt[j] <= SJF_cpubt[i]){
                tempe = SJF_at[i];
                SJF_at[i] = SJF_at[j];
                SJF_at[j] = tempe;
                tempt = SJF_cpubt[i];
                SJF_cpubt[i] = SJF_cpubt[j];
                SJF_cpubt[j] = tempt;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                check[i] = 1;
            }
        }
        temptemp += SJF_cpubt[i];
    }

    SJF_s[0] = SJF_at[0];
    SJF_e[0] = SJF_cpubt[0]+SJF_s[0];
    for(int i=1; i<SJF_numproc; i++){
        if(SJF_at[i] > SJF_e[i-1]){
            SJF_s[i] = SJF_at[i];
            SJF_e[i] = SJF_cpubt[i] + SJF_s[i];
        }
        else{
            SJF_s[i] = SJF_e[i-1];
            SJF_e[i] = SJF_cpubt[i]+SJF_s[i];
        }
    }
    printf("\n");
    for(int i=0; i<SJF_numproc; i++){
        SJF_wt[i] = SJF_s[i] - SJF_at[i];
        SJF_rt[i] = SJF_wt[i];
        SJF_tat[i] = SJF_e[i] - SJF_at[i];

        SJF_wt_ave += SJF_wt[i];
        SJF_rt_ave += SJF_rt[i];
        SJF_tat_ave += SJF_tat[i];
    }

    printf("Process\t\tAT\tBT\tS\tE\tWT\t\tRT\t\tTAT\n");
    for(int i=0; i<SJF_numproc; i++){
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i], SJF_at[i], SJF_cpubt[i], SJF_s[i], SJF_e[i], SJF_wt[i], SJF_rt[i], SJF_tat[i]);
    }

    SJF_fin_wt_ave = SJF_wt_ave/SJF_numproc;
    SJF_fin_rt_ave = SJF_rt_ave/SJF_numproc;
    SJF_fin_tat_ave = SJF_tat_ave/SJF_numproc;

    printf("\n\t\t\t\t\t\tAVE: %.2f\tAVE: %.2f\tAVE: %.2f\n\n", SJF_fin_wt_ave, SJF_fin_rt_ave, SJF_fin_tat_ave);

    printf("GANTT CHART\n");
    printf("  ");
    for(int i=0; i<SJF_numproc; i++)   //start line
    {
        for(int j=0; j<SJF_cpubt[i]; j++)
        {
            printf("--");
        }
    }
    printf("\n|");

    for(int i=0; i<SJF_numproc; i++){ //process
        for(int j=0; j<SJF_e[i]-SJF_s[i]; j++){
            printf(" ");
            if(j == (SJF_e[i]-SJF_s[i]-1)){
                if(p[i]==1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                }
                else if(p[i]==2)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                }
                else if(p[i]==3)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                }
                else if(p[i]==4)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                }
                else if(p[i]==5)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                printf("P%d",p[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
        }
        printf("|");
    }
    printf("\n  ");

    for(int i=0; i<SJF_numproc; i++)   //end line
    {
        for(int j=0; j<SJF_cpubt[i]; j++)
        {
            printf("--");
        }
    }
    printf("\n");

    temp=SJF_s[0];
    for(int i=0; i<SJF_numproc; i++){
        printf("%d", temp);
        for(int j=0; j<SJF_e[i]-SJF_s[i]+1; j++){
            printf(" ");
        }
        temp = SJF_e[i];
    }
    printf("%d",temp);
    printf("\n");
    int temm = 0;
    return 0;
}

///SHORTEST JOB FIRST IO BURST
void SJFIO_Scheduling()
{
    printf("\n\n\t\t***********************************\n\n");
    printf("\n\n\tSHORTEST JOB FIRST with IO SCHEDULING ALGORITHM\n\n");
    float aveWT = 0, aveRT = 0, aveTAT = 0;
    int gant_count = 0, gant_time[MAX], smallest = 9, smallest2 = 9;
    char gant_p[MAX][MAX];
    time2 = 0;
    count = 0;

    time2 = 0;
    bt[smallest] = 999;
    bt2[smallest2] = 999;
    while(count < proc_size){
        smallest = 9;
        smallest2 = 9;
        for(i=0; i < proc_size; i++){
            if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0 && bt2[smallest] > 0){
                smallest = i;
            }
        }

        for(i=0; i < proc_size; i++){
            if(at[i] <= time && bt2[i] < bt2[smallest2] && bt2[i] > 0){
                smallest2 = i;
            }
        }

        if(bt2[smallest2] < bt[smallest]){
            smallest = smallest2;
        }

        if(bt[smallest] == bt2[smallest2]){
            if(smallest2 < smallest){
                smallest = smallest2;
            }
        }

        if(bt[smallest] > 0){
            s[smallest] = time;
            gant_time[gant_count] = time;
            strcpy(gant_p[gant_count], p[smallest]);
            time += bt[smallest];
            at[smallest] = time + io[smallest];
            bt[smallest] = 0;
        } else if(bt[smallest] == 0){
            gant_time[gant_count] = time;
            strcpy(gant_p[gant_count], p[smallest]);
            time += bt2[smallest];
            e[smallest] = time;
            max_end = time;
            bt2[smallest] = 0;
            count++;
            rt[smallest] = s[smallest] - tempat[smallest];
            tat[smallest] = e[smallest] - tempat[smallest];
            wt[smallest] = tat[smallest] - cpu_time[smallest];
        }
        gant_count++;
    }

    for(i = 0; i < proc_size; i++){
        aveWT += (float)wt[i]/(float)proc_size;
        aveRT += (float)rt[i]/(float)proc_size;
        aveTAT += (float)tat[i]/(float)proc_size;
    }

        printf("\n  PROCESS \t AT \t CPU,IO,CPU \t Start \t End \t RT \t WT \t TAT \n");
    for(i = 0; i < proc_size; i++){
        printf("\n  %s \t\t %d \t %d,%d,%d \t\t %d \t %d \t %d \t %d \t %d", p[i], tempat[i], tempbt[i], io[i], tempbt2[i], s[i], e[i], rt[i], wt[i], tat[i]);
    }
    printf("\n---------------------------------------------------------------------");
    printf("\n \t\t\t\t\t    AVERAGE :\t %.2f \t %.2f \t %.2f\n\n", aveRT, aveWT, aveTAT);

    r_rt[y] = aveRT;
    r_wt[y] = aveWT;
    r_tat[y++] = aveTAT;

///GANCHART

    printf("\n\n  LEGEND: \n");
    for(i = 0; i < proc_size; i++){
        printf("\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i+2) * 16);

        printf(" %s ", p[i]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n");

    }

        printf("\n\n\t\t\tGANTT CHART\n\n");

    printf("\n");
    for(i = 0; i < gant_count; i++){
        for(j = 0; j < proc_size; j++){
            if(strcmp(gant_p[i], p[j])==0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (j+2) * 16);
            }
        }
        printf("%d %s     ", gant_time[i], gant_p[i]);
    }
    printf("%d ", max_end);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

///SHORTEST REMAINING TIME FIRST
void SRTF_Scheduling()
{
    int i,j,temp;
    printf("SHORTEST REMAINING TIME FIRST\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &SRTF_numberOfProcesses);
    SRTF_arrivalTime=(int*)malloc(sizeof(int)*SRTF_numberOfProcesses);
    SRTF_CPUBurstTime=(int*)malloc(sizeof(int)*SRTF_numberOfProcesses);
    SRTF_CPUBurstTimeCopy=(int*)malloc(sizeof(int)*SRTF_numberOfProcesses);
    SRTF_processNumber=(int*)malloc(sizeof(int)*SRTF_numberOfProcesses);
    SRTF_waitingTime=(int*)malloc(sizeof(int)*SRTF_numberOfProcesses);

    SRTF_minimumArrivalTime=2147483647;

    for(i=0;i<SRTF_numberOfProcesses;i++)
    {
                    SRTF_waitingTime[i]=0;
                    SRTF_processNumber[i]=i;
                    printf("\nEnter the data for process number : %d\n",i+1);
                    printf("\tArrival Time   : ");
                    scanf("%d",&SRTF_arrivalTime[i]);
                    printf("\tCPU Burst time : ");
                    scanf("%d",&SRTF_CPUBurstTime[i]);
                    SRTF_CPUBurstTimeCopy[i]=SRTF_CPUBurstTime[i];
                    SRTF_totalCPUBurstTime+=SRTF_CPUBurstTime[i];
                    if(SRTF_minimumArrivalTime>SRTF_arrivalTime[i])
                        SRTF_minimumArrivalTime=SRTF_arrivalTime[i];
    }
    SRTF_processSequenceForEachSecond=(int*)malloc(sizeof(int)*SRTF_totalCPUBurstTime);

    /* this function calculates the process sequence for each second. */
    SRTF_calculateProcessSequence();

    for(i=0; i<SRTF_numberOfProcesses; i++)
    {
        SRTF_s[0] = SRTF_arrivalTime[0];
        SRTF_completionTime[i]=SRTF_arrivalTime[i]+(SRTF_waitingTime[i]+SRTF_CPUBurstTimeCopy[i]);
        SRTF_s[i]=SRTF_completionTime[i]-SRTF_CPUBurstTimeCopy[i];
        SRTF_preaverageTurnAroundTime[i] = SRTF_waitingTime[i]+SRTF_CPUBurstTimeCopy[i];
        SRTF_preaverageWaitingTime[i] = (SRTF_waitingTime[i]+SRTF_CPUBurstTimeCopy[i])-SRTF_CPUBurstTimeCopy[i];
        SRTF_responseTime[i] = SRTF_preaverageTurnAroundTime[i]-SRTF_CPUBurstTimeCopy[i];
        SRTF_averageResponseTime+=SRTF_responseTime[i];
    }
    SRTF_fin_averageWaitingTime=SRTF_averageWaitingTime/(float)SRTF_numberOfProcesses;
    SRTF_fin_averageTurnAroundTime=SRTF_averageTurnAroundTime/(float)SRTF_numberOfProcesses;
    ///print
    printf("\nProcess\t\tAT\tCPUBT\tS\tE\tWT\t\tRT\t\tTAT\n");
    for(i=0;i<SRTF_numberOfProcesses;i++)
    {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%.2f\t\t%.2f\t\t%.2f", i+1, SRTF_arrivalTime[i], SRTF_CPUBurstTimeCopy[i], SRTF_s[i], SRTF_completionTime[i], SRTF_responseTime[i], SRTF_preaverageWaitingTime[i], SRTF_preaverageTurnAroundTime[i]);
        printf("\n");
    }
    printf("\n\t\t\t\t\t\tAVE:%.2f\tAVE:%.2f\tAVE:%.2f\n\n", SRTF_fin_averageWaitingTime, SRTF_fin_averageWaitingTime, SRTF_fin_averageTurnAroundTime);

    SRTF_drawGanttChart();
}
void SRTF_calculateProcessSequence()
{
    int i,j,pNumber,prevProcess,tempCPUBurstTime,counter,prevProcesss;
    for(i=SRTF_minimumArrivalTime;i<SRTF_totalCPUBurstTime + SRTF_minimumArrivalTime;i++)
    {
                    pNumber=SRTF_findAptProcessNumber(i);
                    SRTF_processSequenceForEachSecond[i-SRTF_minimumArrivalTime]=pNumber;
                    SRTF_CPUBurstTime[pNumber]--;
                    /*
                                    claculating the waiting time of each process;
                    */
                    for(j=0;j<SRTF_numberOfProcesses;j++)
                                    if(SRTF_CPUBurstTime[j]!=0 && SRTF_arrivalTime[j]<=i && j!=pNumber)
                                                    SRTF_waitingTime[j]++;
    }

    /* claculating the size of gantt chart arrays*/
    SRTF_ganttSize=1;
    prevProcess=SRTF_processSequenceForEachSecond[0];
    for(i=0;i<SRTF_totalCPUBurstTime;i++)
    {
                    if(prevProcess!=SRTF_processSequenceForEachSecond[i])
                                    SRTF_ganttSize++;
                    prevProcess=SRTF_processSequenceForEachSecond[i];
    }

    /* allocating the size of gantt chart arrays */
    SRTF_processNumberGantt=(int*)malloc(sizeof(int)*SRTF_ganttSize);
    SRTF_CPUBurstTimeGantt=(int*)malloc(sizeof(int)*SRTF_ganttSize);

    /* assigning the values to Gantt Chart Arrays */
    prevProcess=SRTF_processSequenceForEachSecond[0];
    tempCPUBurstTime=0;
    counter=0;
    for(i=0;i<SRTF_totalCPUBurstTime;i++)
    {
                    if(prevProcess!=SRTF_processSequenceForEachSecond[i])
                    {
                                    SRTF_processNumberGantt[counter]=prevProcess;
                                    SRTF_CPUBurstTimeGantt[counter]=tempCPUBurstTime;
                                    counter++;
                                    tempCPUBurstTime=0;
                    }
                    tempCPUBurstTime++;
                    prevProcess=SRTF_processSequenceForEachSecond[i];
    }
    SRTF_CPUBurstTimeGantt[SRTF_ganttSize-1]=tempCPUBurstTime;
    SRTF_processNumberGantt[SRTF_ganttSize-1]=prevProcess;

    /* calculating the averageWaitingTime and averageTurnAroundTime */
    SRTF_averageWaitingTime=0;
    SRTF_averageTurnAroundTime=0;
    for(i=0;i<SRTF_numberOfProcesses;i++)
    {
        SRTF_averageWaitingTime+=SRTF_waitingTime[i];
        SRTF_averageTurnAroundTime+=SRTF_waitingTime[i]+SRTF_CPUBurstTimeCopy[i];
    }
}

int SRTF_findAptProcessNumber(int currentTime)
{
    int i,min=2147483647,pNumber;
    for(i=0;i<SRTF_numberOfProcesses;i++)
                    if(SRTF_arrivalTime[i]<=currentTime && min>SRTF_CPUBurstTime[i] && SRTF_CPUBurstTime[i]!=0)
                    {
                                    min=SRTF_CPUBurstTime[i];
                                    pNumber=i;
                    }
    return pNumber;
}
void SRTF_drawGanttChart()
{
    const int maxWidth=100;
    int scalingFactor,i,counter,tempi,currentTime;
    printf("GANTT CHART: \n\n");

    scalingFactor=maxWidth/SRTF_totalCPUBurstTime;
    for(i=0;i<scalingFactor*SRTF_totalCPUBurstTime+2+SRTF_ganttSize;i++)
                    printf("-");
    printf("\n|");
    counter=0,tempi=0;
    for(i=0; i<scalingFactor*SRTF_totalCPUBurstTime; i++)
                    if(i==SRTF_CPUBurstTimeGantt[counter]*scalingFactor+tempi)
                    {
                                    counter++;
                                    tempi=i;
                                    printf("|");
                    }
                    else if(i==(SRTF_CPUBurstTimeGantt[counter]*scalingFactor)/2+tempi){
                        if(SRTF_processNumberGantt[counter]+1==1)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        }
                        else if(SRTF_processNumberGantt[counter]+1==2)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                        }
                        else if(SRTF_processNumberGantt[counter]+1==3)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                        }
                        else if(SRTF_processNumberGantt[counter]+1==4)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        }
                        else if(SRTF_processNumberGantt[counter]+1==5)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                        }
                        else if(SRTF_processNumberGantt[counter]+1==6)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                        }
                        else if(SRTF_processNumberGantt[counter]+1==7)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                        }
                        else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        printf("P%d",SRTF_processNumberGantt[counter]+1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    else
                                    printf(" ");
    printf("|");
    printf("\n");
    for(i=0;i<scalingFactor*SRTF_totalCPUBurstTime+2+SRTF_ganttSize;i++)
                    printf("-");
    printf("\n");

    /* printing the time labels of the gantt chart */
    counter=0;
    tempi=0;
    currentTime=SRTF_minimumArrivalTime;
    printf("%d",currentTime);
    for(i=0;i<scalingFactor*SRTF_totalCPUBurstTime;i++)
                    if(i==SRTF_CPUBurstTimeGantt[counter]*scalingFactor+tempi)
                    {
                                    tempi=i;
                                    currentTime+=SRTF_CPUBurstTimeGantt[counter];
                                    SRTF_averageWaitingTime+=currentTime;
                                    counter++;
                                    printf("%2d",currentTime);
                    }
                    else
                    {
                                    printf(" ");
                    }
    currentTime+=SRTF_CPUBurstTimeGantt[counter];
    printf("%2d\n\n",currentTime);
}

///NON-PREEMPTIVE PRIORITY
void NPP_Scheduling()
{
    int n,i,j,k,cnt,icnt,temp,lowest,arrive,chk;
    //float NPP_wt = 0, NPP_rt = 0, NPP_tat = 0;
    printf("OPERATING SYSTEMS NON-PREEMPTIVE PRIORITY\n");
    printf("\n Enter the number or processes: ");
    scanf(" %d", &n);

    int given[n][3];
    int arrived[n][3];
    int dupl[n][10];
    int fin[n][9];
    int idle[n][3];

    for(i=0;i<n;i++)
    {
        printf("\nP[%d]:",i+1);
        printf(" Enter the AT: ");
        scanf(" %d", &given[i][0]);
        printf("      Enter the BT: ");
        scanf(" %d", &given[i][1]);
        printf("      Enter the Priority level: ");
        scanf(" %d", &given[i][2]);
    }
    for(i=0;i<n;i++)
    {
        dupl[i][0] = i+1;
        dupl[i][1] = given[i][0];
        dupl[i][2] = given[i][1];
        dupl[i][3] = given[i][2];
        dupl[i][9] = 1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(dupl[j][1]>dupl[j+1][1])
            {
                temp = dupl[j+1][0];
                dupl[j+1][0] = dupl[j][0];
                dupl[j][0] = temp;

                temp = dupl[j+1][1];
                dupl[j+1][1] = dupl[j][1];
                dupl[j][1] = temp;

                temp = dupl[j+1][2];
                dupl[j+1][2] = dupl[j][2];
                dupl[j][2] = temp;

                temp = dupl[j+1][3];
                dupl[j+1][3] = dupl[j][3];
                dupl[j][3] = temp;
            }
            else if(dupl[j][1]==dupl[j+1][1])
            {
                if(dupl[j][3]>dupl[j+1][3])
                {
                    temp = dupl[j+1][0];
                    dupl[j+1][0] = dupl[j][0];
                    dupl[j][0] = temp;

                    temp = dupl[j+1][1];
                    dupl[j+1][1] = dupl[j][1];
                    dupl[j][1] = temp;

                    temp = dupl[j+1][2];
                    dupl[j+1][2] = dupl[j][2];
                    dupl[j][2] = temp;

                    temp = dupl[j+1][3];
                    dupl[j+1][3] = dupl[j][3];
                    dupl[j][3] = temp;
                }
            }
        }
    }

    dupl[0][4] = dupl[0][1];
    dupl[0][5] = dupl[0][1] + dupl[0][2];
    dupl[0][6] = 0;
    dupl[0][7] = 0;
    dupl[0][8] = dupl[0][5];
    dupl[0][9] = 0;
    fin[0][0] = dupl[0][0];
    fin[0][1] = dupl[0][1];
    fin[0][2] = dupl[0][2];
    fin[0][3] = dupl[0][3];
    fin[0][4] = dupl[0][4];
    fin[0][5] = dupl[0][5];
    fin[0][6] = dupl[0][6];
    fin[0][7] = dupl[0][7];
    fin[0][8] = dupl[0][8];

    icnt = 0;
    for(j=1;j<n;j++)
    {
        cnt = 0;
        chk = 0;
        for(i=1;i<n;i++)
        {
            if((dupl[i][1]<=fin[j-1][5])&&(dupl[i][9]==1))
            {
                arrived[cnt][0] = dupl[i][1];
                arrived[cnt][1] = dupl[i][3];
                cnt++;
                chk=1;
            }
        }

        if(chk==0)
        {
            idle[icnt][0] = fin[j-1][5];
            idle[icnt][1] = dupl[j][2];
            cnt ++;

            dupl[j][4] = dupl[j][1];
            dupl[j][5] = dupl[j][1] + dupl[j][2];
            dupl[j][6] = 0;
            dupl[j][7] = 0;
            dupl[j][8] = dupl[j][5];
            dupl[j][9] = 0;
            fin[j][0] = dupl[j][0];
            fin[j][1] = dupl[j][1];
            fin[j][2] = dupl[j][2];
            fin[j][3] = dupl[j][3];
            fin[j][4] = dupl[j][4];
            fin[j][5] = dupl[j][5];
            fin[j][6] = dupl[j][6];
            fin[j][7] = dupl[j][7];
            fin[0][8] = dupl[0][8];

            continue;
        }

        arrive = arrived[0][0];
        lowest = arrived[0][1];
        for(i=1;i<cnt;i++)
        {
            if(arrived[i][1]<lowest)
            {
                arrive = arrived[i][0];
                lowest = arrived[i][1];
            }
        }
        for(i=1;i<n;i++)
        {
            if(dupl[i][1]==arrive && dupl[i][3]==lowest)
            {
                fin[j][0] = dupl[i][0];
                fin[j][1] = dupl[i][1];
                fin[j][2] = dupl[i][2];
                fin[j][3] = dupl[i][3];
                if(dupl[i][1]>fin[j-1][5])
                    fin[j][4] = dupl[i][1];
                else
                    fin[j][4] = fin[j-1][5];
                fin[j][5] = fin[j][4] + fin[j][2];
                fin[j][6] = fin[j][4] - fin[j][1];
                fin[j][7] = fin[j][6];
                fin[j][8] = fin[j][5] - fin[j][1];
                dupl[i][9] = 0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        dupl[i][0] = fin[i][0];
        dupl[i][1] = fin[i][1];
        dupl[i][2] = fin[i][2];
        dupl[i][3] = fin[i][3];
        dupl[i][4] = fin[i][4];
        dupl[i][5] = fin[i][5];
        dupl[i][6] = fin[i][6];
        dupl[i][7] = fin[i][7];
        dupl[i][8] = fin[i][8];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(fin[j][0]>fin[j+1][0])
            {
                temp = fin[j+1][0];
                fin[j+1][0] = fin[j][0];
                fin[j][0] = temp;

                temp = fin[j+1][1];
                fin[j+1][1] = fin[j][1];
                fin[j][1] = temp;

                temp = fin[j+1][2];
                fin[j+1][2] = fin[j][2];
                fin[j][2] = temp;

                temp = fin[j+1][3];
                fin[j+1][3] = fin[j][3];
                fin[j][3] = temp;

                temp = fin[j+1][4];
                fin[j+1][4] = fin[j][4];
                fin[j][4] = temp;


                temp = fin[j+1][5];
                fin[j+1][5] = fin[j][5];
                fin[j][5] = temp;

                temp = fin[j+1][6];
                fin[j+1][6] = fin[j][6];
                fin[j][6] = temp;

                temp = fin[j+1][7];
                fin[j+1][7] = fin[j][7];
                fin[j][7] = temp;

                temp = fin[j+1][8];
                fin[j+1][8] = fin[j][8];
                fin[j][8] = temp;
            }
        }
    }
    printf("\n\nProcess\t\tAT\tBT\tPriority\tS\tE\tWT\t\tRT\t\tTAT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t\t%d\t%d\t%d\t\t%d\t%d\t%d\t\t%d\t\t%d", fin[i][0], fin[i][1], fin[i][2], fin[i][3], fin[i][4], fin[i][5], fin[i][6], fin[i][7], fin[i][8]);
    }

    for(i=0;i<n;i++)
    {
        NPP_wt+=dupl[i][6];
        NPP_rt+=dupl[i][7];
        NPP_tat+=dupl[i][8];
    }

    NPP_wt/=(float)n;
    NPP_rt/=(float)n;
    NPP_tat/=(float)n;

    printf("\n     \t\t\t\t\t\t\t\t%.2f\t\t%.2f\t\t%.2f", NPP_wt, NPP_rt, NPP_tat);

    cnt = 0;
    printf("\n\n\n%d",cnt);
    k=0;
    for(i=0;i<n;i++)
    {
        if(cnt==dupl[n-1][5])
            break;

        if(dupl[i][2]>4)
        {
            temp = dupl[i][2]-1;

        }
        else
        {
            temp = 3;
        }

        if((cnt + dupl[i][2])>10)
            temp -= 1;

        if(idle[k][0]==cnt)
        {
            temp = idle[k][1]-1;
            cnt += idle[k][1];
            k++;
            i--;
        }
        else
            cnt += dupl[i][2];

        for(j=0;j<=temp;j++)
        {
            printf("=");
        }

        printf("%d",cnt);
    }

    printf("\n|");
    k=0;
    cnt=0;
    for(i=0;i<n;i++)
    {
        chk = 0;
        if(dupl[i][2]>4)
            temp = dupl[i][2]-3;
        else
            temp = 1;

        if(idle[k][0]==cnt)
        {
            temp = idle[k][1];
            k++;
            chk = 1;
            i-=1;
        }

        for(j=0; j<temp; j++)
        {
            if((j==temp/2)&&(chk==0)){
                if(dupl[i][0]==1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                }

                else if(dupl[i][0]==2)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                }

                else if(dupl[i][0]==3)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                }

                else if(dupl[i][0]==4)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                }

                else if(dupl[i][0]==5)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                }
                else if(dupl[i][0]==6)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                }
                else if(dupl[i][0]==7)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                }

                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                printf("P[%d]",dupl[i][0]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
                printf(" ");
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cnt += dupl[i][2];
        printf("|");
    }

    cnt = 0;
    k=0;
    printf("\n%d",cnt);
    for(i=0;i<n;i++)
    {
        if(cnt==dupl[n-1][5])
            break;

        if(dupl[i][2]>4)
        {
            temp = dupl[i][2]-1;

        }
        else
        {
            temp = 3;
        }

        if((cnt + dupl[i][2])>10)
            temp -= 1;

        if(idle[k][0]==cnt)
        {
            temp = idle[k][1]-1;
            cnt += idle[k][1];
            k++;
            i--;
        }
        else
            cnt += dupl[i][2];

        for(j=0;j<=temp;j++)
        {
            printf("=");
        }

        printf("%d",cnt);
    }
    printf("\n");

    return 0;
}

///NON-PREEMPTIVE PRIORITY IO BURST
void NPPIO_Scheduling()
{
    printf("\n\n\t\t***********************************\n\n");
    printf("\n\n\tNON-PREEMPTIVE PRIORITY with IO SCHEDULING ALGORITHM\n\n");
    int gant_count = 0, gant_time[MAX], smallest = 9;
    char gant_p[MAX][MAX];
    float aveWT = 0, aveRT = 0, aveTAT = 0;
    time = 0;
    count = 0;
    at[smallest] = 999;

    prio[smallest] = 999;
    while(count < proc_size){
        smallest = 9;
        for(i=0; i < proc_size; i++){
            if((prio[i] < prio[smallest]) && bt2[i] > 0 && at[i] <= time){
                smallest = i;
            }else if((prio[i] == prio[smallest]) && bt2[i] > 0 && at[i] <= time){
                if(at[i] < at[smallest]){
                    smallest = i;
                }
            }
        }

        if(bt[smallest] > 0){
            s[smallest] = time;
            gant_time[gant_count] = time;
            strcpy(gant_p[gant_count], p[smallest]);
            time += bt[smallest];
            at[smallest] = time + io[smallest];
            bt[smallest] = 0;
        } else if(bt[smallest] == 0){
            gant_time[gant_count] = time;
            strcpy(gant_p[gant_count], p[smallest]);
            time += bt2[smallest];
            e[smallest] = time;
            max_end = time;
            bt2[smallest] = 0;
            count++;
            rt[smallest] = s[smallest] - tempat[smallest];
            tat[smallest] = e[smallest] - tempat[smallest];
            wt[smallest] = tat[smallest] - cpu_time[smallest];
        }
        gant_count++;

    }

    for(i = 0; i < proc_size; i++){
        aveWT += (float)wt[i]/(float)proc_size;
        aveRT += (float)rt[i]/(float)proc_size;
        aveTAT += (float)tat[i]/(float)proc_size;
    }

        printf("\n  PROCESS \t AT \t CPU|IO|CPU \t Prio \t Start \t End \t RT \t WT \t TAT \n");
    for(i = 0; i < proc_size; i++){
        printf("\n  %s \t\t %d \t %d|%d|%d \t\t %d \t %d \t %d \t %d \t %d", p[i], tempat[i], tempbt[i], io[i], tempbt2[i], prio[i],s[i], e[i], rt[i], wt[i], tat[i]);
    }
    printf("\n---------------------------------------------------------------------");
    printf("\n \t\t\t\t\t    AVERAGE :\t %.2f \t %.2f \t %.2f\n\n", aveRT, aveWT, aveTAT);

    r_rt[y] = aveRT;
    r_wt[y] = aveWT;
    r_tat[y++] = aveTAT;

///GANCHART

    printf("\n\n  LEGEND: \n");
    for(i = 0; i < proc_size; i++){
        printf("\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i+2) * 16);

        printf(" %s ", p[i]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n");

    }

        printf("\n\n\t\t\tGANTT CHART\n\n");

    printf("\n");
    for(i = 0; i < gant_count; i++){
        for(j = 0; j < proc_size; j++){
            if(strcmp(gant_p[i], p[j])==0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (j+2) * 16);
            }
        }
        printf("%d %s     ", gant_time[i], gant_p[i]);
    }
    printf("%d ", max_end);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}

///PREEMPTIVE PRIORITY
void PP_Scheduling()
{
    int i;
    printf("PREEMPTIVE PRIORITY SCHEDULING\n\n");
    printf("Enter the number of processes: ");
    scanf("%d",&PP_numberOfProcesses);
    PP_arrivalTime=(int*)malloc(sizeof(int)*PP_numberOfProcesses);
    PP_CPUBurstTime=(int*)malloc(sizeof(int)*PP_numberOfProcesses);
    PP_CPUBurstTimeCopy=(int*)malloc(sizeof(int)*PP_numberOfProcesses);
    PP_processNumber=(int*)malloc(sizeof(int)*PP_numberOfProcesses);
    PP_waitingTime=(int*)malloc(sizeof(int)*PP_numberOfProcesses);
    PP_priority=(int*)malloc(sizeof(int)*PP_numberOfProcesses);
    PP_minimumArrivalTime=2147483647;

    for(i=0;i<PP_numberOfProcesses;i++)
    {
        PP_waitingTime[i]=0;
        PP_processNumber[i]=i;
        printf("\nEnter the data for process number: %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d", &PP_arrivalTime[i]);
        printf("CPU Burst time: ");
        scanf("%d", &PP_CPUBurstTime[i]);
        printf("Priority: ");
        scanf("%d", &PP_priority[i]);
        PP_CPUBurstTimeCopy[i] = PP_CPUBurstTime[i];
        PP_totalCPUBurstTime+=PP_CPUBurstTime[i];

        if(PP_minimumArrivalTime > PP_arrivalTime[i])
            PP_minimumArrivalTime = PP_arrivalTime[i];
    }
    PP_processSequenceForEachSecond=(int*)malloc(sizeof(int)*PP_totalCPUBurstTime);

    /* this function calculates the process sequence for each second. */

    PP_calculateProcessSequence();

    for(i=0; i<PP_numberOfProcesses; i++)
    {
        if(PP_arrivalTime[i]<PP_e[i-1])
        {
            PP_s[i] = PP_e[i-1];
        }
        else
        {
            PP_s[i] = PP_arrivalTime[i];
        }

        PP_completionTime[i] = PP_arrivalTime[i]+(PP_waitingTime[i]+PP_CPUBurstTimeCopy[i]);
        PP_preaverageTurnAroundTime[i] = PP_waitingTime[i]+PP_CPUBurstTimeCopy[i];
        PP_preaverageWaitingTime[i] = (PP_waitingTime[i]+PP_CPUBurstTimeCopy[i])-PP_CPUBurstTimeCopy[i];
    }
    PP_fin_averageWaitingTime=PP_averageWaitingTime/(float)PP_numberOfProcesses;
    PP_fin_averageTurnAroundTime=PP_averageTurnAroundTime/(float)PP_numberOfProcesses;
    // print
    printf("\n\t\tAT\tCPUBT\tPriority\tS\tE\tWT\t\tRT\t\tTAT\n");

    for(i=0;i<PP_numberOfProcesses;i++)
    {
        printf("P%d\t\t%d\t%d\t%d\t\t%d\t%d\t%.2f\t\t%.2f\t\t%.2f", i+1, PP_arrivalTime[i], PP_CPUBurstTimeCopy[i], PP_priority[i], PP_s[i], PP_completionTime[i], PP_preaverageWaitingTime[i], PP_preaverageWaitingTime[i], PP_preaverageTurnAroundTime[i]);
        printf("\n");
    }
    printf("\n\t\t\t\t\t\t\t\tAVE:%.2f\tAVE:%.2f\tAVE:%.2f", PP_fin_averageWaitingTime, PP_fin_averageWaitingTime, PP_fin_averageTurnAroundTime);

    PP_drawGanttChart();
}
void PP_calculateProcessSequence()
{
    int i, j, pNumber, prevProcess, tempCPUBurstTime, counter, prevProcesss;
    for(i=PP_minimumArrivalTime; i<PP_totalCPUBurstTime+PP_minimumArrivalTime; i++)
    {
        pNumber=PP_findAptProcessNumber(i);
        PP_processSequenceForEachSecond[i-PP_minimumArrivalTime]=pNumber;
        PP_CPUBurstTime[pNumber]--;
        /*
            calculating the waiting time of each process;
        */
        for(j=0;j<PP_numberOfProcesses;j++)
            if(PP_CPUBurstTime[j]!=0 && PP_arrivalTime[j]<=i && j!=pNumber)
                PP_waitingTime[j]++;
    }

    /* calculating the size of gantt chart arrays*/
    PP_ganttSize=1;
    prevProcess=PP_processSequenceForEachSecond[0];
    for(i=0;i<PP_totalCPUBurstTime;i++)
    {
        if(prevProcess!=PP_processSequenceForEachSecond[i])
            PP_ganttSize++;
        prevProcess=PP_processSequenceForEachSecond[i];
    }

    /* allocating the size of gantt chart arrays */
    PP_processNumberGantt=(int*)malloc(sizeof(int)*PP_ganttSize);
    PP_CPUBurstTimeGantt=(int*)malloc(sizeof(int)*PP_ganttSize);

    /* assigning the values to Gantt Chart Arrays */
    prevProcess=PP_processSequenceForEachSecond[0];
    tempCPUBurstTime=0;
    counter=0;
    for(i=0;i<PP_totalCPUBurstTime;i++)
    {
        if(prevProcess!=PP_processSequenceForEachSecond[i])
        {
            PP_processNumberGantt[counter]=prevProcess;
            PP_CPUBurstTimeGantt[counter]=tempCPUBurstTime;
            counter++;
            tempCPUBurstTime=0;
        }
        tempCPUBurstTime++;
        prevProcess=PP_processSequenceForEachSecond[i];
    }

    PP_CPUBurstTimeGantt[PP_ganttSize-1]=tempCPUBurstTime;
    PP_processNumberGantt[PP_ganttSize-1]=prevProcess;


    /* calculating the averageWaitingTime and averageTurnAroundTime */
    PP_averageWaitingTime=0;
    PP_averageTurnAroundTime=0;
    for(i=0;i<PP_numberOfProcesses;i++)
    {
        PP_averageWaitingTime+=PP_waitingTime[i];
        PP_averageTurnAroundTime+=PP_waitingTime[i]+PP_CPUBurstTimeCopy[i];
    }
}
int PP_findAptProcessNumber(int currentTime)
{
    int i,min=2147483647,pNumber;
    for(i=0;i<PP_numberOfProcesses;i++)
        if(PP_arrivalTime[i]<=currentTime && min>PP_priority[i] && PP_CPUBurstTime[i]!=0)
        {
            min=PP_priority[i];
            pNumber=i;
        }
    return pNumber;
}
void PP_drawGanttChart()
{
    const int maxWidth=100;
    int scalingFactor,i,counter,tempi,currentTime;
    printf("\n\nGANTT CHART:\n\n");

    scalingFactor=maxWidth/PP_totalCPUBurstTime;
    for(i=0;i<scalingFactor*PP_totalCPUBurstTime+2+PP_ganttSize;i++)
        printf("-");

    printf("\n|");
    counter=0,tempi=0;
    for(i=0;i<scalingFactor*PP_totalCPUBurstTime;i++)
        if(i==PP_CPUBurstTimeGantt[counter]*scalingFactor+tempi)
        {
            counter++;
            tempi=i;
            printf("|");
        }
        else if(i==(PP_CPUBurstTimeGantt[counter]*scalingFactor)/2+tempi)
        {
            if(PP_processNumberGantt[counter]+1==1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            }

            else if(PP_processNumberGantt[counter]+1==2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            }
            else if(PP_processNumberGantt[counter]+1==3)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            }
            else if(PP_processNumberGantt[counter]+1==4)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            }

            else if(PP_processNumberGantt[counter]+1==5)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            }
            else if(PP_processNumberGantt[counter]+1==6)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            }
            else if(PP_processNumberGantt[counter]+1==7)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            printf("P%d",PP_processNumberGantt[counter]+1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else
            printf(" ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("|");
    printf("\n");
    for(i=0;i<scalingFactor*PP_totalCPUBurstTime+2+PP_ganttSize;i++)
                    printf("-");
    printf("\n");

    /* printing the time labels of the gantt chart */
    counter=0;
    tempi=0;
    currentTime=PP_minimumArrivalTime;
    printf("%d", currentTime);
    for(i=0;i<scalingFactor*PP_totalCPUBurstTime;i++)
        if(i==PP_CPUBurstTimeGantt[counter]*scalingFactor+tempi)
        {
            tempi=i;
            currentTime+=PP_CPUBurstTimeGantt[counter];
            PP_averageWaitingTime+=currentTime;
            counter++;
            printf("%2d", currentTime);
        }
        else
        {
            printf(" ");
        }
    currentTime+=PP_CPUBurstTimeGantt[counter];
    printf("%2d\n\n",currentTime);
}

///ROUND ROBIN
void RR_Scheduling()
{
    int i,j,temp;
    printf("ROUND ROBIN SCHEDULING\n\n");
    printf("Enter the number of processes: ");
    scanf("%d",&RR_numberOfProcesses);
    printf("Enter the Time Quantum: ");
    scanf("%d",&RR_timeQuantum);
    RR_arrivalTime=(int*)malloc(sizeof(int)*RR_numberOfProcesses);
    RR_CPUBurstTime=(int*)malloc(sizeof(int)*RR_numberOfProcesses);
    RR_CPUBurstTimeCopy=(int*)malloc(sizeof(int)*RR_numberOfProcesses);
    RR_processNumber=(int*)malloc(sizeof(int)*RR_numberOfProcesses);
    RR_waitingTime=(int*)malloc(sizeof(int)*RR_numberOfProcesses);
    RR_minimumArrivalTime=2147483647;

    for(i=0;i<RR_numberOfProcesses;i++)
    {
        RR_waitingTime[i]=0;
        RR_processNumber[i]=i;
        printf("\nEnter the data for process number: %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&RR_arrivalTime[i]);
        printf("CPU Burst time: ");
        scanf("%d",&RR_CPUBurstTime[i]);
        RR_CPUBurstTimeCopy[i]=RR_CPUBurstTime[i];
        RR_totalCPUBurstTime+=RR_CPUBurstTime[i];
        if(RR_minimumArrivalTime>RR_arrivalTime[i])
        {
            RR_minimumArrivalTime=RR_arrivalTime[i];
        }
    }

    //implementing bubble sort algorithm sorting processes on the basis of arrival time
    for(i=0;i<RR_numberOfProcesses;i++)
    {
        for(j=0;j<RR_numberOfProcesses-i-1;j++)
        {
            if(RR_arrivalTime[j]>RR_arrivalTime[j+1])
            {
                 temp=RR_arrivalTime[j];
                 RR_arrivalTime[j]=RR_arrivalTime[j+1];
                 RR_arrivalTime[j+1]=temp;

                 temp=RR_CPUBurstTime[j];
                 RR_CPUBurstTime[j]=RR_CPUBurstTime[j+1];
                 RR_CPUBurstTime[j+1]=temp;

                 temp=RR_processNumber[j];
                 RR_processNumber[j]=RR_processNumber[j+1];
                 RR_processNumber[j+1]=temp;
            }
        }
    }

    RR_processSequenceForEachSecond=(int*)malloc(sizeof(int)*RR_totalCPUBurstTime);

    /* this function calculates the process sequence for each second. */

    RR_calculateProcessSequence();

    for(i=0; i<RR_numberOfProcesses; i++)
    {
        if(RR_arrivalTime[i]<RR_e[i-1])
        {
            RR_s[i]=RR_e[i-1];
        }
        else
        {
            RR_s[i]=RR_arrivalTime[i];
        }

        RR_completionTime[i]=RR_arrivalTime[i]+(RR_waitingTime[i]+RR_CPUBurstTimeCopy[i]);
        RR_s[i]=RR_minimumArrivalTime+(RR_timeQuantum*(i));
        RR_responseTime[i] = RR_s[i];
        RR_preaverageTurnAroundTime[i] = RR_waitingTime[i]+RR_CPUBurstTimeCopy[i];
        RR_preaverageWaitingTime[i] = (RR_waitingTime[i]+RR_CPUBurstTimeCopy[i])-RR_CPUBurstTimeCopy[i];
        RR_averageResponseTime+=RR_responseTime[i];
    }
    RR_averageResponseTime=RR_averageResponseTime/(float)RR_numberOfProcesses;
    // print
    printf("\n\tAT\tCPUBT\tS\tE\tWT\t\tRT\t\tTAT\n");

    for(i=0;i<RR_numberOfProcesses;i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%.2f\t\t%.2f\t\t%.2f", i+1, RR_arrivalTime[i], RR_CPUBurstTimeCopy[i], RR_s[i], RR_completionTime[i], RR_preaverageWaitingTime[i], RR_responseTime[i], RR_preaverageTurnAroundTime[i]);
        printf("\n");
    }
    printf("\n\t\t\t\t\tAVE:%.2f\tAVE:%.2f\tAVE:%.2f", RR_fin_averageWaitingTime, RR_averageResponseTime, RR_averageTurnAroundTime);

    RR_drawGanttChart();
}
void RR_calculateProcessSequence()
{
    int i, j, pNumber=RR_processNumber[0], prevProcess, tempCPUBurstTime, counter=0, prevProcesss;
    for(i=RR_minimumArrivalTime;i<RR_totalCPUBurstTime + RR_minimumArrivalTime;i++)
    {
        /* here i denotes the current time */
        prevProcess=pNumber;
        pNumber=RR_findAptProcessNumber(i,pNumber,counter);
        if(pNumber==prevProcess)
        {
            counter++;
        }
        else
            counter=1;

        RR_CPUBurstTime[pNumber]--;
        RR_processSequenceForEachSecond[i-RR_minimumArrivalTime]=pNumber;
        /*
        calculating the waiting time of each process;
        */
        for(j=0;j<RR_numberOfProcesses;j++)
            if(RR_CPUBurstTime[j]!=0 && RR_arrivalTime[j]<=i && j!=pNumber)
                RR_waitingTime[j]++;

    }

    RR_ganttSize=1;
    prevProcess=RR_processSequenceForEachSecond[0];
    for(i=0;i<RR_totalCPUBurstTime;i++)
    {
        if(prevProcess!=RR_processSequenceForEachSecond[i])
            RR_ganttSize++;
            prevProcess=RR_processSequenceForEachSecond[i];
    }

    /* allocating the size of gantt chart arrays */
    RR_processNumberGantt=(int*)malloc(sizeof(int)*RR_ganttSize);
    RR_CPUBurstTimeGantt=(int*)malloc(sizeof(int)*RR_ganttSize);

    /* assigning the values to Gantt Chart Arrays */
    prevProcess=RR_processSequenceForEachSecond[0];
    tempCPUBurstTime=0;
    counter=0;
    for(i=0;i<RR_totalCPUBurstTime;i++)
    {
        if(prevProcess!=RR_processSequenceForEachSecond[i])
        {
            RR_processNumberGantt[counter]=prevProcess;
            RR_CPUBurstTimeGantt[counter]=tempCPUBurstTime;
            counter++;
            tempCPUBurstTime=0;
        }
        tempCPUBurstTime++;
        prevProcess=RR_processSequenceForEachSecond[i];
    }

    RR_CPUBurstTimeGantt[RR_ganttSize-1]=tempCPUBurstTime;
    RR_processNumberGantt[RR_ganttSize-1]=prevProcess;


    /* calculating the averageResponseTime, averageWaitingTime and averageTurnAroundTime */
    RR_averageResponseTime=0;
    RR_averageWaitingTime=0;
    RR_averageTurnAroundTime=0;
    for(i=0;i<RR_numberOfProcesses;i++)
    {
        RR_averageWaitingTime+=RR_waitingTime[i];
        RR_averageTurnAroundTime+=RR_waitingTime[i]+RR_CPUBurstTimeCopy[i];
    }
    RR_fin_averageWaitingTime=RR_averageWaitingTime/(float)RR_numberOfProcesses;
    RR_averageTurnAroundTime=RR_averageTurnAroundTime/(float)RR_numberOfProcesses;
}
int RR_findAptProcessNumber(int currentTime,int currentProcess,int time)
{
    /* this function returns the process number that should run on currentTime. */
    /* time variable is used to indicate the time for which a process is being executed */
    int i, pNumber, answer;
    if(currentTime!=0 && (time==RR_timeQuantum || RR_CPUBurstTime[currentProcess]==0))
    {
        for(i=0;i<RR_numberOfProcesses;i++)
        {
            if(RR_processNumber[i]==currentProcess)
            {
                if((currentProcess+1)==RR_numberOfProcesses)
                    answer=0;
                else
                    answer=currentProcess+1;
                while(RR_arrivalTime[answer]>currentTime || RR_CPUBurstTime[answer]==0)
                    answer=(answer+1)%RR_numberOfProcesses;
                return answer;
            }
        }
    }
    else
    return currentProcess;
}
void RR_drawGanttChart()
{
    const int maxWidth=100;
    int scalingFactor, i, counter, tempi, currentTime;
    printf("\n\nGANTT CHART \n");

    scalingFactor=maxWidth/RR_totalCPUBurstTime;
    for(i=0;i<scalingFactor*RR_totalCPUBurstTime+2+RR_ganttSize;i++)
    printf("-");
    printf("\n|");
    counter=0,tempi=0;
    for(i=0;i<scalingFactor*RR_totalCPUBurstTime;i++)
    if(i==RR_CPUBurstTimeGantt[counter]*scalingFactor+tempi)
    {
        counter++;
        tempi=i;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("|");
    }
    else if(i==(RR_CPUBurstTimeGantt[counter]*scalingFactor)/2+tempi){
        if(RR_processNumberGantt[counter]+1==1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        }

        else if(RR_processNumberGantt[counter]+1==2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        }

        else if(RR_processNumberGantt[counter]+1==3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        }

        else if(RR_processNumberGantt[counter]+1==4)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        }

        else if(RR_processNumberGantt[counter]+1==5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        }
        else if(RR_processNumberGantt[counter]+1==6)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        }
        else if(RR_processNumberGantt[counter]+1==7)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        printf("P%d",RR_processNumberGantt[counter]+1);
    }
    else
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("|");
        printf("\n");

    for(i=0;i<scalingFactor*RR_totalCPUBurstTime+2+RR_ganttSize;i++)
        printf("-");
        printf("\n");

    /* printing the time labels of the gantt chart */
    counter=0;
    tempi=0;
    currentTime=RR_minimumArrivalTime;
    printf("%d",currentTime);
    for(i=0;i<scalingFactor*RR_totalCPUBurstTime;i++)
        if(i==RR_CPUBurstTimeGantt[counter]*scalingFactor+tempi)
        {
            tempi=i;
            currentTime+=RR_CPUBurstTimeGantt[counter];
            RR_averageWaitingTime+=currentTime;
            counter++;
            printf("%2d",currentTime);
        }
        else
        {
            printf(" ");
        }

    currentTime+=RR_CPUBurstTimeGantt[counter];
    printf("%2d\n\n",currentTime);
}

///COMPARISON
void comparison()
{
    ///title
    printf("\n\nComparison of ");
    if (sndmenufirst==1){
        printf("FIRST COME FIRST SERVE and ");
    }
    else if (sndmenufirst==2){
        printf("SHORTEST JOB FIRST and ");
    }
    else if (sndmenufirst==3){
        printf("SHORTEST REMAINING TIME FIRST and ");
    }
    else if (sndmenufirst==4){
        printf("NON-PREEMPTIVE PRIORITY and ");
    }
    else if (sndmenufirst==5){
        printf("PREEMPTIVE PRIORITY and ");
    }
    else if (sndmenufirst==6){
        printf("ROUND ROBIN and ");
    }

    if (sndmenusecond==1){
        printf("FIRST COME FIRST SERVE\n\n");
    }
    else if (sndmenusecond==2){
        printf("SHORTEST JOB FIRST\n\n");
    }
    else if (sndmenusecond==3){
        printf("SHORTEST REMAINING TIME FIRST\n\n");
    }
    else if (sndmenusecond==4){
        printf("NON-PREEMPTIVE PRIORITY\n\n");
    }
    else if (sndmenusecond==5){
        printf("PREEMPTIVE PRIORITY\n\n");
    }
    else if (sndmenusecond==6){
        printf("ROUND ROBIN\n\n");
    }
}

void print_comparison()
{
    ///COMPARISON PROCESS
    float WT_variable_first, WT_variable_second, RT_variable_first, RT_variable_second, TAT_variable_first, TAT_variable_second;

    WT_variable_first = *first_WT_variable;
    WT_variable_second = *second_WT_variable;
    printf("Comparison of Waiting Time\n");
    if(WT_variable_first < WT_variable_second){
        if(sndmenufirst==1){
            printf("1. FCFS");
        }
        else if(sndmenufirst==2){
            printf("1. SJF");
        }
        else if(sndmenufirst==3){
            printf("1. SRTF");
        }
        else if(sndmenufirst==4){
            printf("1. NPP");
        }
        else if(sndmenufirst==5){
            printf("1. PP");
        }
        else if(sndmenufirst==6){
            printf("1. RR");
        }
        printf("\t%.2f\n", WT_variable_first);

        if(sndmenusecond==1){
            printf("2. FCFS");
        }
        else if(sndmenusecond==2){
            printf("2. SJF");
        }
        else if(sndmenusecond==3){
            printf("2. SRTF");
        }
        else if(sndmenusecond==4){
            printf("2. NPP");
        }
        else if(sndmenusecond==5){
            printf("2. PP");
        }
        else if(sndmenusecond==6){
            printf("2. RR");
        }
        printf("\t%.2f\n\n", WT_variable_second);
    }
    else if(WT_variable_first > WT_variable_second){
        if(sndmenusecond==1){
            printf("1. FCFS");
        }
        else if(sndmenusecond==2){
            printf("1. SJF");
        }
        else if(sndmenusecond==3){
            printf("1. SRTF");
        }
        else if(sndmenusecond==4){
            printf("1. NPP");
        }
        else if(sndmenusecond==5){
            printf("1. PP");
        }
        else if(sndmenusecond==6){
            printf("1. RR");
        }
        printf("\t%.2f\n", WT_variable_second);

        if(sndmenufirst==1){
            printf("2. FCFS");
        }
        else if(sndmenufirst==2){
            printf("2. SJF");
        }
        else if(sndmenufirst==3){
            printf("2. SRTF");
        }
        else if(sndmenufirst==4){
            printf("2. NPP");
        }
        else if(sndmenufirst==5){
            printf("2. PP");
        }
        else if(sndmenufirst==6){
            printf("2. RR");
        }
        printf("\t%.2f\n\n", WT_variable_first);
    }

    RT_variable_first = *first_RT_variable;
    RT_variable_second = *second_RT_variable;
    printf("Comparison of Response Time\n");
    if(RT_variable_first < RT_variable_second){
        if(sndmenufirst==1){
            printf("1. FCFS");
        }
        else if(sndmenufirst==2){
            printf("1. SJF");
        }
        else if(sndmenufirst==3){
            printf("1. SRTF");
        }
        else if(sndmenufirst==4){
            printf("1. NPP");
        }
        else if(sndmenufirst==5){
            printf("1. PP");
        }
        else if(sndmenufirst==6){
            printf("1. RR");
        }
        printf("\t%.2f\n", RT_variable_first);

        if(sndmenusecond==1){
            printf("2. FCFS");
        }
        else if(sndmenusecond==2){
            printf("2. SJF");
        }
        else if(sndmenusecond==3){
            printf("2. SRTF");
        }
        else if(sndmenusecond==4){
            printf("2. NPP");
        }
        else if(sndmenusecond==5){
            printf("2. PP");
        }
        else if(sndmenusecond==6){
            printf("2. RR");
        }
        printf("\t%.2f\n\n", RT_variable_second);
    }
    else if(RT_variable_first > RT_variable_second){
        if(sndmenusecond==1){
            printf("1. FCFS");
        }
        else if(sndmenusecond==2){
            printf("1. SJF");
        }
        else if(sndmenusecond==3){
            printf("1. SRTF");
        }
        else if(sndmenusecond==4){
            printf("1. NPP");
        }
        else if(sndmenusecond==5){
            printf("1. PP");
        }
        else if(sndmenusecond==6){
            printf("1. RR");
        }
        printf("\t%.2f\n", RT_variable_second);

        if(sndmenufirst==1){
            printf("2. FCFS");
        }
        else if(sndmenufirst==2){
            printf("2. SJF");
        }
        else if(sndmenufirst==3){
            printf("2. SRTF");
        }
        else if(sndmenufirst==4){
            printf("2. NPP");
        }
        else if(sndmenufirst==5){
            printf("2. PP");
        }
        else if(sndmenufirst==6){
            printf("2. RR");
        }
        printf("\t%.2f\n\n", RT_variable_first);
    }

    TAT_variable_first = *first_TAT_variable;
    TAT_variable_second = *second_TAT_variable;
    printf("Comparison of Turn Around Time\n");
    if(TAT_variable_first < TAT_variable_second){
        if(sndmenufirst==1){
            printf("1. FCFS");
        }
        else if(sndmenufirst==2){
            printf("1. SJF");
        }
        else if(sndmenufirst==3){
            printf("1. SRTF");
        }
        else if(sndmenufirst==4){
            printf("1. NPP");
        }
        else if(sndmenufirst==5){
            printf("1. PP");
        }
        else if(sndmenufirst==6){
            printf("1. RR");
        }
        printf("\t%.2f\n", TAT_variable_first);

        if(sndmenusecond==1){
            printf("2. FCFS");
        }
        else if(sndmenusecond==2){
            printf("2. SJF");
        }
        else if(sndmenusecond==3){
            printf("2. SRTF");
        }
        else if(sndmenusecond==4){
            printf("2. NPP");
        }
        else if(sndmenusecond==5){
            printf("2. PP");
        }
        else if(sndmenusecond==6){
            printf("2. RR");
        }
        printf("\t%.2f\n\n", TAT_variable_second);
    }
    else if(TAT_variable_first > TAT_variable_second){
        if(sndmenusecond==1){
            printf("1. FCFS");
        }
        else if(sndmenusecond==2){
            printf("1. SJF");
        }
        else if(sndmenusecond==3){
            printf("1. SRTF");
        }
        else if(sndmenusecond==4){
            printf("1. NPP");
        }
        else if(sndmenusecond==5){
            printf("1. PP");
        }
        else if(sndmenusecond==6){
            printf("1. RR");
        }
        printf("\t%.2f\n", TAT_variable_second);

        if(sndmenufirst==1){
            printf("2. FCFS");
        }
        else if(sndmenufirst==2){
            printf("2. SJF");
        }
        else if(sndmenufirst==3){
            printf("2. SRTF");
        }
        else if(sndmenufirst==4){
            printf("2. NPP");
        }
        else if(sndmenufirst==5){
            printf("2. PP");
        }
        else if(sndmenufirst==6){
            printf("2. RR");
        }
        printf("\t%.2f\n\n", TAT_variable_first);
    }
    system("pause");
}

void delay(int number_of_seconds)
{
    int milli_seconds = 3500 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
