// road1.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
˵��·����ʵ�����ڲ�ԭ���߹����µĺۼ����쳤�վþͽ����γ��ˡ���
֧�����˲��������ﶨ���Ѿã����Կ�������������ԭʼ�ĵ�·��
LONG
        );

        
        set("exits", ([
            "northeast" : __DIR__"road2",
            "west" : __DIR__"shop",
            "east" : __DIR__"caoyuan4",
            "southdown" : __DIR__"caoyuan2",          
        ]));

        set("outdoors", "��ԭ");
        
        set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
