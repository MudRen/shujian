// Room: /d/fuzhou/beimen.c
// lklv modify 2001.9.10

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ����׸����ݵı��š���������Ͽɵ����ݸ�������ɽ�򣬳�����
�򱱿ɵֽ���һ�������ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
                "north" : __DIR__"road5",
                "south" : __DIR__"beijie",
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
	return FINGER_D->get_killer() + "\n����Ѳ��\nĳĳĳ\n";
}
