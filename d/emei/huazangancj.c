// huazangancj.c
// �ؾ�¥
inherit ROOM;
#include <room.h>

void create()
{
	set("short", "�ؾ�¥");
	set("long",@long
С��¥�ϱ��Ƕ����ɵĲؾ����ˡ����ﶼ���������飬�߼��������ܡ�
��������һ�Ŵ����ӣ����Ϸ��˼����𾭡��и�Сʦ̫�����򾲵�ʦ̫���顣
long);
	set("exits",([
            "down" : __DIR__"chuwujian",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-dao" : 1,
		"/d/emei/obj/fojing1" : 1,
		"/d/emei/obj/fojing2" : 1,
          ]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "down" && present("shu", me) && objectp(present("jingdao shitai", environment(me))))
		return notify_fail("����ʦ̫�ȵ������ؾ�¥���鼮���������\n");

	return ::valid_leave(me, dir);
} 
