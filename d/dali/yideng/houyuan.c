// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��Ժ��Ժ");
	set("long", @LONG
����һ�������СԺ������Сɳ����æ�Ŵ�ɨ���棬��Ժ����ǳ�������
�����������������и����ţ�һ����ʯ·���۵�ͨ��ǰ����
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"west" : __DIR__"chufang",
		"south" : __DIR__"dadian",
		"east" : __DIR__"liangong",
		"northwest" : __DIR__"xiaojing1",
	]));

	setup();
}
