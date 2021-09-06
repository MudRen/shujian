// Room: /d/city/ximen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ţ���ǽ�����ż���ͨ����ʾ(gaoshi)��������������ıؾ�֮
�أ��ٱ��ǽ䱸ɭ�ϡ�һ����ֱ����ʯ���������������졣�����ǽ��⣬
����ġ����εġ���·�ģ����˴Ҵҡ������ǳ��������֡�
LONG
	);
	set("outdoors", "����");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"wroad1",
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
	write(CHINESE_D->get_title("����֪����ʾ","�Գ�֮"));
	return FINGER_D->get_killer() + "\n";
}
