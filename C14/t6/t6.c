#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 33
#define MAX_PLS 19

struct name {
	char fname[SIZE];
	char lname[SIZE];
};

struct stat {
	int get_b;
	int hits;
	int walks;
	int run_scored;
};
	
struct player {
	int num; //0-18
	struct name fl;
	struct stat st;
	float avg; //hits / walks
};

struct team {
	char team_name[SIZE];
	int num_of_players;
	struct player players[MAX_PLS];
	struct stat team_stat;
	float team_avg;
};

void init_team_players(struct player team[], int n);
void init_team(struct team* p_team);
void prepare_file(FILE** fp);
void get_file_name(char* file_name, int n);
void open_file(FILE**fp, char* file_name);
void close_file(FILE** fp);
void get_data_from_file(FILE** fp, struct team* p_team, int n);
void calc_avg_all(struct player team[], int n);
void calc_avg_player(struct player* p_plr);
void calc_avg_team(struct team* p_team, int n);
void print_all_players(const struct player team[], int num_of_players, int n);
void print_player(const struct player* p_plr);
void print_team_data(const struct team* p_team);
void eat_space(FILE** fp);
char* s_gets(char* st, int n);


int main(void) {
	struct team team1 = {
		.team_name = "Capitoshka",
	};
	FILE* fp;
	prepare_file(&fp); //Либо файл будет открыт, либо будет совершён выход из программы
	init_team(&team1);
	init_team_players(team1.players, MAX_PLS);
	get_data_from_file(&fp, &team1, MAX_PLS);
	calc_avg_all(team1.players, MAX_PLS);
	calc_avg_team(&team1, MAX_PLS);
	print_team_data(&team1);
	print_all_players(team1.players, team1.num_of_players, MAX_PLS);
	close_file(&fp);
	printf("-- Работа программы завершена.\n");
	return 0;
}


void init_team_players(struct player team[], int n) {
	for (int i = 0; i < n; ++i)
		team[i] = (struct player) {-1, {"", ""}, {0, 0, 0, 0}, 0};
}

void init_team(struct team* p_team) {
	p_team->team_stat.get_b = 0;
	p_team->team_stat.hits = 0;
	p_team->team_stat.walks = 0;
	p_team->team_stat.run_scored = 0;
	p_team->team_avg = 0;
}

void prepare_file(FILE** fp) {
	char file_name[SIZE];
	get_file_name(file_name, SIZE);
	open_file(fp, file_name);
}

void get_file_name(char* file_name, int n) {
	printf("-- Введите название файла с данными: ");
	while (s_gets(file_name, n) == NULL)
		printf("-- Получено NULL, введите правильное название файла: ");
}

void open_file(FILE**fp, char* file_name) {
	if ((*fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "-- Ошибка при открытии файла %s.\n", file_name);
		exit(EXIT_FAILURE);
	}
}

void close_file(FILE** fp) {
	if (fclose(*fp) != 0) {
		fprintf(stderr, "ОШибка при закрытии файла с данными.\n");
		exit(EXIT_FAILURE);
	}
}

void get_data_from_file(FILE** fp, struct team* p_team, int n) {
	int num, get_b, hits, walks, run_scored;
	int count_new_player = 0;
	while (fscanf(*fp, "%d", &num) == 1 && num >= 0 && num <= 18) {
		if (p_team->players[num].num == -1) {
			p_team->players[num].num = num;
			if (++count_new_player > MAX_PLS) {
				--count_new_player;
				break;
			}	
			if (fscanf(*fp, " %s %s ", 
				  p_team->players[num].fl.fname, p_team->players[num].fl.lname) != 2) 
			{
				fprintf(stderr, "Ошибка в формате файла.\n");
				exit(EXIT_FAILURE);
			}
		} else
			fscanf(*fp, " %*s %*s "); //Не нужно копировать повторно строковые данные, если игрок уже внесён в базу
		if (fscanf(*fp, "%d %d %d %d", &get_b, &hits, &walks, &run_scored) != 4) {
			fprintf(stderr, "Ошибка в формате файла.\n");
			exit(EXIT_FAILURE);
		}
		p_team->players[num].st.get_b += get_b;
		p_team->players[num].st.hits += hits;
		p_team->players[num].st.walks += walks;
		p_team->players[num].st.run_scored += run_scored;
	}
	p_team->num_of_players = count_new_player;
	rewind(*fp);
}

void print_player(const struct player* p_plr) {
	if (p_plr->num == -1)
		return;
	printf("-- %d: %s %s\n", p_plr->num, p_plr->fl.fname, p_plr->fl.lname);
	printf("   Get balls:   %d\n", p_plr->st.get_b);
	printf("   Hits:        %d\n", p_plr->st.hits);
	printf("   Walks:       %d\n", p_plr->st.walks);
	printf("   Runs scored: %d\n", p_plr->st.run_scored);
	printf("   AVG:         %.2f\n", p_plr->avg);
	putchar('\n');
}

void print_all_players(const struct player team[], int num_of_players, int n) {
	printf("-- Информация о %d/%d игроках:\n", num_of_players, n);
	for (int i = 0; i < n; ++i)
		print_player(&team[i]);
}

void print_team_data(const struct team* p_team) {
	printf("-- Данные команды %s:\n", p_team->team_name);
	printf("   Get balls:   %d\n", p_team->team_stat.get_b);
	printf("   Hits:        %d\n", p_team->team_stat.hits);
	printf("   Walks:       %d\n", p_team->team_stat.walks);
	printf("   Runs scored: %d\n", p_team->team_stat.run_scored);
	printf("   AVG:         %.2f\n", p_team->team_avg);
	putchar('\n');
}

void calc_avg_all(struct player team[], int n) {
	printf("-- Провожу расчёт средних значений...\n");
	for (int i = 0; i < n; ++i)
		calc_avg_player(&team[i]);
	putchar('\n');
}

void calc_avg_player(struct player* p_plr) {
	if (p_plr->st.run_scored != 0)
		p_plr->avg = (float) p_plr->st.hits / p_plr->st.run_scored;
}

void calc_avg_team(struct team* p_team, int n) {
	for (int i = 0; i < n; ++i) {
		p_team->team_stat.get_b += p_team->players[i].st.get_b;
		p_team->team_stat.hits += p_team->players[i].st.hits;
		p_team->team_stat.walks += p_team->players[i].st.walks;
		p_team->team_stat.run_scored += p_team->players[i].st.run_scored;
		p_team->team_avg += p_team->players[i].avg;
	}
}

void eat_space(FILE** fp) {
	char ch = getc(*fp);
	if (ch != ' ')
		ungetc(ch, *fp);
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
