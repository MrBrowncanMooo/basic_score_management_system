#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

enum moduls {Chinese, Math, English, Physics, Chemistry};

const char *STUDENT_FORMAT_IN="(%d,%s,%c,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%d)\n";
const char *STUDENT_FORMAT_OUT="(%d,%[^,],%c,%f,%f,%f,%f,%f,%f,%d)\n";

static int NUMBER_OF_STUDENT;

struct student
{
    unsigned int id;
    char name[25];
    char sex;
    float score[5];
    float total_score;
    int rank;
};

// display and stabilizer functions
void DISPLAY_STUDENT();
void SEARCH_STUDENT();
void ADD_STUDENT();
void MODIFY_STUDENT();
void DELETE_STUDENT();
void RETRIEVED();
//stabilizer functions
void RANK_OF_STUDENT();
void ID_OF_STUDENT();
void COUNT_NUMBER_OF_STUDENT();
void CORRECT_NAME(char *);
void CHECK_IF_EXIST(int,char* ,const char* ,int* );
void BACKUPS_STABILIZER(struct student,const char*);
void DATA_SECURE(int);


int main()
{
    int choice=1;
    DATA_SECURE(choice);
    do
    {
        printf("\n\n\n\t\t\t============STUDENT RECORD MANAGEMENT============\n\n");
        printf("\t\t\t\t1-Display\n\t\t\t\t2-Search\n\t\t\t\t3-Add\n\t\t\t\t4-Modify\n\t\t\t\t5-Delete\n\t\t\t\t6-Retrieved\n\t\t\t\t0-Exit\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                system("cls");
                DISPLAY_STUDENT();
                printf("\t\tPress any key to back to MENU.....\n");
                getch();
                system("cls");
            }break;
            case 2:
            {
                system("cls");
                SEARCH_STUDENT();
                printf("\t\tPress any key to back to MENU.....\n");
                getch();
                system("cls");
            }
            break;
            case 3:
            {
                system("cls");
                ADD_STUDENT();
                printf("\t\tPress any key to back to MENU.....\n");
                getch();
                system("cls");
            }
            break;
            case 4:
            {
                system("cls");
                MODIFY_STUDENT();
                printf("\t\tPress any key to back to MENU.....\n");
                getch();
                system("cls");
            }
            break;
            case 5:
            {
                system("cls");
                DELETE_STUDENT();
                printf("\t\tPress any key to back to MENU.....\n");
                getch();
                system("cls");
            }
            break;
            case 6:
            {
                system("cls");
                RETRIEVED();
                printf("\t\tPress any key to back to MENU.....\n");
                getch();
                system("cls");
            }
            break;
            case 0:
            {
                DATA_SECURE(choice);
                printf("\n\t\tThank you for using this software.\n\n");
            }
            break;
            default:
            {
                printf("\t\tPlease select one of the choice.\n");
                printf("\t\tPress any to get back.....\n");
                getch();
                system("cls");
            }
        }
    } while (choice!=0);
    
    return 0;
}

// display and stabilizer functions

void DISPLAY_STUDENT()
{
    FILE *fp;
    struct student info;
    int choice,dis=0;
    char buffer[200];
    printf("\n\n\n\t\t\t=================STUDENT RECORDS=================\n\n");
    printf("\n\n\t\t\t1-Display by student ID\n\t\t\t2-Display by student RANK\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d",&choice);
    getchar();
    fp=fopen("projectC.txt","r");
    if(fp==NULL)
    {
        printf("\t\tERROR can't open the file.\n");
    } 
    else
    {
        switch(choice)
        {
            case 1:
            {
                dis=1;
                fclose(fp);
                ID_OF_STUDENT();
            }break;
            case 2:
            {
                dis=1;
                fclose(fp);
                RANK_OF_STUDENT();
            }break;
            default:
                {
                    printf("\t\tChoice invalid.\n");
                }
        }
        if(dis==1)
        {
            fp=fopen("projectC.txt","r");
            printf("\n\t\t\tThere's %d students\n\n",NUMBER_OF_STUDENT);
            printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
            fgets(buffer,200,fp);
            while(!feof(fp))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                fgets(buffer,200,fp);
            }
            fclose(fp);    
        }
    }
}

