// /u/beyond/hz/ changlang1.c ����
 
 
inherit ROOM;
void create()
{
        set("short","����");
        set("long", @LONG
���߽����ȣ�������������ȫ��һ�������ʲʻ�������������ԡ�ÿ
һ�������������������㶼�����ˣ���ԭ����·���Ҳ����ˡ�
LONG
        );
        set("exits", ([
            "east" : __FILE__,
            "west" : __FILE__,
            "north" : __FILE__,
            "south" : __DIR__"changlang3",
            
]));
        set("coor/x",50);
  set("coor/y",-300);
   set("coor/z",0);
   setup();
}
