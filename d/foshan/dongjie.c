// Room: dongjie.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
������Ƿ�ɽ���֣�������һ���ӻ��̣������߾��Ƿ�ɽ�㳡�ˡ���
��������Ƿ�ɽ�㳡���ܶ��˶�����ȥ���������������������Ƚ����֡�
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ 
            "east" : __DIR__"dongjie2",
            "north" : __DIR__"grocer",
            "west" : __DIR__"guangchang",
]));

	set("no_clean_up", 0);
	set("coor/x",10);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}
