// Room : /d/wudang/gudi.c �ȵ�
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",BLU"�ȵ�"NOR);
        set("long", @LONG
�������䵱��ɽ��Ͽ�ȹȵף�������ˣ�ɽ����򰡣�����Ƕ��͵�ɽ�ڣ�
ֻ�ж��Ϸ��ƺ���һƬ���֣�����Ҷ���������������ɵġ�����������ɷ��
�ö�������
LONG                           
        );
        set("outdoors", "�䵱");

        set("exits", ([               
                 "southeast" : __DIR__"clbianyuan1",
        ]));
        setup();


}

