#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# include <signal.h>

typedef struct struct_node {
    unsigned int int_value;     // field_0
    unsigned int padding;       // padding (offset 4)
    struct struct_node *next;   // field_8
} struct_node;

FILE *infile;
int num_input_strings = 0;
char input_string[1360];
int n1[8] = { 36, 134525716, 134525704, 0, 0, 0, 0, 0 };
char array_phase_5[16] = { 105, 115, 114, 118, 101, 97, 119, 104, 111, 98, 112, 110, 117, 116, 102, 103 };

struct_node node6 = { .int_value = 0x1b0, .next = NULL };
struct_node node5 = { .int_value = 0xd4, .next = &node6 };
struct_node node4 = { .int_value = 0x3e5, .next = &node5 };
struct_node node3 = { .int_value = 0x12d, .next = &node4 };
struct_node node2 = { .int_value = 0x2d5, .next = &node3 };
struct_node node1 = { .int_value = 0xfd, .next = &node2 };
void secret_phase(void);

void sig_handler()
{
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");
  sleep(3);
  printf("Well...");
  fflush(stdout);
  sleep(1);
  printf("OK. :-)\n");
  exit(16);
}

void initialize_bomb(void)
{
  signal(2,sig_handler);
  return;
}

void explode_bomb()
{
  printf("\nBOOM!!!\n");
  printf("The bomb has blown up.\n");
  exit(8);
}

int fun7(int *a1, int a2)
{
  if ( !a1 )
    return -1;
  if ( a2 < *a1 )
    return 2 * fun7(a1[1], a2);
  if ( a2 == *a1 )
    return 0;
  return 2 * fun7(a1[2], a2) + 1;
}

void phase_defused()
{
  char v0;
  char v1[80];

  if ( num_input_strings == 6 )
  {
    if ( sscanf(input_string, "%d %s", &v0, v1) == 2 && !strings_not_equal(v1, "austinpowers") )
    {
      printf("Curses, you've found the secret phase!\n");
      printf("But finding it and solving it are quite different...\n");
      secret_phase();
    }
    printf("Congratulations! You've defused the bomb!\n");
  }
}

