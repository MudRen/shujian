// more.c

#include <ansi.h>

nosave string *text;
nosave int size;
nosave int width;

private void more(string cmd, int line)
{
	int i;

	write(REST+ESC+"[K");
	switch(cmd) {
		case "q":
			write("\n");
			return;
		case "b":
			line -= 46;
			if (line < 1) line = 1;
		default:
			for (i=line + 23; line <= size && line < i; line++) {
				if (size > 23)
					write(sprintf("%*d:", width, line));
				write(sprintf(" %s\n", text[line-1]));
			}
			if (line > size) return;
	}
	write(sprintf(SAVEC+"== ��ʣ "HIY"%*d"NOR" �� == (ENTER ������һҳ��q �뿪��b ǰһҳ)"+ESC+"[A",
		width, size - line + 1)
	);
	input_to((:more:), 3, line);
}

void start_more(string msg)
{
	if (!stringp(msg)) return;
	write("\n"+SAVEC);
	text = explode(msg, "\n");
	size = sizeof(text);
	width = strlen(size+"");
	more("", 1);
}
