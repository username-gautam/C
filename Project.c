#include <stdio.h>

char name[100][30];
char party[100][20];
int votes[100] = {0};
int n = 0;

void registerCandidate()
{
    printf("\nEnter candidate name: ");
    scanf("%s", name[n]);

    printf("Enter candidate party: ");
    scanf("%s", party[n]);

    printf("Candidate Registered Successfully!\n");
    n++;
}

void castVote()
{
    int i, vote;

    if(n == 0)
    {
        printf("No candidates registered!\n");
        return;
    }

    printf("\n--- Candidate List ---\n");

    for(i = 0; i < n; i++)
    {
        printf("%d. %s (%s)\n", i + 1, name[i], party[i]);
    }

    printf("Enter candidate number: ");
    scanf("%d", &vote);

    if(vote >= 1 && vote <= n)
    {
        votes[vote - 1]++;
        printf("Vote Cast Successfully!\n");
    }
    else
    {
        printf("Invalid Candidate Number!\n");
    }
}

void countVotes()
{
    int i;

    printf("\n--- Vote Counting ---\n");

    for(i = 0; i < n; i++)
    {
        printf("%s (%s): %d Votes\n", name[i], party[i], votes[i]);
    }
}

void declareWinner()
{
    int i, max = 0, winner = 0;

    if(n == 0)
    {
        printf("No candidates registered!\n");
        return;
    }

    for(i = 0; i < n; i++)
    {
        if(votes[i] > max)
        {
            max = votes[i];
            winner = i;
        }
    }

    if(max == 0)
    {
        printf("No votes have been cast yet!\n");
        return;
    }

    printf("\n===== WINNER =====\n");
    printf("Candidate: %s\n", name[winner]);
    printf("Party: %s\n", party[winner]);
    printf("Total Votes: %d\n", max);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== ELECTRONIC VOTING SYSTEM =====\n");
        printf("1. Candidate Registration\n");
        printf("2. Cast Vote\n");
        printf("3. Vote Counting\n");
        printf("4. Winner Declaration\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                registerCandidate();
                break;

            case 2:
                castVote();
                break;

            case 3:
                countVotes();
                break;

            case 4:
                declareWinner();
                break;

            case 5:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}
