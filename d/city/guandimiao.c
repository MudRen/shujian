// Room: /d/city/guandimiao.c
// Date: Look 99/09/20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "�ص���" NOR);
	set("long", @LONG
�������ݳǶ����һ���ص�����˵ҹ�ﾭ�������ڴ˾������ƣ���ͨ��
���ǲ��������Ƿ�֮�صġ����������й���Ĺص����������������ֳ�������
�µ������Ҹ��ǹع��Ľ����ֵ��������ŷɣ�һ�����������ˣ��·�Ҫɱ����
�²���֮�ˡ�
LONG
	);
        set("indoors", "����");

	set("exits", ([
		"southwest" : __DIR__"dongmen",
	]));
//	set("objects", ([__DIR__"npc/linghuchong" : 1]));

	set("incity",1);
	setup();
}

void init()
{
	object me = this_player();
  	object weapon = me->query_temp("weapon");
	if (weapon){
		tell_object(me, YEL"�㿴���ص۵���������񣬴��˸���ս�����Խ��ķ��������еı�����\n"NOR);
		weapon->unequip();
	}
//	add_action("do_jiebai","jiebai");
}

/*
int do_jiebai(string arg)
{
	string arg1, arg2, arg3;
       	object me, ob1, ob2, ob3;
       	int i;

       	me = this_player();

       	if (!arg) return notify_fail("��ʽ��jiebai with <id> <id> <id>\n");
	i = sscanf(arg, "%s %s %s", arg1,arg2,arg3);
        if( i >= 0 && i <= 2 ){
        	if (!arg1) return notify_fail("��Ҫ��˭��ݣ�\n");
        	if (arg1){
			if (!(ob1 = present(arg1, environment(me))))
				return notify_fail("��Ҫ��ݵ��˲������\n");
			if (ob1==me )
				return notify_fail("�㲻�ܺ��Լ���ݡ�\n");
			if (!living(ob1)
                         || !ob1->is_character())
				return notify_fail("��Ҫ��˭��ݣ�\n");
		}
                if (arg2){
			if (!(ob2 = present(arg1, environment(me))))
				return notify_fail("��Ҫ��ݵ��˲������\n");
			if (ob2==me )
				return notify_fail("�㲻�ܺ��Լ���ݡ�\n");
			if (ob2==ob1)
				return notify_fail("���Ѿ�������"+arg2+"�����֣�����Ҫ�������Ρ�\n");
                	if (!living(ob2)
			 || !ob2->is_character())
				return notify_fail("��Ҫ��˭��ݣ�\n");
		}
                if (arg3){
			if (!(ob3 = present(arg1, environment(me))))
				return notify_fail("��Ҫ��ݵ��˲������\n");
			if (ob3==me)
				return notify_fail("�㲻�ܺ��Լ���ݡ�\n");
			if (ob3==ob1 || ob3==ob2)
				return notify_fail("���Ѿ�������"+arg3+"�����֣�����Ҫ�������Ρ�\n");
                	if (!living(ob3)
			 || !ob3->is_character())
				return notify_fail("��Ҫ��˭��ݣ�\n");
		}
        }
        else {
                return notify_fail("��ݵ����������Ƕ����ĸ���\n");
	}
	return notify_fail("Ŀǰ��"+(string)i+"����ݶ���"+arg1+arg2+arg3+"\n");
}
*/