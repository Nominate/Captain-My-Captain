#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int choice = 0;
    printf("Captain. My Captain.  What are you interested in?\n");
    printf("1) Outings\n");
    printf("2) Land Training\n");
    printf("3) Crews\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        outings();
    else if (choice == 2)
        land_training();
    else if (choice == 3)
        crews();
    else
        printf("That wasn't a valid selection\n");
    return 0;
}

int outings(){
    int choice = 0;
    printf("What would you like to do?\n");
    printf("1) View Outings\n");
    printf("2) Edit Outings\n");
    printf("3) Schedule Outings\n");
    printf("4) Cancel Outings\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        view_outings();
    else if (choice == 2)
        edit_outings();
    else if (choice == 3)
        schedule_outings();
    else if (choice == 4)
        cancel_outings();
    else
        printf("That wasn't a valid selection\n");
    return 0;
}

int view_outings(){
    int choice = 0;
    printf("Which outings would you like to view?\n");
    printf("1) All outings\n");
    printf("2) All of M1's outings\n");
    printf("3) All of M2's outings\n");
    printf("4) All of M3's outings\n");
    printf("5) All of M4's outings\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        print_outings("ALL");
    else if (choice == 2)
        print_outings("M1");
    else if (choice == 3)
        print_outings("M2");
    else if (choice == 4)
        print_outings("M3");
    else if (choice == 5)
        print_outings("M4");
    else
        printf("That wasn't a valid selection\n");
    return 0;
}



int print_outings(char crew[3]){
    int correct = 1;
    FILE * fh;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fh = fopen("outings.dat", "r");
    if (fh == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fh)) != -1) {
        if ((line[0] != '#') && (line[0] != '\n') && (line[0] != '/'))
            if (crew[1] == line[27])
                printf("%s", line);
            else if (crew[0] == 'A')
                printf("%s", line);
    }
    if (line)
        free(line);
    return 0;
}

int edit_outings(){
    int choice = 0;
    printf("Which outing would you like to edit?\n");
    printf("1) Show me all outings\n");
    printf("2) Show me M1's outings\n");
    printf("3) Show me M2's outings\n");
    printf("4) Show me M3's outings\n");
    printf("5) Show me M4's outings\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        change_outings("ALL");
    else if (choice == 2)
        change_outings("M1");
    else if (choice == 3)
        change_outings("M2");
    else if (choice == 4)
        change_outings("M3");
    else if (choice == 5)
        change_outings("M4");
    else
        printf("That wasn't a valid selection\n");
    return 0;
}

int change_outings(char crew[3]){
    int choice;
    char lines[100][35];
    int positions[100];
    int i = 0;
    int correct = 1;
    FILE * fh;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fh = fopen("outings.dat", "r");
    if (fh == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fh)) != -1) {
        if ((line[0] != '#') && (line[0] != '\n') && (line[0] != '/'))
        {
            if (crew[1] == line[27]){
                printf("%d: ", i);
                printf("%s", line);
                positions[i] = ("%1d", ftell(fh));
                strcpy(lines[i], line);
                ++i;
            }
            else if (crew[0] == 'A'){
                printf("%d: ", i);
                printf("%s", line);
                positions[i] = ("%1d", ftell(fh));
                strcpy(lines[i], line);
                ++i;
            }
        }
    }
    if (line)
        free(line);
    printf("Which outing would you like to edit?\n");
    fscanf(stdin, "%d", &choice);
    if (choice >= i)
        printf("That's not a valid selection\n");
    else
    {
        char day[6];
        char start_time[4];
        char finish_time[4];
        char location[4];
        char crew[2];
        
        printf(lines[choice]);
        FILE * pFile;
        pFile = fopen ("outings.dat" , "rb+");
        fseek (pFile , positions[choice] - 30, SEEK_SET);
        printf("Please enter the day this outing will occur on: ");
        fscanf(stdin, "%s", &day);
        fputs (day , pFile);
        fputs ("; " , pFile);
        printf("Please enter the start time in 24h format without a colon: ");
        fscanf(stdin, "%s", &start_time);
        fputs (start_time , pFile);
        fputs ("; " , pFile);
        printf("Please enter your finish time in 24h format without a colon: ");
        fscanf(stdin, "%s", &finish_time);
        fputs (finish_time , pFile);
        fputs ("; " , pFile);
        printf("Please enter the location for this outing: ");
        fscanf(stdin, "%s", &location);
        fputs (location , pFile);
        fputs ("; " , pFile);
        printf("Please enter which crew this outing is for: ");
        fscanf(stdin, "%s", &crew);
        fputs (crew , pFile);
        fputs (";\n" , pFile);
        fclose (pFile);
        i = 0;
        //replace(mystr, lines[choice], '*')
    }
    return 0;
}

