#include <ansi.h>
#define X 5
#define Y 5
#define S 1
int help(object me);

int main(object me)
{
	help(me);
	return 1;
}

int help(object me)
{
	int y, x, lvl, exp, mylvl = me->query("max_pot")-101, start;
	string str;
	int i,j,p;

	write("�ȼ��;���������ձ�\n");
	start = mylvl - X * Y / 2;
	if (start < 0)
		start = 0;
	for (y = 1; y <= Y; y++) {
		str = "";
		for (x = 0; x < X; x++) {
			lvl = (y + x * Y) * S - 1 + start;
			exp = lvl * lvl * lvl / 10;
			if (lvl > mylvl && lvl <= mylvl + S)
				str += HIY;
			str += sprintf("%3d %8d", lvl + 1, exp);
			if (lvl > mylvl && lvl <= mylvl + S)
				str += NOR;
			if (x < X-1)
				str += " | ";
		}
		write(str + "\n");
	}
	i = uptime()-me->query_temp("time");
	tell_object(me,"����������"
		+ CHINESE_D->chinese_time(i) + "��\n");
	j = me->query("combat_exp") - me->query_temp("combat_exp") + me->query_temp("onhook_exp");
	p = me->query("combat_exp") - me->query_temp("combat_exp");
	tell_object(me, "����ֵ"
		+(j<0?"������" + (-j) + "��": j > 0?"������" + j +"��":"û�б䶯")+"��\n");
	
	tell_object(me, "ʵս��ȡ�ľ���ֵ"
		+(p<0?"������" + (-p) + "��": p > 0?"������" + p +"��":"û�б䶯")+"��\n");		
			
	if(i!=0)
	{
		j = j*60/i;
		j = j*60;
		if(j!=0) tell_object(me,"ÿСʱ"+(j>0?"���ʣ�":"����")+(j>0?chinese_number(j):chinese_number(-j))+"�㾭�顣\n");
	}
	
	if(me->query("registered") > 2) ;
	else write("�������ٽ羭��ֵ��"+me->query("mud_age")/6+"\n");

				

				
	return 1;
}