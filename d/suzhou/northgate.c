// ���ݱ���
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǳ����ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں����ģ���˰�ֽ����
�Ĺٸ���ʾ(gaoshi)���Ե��ر����ۡ�������һƬ��ɽ���룬һ������С��
��ɽ�����Ѷ��ϡ�
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits",([
		"north" : __DIR__"qsgdao6",
		"west" : __DIR__"bingying.c",
		"south" : __DIR__"beidajie2",
	]));
	set("objects", ([
		NPC_D("guanfu/wujiang") : 1,
		NPC_D("guanfu/bing") : 2,
	]));
	set("outdoors", "����");
	set("incity",1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��֪��\n";
}
