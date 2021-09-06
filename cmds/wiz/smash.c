// smash.c

// Modified by mxzhao 

inherit F_CLEAN_UP;

#include <ansi.h>
#include <command.h>

int help(object me);
 
int main(object me, string arg)
{
        object ob;

        if (!arg)
        {
                return help(me);
        }

        ob = present(arg, environment(me));

        if (!ob)
        {
                return notify_fail("�Ҳ����������.\n");
        }

        message_vision(HIY "$N�߾�˫�ִ�ȣ�ȥ���ɣ�\n"
                "\n" HIW
                "ֻ������һ�����磮����������\n"
                "\n" BLU
                "         ��������������\n" HIC
                "               /\n"
                "              /\n"
                "             /\n"
                "             ����\n"
                "                /\n"
                "               /\n"
                "              /\n"
                "\n" HIB
                "��ƫ���еػ���$n, ��$n��Ϊһ�ѻҽ���\n" NOR, me, ob);
	if (wiz_level(me) < wiz_level(ob))
        {
                message_vision(HIM "\n$N" HIM "����ð���������̣�"
                                       "ȴû�а�����顣\n\n" NOR,
                                       ob);
                return 1;
        }
        ob->set_temp("last_damage_from", "��������");
        ob->die();

        write( HIG "��������������... ��ˬ��ˬ��ˬ��ˬ��\n\n" NOR );
        
        EMOTE_D->do_emote(me, "innocent", me->query("id"));

        return 1;
}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: smash <����>
 
hehehehehe...........

HELP
   );
   return 1;
}
