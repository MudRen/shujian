// count.c

#include <ansi.h>
#define SYNTAX  "ָ���ʽ��count [all | a-z]\n"

inherit F_CLEAN_UP;

private int do_count_players(string letter);

int main(object me, string arg)
{
	if (me != this_player(1) || wiz_level(me) < wiz_level("(arch)"))
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

	if( !arg )
		return notify_fail(SYNTAX);
	
	if( arg != "all" ){
		if( arg[0] < 'a' || arg[0] > 'z' )
			return notify_fail(SYNTAX);
	}
	
	return do_count_players(arg);

	return 1;
}

private int do_count_players(string letter)
{
	int i, j, k = 0, x = 0;
	string *dir, name;
	mixed *info;

	seteuid(getuid());
	write("\n*** ������Ҵ��浵�У����Ժ�.... ***\n");
	
	if( letter == "all" ){
		dir = get_dir(DATA_DIR + "login/");
	
		for(i=0; i<sizeof(dir); i++) {
			reset_eval_cost();
			x = 0;
			info = get_dir(DATA_DIR + "login/" + dir[i] + "/", -1);
			j = sizeof(info);
			while (j--) {
				if (sscanf(info[j][0]+"$", "%s.o$", name)==1 ) 
					x++;
			}
			k += x;
			write(" " + dir[i] + " : " + x + " λ��\n");
			flush_messages();
		}
		write("\n\n�ܹ��� " + k + " λʹ���ߡ�\n");
	}
	
	else {
		info = get_dir(DATA_DIR + "login/" + letter + "/", -1);
		j = sizeof(info);
		while (j--) {
			if (sscanf(info[j][0]+"$", "%s.o$", name)==1 ) 
				k++;
		}
		write("\n�� " + letter + " ��ĸ��ͷ���ܹ��� " + k + " λʹ���ߡ�\n");
	}
	
	return 1;
}
