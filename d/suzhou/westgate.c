// Room: /city/ximen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���������
������ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ(gaoshi)��
�������ﷸ��������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�
һ����ֱ����ʯ���������������졣�����ǽ��⣬����ġ����εġ���
·�ģ����˴Ҵҡ���ӿ��˽Ų������¹ٱ��Ҳꡣ�����ǳ��
LONG
	);
        set("outdoors", "����");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits",([
		"west" : __DIR__"qsgdao3",
		"east" : __DIR__"xidajie2",
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
	return FINGER_D->get_killer() + "\n����֪��\n��֪��\n";
}