int schedule_outings(){
    printf("");
    printf("");
    return 0;

}

int cancel_outings(){

    return 0;

}

int land_training(){
    int choice = 0;
    printf("What would you like to do?\n");
    printf("1) View planned land training\n");
    printf("2) Edit land training\n");
    printf("3) Schedule land training\n");
    printf("4) Cancel land traing\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        view_land_training();
    else if (choice == 2)
        edit_land_training();
    else if (choice == 3)
        schedule_land_training();
    else if (choice == 4)
        cancel_land_training();
    else
        printf("That wasn't a valid selection\n");
    return 0;
}


int view_land_training(){
    return 0;
}
int edit_land_training(){
    return 0;
}
int schedule_land_training(){
    return 0;
}
int cancel_land_training(){
    return 0;
}

int crews(){
    int choice = 0;
    printf("What would you like to do?\n");
    printf("1) View crews\n");
    printf("2) Edit crews\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        view_crews();
    else if (choice == 2)
        edit_crews();
    else
        printf("That wasn't a valid selection\n");
    return 0;
}

int view_crews(){
    int choice = 0;
    printf("Which crews are you interested in?\n");
    printf("1) All\n");
    printf("2) M1\n");
    printf("3) M2\n");
    printf("4) M3\n");
    printf("5) M4\n");
    printf("Please make a selection: ");
    fscanf(stdin, "%d", &choice);
    if (choice == 1)
        print_crews("ALL");
    else if (choice == 2)
        print_crews("M1");
    else if (choice == 3)
        print_crews("M2");
    else if (choice == 4)
        print_crews("M3");
    else if (choice == 5)
        print_crews("M4");
    else
        printf("That wasn't a valid selection\n");
    return 0;
}

int print_crews(char crew[3]){
    int i = 0;
    char * seat = NULL;
    int correct = 1;
    FILE * fh;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fh = fopen("crews.dat", "r");
    if (fh == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fh)) != -1) {
        if (crew != "ALL")
        {
            if (line[0] == '#')
            {
                if (line[2] == 'E')
                {
                    correct = 1;
                }
                else if (line[3] == crew[1])
                {
                    correct = 0;
                    i = 0;
                    printf("\nM%c\n", crew[1]);
                }
            }
        }
        else
        {
            if ((line[3] == '1') || (line[3] == '2') 
                || (line[3] == '3') || (line[3] == '4'))
            {
                printf("\nM%c\n", line[3]);
            }
            correct = 0;
        }
        if (correct == 0)
            if ((line[0] != '#') && (line[0] != '\n') && (line[0] != '/'))
            {
                if (i == 0)
                    seat = "Cox";
                else if (i == 1)
                    seat = "Stroke";
                else if (i == 2)
                    seat = "Seven";
                else if (i == 3)
                    seat = "Six";
                else if (i == 4)
                    seat = "Five";
                else if (i == 5)
                    seat = "Four";
                else if (i == 6)
                    seat = "Three";
                else if (i == 7)
                    seat = "Two";
                else if (i == 8)
                    seat = "Bow";
                else if (i == 9)
                    seat = "\nCoach";
                printf("%s: %s", seat, line);
                ++i;
                if (i == 10)
                    i = 0;
            }
    }

    if (line)
        free(line);
    else
        printf("This crew doesn't exist");
    return 0;
}


int edit_crews(){
    return 0;
}
