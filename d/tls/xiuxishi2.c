inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ��׼ҵ����ǵ�˯�������Ŵ������ţ����ߺܻ谵�������ģ�
ֻ��΢΢�ĺ����������������ǳ����ӣ���ǽ���źܶ���ľ�崲��
�����ĵ��߹�ȥ�������ſմ�����������
LONG);
        set("exits", ([
               "north" : __DIR__"men4",
            ]));
        set("no_fight",1);
        set("sleep_room", 1);
        set("coor/x",-380);
  set("coor/y",-330);
   set("coor/z",20);
   setup();
}



