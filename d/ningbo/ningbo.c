// Room: /d/ningbo/ningbocheng.c ����

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", HIY"������"NOR);
	set("long", @LONG
�����������ǵĳ����ģ��������Ǳ����Ĵ�ǣ����������ϱ����ұ���֮
�أ�����פ�����ر���ʿ���ǳ��˸����̲��������������ˣ����������𸽽�
ɽ�ϵĲݿܡ����ű������Ÿ�ʾ(gaoshi)��д�Źٸ�ͨ�����ӷ�������һ�Ӷ�
�ٱ�����ȥȥ��һ��ɭ����������ĺ���������罻������Ҫͨ����
LONG
	);
        set("objects",([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("exits", ([
		"west" : __DIR__"ttcsi",
		"northwest" : __DIR__"aywsi",
		"south" : __DIR__"kedian",
		"east" : __DIR__"dongqianhu",
	]));
	set("outdoors", "����");
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����֪��\n";
}
