inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ���
��ϡ�٣������ĵغ������塣�����ǲ���ͤ�ͱ����ţ��ϱ��Ǳ�Ӫ�����߾�
�������ˡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
              "northeast" : __DIR__"canglangting",
              "southeast" : __DIR__"baodaiqiao",
	      "south" : __DIR__"bingyindamen",
              "west" : __DIR__"xidajie2",
	      "north" : __DIR__"yamen",
	]));

	set("coor/x",100);
  set("coor/y",-210);
   set("coor/z",0);
   set("incity",1);
	setup();
}

