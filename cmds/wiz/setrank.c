// rank.c
// by snowman@SJ 11/03/2000

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	
        if( !arg ) {
                write(RANK_D->query_rank(me)+me->short(1)+"\n");
                return 1;
        }
        
        if( strlen(arg) > 30 )
                return notify_fail("���ͷ��̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	if( sscanf(arg, "%s %s", arg, str)!=2 )
		return notify_fail("��Ҫ����ͷ�ε���һ�(rank, color, level, self_rude, self, rude, respect)\n");
		
	switch(arg){
		case "rank": 
		case "color":
		case "self_rude":
		case "self":
		case "rude":
		case "respect":
			me->set("rank_info/"+arg, str); break;
			
		case "level": if(intp(atoi(str)) )
				me->set("rank_info/level", atoi(str)); 
				break;
		default: return notify_fail("��Ҫ����ͷ�ε���һ�(rank, color, level, self_rude, self, rude, respect)\n");
	}

        write("�㽫ͷ�ε� "+arg+" �����Ϊ��"+str+"��\n");
        write(RANK_D->query_rank(me)+me->short(1)+"\n");
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : rank <��Ŀ> <�ִ�>
 
���ָ���������Ϊ�Լ��趨һ��ͷ�εĵȼ�����ɫ�ȡ�
HELP
        );
        return 1;
}
