// /d/chengdu/dabeimen.c
// By Jpei

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ǳɶ��ı������ˡ��ɶ��ش����У�һ������ս�����ţ����Ժ���
������ʿ�������ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
                "north" : __DIR__"road4",
		"south" : __DIR__"beidajie4",
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

