// Room: /d/fuzhou/wroad3.c
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
		"southwest" : __DIR__"wroad4",
		"northeast" : __DIR__"wroad2",
	]));

	set("outdoors", "����");
	setup();
}
