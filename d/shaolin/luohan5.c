inherit ROOM;
void create()
{
      set("short", "�޺����岿");
       set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�����
���������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵�
��ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ�
���书�����ڴ������
LONG
       );

       set("exits", ([
               "east" : __DIR__"lwc6",
               "west" : __DIR__"yanwutang",
               "south" : __DIR__"luohan4",
               "north" : __DIR__"luohan6",
       ]));

       set("objects",([
               CLASS_D("shaolin") + "/cheng-jian" : 1,
       ]));
       set("coor/x",-10);
  set("coor/y",280);
   set("coor/z",120);
   set("coor/x",-10);
 set("coor/y",280);
   set("coor/z",120);
   setup();
}
