// Cmd:  zhua.c
// Created by Numa 1999-12-10
// Add Log

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, obj;
        int runner;
        
        if (!arg)
                return notify_fail("ָ���ʽ�� zhua <ĳ��>��\n");
        if( sscanf(arg, "%s with %d", arg, runner) != 2 ) 
              runner = 3;
        	
        obj = present(arg, environment(me));
        if(!obj)
                obj = present(arg, me);
        if(!obj)
                obj = find_player(arg);
        if(!obj || !me->visible(obj))
                obj = find_object(resolve_path(me->query("cwd"), arg));
        if("me" == arg)
                obj = me;
               
        if(!obj)
                return notify_fail("�Ҳ���ָ���������\n");

        ob = new("/clone/npc/antirobot"+runner);
        ob->test_robot(obj);
        tell_object(me,HIY + obj->name(1)+HIY"("+capitalize(obj->query("id"))+")�Ѿ������ķԸ���ȥ����ˡ�\n");
        
	log_file("static/ROBOT",
		sprintf("%-8s%-8s �� %-8s(%-8s) ǿ��ִ�л����˼�顣\n",
			obj->query("name"),getuid(obj),me->query("name"),getuid(me)
		), obj, ({ me })
	);
			        
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : zhua <ĳ��> with <1|2|3>

��ָ���������ĳ����ҽ��ܻ����˳�顣
zhua xxx with 1-3 �����ֱ�ʾ���ĸ�antirobotȥ���ԡ�
HELP
    );
    return 1;
}

