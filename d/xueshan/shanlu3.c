// Room: shanlu3.c

inherit ROOM;

void create()
{
	set("short", "ǧ����");
	set("long", @LONG
����ɽ���𽥶��ͣ�ʯ��Ҳխ����࣬��·���Զ��Ǻ�ѹѹ�����֡����ǣ�
    ��������������������������б����
    �Ѻޱ�ɽ���������ɽ���������ڡ�
LONG
	);

	set("exits", ([
		"westdown" : __DIR__"shanlu4",
		"eastdown" : __DIR__"shanlu2",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-280);
  set("coor/y",150);
   set("coor/z",10);
   setup();
}
