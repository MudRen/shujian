inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ��ţ�����ͨ��
���ϴ�ֵ����ĵضΣ�����������������������԰�������棬�����ݳǵ���
���š�
LONG
	);
        set("outdoors", "suzhou");

	set("exits", ([
		"east" : __DIR__"tingyuxuan",
		"south" : __DIR__"southgate",
		"west" : __DIR__"liuyuan",
		"north" : __DIR__"nandajie1",
	]));
        set("coor/x",110);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}

