// Room: /d/fuzhou/wroad7.c
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
		"southwest" : __DIR__"wroad8",
		"northeast" : __DIR__"wroad6",
	]));

	set("outdoors", "����");
	setup();
}
