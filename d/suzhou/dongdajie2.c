inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�����������
�ǹٱ���ߺ������������һ�����ֺŵ�ҩ�̣��ϱ��Ǵ����̣�������������
����Զ����������
LONG
	);
        set("outdoors", "suzhou");
	set("exits", ([
		"east" : __DIR__"eastgate",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"dongdajie3",
 "north" : __DIR__"lichuntang",
                "northwest" : __DIR__"hutong2",
	]));

	set("coor/x",150);
  set("coor/y",-210);
   set("coor/z",0);
   set("incity",1);
	setup();
}

