// Room: /d/xingxiu/jyge.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
���Ǿ������ݵ��ϳ��š��������ͽ����ˣ�����о���פ������ʱ������
�����ˡ���С�����������뿪���Ƿ�֮�ء��������ϣ���ͨ�������Ĵ����
���ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG);

	set("outdoors", "����");

	set("exits", ([
		"north" : __DIR__"lanzhou",
		"south" : __DIR__"sroad1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\nȫ��ͨ����\n";
}
