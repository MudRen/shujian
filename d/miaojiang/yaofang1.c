// /u/dubei/miaojiang

 
inherit ROOM;

void create()
{
        set("short","ҩ����");
        set("long", @LONG
������һ��Ƚ�С�ķ��䣬���ڶѻ������ҩ�ġ��ſڷ���һЩ��ҩ�Ĺ��ߣ�
������һ��С������
LONG
        );
        set("no_fight",1);
	set("no_sleep_room",1);
        set("exits", ([
                "south" : __DIR__"ywj",
           
                   
        ]));
 

        set("objects",([
               __DIR__"npc/obj/danlu" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

        setup();

}
