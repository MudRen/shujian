// emei ����

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ͱ��ϵĶ��ڣ����ڱ߲����˵���������ں����ģ�����ϸ��
�˶��񣬺�������һ����Ӱ�����о���ѧ��
LONG);
	set("exits", ([
		"enter" : __DIR__"houshansd",
	]));

	set("objects",([
		"/clone/weapon/blade/chuanliu-dao" : 1,
	]));

        set("outdoors", "��üɽ");
        setup();
}