int blank_line(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while( 1 ) {
    if (cVar1 == '\0') {
      return 1;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if ((*(byte *)(__ctype_b + 1 + cVar1 * 2) & 0x20) == 0) break;
    cVar1 = *param_1;
  }
  return 0;
}

char *skip()
{
  char *v0;
  char *v1;

  while (v0 && blank_line(v0))
  {
    v0 = fgets((char *)(80 * num_input_strings + 134526592), 80, infile);
    v1 = v0;
  }
  return v1;
}

char *read_line()
{
  unsigned int v0;
  unsigned int v1;
  int v2;

  if ( !skip() )
  {
    if ( infile == stdin )
      goto LABEL_6;
    if ( getenv("GRADE_BOMB") )
      exit(0);
    infile = stdin;
    if ( !skip() )
    {
LABEL_6:
      printf("Error: Premature EOF on stdin\n");
      explode_bomb();
    }
  }
  v0 = strlen(&input_string[80 * num_input_strings]) + 1;
  v1 = v0 - 1;
  if ( v0 == 80 )
  {
    printf("Error: Input line too long\n");
    explode_bomb();
  }
  v2 = 80 * num_input_strings;
  byte_804B67F[v1 + v2] = 0;
  ++num_input_strings;
  return v2 + 134526592;
}


void read_six_numbers(char *param_1, int *param_2)
{
  int iVar1;
  
  iVar1 = sscanf(param_1,"%d %d %d %d %d %d",&param_2[0],&param_2[1],&param_2[2],&param_2[3],
                 &param_2[4],&param_2[5]);
  if (iVar1 < 6) {
    explode_bomb();
  }
  return;
}

void phase_1(char *a1)
{
  int result;

  result = strcmp(a1, "Public speaking is very easy.");
  if ( result )
    explode_bomb();
  return ;
}

void phase_2(char *param_1)
{
  int i;
  int aiStack_20 [7];
  
  read_six_numbers(param_1,aiStack_20);
  if (aiStack_20[1] != 1) {
    explode_bomb();
  }
  i = 1;
  do {
    if (aiStack_20[i + 1] != (i + 1) * aiStack_20[i]) {
      explode_bomb();
    }
    i = i + 1;
  } while (i < 6);
  return;
}

int phase_3(char *s)
{
  int result;
  char v2;
  int v3;
  char v4;
  int v5;

  if ( sscanf(s, "%d %c %d", &v3, &v4, &v5) <= 2 )
    explode_bomb();
  result = v3;
  switch ( v3 )
  {
    case 0:
      v2 = 113;
      if ( v5 != 777 )
        explode_bomb();
      return result;
    case 1:
      v2 = 98;
      if ( v5 != 214 )
        explode_bomb();
      return result;
    case 2:
      v2 = 98;
      if ( v5 != 755 )
        explode_bomb();
      return result;
    case 3:
      v2 = 107;
      if ( v5 != 251 )
        explode_bomb();
      return result;
    case 4:
      v2 = 111;
      if ( v5 != 160 )
        explode_bomb();
      return result;
    case 5:
      v2 = 116;
      if ( v5 != 458 )
        explode_bomb();
      return result;
    case 6:
      v2 = 118;
      if ( v5 != 780 )
        explode_bomb();
      return result;
    case 7:
      v2 = 98;
      if ( v5 != 524 )
        explode_bomb();
      return result;
    default:
      explode_bomb();
  }
  if ( v2 != v4 )
    explode_bomb();
  return result;
}

int func4(unsigned int a0)
{
    unsigned int v0;
    unsigned int v1;

    printf("a0=%d\n", a0);
    if (a0 <= 1)
        return 1;
    v0 = func4(a0 - 1);
    v1 = func4(a0 - 2) + v0;
    return v1;
}

void phase_4(char *str)
{
  int result;
  int number;

  if ( sscanf(str, "%d", &number) != 1 || number <= 0 )
    explode_bomb();
  result = func4(number);
  if ( result != 55 )
    explode_bomb();
  return ;
}

int phase_5(char *a1)
{
  int i;
  int result;
  char v3[8];

  if ( strlen(a1) != 6 )
    explode_bomb();
  for ( i = 0; i <= 5; ++i )
    v3[i] = array_phase_5[a1[i] & 0xF];
  v3[6] = 0;
  result = strcmp(v3, "giants");
  if ( result )
    explode_bomb();
  return result;
}

void phase_6(char *input_str)
{
    int j;
    struct_node *tmp_node;
    int i;
    struct_node *node;
    struct_node *local_34;          // tête de la nouvelle liste
    struct_node *tmp2_node;
    struct_node *tmp3_node;
    struct_node *selected[6];       // stocke 6 pointeurs sélectionnés
    int list_digit[6];

    node = &node1;
    printf("input_str: '%s'\n", input_str);
    read_six_numbers(input_str, list_digit);
    
    /* -------------------------------
       1) Vérification des 6 nombres
       ------------------------------- */
    printf("debug\n");
    i = 0;
    do {
        // les valeurs doivent être entre 1 et 6
        if (5 < list_digit[i] - 1) {
            explode_bomb();
        }
        // vérifier qu'aucune valeur n'est dupliquée
        j = i;
        while (++j < 6) {
            if (list_digit[i] == list_digit[j]) {
            explode_bomb();
            }
        }
    } while (++i < 6);
    printf("debug1\n");
    /* -------------------------------
       2) Récupérer le nœud n° list_digit[i]
       depuis la liste chainée node1 → node1->next → …
       ------------------------------- */
    for (i = 0; i < 6; ++i) {
        int steps = list_digit[i];
        tmp_node = node;            // commence à node1
        for (j = 1; j < steps; ++j) {
            if (tmp_node->next == NULL)
                explode_bomb();
            tmp_node = tmp_node->next;
        }
        selected[i] = tmp_node;     // stocke le pointeur, pas son adresse en int
    }
    printf("debug2\n");

    /* -------------------------------
       3) Rechaîner les nœuds dans l’ordre
       indiqué par selected[]
       ------------------------------- */
    
    local_34 = selected[0];

    i = 1;
    tmp3_node = local_34;
    do {
        // tmp2_node = (int *)local_30[i + -1];
        printf("selected[%d]=%d\n", i, selected[i]);
        tmp2_node = selected[i];
        tmp3_node->next = tmp2_node;
        tmp3_node = tmp2_node;
    } while (++i < 6);
    // tmp2_node[2] = 0;
    tmp2_node->next = NULL;

    /* -------------------------------
       4) Vérification : la liste doit être
       triée en valeur décroissante
       ------------------------------- */
    i = 0;
    do {
        if (local_34->int_value < local_34->next->int_value)
            explode_bomb();
        local_34 = local_34->next;
    } while (++i < 5);

    return;
}

void secret_phase(void)
{
  char *uVar1;
  int iVar2;
  
  uVar1 = read_line();
  iVar2 = strtol(uVar1, 0, 10);
  if (1000 < iVar2 - 1) {
    explode_bomb();
  }
  iVar2 = fun7(n1, iVar2);
  if (iVar2 != 7) {
    explode_bomb();
  }
  printf("Wow! You\'ve defused the secret stage!\n");
  phase_defused();
  return;
}

int main(int argc, const char **argv, const char **envp)
{
	char *input;

	if ( argc == 1 )
	{
		infile = stdin;
	}
	else
	{
		if ( argc != 2 )
		{
			printf("Usage: %s [<input_file>]\n", *argv);
			exit(8);
		}
		infile = fopen(argv[1], "r");
		if (!infile)
		{
			printf("%s: Error: Couldn't open %s\n", *argv, argv[1]);
			exit(8);
		}
	}
	initialize_bomb();
	printf("Welcome this is my little bomb !!!! You have 6 stages with\n");
	printf("only one life good luck !! Have a nice day!\n");
	input = read_line();
	phase_1(input);
	phase_defused();
	printf("Phase 1 defused. How about the next one?\n");
	input = read_line();
	phase_2(input);
	phase_defused();
	printf("That's number 2.  Keep going!\n");
	input = read_line();
	phase_3(input);
	phase_defused();
	printf("Halfway there!\n");
	input = read_line();
	phase_4(input);
	phase_defused();
	printf("So you got that one.  Try this one.\n");
	input = read_line();
	phase_5(input);
	phase_defused();
	printf("Good work!  On to the next...\n");
	input = read_line();
	phase_6(input);
	phase_defused();
	return 0;
}