//caomeidi.c by zly
 
inherit ROOM;

void create()
{
        set("short","��ݮ��");
        set("long",
"������һ���ݮ�أ��ʺ�Ĳ�ݮɢ�����̲��У����˸е�������⡣\n"
        );
        set("outdoors","��ɽ");
        set("exits", ([
            "northeast" : __DIR__"shulin1",
            "west" : __DIR__"shulin2",
            "south" : __DIR__"dukou_tanbao",
]));

         set("objects" , ([
             __DIR__"obj/caomei" : random(4),
]));

        set("coor/x",-10);
  set("coor/y",-590);
   set("coor/z",0);
   setup();
}

