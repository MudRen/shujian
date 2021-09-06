// Room: /d/city/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ݶ����ţ��������Ϸ����š����š�����������֣���ǽ������
���Źٸ��ĸ�ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ�ͨ�������С��Ϊ
�һ����ֱ����ʯ���������������졣�����ǽ��⣬��Լ�ɼ�һƬһ��
�޼ʵ����֣�����Ī�⡣
LONG
	);
        set("outdoors", "����");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/group/entry/yzeroad1",
		"south" : __DIR__"yzyunhe",
		"north" : "/d/zhiye/biaoju1",
		"northeast" : __DIR__"guandimiao",
		"west" : __DIR__"dongdajie0",
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