void SEARCH_STUDENT()
{
    FILE *fp;
    struct student info;
    char buffer[200];
    int student_id,student_rank,choice,found=0;
    printf("\n\n\n\t\t\t============SEARCH STUDENT============\n\n");
    fp=fopen("projectC.txt","r");
    if(fp==NULL) printf("\t\tERROR can't open the file.\n");
    else
    {
        printf("\n\n\t\t\t1-Search by student ID\n\t\t\t2-Search by student RANK\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                printf("\n\t\tEnter Student ID:");
                scanf("%d",&student_id);
                getchar();
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.id==student_id)
                    {
                        found=1;
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
                fclose(fp);
            }
            break;
            case 2:
            {
                printf("\n\t\tEnter Student RANK:");
                scanf("%d",&student_rank);
                getchar();
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.rank==student_rank)
                    {
                        found=1;
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
                fclose(fp);
            }
            break;
            default:
            {
                found=2;
                printf("\t\t\tChoice invalid.\n");
            }
        }
        if(!found) printf("\n\t\tStudent Not found.\n");
    }
}

void ADD_STUDENT()
{
    FILE *fp;
    struct student info;
    char another;
    int valid=2;
    do
    {
        printf("\n\n\n\t\t\t============ADDING STUDENT============\n\n");
        printf("Enter student ID         :");
        scanf("%d",&info.id);
        getchar();
        printf("Enter student name       :");
        gets(info.name);
        printf("Enter student sex(M/F)   :");
        scanf("%c",&info.sex);
        getchar();
        printf("Enter score of Chinese   :");
        scanf("%f",&info.score[Chinese]);
        getchar();
        printf("Enter score of Math      :");
        scanf("%f",&info.score[Math]);
        getchar();
        printf("Enter score of English   :");
        scanf("%f",&info.score[English]);
        getchar();
        printf("Enter score of Physic    :");
        scanf("%f",&info.score[Physics]);
        getchar();
        printf("Enter score of chemistry :");
        scanf("%f",&info.score[Chemistry]);
        getchar();
        CORRECT_NAME(info.name);
        if(info.sex>=97&&info.sex<=122) info.sex-=32;
        info.total_score=(info.score[Chinese]+info.score[Math]+info.score[English]+info.score[Physics]+info.score[Chemistry]);
        info.rank=1;
        CHECK_IF_EXIST(info.id,info.name,"projectC.txt",&valid);
        if(valid)
        {
            fp=fopen("projectC.txt","a");
            fprintf_s(fp,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
            printf("\n\t\t\tStudent added successfully\n");
            fclose(fp);
        }
        else if(!valid)
        {
            printf("\n\t\t\t%d , %s exists in student list, can not store this student twice\n",info.id,info.name);
            printf("\n\t\t\tIf you want to modify record use \"Modify\" function in menu.\n");
        }
        printf("\n\t\t\tDo you want to add another student?(y/n)\n\t\t\t");
        scanf("%c",&another);
        getchar();
    } while (another=='Y'||another=='y');
    RANK_OF_STUDENT();
}

void MODIFY_STUDENT()
{
    FILE *fp,*fp1;
    struct student info;
    int found=0,student_id,student_rank,choice;
    float student_totalscore;
    char student_name[25],buffer[200],choice2;
    printf("\n\n\n\t\t\t============MODIFIE STUDENT============\n\n");
    fp=fopen("projectC.txt","r");
    if(fp==NULL)
    {
        printf("\t\tERROR can't open the file.\n");
        fclose(fp);
    }
    else
    {
        fp1=fopen("temp.txt","a");
        printf("\n\n\t\t\t1-Modify by student ID\n\t\t\t2-Modify by student RANK\n\t\t\t3-Modify by student NAME\n\t\t\t4-Modify by student TOTAL SCORE\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                printf("\n\t\tEnter Student ID:");
                scanf("%d",&student_id);
                getchar();
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.id==student_id)
                    {
                        found=1;
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tRe-enter the data:\n");
                        printf("Enter student ID         :");
                        scanf("%d",&info.id);
                        getchar();
                        printf("Enter student name       :");
                        gets(info.name);
                        printf("Enter student sex(M/F)   :");
                        scanf("%c",&info.sex);
                        getchar();
                        printf("Enter score of Chinese   :");
                        scanf("%f",&info.score[Chinese]);
                        getchar();
                        printf("Enter score of Math      :");
                        scanf("%f",&info.score[Math]);
                        getchar();
                        printf("Enter score of English   :");
                        scanf("%f",&info.score[English]);
                        getchar();
                        printf("Enter score of Physic    :");
                        scanf("%f",&info.score[Physics]);
                        getchar();
                        printf("Enter score of chemistry :");
                        scanf("%f",&info.score[Chemistry]);
                        getchar();
                        CORRECT_NAME(info.name);
                        if(info.sex>=97&&info.sex<=122) info.sex-=32;
                        info.total_score=(info.score[Chinese]+info.score[Math]+info.score[English]+info.score[Physics]+info.score[Chemistry]);
                        info.rank=1;
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    else
                    {
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
            break;
    
            case 2:
            {
                printf("\n\t\tEnter Student RANK:");
                scanf("%d",&student_rank);
                getchar();
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.rank==student_rank)
                    {
                        found=1;
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tRe-enter the data:\n");
                        printf("Enter student ID         :");
                        scanf("%d",&info.id);
                        getchar();
                        printf("Enter student name       :");
                        gets(info.name);
                        printf("Enter student sex(M/F)   :");
                        scanf("%c",&info.sex);
                        getchar();
                        printf("Enter score of Chinese   :");
                        scanf("%f",&info.score[Chinese]);
                        getchar();
                        printf("Enter score of Math      :");
                        scanf("%f",&info.score[Math]);
                        getchar();
                        printf("Enter score of English   :");
                        scanf("%f",&info.score[English]);
                        getchar();
                        printf("Enter score of Physic    :");
                        scanf("%f",&info.score[Physics]);
                        getchar();
                        printf("Enter score of chemistry :");
                        scanf("%f",&info.score[Chemistry]);
                        getchar();
                        CORRECT_NAME(info.name);
                        if(info.sex>=97&&info.sex<=122) info.sex-=32;
                        info.total_score=(info.score[Chinese]+info.score[Math]+info.score[English]+info.score[Physics]+info.score[Chemistry]);
                        info.rank=1;
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    else
                    {
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
            break;

            case 3:
            {
                printf("\n\t\tEnter Student NAME:");
                gets(student_name);
                CORRECT_NAME(student_name);
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(!strncmp(info.name,student_name,sizeof(info.name)))
                    {                
                        found=1;
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tRe-enter the data:\n");
                        printf("Enter student ID         :");
                        scanf("%d",&info.id);
                        getchar();
                        printf("Enter student name       :");
                        gets(info.name);
                        printf("Enter student sex(M/F)   :");
                        scanf("%c",&info.sex);
                        getchar();
                        printf("Enter score of Chinese   :");
                        scanf("%f",&info.score[Chinese]);
                        getchar();
                        printf("Enter score of Math      :");
                        scanf("%f",&info.score[Math]);
                        getchar();
                        printf("Enter score of English   :");
                        scanf("%f",&info.score[English]);
                        getchar();
                        printf("Enter score of Physic    :");
                        scanf("%f",&info.score[Physics]);
                        getchar();
                        printf("Enter score of chemistry :");
                        scanf("%f",&info.score[Chemistry]);
                        getchar();
                        CORRECT_NAME(info.name);
                        if(info.sex>=97&&info.sex<=122) info.sex-=32;
                        info.total_score=(info.score[Chinese]+info.score[Math]+info.score[English]+info.score[Physics]+info.score[Chemistry]);
                        info.rank=1;
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    else
                    {
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
            break;

            case 4:
            {
                printf("\n\t\tEnter Student TOTAL SCORE:");
                scanf("%f",&student_totalscore);
                getchar();
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.total_score==student_totalscore)
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\t Is this the student you want to modify?(y/n)\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            printf("\n\t\t\tRe-enter the data:\n");
                            printf("Enter student ID         :");
                            scanf("%d",&info.id);
                            getchar();
                            printf("Enter student name       :");
                            gets(info.name);
                            printf("Enter student sex(M/F)   :");
                            scanf("%c",&info.sex);
                            getchar();
                            printf("Enter score of Chinese   :");
                            scanf("%f",&info.score[Chinese]);
                            getchar();
                            printf("Enter score of Math      :");
                            scanf("%f",&info.score[Math]);
                            getchar();
                            printf("Enter score of English   :");
                            scanf("%f",&info.score[English]);
                            getchar();
                            printf("Enter score of Physic    :");
                            scanf("%f",&info.score[Physics]);
                            getchar();
                            printf("Enter score of chemistry :");
                            scanf("%f",&info.score[Chemistry]);
                            getchar();
                            CORRECT_NAME(info.name);
                            if(info.sex>=97&&info.sex<=122) info.sex-=32;
                            info.total_score=(info.score[Chinese]+info.score[Math]+info.score[English]+info.score[Physics]+info.score[Chemistry]);
                            info.rank=1;
                            fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                        else
                        {
                            fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
            break;

            default:
            {
                found=2;
                printf("\t\tChoice invalid.\n");
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    fgets(buffer,200,fp);
                }
            }

        } 
        fclose(fp);
        fclose(fp1);
        if(!found)
        {
            printf("\n\t\tStudent Not found.\n");
        } 
        else if(found==1)
        {
            printf("\n\t\tStudent modified successfully.\n");
        } 
        remove("projectC.txt");
        rename("temp.txt","projectC.txt");
        RANK_OF_STUDENT();
    }
}

void DELETE_STUDENT()
{
    FILE *fp,*fp1,*fp2;
    struct student info,stp2;
    int found=0,student_id,student_rank,choice;
    float student_totalscore;
    char student_name[25],buffer[200],choice2;
    printf("\n\n\n\t\t\t============DELETE STUDENT============\n\n");
    fp=fopen("projectC.txt","r");
    if(fp==NULL)
    {
        printf("\t\tERROR can't open the file.\n");
        fclose(fp);
    }
    else
    {
        fp2=fopen("temp.txt","a");
        printf("\n\n\t\t\t1-Delete by student ID\n\t\t\t2-Delete by student RANK\n\t\t\t3-Delete by student NAME\n\t\t\t4-Delete by student TOTAL SCORE\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                printf("\n\t\tEnter Student ID:");
                scanf("%d",&student_id);
                getchar();
                if(fp==NULL) printf("ERROR can't open the file.\n");
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.id==student_id)
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tAre you sure you want delete this student(y/n)?\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            BACKUPS_STABILIZER(info,"backups.txt");
                        }
                        else
                        {
                            found=2;
                            fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
            break;
    
            case 2:
            {
                printf("\n\t\t\tEnter Student RANK:");
                scanf("%d",&student_rank);
                getchar();
                if(fp==NULL) printf("ERROR can't open the file.\n");
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.rank==student_rank)
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tAre you sure you want delete this student(y/n)?\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            BACKUPS_STABILIZER(info,"backups.txt");
                        }
                        else
                        {
                            found=2;
                            fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
            break;
    
            case 3:
            {
                printf("\n\t\tEnter Student NAME:");
                gets(student_name);
                CORRECT_NAME(student_name);
                if(fp==NULL) printf("ERROR can't open the file.\n");
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(!strcmp(info.name,student_name))
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tAre you sure you want delete this student(y/n)?\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            BACKUPS_STABILIZER(info,"backups.txt");
                        }
                        else
                        {
                            found=2;
                            fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
        break;
    
            case 4:
            {
                printf("\n\t\tEnter Student TOTAL SCORE:");
                scanf("%f",&student_totalscore);
                getchar();
                if(fp==NULL) printf("ERROR can't open the file.\n");
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.total_score==student_totalscore)
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\tAre you sure you want delete this student(y/n)?\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            BACKUPS_STABILIZER(info,"backups.txt");
                        }
                        else
                        {
                            found=2;
                            fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp);
                }
            }
        break;
    
            default:
            {
                found=2;
                printf("\n\t\tChoice invalid.\n");
                fgets(buffer,200,fp);
                while(!feof(fp))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    fgets(buffer,200,fp);
                }
            }
    
    }
        fclose(fp);
        fclose(fp2);
        if(!found)
        {
            printf("\n\t\tStudent Not found.\n");
        } 
        else if(found==1)
        {
            printf("\n\t\tStudent deleted successfully.\n");
        } 
        remove("projectC.txt");
        rename("temp.txt","projectC.txt");
        COUNT_NUMBER_OF_STUDENT();
        RANK_OF_STUDENT();
    }
}

void RETRIEVED()
{
    FILE *fp1,*fp2;
    struct student info;
    int found=0,student_id,student_rank,choice;
    float student_totalscore;
    char student_name[25],buffer[200],typeofenter[14],choice2;
    printf("\n\n\n\t\t\t============RETRIEVE STUDENT============\n\n");
    fp1=fopen("backups.txt","r");
    if(fp1==NULL)
    {
        printf("\t\tERROR can't open the file.\n");
        fclose(fp1);
    }
    else
    {
        fp2=fopen("temp.txt","a");
        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
        fgets(buffer,200,fp1);
        while(!feof(fp1))
        {
            sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
            printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
            fgets(buffer,200,fp1);
        }
        fseek(fp1,0,SEEK_SET);
        printf("\n\n\t\t\t1-Retrieve by student ID\n\t\t\t2-Retrieve by student NAME\n\t\t\t3-Retrieve by student TOTAL SCORE\n\t\t\t4-Retrieve by student RANK\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                strcpy(typeofenter,"ID");
                printf("\n\t\t\tEnter student ID:");
                scanf("%d",&student_id);
                getchar();
                fgets(buffer,200,fp1);
                while(!feof(fp1))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.id==student_id)
                    {
                        found=1;
                        BACKUPS_STABILIZER(info,"projectC.txt");
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp1);
                }
            }
            break;
            case 2:
            {
                strcpy(typeofenter,"NAME");
                printf("\n\t\t\tEnter student NAME:");
                gets(student_name);
                CORRECT_NAME(student_name);
                fgets(buffer,200,fp1);
                while(!feof(fp1))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(!strncmp(info.name,student_name,sizeof(student_name)))
                    {
                        found=1;
                        BACKUPS_STABILIZER(info,"projectC.txt");
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp1);
                }
            }
            break;
            case 3:
            {
                strcpy(typeofenter,"TOTAL SCORE");
                printf("\n\t\t\tEnter student TOTAL SCORE:");
                scanf("%f",&student_totalscore);
                getchar();
                fgets(buffer,200,fp1);
                while(!feof(fp1))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.total_score==student_totalscore)
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\t Is this the student you want to modify?(y/n)\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            BACKUPS_STABILIZER(info,"projectC.txt");
                        }
                        else
                        {
                            fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp1);
                }
            }
            break;
            case 4:
            {
                strcpy(typeofenter,"RANK");
                printf("\n\t\t\tEnter student RANK:");
                scanf("%d",&student_rank);
                getchar();
                fgets(buffer,200,fp1);
                while(!feof(fp1))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    if(info.rank==student_rank)
                    {
                        printf("%-12s%-25s%-10s%-12s%-12s%-12s%-12s%-12s%-12s%-5s\n","StudentID","name","sex","chinese","math","english","physic","chemistry","total","rank");
                        printf("%-12d%-25s%-10c%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-12.2lf%-5d\n",info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        printf("\n\t\t\t Is this the student you want to modify?(y/n)\n\t\t");
                        scanf("%c",&choice2);
                        getchar();
                        if(choice2=='y'||choice2=='Y')
                        {
                            found=1;
                            BACKUPS_STABILIZER(info,"projectC.txt");
                        }
                        else
                        {
                            fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                        }
                    }
                    else
                    {
                        fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    }
                    fgets(buffer,200,fp1);
                }
            }
            break;
            default:
            {
                found=2;
                printf("\n\t\t\tChoice invalid.\n");
                fgets(buffer,200,fp1);
                while(!feof(fp1))
                {
                    sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                    fprintf_s(fp2,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                    fgets(buffer,200,fp1);
                }
            }
        }
        fclose(fp1);
        fclose(fp2);
        remove("backups.txt");
        rename("temp.txt","backups.txt");
        if(!found) printf("\n\t\t\tThe %s not in the list.\n",typeofenter);
        else if(found==1) printf("\n\t\t\tStudent backup successfully\n");
        RANK_OF_STUDENT();
    }
}

