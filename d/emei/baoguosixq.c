// Room: /d/emei/baoguosixq.c

inherit ROOM;

void create()
{
	set("short", "��������ǽ");
	set("long", @LONG
�����Ƕ�üɽ�����µ���ǽ����Ժ���������ǽ�Ǳ�Ʈ�����ڿ����л�
�졣һ��ɽϪ������ɽ�ϵĽ����������������ɽ����ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baoguosi",
]));

	set("coor/x",-200);
  set("coor/y",-120);
   set("coor/z",10);
   setup();
}
