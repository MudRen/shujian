inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�ɮ���ǵ�˯�������Ŵ������ţ����ߺܻ谵�������ģ�ֻ
��΢΢�ĺ����������������ǳ����ӣ���ǽ���źܶ���ľ�崲��
�����ĵ��߹�ȥ�������ſմ�����������
LONG);
        set("exits", ([
               "south" : __DIR__"road4",
               "west" : __DIR__"sroom",
        ]));
        set("no_fight",1);
        set("sleep_room", 1);
        set("coor/x",-340);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}




