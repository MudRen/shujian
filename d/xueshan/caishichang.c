// Room: caishichang.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�����ƽ̹�Ĳ�ԭͻȻ¡��һ����ɽ�����²���һ�Ѷ�ɢ�����ʯ��ɽ��
����Զ�Ϳ�������ƹƹ���ҵ�������ԭ�������Ǹ���ʯ��������ʮ������������
�󴸴�ʯͷ����Զ��С����վ�Ÿ�������������ǡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"tianyunmc",
		"eastdown" : __DIR__"cunluo1",
	]));
        set("objects", ([__DIR__"npc/seleng" : 1,]));
        set("outdoors", "ѩɽ");
	set("coor/x",-210);
  set("coor/y",150);
   set("coor/z",0);
   setup();
}
