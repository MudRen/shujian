// Room: shanlu6.c

inherit ROOM;

void create()
{
	set("short", "ѩ���ŵ�");
	set("long", @LONG
   ���Կ�����������ɽ��
   ��ѩ���֣������ڵ��ߡ�
   �����ӹ�ͷ��������ֽУ������ڶ���
   ���޶������У����п��ӣ�ɱ���ķ���
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"shanlu7",
		"northwest" : __DIR__"shanlu5",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-280);
  set("coor/y",160);
   set("coor/z",20);
   setup();
}
