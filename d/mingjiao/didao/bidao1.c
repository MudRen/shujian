// /d/mingjiao/bidao1.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06

inherit ROOM;
void create()
{
       set("short","�ص����");
       set("long", @LONG
����һ���������µ��ص���ڡ����������˼������ݡ������������ۣ�
�������������������ǰ���͹͹��ʯ�ڡ�
LONG);
	set("exits", ([
		"out" : "/d/mingjiao/wxiang",
		"north" : __DIR__"bidao2",
	]));
        setup();
}
