// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "Сʯ��");
	set("long", @LONG
����������Ժ�ͺ�����һ��ʯ���š����±��̵ĺ�ˮ������΢����Զ����
�����ϴ���������������ߵ��������ź����ϴ�����΢��ʱ��ʱ��ҡ���š�
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"hetang",
	]));

	setup();
}
