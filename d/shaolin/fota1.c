#include <room.h>
inherit ROOM;


void create()
{
	set("short", "����һ��");
	set("long", @LONG
������������棬�����������ž���������Լ����������һ������ҳ�
�������ܲ��ķ��衣��Ȼһ����粻֪���Ĵ��˹������㲻�����˸�������

LONG
);

	set("exits", ([
		"up"     : __DIR__"fota2", 
                "out"     : __DIR__"fotaout",       
         	]));

	

	setup();

}

