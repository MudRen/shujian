// Room: /d/fuzhou/minzhai.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һ����լ�����е�ǽ���з�����������һ���������ˡ��������з���
������д�ţ������綫������ˮ���ٱ���ɽ�����ɡ���������һ�Ű���������
��̫ʦ�Σ����������˸ոճ�ȥ���ã������ϵĲ軹���µġ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"xixiang",
	]));

	set("outdoors", "����");
	setup();
}
