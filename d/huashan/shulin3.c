// Room: /d/huashan/shulin2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص������֡�
��ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ���������
��˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β����������ƺ���
ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG);

        set("exits", ([
                "east" : __DIR__"shulin3",
                "south" : __FILE__,
                "west" : __DIR__"shulin1",
                "north" : __FILE__,
        ]));

        set("outdoors", "��ɽ");
        set("coor/x",50);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

void init()
{
       set("exits/east", __DIR__"shulin"+(1+random(4)));
       set("exits/south", __DIR__"shulin"+(1+random(4)));
       set("exits/north",  __DIR__"shulin"+(1+random(4)));
       set("exits/west",  __DIR__"shulin"+(1+random(4)));
}

