// emei ��ľ��

#include <room.h>
inherit ROOM;

int do_zong(string arg);

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
������һƬһ�˶�ߵĹ�ľ�ԣ������Ѿ������㼣��һ��紵������ľ��
����ɳɳ�������������������ǰ�����ľ������û��·��ÿ��һ������������
���̵��¿㣬����������塣ǰ����һ��ܸߵ��ͱڣ���Լ���ƺ�������һ��
����Ķ��ڣ��ͱ�������һ��ˮ̶��
LONG
	);

	set("exits", ([
		"westup" : __DIR__"houshangm",
	]));

	set("outdoors", "��üɽ");
	setup();
}

void init()
{
	add_action("do_zong", ({"zong", "yue"}));
}

int do_zong(string arg)
{
	object me=this_player();

	if (!arg && arg != "�ͱ�" && arg != "����" )
		return notify_fail("��Ҫ��ʲô��\n");

	if ( random((int)me->query("jingli")) >= 100 
	|| me->query("family/master_id") == "guhong zi") {
		message_vision("$Nһ�������ͱڵĶ���Ծȥ��\n", me);
		me->move(__DIR__"houshandk");
	}
	else {
		message_vision("$Nһ�������ͱڵĶ���Ծȥ�����һ����С�ģ�ˤ����ˮ̶��\n", me);
		me->move(__DIR__"shuitan");
		me->set("water", 555);
		me->unconcious();
	}
	return 1;
} 
