// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
������·������ɭɭ���ľ��ޱȣ����˷��׾�����������Ϣ�Ÿ��������
������ת���������˵�ϲ����������������ʯ�ݡ�
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"north" : __DIR__"shiwu",
		"east" : __DIR__"xiaojing3",
	]));

	setup();
}
