// Room: beijie.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
�����Ƿ�ɽ�ı���֣������Ľֵ��ϳ�ˮ���������������������߾�
�Ƿ�ɽ�Ĺ㳡�ˣ������������У��ƺ�ʮ�����֡�
LONG
	);
        set("outdoors","��ɽ");
        set("exits", ([ 
            "south" : __DIR__"guangchang",
            "north" : __DIR__"beimen",
]));

	set("no_clean_up", 0);
	set("coor/x",0);
  set("coor/y",-520);
   set("coor/z",0);
   setup();
}
