// Room: /d/chengdu/guandim.c �ص���
// Build by Lklv@SJ 2001.9.28

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"�ص���"NOR);
	set("long", @LONG
����һ���ưܵĹص�����ǰ��������ʢ��������Ϊ�����˻���������
���ˣ���û��ʲô�������㡣������֪������������һȺ�л��ӣ���������Ϊ
ҹ����Ϣ�İ���֮��������������ؤ��Ĵ��Ƿֶ档������һ����������ʯ
�����ͨ�����⡣
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"houyuan",
	]));

        set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
                CLASS_D("gaibang/quan") : 1,
                CLASS_D("gaibang/lichunlai") : 1,
        ]));

	set("incity",1);
	setup();
}
