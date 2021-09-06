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
                return notify_fail("找不到这个生物.\n");
        }

        message_vision(HIY "$N高举双手大喝：去死吧！\n"
                "\n" HIW
                "只见晴天一道闪电．．．．．．\n"
                "\n" BLU
                "         ———————\n" HIC
                "               /\n"
                "              /\n"
                "             /\n"
                "             ——\n"
                "                /\n"
                "               /\n"
                "              /\n"
                "\n" HIB
                "不偏不倚地击中$n, 将$n化为一堆灰烬。\n" NOR, me, ob);
	if (wiz_level(me) < wiz_level(ob))
        {
                message_vision(HIM "\n$N" HIM "身上冒着缕缕青烟，"
                                       "却没有半点事情。\n\n" NOR,
                                       ob);
                return 1;
        }
        ob->set_temp("last_damage_from", "被闪电劈");
        ob->die();

        write( HIG "哈哈哈，哈哈哈... 好爽，爽！爽！爽！\n\n" NOR );
        
        EMOTE_D->do_emote(me, "innocent", me->query("id"));

        return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
hehehehehe...........

HELP
   );
   return 1;
}
