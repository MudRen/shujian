// /d/xingxiu/silk8.c
inherit ROOM;

void create()
{
        set("short", "�¹Ȼ��ٹ��");
        set("long", @LONG
�������¹Ȼ붼�ǡ��¹Ȼ�ԭΪ�ʱ���һ֧�������ڱ���������������
�Ȼ���������Ǩ�ڴˡ����¹Ȼ�Ϊ��������ɺ��������ڷ�ٹ���ڡ����ڻ�
������Χ�Ķ�����壬���ڴ���Ͽ������������޲�͸�����档
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk7",
                "west" : __DIR__"bank",
                "northwest" : __DIR__"silk9",
                "south" : __DIR__"nanjiang",
                "north" : __DIR__"silk10",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
                __DIR__"npc/bing" : 2,
        ]));

   set("coor/x",-300);
 set("coor/y",110);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";