//stabilizer functions

void COUNT_NUMBER_OF_STUDENT()
{
    FILE *fp;
    struct student info;
    char buffer[200];
    NUMBER_OF_STUDENT=0;
    fp=fopen("projectC.txt","r");
    if(fp!=NULL)
    {
        fgets(buffer,200,fp);
        while(!feof(fp))
        {
            sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
            NUMBER_OF_STUDENT++;
            fgets(buffer,200,fp);
        }
    }
    fclose(fp);
}

void CORRECT_NAME(char *namec)
{
    int i,t;
    char b,a[200];
    strcpy(a,namec);
    do
    {
        i=0,t=0;
        while(a[i])
        {
            if(a[i]==32&&a[i+1]==32)
            {
                t++;
                for(int j=i;a[j];j++) a[j]=a[j+1];
            }
            i++;
        }

    }while(t!=0);
    if(a[0]==32)
    {
        for(int j=0;a[j];j++) a[j]=a[j+1];
    }

    if(a[0]>=97&&a[0]<=122) a[0]-=32;
    i=0;
    while(a[i])
    {
        if(a[i]==32)
        {
            if(a[i+1]>=97&&a[i+1]<=122) a[i+1]-=32;
            else if(a[i+1]==0) a[i]=0;
            else if(a[i+1]==136) a[i+1]=203;
            else if(a[i+1]==143) a[i+1]=233;
            else if(a[i+1]==142) a[i+1]=131;
            else if(a[i+1]==157) a[i+1]=244;
            else if(a[i+1]==141) a[i+1]=130;
        }
        else if(a[i]!=32)
        {
            if(a[i+1]>=65&&a[i+1]<=90) a[i+1]+=32;
            else if(a[i+1]==203) a[i+1]=136;
            else if(a[i+1]==233) a[i+1]=143;
            else if(a[i+1]==131) a[i+1]=142;
            else if(a[i+1]==244) a[i+1]=157;
            else if(a[i+1]==130) a[i+1]=141;
        }
        i++;
    }
    strcpy(namec,a);
}

