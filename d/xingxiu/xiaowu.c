// Room: /d/xingxiu/xiaowu

inherit ROOM;
#include <ansi.h>

void create()
{
           set("short", "����С��");
        set("long", @LONG       
һ���ƾɵ�С�ݣ�����ʮ�����ң�ǽ�����߰���Ķѷ���һЩ�������
������ǽ�ϵ�С�����������������վ����һ���ߴ�ĺ��ӣ�
LONG
        );
        set("exits", ([
              "south" : __DIR__"jyg", 
        ]));

        set("objects",([
                __DIR__"npc/maguangzuo" : 1,
        ]));
 
        set("coor/x",-210);
  set("coor/y",80);
   set("coor/z",-10);
   setup();
}

