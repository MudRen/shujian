 // muchang7.c ����
 
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG 
������һƬãã�޼ʵ�������һ���������ߵĲ�ԭ��Զ���ܿ������ʵ�ѩ
ɽ�������ܿ������������ڷ���ţ��С�������ڱ�����ˣ��
LONG);
        set("exits",([
                "north" : __DIR__"muchang6",
                "south" : __DIR__"muchang7",
                "west" :__DIR__"cunluo1",
                "east" :__DIR__"muchang7",
        ]));

        set("coor/x",-190);
  set("coor/y",150);
   set("coor/z",-10);
   setup();
}
