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
            "south" : __FILE__,
            "north" : __DIR__"changlang2",
            
]));
        set("coor/x",50);
  set("coor/y",-310);
   set("coor/z",0);
   setup();
}