void RANK_OF_STUDENT()
{
    COUNT_NUMBER_OF_STUDENT();
    if(NUMBER_OF_STUDENT>1)
    {
        FILE *fp,*fp1;
        fp=fopen("projectC.txt","r");
        fp1=fopen("temp.txt","a");
        char buffer[200];
        int c=0,d;
        struct student info;
        float b;
        struct ranking
        {
            int sid;
            float ts;
        }a[NUMBER_OF_STUDENT];
        fgets( buffer, 200, fp);
        while(!feof(fp))    
        {
            sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
            a[c].sid=info.id;
            a[c].ts=info.total_score;
            c++;
            fgets( buffer, 200, fp);
        }
        for(int i=0;i<NUMBER_OF_STUDENT;i++)    
        {
            for(int j=i;j<NUMBER_OF_STUDENT;j++)
            {
                if(a[j].ts>a[i].ts)
                {
                    b=a[i].ts;
                    a[i].ts=a[j].ts;
                    a[j].ts=b;
                    d=a[i].sid;
                    a[i].sid=a[j].sid;
                    a[j].sid=d;
                }
            }
        }
        for(int i=0;i<NUMBER_OF_STUDENT;i++)    
        {
            fseek(fp,0,SEEK_SET);
            fgets( buffer, 200, fp);
            while(!feof(fp))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                if(info.total_score==a[i].ts&&info.id==a[i].sid)
                {
                    info.rank=i+1;
                    fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                }
                fgets( buffer, 200, fp);
            }
        }
        fclose(fp);
        fclose(fp1);
        remove("projectC.txt");
        rename("temp.txt","projectC.txt");
    }
}

