inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
������������һ���ǳ��ľ��ĳ��ȣ�����ֱͨ���޾��ȵء�����
��ͷ����һ���ݣ�������Ȼ������ï�ܵ������ֻ�Ϊһ�塣
LONG);

   set("exits",([
      "west" : __DIR__"songlin",
      "north" : __DIR__"songlin1",
      "enter" : __DIR__"monitang",
      "south" : __DIR__"songlin2",
     ]));
 set("coor/x",-270);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}




