// Room: /d/huashan/celang2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǻ�ɽ�����õĲ���, ׯ�Ϲ���, ���Է����Ӱ��ɽ����������һ��
ɽ�ط�⡣�������ߣ����ǻ�ɽ���ӵ����䳡�ˡ�
LONG
        );
        set("exits", ([
		"east" : __DIR__"lianwu2",
		"west" : __DIR__"qianting",
	]));

	set("no_clean_up", 0);
	set("indoors", "��ɽ" );

	set("coor/x",90);
  set("coor/y",-10);
   set("coor/z",80);
   setup();
}