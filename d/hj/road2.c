// road2.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
˵��·����ʵ�����ڲ�ԭ���߹����µĺۼ����쳤�վþͽ����γ��ˡ���
֧�����˲��������ﶨ���Ѿã����Կ�������������ԭʼ�ĵ�·�����ߺ�����
һ��С���
LONG);
        
        set("exits", ([
            "southwest" : __DIR__"road1",
            "north" : __DIR__"room-ji",
            "northeast" : __DIR__"caoyuan6",
            
        ]));

        set("objects", ([
                    __DIR__"npc/bird" : 1
        ]));

        set("outdoors", "��ԭ");
        
        set("coor/x",-300);
  set("coor/y",120);
   set("coor/z",0);
   setup();
}
