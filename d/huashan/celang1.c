// Room: /d/huashan/celang1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǻ�ɽ�����õĲ���, ׯ�Ϲ���, ���Է����Ӱ��ɽ����������һ��
ɽ�ط�⡣������ǻ�ɽ���ӵ����䳡�ˡ�
LONG
        );
        set("exits", ([
		"west" : __DIR__"lianwu1",
		"east" : __DIR__"qianting",
	]));

	set("outdoors", "��ɽ" );

	set("coor/x",70);
  set("coor/y",-10);
   set("coor/z",80);
   setup();
}
