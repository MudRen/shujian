// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������С��Ķ��棬��������������·��˵Ц��·����һЩ��֪����Ұ��
ɢ������������㡣
LONG
        );

        set("exits", ([
                 "southeast" : __DIR__"lianwuc",
                 "west" : __DIR__"jiedao3",
                 "east" : __DIR__"guoyuan", 
        ]));
        set("objects",([
//                __DIR__"npc/miaobing" : 1,

        ]));

        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

        setup();

}
