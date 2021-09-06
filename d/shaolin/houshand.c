#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ��СС��ɽ��������û���κ���Ʒ�������Ϻ��з������ң�����ʯ
�ڣ���Ŀ����������տյ�������ֵ��ǵ��Ͼ�Ȼ����һС��ľм����֪����
ʲô��;��
LONG
        );

        set("exits", ([ 
		"out" : __DIR__"yading",
	]));

        set("objects",([ 
		"/kungfu/class/shaolin/wu-xiang" : 1,
	]));

        setup();
}

void init()
{
	add_action("do_bo", ({ "bo" }));
} 

int do_bo(string arg)
{
	object me=this_player();

	if( !me->query("wxz/done") )
		return 0;
	if( !arg || arg!="ľм" )
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");
	if( me->query_skill("wuxiang-zhi",1)>200 ) 
		return notify_fail("��о��Ѿ��޷�����������ľм����Լ������ָ����Ϊ�ˡ�\n");

	if(me->query("neili")<50) return notify_fail("�������������\n");
	if(me->query("jingli")<100) return notify_fail("��ľ���������\n");

	message_vision("$N˫�����䣬�����ľ������ϵ���ľмͻȻ������Ծ����������������һ�����ε�ϸ����������һ�㡣\n",me);
	me->add("neili",-50);
	me->add("jingli",-100);
	me->improve_skill("wuxiang-zhi", me->query_int());
	return 1;
}
