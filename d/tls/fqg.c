inherit ROOM;

void create()
{
  set("short","��Ȫ��");
  set("long",@LONG
�������������µĺ�ɽ��ƫƧ�ĵط��ˣ�һ���ٲ������������
����������ٲ������ˮ��������ֱ���£��ó�һ������ɫ�ʺ磬
�ٲ�˳��ɽ����������İ����ţ�·�ߴ�ʯ�������������졣
LONG);
     set("outdoors", "������");
     set("exits",([
           "northup" : __DIR__"wxt",
           "south" : __DIR__"bzqn",
               ]));

     set("coor/x",-390);
  set("coor/y",-260);
   set("coor/z",30);
   setup();
}