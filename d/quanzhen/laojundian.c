#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ͼ���");
        set("long", @LONG
�����ǹ���̫���Ͼ��Ĵ����������Ͼ��������Ͼ�
������ţ�ϣ������ƶ�ȥ��������������ͯ�ӣ�������������
�еĵض�������שһ�����̳ɣ���ɨ��һ����Ⱦ��
LONG);
        set("exits", ([
                "east" : __DIR__"houtang1",
                "south" : __DIR__"tongtiandian",
                "north" : __DIR__"yuanshidian",
                "west" : __DIR__"datang3",
        ]));
        set("objects", ([
                 CLASS_D("quanzhen") + "/qiu" : 1,
        ]));
        setup();
}
/*
int valid_leave(object me, string dir)
{        
        if ((string)me->query("family/family_name") != "ȫ���" 
           && dir == "east"  
           && present("qiu chuji", environment(me)))
	return notify_fail(
"�𴦻���ס��������������ҽ������������Ӿ������㲻�ܽ�ȥ���ҡ���\n");

	return ::valid_leave(me, dir);
}

*/



