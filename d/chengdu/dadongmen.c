// /d/chengdu/dadongmen.c
// By Jpei

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ǳɶ��Ķ������ˡ��ɶ��ش����У�һ������ս�����š����ǳ�͢
����פ�����ر������ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
                "west" : __DIR__"ddajie4",
		"east" : __DIR__"eroad1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("outdoors", "�ɶ�");
	set("incity",1);
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n���ݴ�ʷ\n˾��Զ\n";
}
