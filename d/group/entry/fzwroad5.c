// Room: /d/fuzhou/wroad5.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ����һ��ɽ·��ʱֵ���գ�·�Ե�ɽ���ϵ��������˽��ɫ��
�Ͳ˻���һ����ɽ�紵�����������������Ͳ˻�����ζ���ɴ������Ϸ���ɽ�
�����㣬�������ɵ����ݡ�
LONG
	);

	set("exits", ([
		"southwest" : "/d/fuzhou/wroad6",
		"east" : "/d/fuzhou/wroad4",
	]));
	set("group", 1);
	set("outdoors", "���ݳ�");
	setup();
}
