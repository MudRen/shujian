// Room: caidi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�˵�");
        set("long", @LONG
���˵�λ�ڷ����ϵĺ�լ�ԣ�վ������︮��Ρ���ǽ����Ŀ��
�����˵����ܲ��ײ˳�����Ϊ�����������Զ���һ��С��ñ�ӣ�һ������
���ޡ�������һ��ľ��(door)��
LONG
        );
        set("outdoors","��ɽ");
        set("exits", ([
            "west" :  __DIR__"zhongjia",
        ]));

        set("item_desc", ([
            "door" : "����һ���ƾɵ�ľ�š�\n",
]));

        create_door("west", "ľ��", "east", DOOR_CLOSED);
        set("coor/x",20);
  set("coor/y",-570);
   set("coor/z",0);
   setup();
}
