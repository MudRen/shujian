// /d/xingxiu/silk7.c
inherit ROOM;

void create()
{
        set("short", "ɳ��");
        set("long", @LONG
�����Ƕػͳ����ڵأ���˿��֮·�ϵ��ʺ����������ǽ���ʣ�����
�߳���ǽһ���ĳǶա����ڻ������Χ�Ķ�����壬���ڴ���Ͽ���������
���޲�͸�����档
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "southeast" : __DIR__"silk6",
                "west" : __DIR__"silk8",
                "northup" : __DIR__"silk7a",
        ]));

        set("coor/x",-290);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-290);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-290);
 set("coor/y",110);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";