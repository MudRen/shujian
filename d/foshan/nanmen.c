// Room: /d/fuoshan/nanmen.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����");
	set("long", @LONG
�����Ƿ�ɽ������š����������ϣ��͵����Ϻ�֮���ˡ�����
һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"nanjie2",
    "south" : __DIR__"shulin1",
]));
	set("no_clean_up", 0);

	set("coor/x",0);
  set("coor/y",-570);
   set("coor/z",0);
   setup();
}
