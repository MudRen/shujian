// Room: /d/chengdu/beidajie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��ı���֡�����ͨ�򱱳��ţ��ϱ��Եúܷ�æ��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"beidajie3",
		"south" : __DIR__"beidajie1",
		"west"	: "/d/zhiye/yaodian1",
		"east"	: "/d/zhiye/yaochang1",
	]));
	
	set("objects",([
		"/d/zhiye/npc/caiyao-ren" : 1,
	]));
	
	set("incity",1);
	setup();
}

