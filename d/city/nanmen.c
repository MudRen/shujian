// Room: /d/city/nanmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݵ��ϳ��ţ���ǽ������һ�Źٸ��ĸ�ʾ(gaoshi)�������ǻ��ε�
��ɢ�أ��������η��Ӻܶ࣬�����ٱ���������ؼ����������ˣ��鿴����
�Ƿ�Я����˽�Ρ��ϱߵ���ʯ�������һֱͨ��Զ��������������ͷ��
LONG
	);
        set("outdoors", "����");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south" : __DIR__"jiangbei",
                "north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("incity",1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n�Գ�֮\n";
}
