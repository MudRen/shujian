inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
������һƬï�ܵ������֣������ߴ�֦Ҷïʢ����һ�߽�����
�����ʧ�˷���һ������������ͨ���������
LONG);

     set("outdoors", "������");
     set("exits",([
           "east" : __FILE__,
           "west" : __DIR__"songlin-3",
           "north" : __DIR__"songlin1",
           "south" : __DIR__"songlin1",
     ]));
    
     set("coor/x",-300);
  set("coor/y",-290);
   set("coor/z",40);
   setup();
}
