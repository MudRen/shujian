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
           "west" : __FILE__,
           "north" : __DIR__"songlin2",
           "south" : __DIR__"songlin2",
     ]));
    
     set("coor/x",-300);
  set("coor/y",-280);
   set("coor/z",40);
   setup();
}