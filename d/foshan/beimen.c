// Room: beimen.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
�����Ƿ�ɽ��ı��š��������򱱣���������ɴ���ԭ������
һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ 
            "south" : __DIR__"beijie",
            "north" : __DIR__"lingnan",
]));

	set("coor/x",0);
  set("coor/y",-510);
   set("coor/z",0);
   setup();
}
