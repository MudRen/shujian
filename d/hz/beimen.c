// /d/hz/beimen.c ����

#include <ansi.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short",HIY"����"NOR);
	set("long", @LONG
������Ǻ��ݳǵı����ˣ��׻�˵���������ã������պ���Ľ��������
�ο����ﲻ������վ�ڳ��ſڰ��صĹٱ���Ҳϸϸ�̲�������οͣ�������
�߹�������æ��ǰ�̲顣���ſ�����һ�Ÿ�ʾ(gaoshi)��
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits",([
                  "north" : "/d/group/entry/hzqsd7",
                  "south" : __DIR__"qsddao6",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("outdoors", "����");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n����\n";
}