void ID_OF_STUDENT()
{
    COUNT_NUMBER_OF_STUDENT();
    if(NUMBER_OF_STUDENT>1)
    {
        FILE *fp,*fp1;
        fp=fopen("projectC.txt","r");
        fp1=fopen("temp.txt","a");
        struct student info;
        int k=0;
        int a[NUMBER_OF_STUDENT],b;
        char buffer[200];
        fgets(buffer,200,fp);
        while(!feof(fp))
        {
            sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
            a[k]=info.id;
            k++;
            fgets(buffer,200,fp);
        }
        for(int i=0;i<NUMBER_OF_STUDENT;i++)
        {
            for(int j=i;j<NUMBER_OF_STUDENT;j++)
            {
                if(a[j]<a[i])
                {
                    b=a[i];
                    a[i]=a[j];
                    a[j]=b;
                }
            }
        }
        for(int i=0;i<NUMBER_OF_STUDENT;i++)
        {
            fseek(fp,0,SEEK_SET);
            fgets(buffer,200,fp);
            while(!feof(fp))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                if(info.id==a[i])
                {
                    fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                }
                fgets(buffer,200,fp);
            }
        }
        fclose(fp);
        fclose(fp1);
        remove("projectC.txt");
        rename("temp.txt","projectC.txt");
    }
}

