// /d/hz/hongyuchi.c �յ�
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short",HIM"�յ�"NOR);
        set("long", @LONG
�������յ�֮�ϣ������ο��������ﲻ�����������������ַǷ����յ�
��ɫ��ʱ��ͬ��������죬�������Դ�����ɫ����������ʱ������������
ɫ���ˣ���֦����������ѿ���������������Ϸ��������˷��ա��������
���ޣ���ϼ���أ����������������н����⡣�������ں�ɽ֮�䣬������ʫ
�黭�⡣�յ̵������ǻ��۹���,������һ����ʯ�������������һ��С�š�
LONG
        );
	set("objects",([
		__DIR__"npc/you" : 2,
	]));
	set("exits", ([
		"south" : __DIR__"hggyu",
		"west" : __DIR__"yingboqiao",
		"north" : __DIR__"qsddao2",
		"east" : __DIR__"kuahong",
	]));
	set("outdoors", "����");
	setup();
}
