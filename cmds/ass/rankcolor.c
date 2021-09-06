// rankcolor.c
//

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object ob;
        string color;
        //if( me != this_player() ) return 0;
        if( !arg || sscanf(arg, "%s %s", ob, color) != 2 )
                return notify_fail("����Ϊ˭����ʲô��ɫ��\n");
        if(!(ob = present(ob, environment(me))) )
                return notify_fail("û������� ��\n");
        if( wiz_level(me) < wiz_level(ob) )
               return notify_fail("��û������Ȩ����\n");
        ob->set("rankcolor",color);
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : rankcolor <id, color>
 
���ָ���������޸�rank����ɫ��Ŀǰ���޸ĵ���ɫ�У�
BLK - ��ɫ              NOR - �ָ�������ɫ
RED - ��ɫ              HIR - ����ɫ
GRN - ��ɫ              HIG - ����ɫ
YEL - ����ɫ    HIY - ��ɫ
BLU - ����ɫ    HIB - ��ɫ
MAG - ǳ��ɫ    HIM - �ۺ�ɫ
CYN - ����ɫ    HIC - ����ɫ
WHT - ǳ��ɫ    HIW - ��ɫ
HELP
        );
        return 1;
}

