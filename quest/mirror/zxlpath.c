// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����¥����");
	set("long", @LONG
��������¥���ã������������˿ͺ�����С�������������������
�̶��ĺ����������������������������������ַǷ����������������
ǰ�����Ž��ĸ��ո����֣�����ʳ��
������õ���������ϵ���ĵ����������ܽ������
LONG);
	set("exits", ([
        "east"   : __DIR__"meigui",
        "north"  : __DIR__"furong",
        "south"  : __DIR__"mudan",
        "west"   : __DIR__"zuixianlou2",
	]));
        setup();
}
//�Ǿ���
int is_mirror() { return 1; }

