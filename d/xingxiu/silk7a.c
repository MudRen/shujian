// /d/xingxiu/silk7a.c
inherit ROOM;

void create()
{
        set("short", "��ͷ���");
        set("long", @LONG
�����ǻ�����ش����Ƿ�ʴ̨�ص���Ȼ������Χ���˼������ĸ��̲��
��ش�������ϣ������δ�磬������ʴ�����¼�Ӳ���к����ݸ��Ĳ��֣�
�γ����գ������岼��������ͷ�����д˳ơ�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk3c",
                "southdown" : __DIR__"silk7",
                "southeast" : __DIR__"silk5a",
        ]));

        set("coor/x",-280);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-280);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-280);
 set("coor/y",110);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";