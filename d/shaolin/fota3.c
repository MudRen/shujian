#include <room.h>
inherit ROOM;


void create()
{
	set("short", "��������");
	set("long", @LONG

������������棬�����������ž���������Լ����������һ������ҳ���
�����ܲ��ķ��衣��Ȼһ����粻֪���Ĵ��˹������㲻�����˸�������
LONG
	);

	set("exits", ([
		"down"     : __DIR__"fota2", 
                   
         	]));

//	set("outdoors", "shaolin");

	setup();

}

