//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ų���");
	set("long", @LONG
������һ�ιų��ǡ��ഫ�ǵ�����ʼ���������ĸ�������������ʮ����
���ޡ����±�Ǩ���׺�ɣ������������һƬ���棬Ψһ��ϡ�ɼ����Ǻ���
�Ƴɵķ��̨���С����һ�����������
LONG );
	set("exits", ([
		"west" : __DIR__"yinpanshui",
		"east" : __DIR__"shimen",
	]));

	set("outdoors", "����");
	setup();
}
