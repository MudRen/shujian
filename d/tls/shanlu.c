#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������Ӧ�ַ��Ա�ɽ���µ�ɽ·��·������ש�̳ɣ�ÿ�����岽����
һƥ�ɺ������Ƴ�ש��������ʵ���˲��ٹ���ǰ����һƬ�������ӣ�ң
�ֺ�ǽ�����������������������һ����Ժ�������ͷ���̴����ζ��
LONG);
        set("outdoors", "dali");

        set("exits", ([             
               "south" : __DIR__"ylf2",
               "north" : __DIR__"gate",
        ]));
set("objects",([
                __DIR__"npc/duan-m" : 2,
        ]));

        set("coor/x",-350);
  set("coor/y",-370);
   set("coor/z",20);
   setup();
}