// hsk.c ����������
inherit ROOM;
void create()
{
        set("short", "����������");
        set("long", @LONG
���ǹ��������˾�ס�����񣬷�Բ�����ɣ�������һ��ľ��������������
Сľ׮Χ��һȦ����������ţƤ�����ľ׮�ٶ��ڵ��ϡ���ԭ�Ͼ�ס�����嶼
ϲ���������񣬷���򵥡����ɹ���������࣬��ͳ����������Ϊ���ɹŰ�����
LONG);
        set("exits", ([
            "west" : __DIR__"majiu",
            "east" : __DIR__"caoyuan",
            "southwest" : __DIR__"room-che",
         ]));
         
         set("objects", ([
                    __DIR__"npc/hasake1" : 1,
                    __DIR__"obj/cheese" : 1,
         ]));        
         set("coor/x",-330);
  set("coor/y",80);
   set("coor/z",0);
   setup();
}
