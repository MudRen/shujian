// /d/xingxiu/yili2.c
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "������");
        set("long", @LONG
��������������ģ�����������ʮ�����֡�ֻ�Ƕ���ά������ˣ����Ǻ�
��˵��������������������С�������������ٻ�����������������������
һ�Ҵ����̣�����ס������һ����������������ǳ������Ŀ�ջ���������
��������ˡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
        	"west" : __DIR__"store",
        	"east" : __DIR__"house",
        	"northwest" : __DIR__"kezhan",
        	"south" : __DIR__"yili1",
        	"north" : __DIR__"store1",
        ]));
        set("objects", ([
		__DIR__"../npc/woman": 1,
		__DIR__"../npc/hman": 1,
		__DIR__"../npc/wujiang": 1,
	]));
	setup();
        quarter_pass();
}

void quarter_pass()
{
        string local;

        local = NATURE_D->query_daytime();

        switch(local){
            case "event_night":
            case "event_midnight":
                  set("long", @LONG
��������������ģ�����������ʮ�����֡�ֻ�Ƕ���ά������ˣ����Ǻ�
��˵��������������������С�������������ٻ�����������������������
һ�Ҵ����̣�����ס������һ����������������ǳ������Ŀ�ջ���������
������Ѿ������ˡ�
LONG);
        	  delete("exits/south");
                  break;
            default: set("long", @LONG
��������������ģ�����������ʮ�����֡�ֻ�Ƕ���ά������ˣ����Ǻ�
��˵��������������������С�������������ٻ�����������������������
һ�Ҵ����̣�����ס������һ����������������ǳ������Ŀ�ջ���������
��������ˡ�
LONG);
                  set("exits/south", __DIR__"yili1");
        	  break;
        }
        call_out("quarter_pass", 60);
}
