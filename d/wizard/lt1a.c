#include <ansi.h>

inherit ROOM;
string look_leitai();
void create()
{
	set("short", "�����Ŷ���̨");
	set("long", "�������齣������ķ����ű�����̨(leitai)�Ŀ�̨��̨�¼���������
���Ÿ��ɵĹ��ڡ������˵�����кܶ��������ʿ������������ա���������
���У������ޱȡ�\n");
	set("no_get_from", 1);
	set("no_sleep_room", 1);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("leitai", "/cmds/leitai/leitai1");
	set("exits", ([
		"west" : __DIR__"lt1",
	]));
	set("item_desc",([
		"leitai" : (: look_leitai :),
	]));
	setup();
}

#include "leitai_fun.h"
#include "leitai.h"
