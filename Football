#include <stdio.h>

// Structure for basketball team
struct basketball_team {
    char name[50];
    int victories;
    int losses;
    int turnovers;
    int rebounds_recovered;
    char best_scorer_name[50];
    int best_scorer_3_pointers;
};

// Structure for soccer team
struct soccer_team {
    char name[50];
    int victories;
    int losses;
    int draws;
    int goals_for;
    int goals_against;
    char goal_scorer_name[50];
    int goal_scorer_goals;
};

int main() {
    struct basketball_team b_team;
    struct soccer_team s_team;
    
    // Input for basketball team
    printf("Enter basketball team information:\n");
    printf("Name: ");
    scanf("%s", &b_team.name);
    printf("Number of victories: ");
    scanf("%d", &b_team.victories);
    printf("Number of losses: ");
    scanf("%d", &b_team.losses);
    printf("Number of turnovers: ");
    scanf("%d", &b_team.turnovers);
    printf("Number of rebounds recovered: ");
    scanf("%d", &b_team.rebounds_recovered);
    printf("Name of the best 3-point scorer: ");
    scanf("%s", &b_team.best_scorer_name);
    printf("Number of 3-pointers for the best scorer: ");
    scanf("%d", &b_team.best_scorer_3_pointers);
    
    // Input for soccer team
    printf("\nEnter soccer team information:\n");
    printf("Name: ");
    scanf("%s", &s_team.name);
    printf("Number of victories: ");
    scanf("%d", &s_team.victories);
    printf("Number of losses: ");
    scanf("%d", &s_team.losses);
    printf("Number of draws: ");
    scanf("%d", &s_team.draws);
    printf("Number of goals for: ");
    scanf("%d", &s_team.goals_for);
    printf("Number of goals against: ");
    scanf("%d", &s_team.goals_against);
    printf("Name of the team's goalscorer: ");
    scanf("%s", &s_team.goal_scorer_name);
    printf("Number of goals of the goalscorer: ");
    scanf("%d", &s_team.goal_scorer_goals);
    
    // Displaying basketball team results
    printf("\nBasketball team results:\n");
    printf("Name: %s\n", b_team.name);
    printf("Number of victories: %d\n", b_team.victories);
    printf("Number of losses: %d\n", b_team.losses);
    printf("Number of turnovers: %d\n", b_team.turnovers);
    printf("Number of rebounds recovered: %d\n", b_team.rebounds_recovered);
    printf("Best 3-point scorer: %s (%d 3-pointers)\n", b_team.best_scorer_name, b_team.best_scorer_3_pointers);
    
    // Displaying soccer team results
    printf("\nSoccer team results:\n");
    printf("Name: %s\n", s_team.name);
    printf("Number of victories: %d\n", s_team.victories);
    printf("Number of losses: %d\n", s_team.losses);
    printf("Number of draws: %d\n", s_team.draws);
    printf("Number of goals for: %d\n", s_team.goals_for);
    printf("Number of goals against: %d\n", s_team.goals_against);
    printf("Team's goalscorer: %s (%d goals)\n", s_team.goal_scorer_name, s_team.goal_scorer_goals);
    return 0;
} 