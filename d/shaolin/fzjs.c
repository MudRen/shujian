// Room: /d/shaolin/fzjs.c
// Date: YZC 96/01/19

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIG"���ɾ���"NOR);
	set("long", @LONG
����ĵ�������������ŷ�����ʮ���Ʋ����ţ�������һ����ľ��̳��
��̳�Ϸ��Ÿ����Ƶ�ľ�㡣�����߸�����һ��������ۼ�Ĵ�ƿ���ϲ�̴��
��֦���������ƣ��뵷ҷ�������һƬ���֮�������������Ƿ��ɶ�ɮ�ڽ�
��˵���ĵط���
LONG
	);

	set("exits", ([
		"up" : __DIR__"fzjs1",
		"east" : __DIR__"xiaolu7",
	]));

	setup();
}