//haitan.c
//wzfeng

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��̲");
	set("long", @LONG
�����Ƕ���֮����һ��С��̲��������ȥ��һƬ�޼ʵĵ�ãã�󺣣�Զ��
����һ�ߣ�������������ֻ��Ÿ�ں��Ϸ��衣��̲������ϡϡ�������һЩ��
����Ϊïʢ����ľ(tree)��
LONG
);
	set("exits", ([
		"southwest" : __DIR__"xiaolu",
//		"southeast" : __DIR__"haitan1",
	]));

	set("sld_boat", 1);

	set("objects",([
		__DIR__"npc/shangren" : 1,
	]));
	set ("item_desc", ([
		"tree":"һЩ������Ϊïʢ����ľ������Կ�(chop)��\n",  
	]));
	set("outdoors", "����");
	setup();
}

void init()
{
	add_action("do_kan", "chop");
}

int do_kan(string arg)
{
	object me,weapon1,wood;
	me = this_player();
	
	if( !arg || arg=="" ) return 0;
	
	if(arg!="tree")
		return notify_fail("��Ҫ��ʲô��\n");

	if(!(weapon1=me->query_temp("weapon")))
		return notify_fail("�����û�����������ֿ���\n");

        if( weapon1->query("flag") != 4 )
                return notify_fail("��������������޷����У�����ܿ�������\n");

	if(present("mu tou", environment(me)))
		return notify_fail("���ﲻ���Ѿ���ľͷ���𣿲�Ҫ���⿳����ľ!!!\n");

	message_vision( HIR "ֻ��$N���һ��������������������$n"HIR"����Χ����ľ��ȥ ....\n" NOR, me,weapon1);
	message_vision( HIR "ֻ�������ꡱһ������Χ�ļ��ô����ѱ�$N��$n"HIR"���ɼ��ء�\n"NOR,me,weapon1);
	wood = new(__DIR__"npc/obj/mutou");
        wood->move(environment(me));
        return 1;
}
