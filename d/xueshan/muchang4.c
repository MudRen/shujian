 // muchang4.c ����
 
inherit ROOM;


void create()
{
        set("short","����");
        set("long",@LONG 
������һƬãã�޼ʵ�������һ���������ߵĲ�ԭ��Զ���ܿ������ʵ�ѩ
ɽ�������ܿ������������ڷ���ţ��С�������ڱ�����ˣ��
LONG);
        set("exits",([
                "north" : __DIR__"muchang4",
                "south" : __DIR__"cunluo2",
                "west" :__DIR__"muchang1",
                "east" :__DIR__"muchang5"
        ]));
             set("objects", ([__DIR__"npc/maoniu" : 1, ]));
        set("coor/x",-200);
  set("coor/y",170);
   set("coor/z",-10);
   setup();
}
