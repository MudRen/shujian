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
           "west" : __DIR__"lang",
           "east" : __DIR__"lang2",
           "north" : __DIR__"songlin2",
           "south" : __DIR__"songlin1",
     ]));
     set("coor/x",-280);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}
