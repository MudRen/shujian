#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short","��Ժ��");
	 set("long",@long
�����߾��������ɵ��ӵ���Ϣ�����ͳԶ����ĵط��ˣ����������Ӻ�Ժ��
���ţ����Ͽ������ִ��Ľ�����ʿ�߹����������⣬��һƬ��ɫ�����֣���
�����£�ֻ�������ϴ�������������
long);
	 set("exits",([
            "west" : __DIR__"lang",
            "east" : __DIR__"shilu2",
         ]));

         set("outdoors", "����");
         setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "������")
		return notify_fail("�����������ɵĺ�Ժ��ˡ���Ӵ���͡�\n");
	return ::valid_leave(me, dir);
}
