// Room: /u/xdd/gumu/xiaolu2
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIG"����С��"NOR);
     set("long", @LONG
����ɽ�µ�С��������ȫ���ƽ�����������ɽ��ȫ���ɵ������������죬
����һ�����������ٰ��ճ��������Ҳ����������ʿ������䡣���ϱ�������
�㳡��
LONG        );

	set("outdoors","��Ĺ");

	set("exits", ([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"xiaolu3",
		"southeast" : "/d/group/entry/gmchang",
	]));
	setup();
}
