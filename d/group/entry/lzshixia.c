//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ʯϿ��");
	set("long", @LONG
ʯϿ������ǰ�Ļƺӹʵ������ڱ���Ǵ��СС�Ķ���ʯ�����������ɸ�
�ĸ��£�ǧ�����֣�������˵�����µĲ�ɣ��Ҫ�������õĻ�������������
���ǳ�Ư�����ǳ������껨ʯ��
LONG );
	set("exits", ([
		"southwest" : "/d/lanzhou/tumenzi",
		"northeast" : "/d/lanzhou/bingcao",
	]));
	set("group", 1);
	set("outdoors", "���ݳ�");
	setup();
}
