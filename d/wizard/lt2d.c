#include <ansi.h>

inherit ROOM;
string look_leitai();
void create()
{
	set("short", "�����Ŷ���̨");
	set("long", "�������齣������������ű�����̨(leitai)�Ŀ�̨��̨�¼���������
���Ÿ��ɵĹ��ڡ������˵�����кܶ��������ʿ������������ա���������
���У������ޱȡ�\n");
	set("no_sleep_room", 1);
	set("sleep_room", 1);
	set("no_get_from", 1);
	set("no_fight", 1);
	set("leitai", "/cmds/leitai/leitai2");
	set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"lt2",
	]));
	set("item_desc",([
		"leitai" : (: look_leitai :),
	]));
	setup();
}

#include "leitai_fun.h"
#include "leitai.h"
