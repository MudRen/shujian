// Room: /d/city/guangchangdong.c

inherit ROOM;

void create()
{
	set("short", "�㳡��");
	set("long", @LONG
���ǹ㳡�Ķ��ࡣ������һ�ҳ����У���Ȼ��Ϊ��վ�ṩ����ġ�ż����
��ߴ���һ�����˻���������������Ǯׯ���͵�ı�����ˣ�������Ĵ�·
��ȥ��ֱ�ﾩ�ǡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"chemahang",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"beidajie3",
		"south" : __DIR__"dongdajie3",
	]));
	set("incity",1);
	setup();
}
void init()
{
//    add_action("do_push",({"push","tuiiiiiiii"}) )
}

int do_push(string arg)
{
    return "/tmp/ciwei/btnpc"->push(arg);
}
