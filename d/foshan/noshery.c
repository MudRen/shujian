// Room: /d/fuoshan/noshery.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "С�Ե�");
	set("long", @LONG
���Ƿ�ɽ�ǳ�������һ��С�Ե꣬ר����ɽ�������ز�С�ԣ��ܶ���
���������˺��οͶ�Ҫ�صظ�����һЩ�ز���һ�����ϰ�������к�����
�ˡ�
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nanjie2",
]));

        set("objects", ([
        __DIR__"npc/song" : 1,
]));

	set("no_clean_up", 0);

	set("coor/x",-10);
  set("coor/y",-560);
   set("coor/z",0);
   setup();
}
