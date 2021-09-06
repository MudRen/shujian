// Room: /d/village/caidi.c
// Date: Look 99/07/18

#include <room.h>
inherit ROOM;

void create()
{
       set("short","�˵�");
       set("long", @LONG
�����ǻ�ɽ����������Ϊ���Ĳ˵أ��տ���һƬ����һ��������ͷ������
�����ţ���Ȼ��������ʱ��·�ˡ�
LONG
     );

	set("exits", ([
		"west" : __FILE__,
		"east" : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	setup();
}

void init()
{
	object ob;
	int jingli;

	ob = this_player();
	jingli = ob->query("jingli");

        ob->add("jingli", -random(40));
        if(jingli < 50)
		ob->unconcious();
        ob->add_busy(random(1));
}

int valid_leave(object me, string dir)
{
	if (random(10) < 6)
		me->add_temp("mark/����",1);
	if (random(10) > 8)
		me->add_temp("mark/����",-1); 
        
	if (me->query_temp("mark/����") > 9)
	{
		me->move(__DIR__"zhongxin");
		me->delete_temp("mark/����");
		return notify_fail("��������һͨ����Ȼ�����Լ��߻���ԭ�ء�\n");
	}  

	return ::valid_leave(me, dir);
}
