#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long",@long
������һ��С��԰����̫�������������������������滨�ܣ���ֻ����
��������Ϯ����
    ������һ��ʯ��·�������ȥ�����������ȣ��������Ϳɼ�����
ʥ�ã���������Сʯ�ţ��羰��Ҳ����
long);
	set("exits",([
		"north" : __DIR__"shilu1",
		"south" : __DIR__"lang1",
		"west" : __DIR__"shiqiao",
		"east" : __DIR__"lang",
	]));
	set("outdoors", "����");
	setup();
}
