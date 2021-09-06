// Room: /city/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ��
��ֱ����ʯ���������������죬�����ǳ��
LONG
	);
        set("outdoors", "����");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
	//	"east" : "",
        //	"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie2",
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
