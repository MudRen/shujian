// room-che1.c

inherit ROOM;

void create()
{
        set("short", "������ļ�");
        set("long", @LONG
���������������ʰ�ú����࣬һ����֯���컨�̲ݵ���ë̺�������ܡ�
�����Ϸ��ż�������룬һ�����������Ů�������˾ƽ�����Ц�����ؿ����㡣
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"hsk",
             "west" : __DIR__"caoyuan8",
             "south" : __DIR__"caoyuan8",
             "east" : __DIR__"caoyuan8",
        ]));

        set("objects", ([
              __DIR__"npc/aman" : 1
        ]));
      
        set("coor/x",-340);
  set("coor/y",70);
   set("coor/z",0);
   setup();
}
