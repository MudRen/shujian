 // muchang2.c ����
 
inherit ROOM;


void create()
{
        set("short","����");
        set("long",@LONG 
������һƬãã�޼ʵ�������һ���������ߵĲ�ԭ��Զ���ܿ������ʵ�ѩ
ɽ�������ܿ������������ڷ���ţ��С�������ڱ�����ˣ��
LONG);
        set("exits",([
                "north" : __DIR__"muchang1",
                "south" : __DIR__"muchang3",
                "west" :__DIR__"muchang2",
                "east" :__DIR__"cunluo2"
        ]));

        set("coor/x",-200);
  set("coor/y",160);
   set("coor/z",-10);
   setup();
}
