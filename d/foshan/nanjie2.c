// Room: /d/fuoshan/nanjie2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ�Ͻ�");
	set("long", @LONG
����һ����������ʯ��·��������һ���������С�������һ��С
�Ե꣬ר��һЩ��ɽ���ز�С�ԡ�������Ƿ�ɽ�����ˡ�
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"alleyway",
  "west" : __DIR__"noshery",
  "north" : __DIR__"nanjie",
  "south" : __DIR__"nanmen",
]));

	set("coor/x",0);
  set("coor/y",-560);
   set("coor/z",0);
   setup();
}
