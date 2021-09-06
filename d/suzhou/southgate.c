// Room: /city/nanmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�����ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬
�ٸ��ĸ�ʾ(gaoshi)��˲�̫��Ŀ���ٱ��Ǳ������Ļ���Ц�����������ƺ�
���Ǻ�������ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣
LONG
	);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("outdoors", "����");
	set("exits",([
		"north" : __DIR__"nandajie2",
		"south" : __DIR__"qsgdao2",
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
