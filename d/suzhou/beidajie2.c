inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣
�ϱ��Եúܷ�æ��������һ�������¥����Ϊ����¥��������һ�����֣�
������һ����ֱ�Ĵ�֣�ʮ�ַ�����
LONG
	);
        set("outdoors", "suzhou");

	set("exits", ([
		"east" : __DIR__"chunzailou",
		"south" : __DIR__"beidajie1",
                "west" : __DIR__"zijinan",
                "north" : __DIR__"northgate",
	]));

	set("coor/x",110);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}

