// /d/xingxiu/nanjiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "�Ͻ�ɳĮ");
        set("long", @LONG
����Ǻ�嫵���������ɴ�ɳĮ��һ�߽�������·���ʧ�˷���
��е�����ʮ�ֽ��ʣ����ǿ�Щ�뿪�ɡ�
LONG
        );

        set("exits", ([
        "northeast" : __FILE__,
        "southeast" : __FILE__,
        "southwest" : __FILE__,
        "northwest" : __DIR__"nanjiang1",
        "north" : __DIR__"silk8",
        "west" : __FILE__,
        "south" : __FILE__,
        "east" : __FILE__,
        ]));
        set("coor/x",-300);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-300);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-300);
 set("coor/y",100);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
        int current_water;

        current_water = me->query("water");
        if (current_water==0) {
          write("���Ѿ��е������ˣ�ڤڤ����������˽���̧�˳�����\n");
          me->move(__DIR__"silk8");
          me->unconcious();
        }

        if (current_water>0 && current_water<=20) {
            write("�����ȱˮ����ð���ǡ�\n");
            me->set("water",0);
        }

        if (current_water>20) {
            me->set("water",current_water-20);
        }
        if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
           return notify_fail("�����Ǳ���ȥ�������������ɳĮ�еĺ�����¥��\n");
        return ::valid_leave(me, dir);
}