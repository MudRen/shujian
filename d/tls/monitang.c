#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"Ĳ����"NOR);
        set("long",@LONG
���������¸�ɮ�ǵľ���֮����ȫ����ľ���ƣ�����ľ����ľ�Ͼ���ȥ
Ƥ����Ȼ���ӣ���һ·������̻Ի͵ĵ��ý�Ȼ��ͬ�����������Ϸ�������
�������ü���Ϻ��С�
LONG
        );
        set("exits", ([
		"out": __DIR__"lang2",
	]));
	set("objects",([
		__DIR__"npc/ben-guan" : 1,
		__DIR__"npc/ben-xiang" : 1,
		__DIR__"npc/ben-can" : 1,
        ]));
        setup();
}