void CHECK_IF_EXIST(int ch_id,char* ch_name,const char* ch_fname,int* ch_result)
{
    FILE *fp3;
    *ch_result=1;
    struct student info;
    fp3=fopen(ch_fname,"r");
    if(fp3!=NULL)
    {
        char buffer[200];
        fseek(fp3,0,SEEK_SET);
        fgets(buffer,200,fp3);
        while(!feof(fp3))
        {
            sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
            if(info.id==ch_id||!strcmp(info.name,ch_name))
            {
                *ch_result=0;
            }
            fgets(buffer,200,fp3);
        }
    }

    fclose(fp3);
}

void BACKUPS_STABILIZER(struct student stdp ,const char* bs_fname)
{
    struct student info;
    int valid;
    char buffer[200];
    CHECK_IF_EXIST(stdp.id,stdp.name,bs_fname,&valid);
    if(valid)
    {
        FILE *fp5;
        fp5=fopen(bs_fname,"a");
        fprintf_s(fp5,STUDENT_FORMAT_IN,stdp.id,stdp.name,stdp.sex,stdp.score[Chinese],stdp.score[Math],stdp.score[English],stdp.score[Physics],stdp.score[Chemistry],stdp.total_score,stdp.rank);
        fclose(fp5);
    }
    else if(!valid)
    {
        FILE *fp5,*fp6;
        fp5=fopen(bs_fname,"r");
        fp6=fopen("temp1.txt","a");
        fseek(fp5,0,SEEK_SET);
        fgets(buffer,200,fp5);
        while(!feof(fp5))
        {
            sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
            if(!strcmp(info.name,stdp.name)||info.id==stdp.id)
            {
                fprintf_s(fp6,STUDENT_FORMAT_IN,stdp.id,stdp.name,stdp.sex,stdp.score[Chinese],stdp.score[Math],stdp.score[English],stdp.score[Physics],stdp.score[Chemistry],stdp.total_score,stdp.rank);
            }
            else
            {
                fprintf_s(fp6,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
            }
            fgets(buffer,200,fp5);
        }
        fclose(fp5);
        fclose(fp6);
        remove(bs_fname);
        rename("temp1.txt",bs_fname);
    }
}

void DATA_SECURE(int status)
{
    FILE *fp,*fp1,*fp2,*fp3;
    struct student info;
    char buffer[200];
    if(status)
    {
        fp=fopen("20210950_STD_INFO.txt","r");
        fp2=fopen("20210950_BACKUPS.txt","r");
        if(fp!=NULL&&fp2!=NULL)
        {
            fp1=fopen("projectC.txt","w");
            fp3=fopen("backups.txt","w");
            fseek(fp,0,SEEK_SET);
            fgets(buffer,200,fp);
            while(!feof(fp))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                fgets(buffer,200,fp);
            }   
            fseek(fp2,0,SEEK_SET);
            fgets(buffer,200,fp2);
            while(!feof(fp2))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                fprintf_s(fp3,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                fgets(buffer,200,fp2);
            }   
            fclose(fp1);
            fclose(fp3);
        }
        fclose(fp);
        fclose(fp2);
    }
    if(!status)
    {
        fp=fopen("projectC.txt","r");
        fp2=fopen("backups.txt","r");
        if(fp!=NULL&&fp2!=NULL)
        {
            fp1=fopen("20210950_STD_INFO.txt","w");
            fp3=fopen("20210950_BACKUPS.txt","w");
            fseek(fp,0,SEEK_SET);
            fgets(buffer,200,fp);
            while(!feof(fp))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                fprintf_s(fp1,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                fgets(buffer,200,fp);
            }   
            fseek(fp2,0,SEEK_SET);
            fgets(buffer,200,fp2);
            while(!feof(fp2))
            {
                sscanf(buffer,STUDENT_FORMAT_OUT,&info.id,&info.name,&info.sex,&info.score[Chinese],&info.score[Math],&info.score[English],&info.score[Physics],&info.score[Chemistry],&info.total_score,&info.rank);
                fprintf_s(fp3,STUDENT_FORMAT_IN,info.id,info.name,info.sex,info.score[Chinese],info.score[Math],info.score[English],info.score[Physics],info.score[Chemistry],info.total_score,info.rank);
                fgets(buffer,200,fp2);
            }   
            fclose(fp1);
            fclose(fp3);
        }
        fclose(fp);
        fclose(fp2);
        remove("projectC.txt");
        remove("backups.txt");
    }
}