#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	int max;
	int num;
	int *stk;
}Stack;
void initialize(Stack *s, int x)
{
	s->num = 0;
	if ((s->stk = calloc(x, sizeof(int))) == NULL)
		exit(EXIT_FAILURE);
	s->max = x;
}
void push(Stack *s, int c)
{
	s->stk[s->num++] = c;
}
char pop(Stack *s)
{
	return s->stk[--s->num];
}
bool is_empty(Stack *s)
{
	return s->num == 0;
}
void Terminate(Stack *s)
{
	free(s->stk);
}
void empty(Stack *s)
{
	s->max = s->num = 0;
}
char peek(Stack *s)
{
	return s->stk[s->num - 1];
}
int main(void)
{
	
	Stack s;
	int t;
	while (1)
	{
		char ch[102];
		initialize(&s, 101);
		t = 0;
		fgets(ch, 101, stdin);
		while (ch[t] != '.')
		{

			if (ch[t] == '(' || ch[t] == '[')
				push(&s, ch[t]);
			else if (ch[t] == ')')
			{
				if (!is_empty(&s))
				{
					char c;
					while (!is_empty(&s))
					{
						if ((c = peek(&s)) == '(')
							break;
						if (c == '['||c==']')
						{
							break;
						}

						pop(&s);
					}
				}
				if (is_empty(&s))
					push(&s, ch[t]);
				else if (peek(&s) == '[')
					push(&s, ch[t]);
				else
					pop(&s);
			}
			else if (ch[t] == ']')
			{
				if (!is_empty(&s)) {
					char c;
					while (!is_empty(&s))
					{
						if ((c = peek(&s)) == '[')
							break;
						if (c == '('||c==')')
						{
							break;
						}

						pop(&s);
					}
				}
				if (is_empty(&s))
					push(&s, ch[t]);
				else if (peek(&s) == '(')
					push(&s,ch[t]);
				else
					pop(&s);
			}
			else
				;
			t++;
		}
		if (t == 0)
			break;

		if (is_empty(&s))
			printf("YES\n");
		else
		{
			while (!is_empty(&s))
			{
				char k = pop(&s);
				if (k == '(' || k == ')' || k == '[' || k == ']')
				{
					printf("NO\n");
					break;
				}
				if (is_empty(&s))
					printf("YES\n");
			}
		}
		empty(&s);
	}

	Terminate(&s);
	return 0;
}
