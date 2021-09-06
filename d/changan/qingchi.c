// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/qingchi.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "���");
	set("long", @LONG
�����ǳ����ǵ���ء��ذ����Ϻõ�̴��ľ���⻬���Դ���ʪ�������ǽ
�ڹ����˷�ɵĻ�����ɢ�������˵������������绨�����СѾ������æµ��
�����⣬һ���޴����ͭ�׼����һ��ϣ�Ѿ�������������ļ�����Ȫˮ��
LONG
        );
        set("no_fight", 1); 

        set("exits", ([
                "east" : __DIR__"fengchi",
                "west" : __DIR__"longchi",
                "north": __DIR__"eastjie2",
        ]));

	set("objects", ([
		__DIR__"npc/xiaoyahuan" : 1,
	]));

	set("item_desc",([            
		"east" : "���������ܴ���ʲôҲ��������\n",
		"west" : "���������ܴ���ʲôҲ��������\n",
	])); 

        set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir != "north" && me->query_conditions_by_type("poison"))
		return notify_fail("���������о綾��ȥϴ�裬������Σ��Ŷ��\n");
	if ( dir != "north" && is_wanted(me))
		return 0;
	if ((dir == "east" || dir == "west" )&& me->query_temp("pay_wash") < 1) {
		return notify_fail("СѾ��һ����ס��˵������Ҫ��Ǯ�İ���һ���ƽ𣡡�\n");
	}
	if ((dir == "west" && me->query("gender") == "Ů��")
	||(dir == "east" && me->query("gender") != "Ů��")) {
		return notify_fail("СѾ��һ����ס��˵�������ߴ��ˣ�������ǣ���\n");
        }
	return ::valid_leave(me,dir);
}
